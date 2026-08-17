#include "xmldocumentloader.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTextStream>
#include <QXmlStreamAttribute>
#include <QXmlStreamReader>

#include "global.h"

XmlDocumentLoader::XmlDocumentLoader() { }

void XmlDocumentLoader::generatePodatkovaNakladna(const Person& seller,
    const Person& customer,
    const QSqlTableModel* model,
    const QDate& date,
    const QString& listnumber)
{
    QFile input(":podatkova.xml");
    input.open(QIODevice::ReadOnly);
    QTextStream in(&input);
    QString xml_data = in.readAll();

    // Creating data and calculating all sum
    float all_sum {};
    QString data {};

    for (int i = 0; i < model->rowCount(); ++i) {
        const float price = model->index(i, PRICE_COLUMN_INDEX).data(Qt::DisplayRole).toFloat();
        const float sum = model->index(i, SUM_COLUMN_INDEX).data(Qt::DisplayRole).toFloat();
        all_sum += sum;

        const QString unit = model->index(i, UNIT_COLUMN_INDEX).data(Qt::DisplayRole).toString();

        // if == 4 then item is by UA supplier
        const QString tnved = model->index(i, TNVED_COLUMN_INDEX).data(Qt::DisplayRole).toString();

        QString row = PODATKOVA_NAKLADNA_ROW;
        row.replace(":TNVED", tnved.toHtmlEscaped());
        row.replace(":isImport",
            tnved.size() == 4 ? ""
                              : "<RXXXXG32 ROWNUM=\":i\">1</RXXXXG32>\n");
        row.replace(
            ":Name",
            model->index(i, NAME_COLUMN_INDEX).data(Qt::DisplayRole).toString().toHtmlEscaped());
        row.replace(":UnitCode", UNIT_CODE[unit]);
        row.replace(":Unit", unit.toHtmlEscaped());
        row.replace(
            ":Count",
            model->index(i, COUNT_COLUMN_INDEX).data(Qt::DisplayRole).toString());
        row.replace(":Price", QString::number(price, 'f', 2));
        row.replace(":Sum", QString::number(sum, 'f', 2));
        row.replace(":i", QString::number(i + 1));

        data += row + "\n";
    }

    // Calculating pdv
    const float pdv = all_sum * 0.2;
    const float all_sum_with_pdv = all_sum + pdv;

    xml_data.replace(":EDRPOY", seller.edrpoy.toHtmlEscaped());
    xml_data.replace(":ListNumber", listnumber.toHtmlEscaped());
    xml_data.replace(":Month", date.toString("MM"));
    xml_data.replace(":Year", date.toString("yyyy"));
    xml_data.replace(":Date_No_Dots", date.toString("ddMMyyyy"));

    xml_data.replace(":SellerName", seller.name.toHtmlEscaped());
    xml_data.replace(":CustomerName", customer.name.toHtmlEscaped());
    xml_data.replace(":IPN", seller.ipn.toHtmlEscaped());
    xml_data.replace(":c_IPN", customer.ipn.toHtmlEscaped());

    xml_data.replace(":All_with_Pdv", QString::number(all_sum_with_pdv));
    xml_data.replace(":Pdv", QString::number(pdv));
    xml_data.replace(":All", QString::number(all_sum));

    xml_data.replace(":Data", data);

    // Formatting SellerName for sign
    const QStringList params = seller.name.split(" ", Qt::SkipEmptyParts);
    QString formattedName = seller.name;
    // Expected form: "ФОП Прізвище Ім'я По-батькові".
    if (params.size() >= 4)
        formattedName = QString("%1. %2. %3")
                            .arg(params.at(2).at(0), params.at(3).at(0), params.at(1));
    xml_data.replace(":SellerFormattedName", formattedName.toHtmlEscaped());

    // SAVE TO FILE
    const QString fileName = QFileDialog::getSaveFileName(
        nullptr, "Вигрузити файл", "/", ("Xml-files (*.xml)"));
    if (fileName.isEmpty())
        return;

    QFile result(fileName);
    if (!result.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(nullptr, "Помилка", "Не вийшло зберегти XML-файл", QMessageBox::Ok);
        return;
    }
    QTextStream out(&result);
    out << xml_data;
}

void XmlDocumentLoader::loadOmegaNakladnaToDB(const QString& fileName)
{
    // 1. Open file and read xml-data
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        return;

    // Data
    int list_id {};
    QVector<Record> records;

    // 2. Parse xml
    QXmlStreamReader reader(&file);
    while (reader.readNextStartElement()) {
        if (reader.name().toString() == "ZVIT") {
            while (reader.readNextStartElement()) {
                if (reader.name() == "ORG") {
                    while (reader.readNextStartElement()) {
                        if (reader.name() == "FIELDS") {
                            while (reader.readNextStartElement()) {
                                if (reader.name() == "EDRPOU")
                                    list_id = insertNewNakladnaWithSellerEDRPOY(reader.readElementText());
                                else
                                    reader.skipCurrentElement();
                            }
                        } else if (reader.name() == "CARD") {
                            while (reader.readNextStartElement()) {
                                if (reader.name() == "DOCUMENT") {
                                    int currentRow {}; // starting from 1-th tab rows
                                    Record product {};
                                    while (reader.readNextStartElement()) {
                                        if (reader.name() == "ROW") {
                                            // Get current row index
                                            for (const QXmlStreamAttribute& attr :
                                                reader.attributes()) {
                                                if (attr.name().toString() == QStringLiteral("TAB")) {

                                                    if (attr.value().toString() == "0") {
                                                        reader.skipCurrentElement();
                                                        break;
                                                    }

                                                    if (currentRow != attr.value().toInt()) // if current row changed
                                                    {
                                                        // Remember product
                                                        if (currentRow > 0)
                                                            records.push_back(product);

                                                        // remember new current row
                                                        currentRow = attr.value().toInt();
                                                    }

                                                } else if (attr.name().toString() == QStringLiteral("NAME")) {
                                                    if (!parseOmegaNakladnaRowByAttributeName(
                                                            reader, attr.value().toString(), product))
                                                        reader.skipCurrentElement();
                                                }
                                            }
                                        } else
                                            reader.skipCurrentElement();
                                    }
                                    records.push_back(product); // push last product

                                    // check for product existing
                                    QSqlQuery qry;

                                    for (auto &item : records)
                                    {
                                        const QString column = item.code.isEmpty() ? "catalog" : "code";
                                        const QString value = item.code.isEmpty() ? item.catalog : item.code;
                                        qry.prepare("SELECT id FROM product WHERE " + column + " = :value");
                                        qry.bindValue(":value", value);
                                        qry.exec();

                                        int product_id {};
                                        if (qry.next()) // if exists
                                            product_id = qry.value(0).toInt();

                                        if (!product_id) // if not
                                            product_id = insertNewProduct(item);

                                        if (product_id == -1)
                                            return;

                                        // insert to list
                                        insertNewRecordToList(list_id,
                                            product_id,
                                            item.count,
                                            item.purchase_price);
                                    }

                                } else
                                    reader.skipCurrentElement();
                            }
                        }
                    }
                } else
                    reader.skipCurrentElement();
            }
        } else
            reader.skipCurrentElement();
    }

    // 3. Open tab records
    emit tabRecordsRequested(list_id);
}

int XmlDocumentLoader::insertNewProduct(const Record& newProduct)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO product(code, catalog, name, unit, purchase_price) "
                "VALUES(:code, :catalog, :name, :unit, :price)");
    qry.bindValue(":code", newProduct.code);
    qry.bindValue(":catalog", newProduct.catalog);
    qry.bindValue(":name", newProduct.name);
    qry.bindValue(":unit", newProduct.unit);
    qry.bindValue(":price", newProduct.purchase_price);
    if (!qry.exec()) {
        QMessageBox::critical(nullptr,
            "Помилка завантаження накладної #1",
            qry.lastError().text(),
            QMessageBox::Ok);
        return -1;
    }

    return qry.lastInsertId().toInt();
}

void XmlDocumentLoader::insertNewRecordToList(const int& list_id,
    const int& product_id,
    const QString& count,
    const QString& price)
{
    QSqlQuery qry;

    // 1. Add new amount to DB
    qry.prepare("SELECT amount FROM product WHERE id = :id");
    qry.bindValue(":id", product_id);
    qry.exec();
    if (!qry.next()) {
        QMessageBox::critical(nullptr,
            "Помилка завантаження накладної #2",
            qry.lastError().text(),
            QMessageBox::Ok);
        return;
    }
    const int new_amount = qry.value(0).toInt() + count.toInt();

    qry.prepare("UPDATE product SET amount = :amount WHERE id = :id");
    qry.bindValue(":amount", new_amount);
    qry.bindValue(":id", product_id);
    if (!qry.exec()) {
        QMessageBox::critical(nullptr,
            "Помилка завантаження накладної #3",
            qry.lastError().text(),
            QMessageBox::Ok);
        return;
    }

    // 2. Insert into record table
    qry.prepare("INSERT INTO record(count, product_id, list_id, price) "
                "VALUES(:count, :product_id, :list_id, :price)");
    qry.bindValue(":count", count);
    qry.bindValue(":product_id", product_id);
    qry.bindValue(":list_id", list_id);
    qry.bindValue(":price", price);
    if (!qry.exec()) {
        QMessageBox::critical(nullptr,
            "Помилка завантаження накладної #4",
            qry.lastError().text(),
            QMessageBox::Ok);
        return;
    }
}

int XmlDocumentLoader::insertNewNakladnaWithSellerEDRPOY(const QString& EDRPOY)
{
    QSqlQuery qry;
    int list_id {};
    qry.prepare("SELECT MAX(number) FROM list WHERE type = :type");
    qry.bindValue(":type", DOC_TYPES_NAMES[DOC_TYPES::Nakladna_na_nadhodjennya]);
    qry.exec();
    if (qry.next())
    {
        const int newListNumber = qry.value(0).toInt() + 1;
        qry.prepare("SELECT id FROM seller WHERE edrpoy = :edrpoy");
        qry.bindValue(":edrpoy", EDRPOY);
        qry.exec();
        if (qry.next()) {
            const int sellerId = qry.value(0).toInt();
            qry.prepare("INSERT INTO list(seller_id, number, type) VALUES(:seller_id, :number, :type)");
            qry.bindValue(":seller_id", sellerId);
            qry.bindValue(":number", newListNumber);
            qry.bindValue(":type", DOC_TYPES_NAMES[DOC_TYPES::Nakladna_na_nadhodjennya]);
            if (qry.exec())
                list_id = qry.lastInsertId().toInt();
        }
    }

    return list_id;
}

bool XmlDocumentLoader::parseOmegaNakladnaRowByAttributeName(
    QXmlStreamReader& reader,
    const QString& attribute,
    Record& product)
{
    if (attribute.contains(QStringLiteral("D10"))) // Code
    {
        while (reader.readNextStartElement())
            if (reader.name() == QStringLiteral("VALUE"))
                product.code = reader.readElementText().replace(" ", "");
    } else if (attribute.contains(QStringLiteral("D11"))) // Catalog
    {
        while (reader.readNextStartElement())
            if (reader.name() == QStringLiteral("VALUE"))
                product.catalog = reader.readElementText().replace(" ", "");
    } else if (attribute.contains(QStringLiteral("D2"))) // name
    {
        while (reader.readNextStartElement())
            if (reader.name() == QStringLiteral("VALUE"))
                product.name = reader.readElementText();
    } else if (attribute.contains(QStringLiteral("D4"))) // unit
    {
        while (reader.readNextStartElement())
            if (reader.name() == QStringLiteral("VALUE"))
                product.unit = reader.readElementText();
    } else if (attribute.contains(QStringLiteral("D6"))) // count
    {
        while (reader.readNextStartElement())
            if (reader.name() == QStringLiteral("VALUE"))
                product.count = reader.readElementText();
    } else if (attribute.contains(QStringLiteral("D7"))) // price
    {
        while (reader.readNextStartElement())
            if (reader.name() == QStringLiteral("VALUE"))
                product.purchase_price = reader.readElementText();
    } else
        return false;

    return true;
}
