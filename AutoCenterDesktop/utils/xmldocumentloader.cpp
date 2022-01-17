#include "xmldocumentloader.h"

#include <QSqlTableModel>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

#include "global.h"

XmlDocumentLoader::XmlDocumentLoader()
{
}

void XmlDocumentLoader::generatePodatkovaNakladna(const Person &seller, const Person &customer, const QSqlTableModel *model, const QDate &date, const QString &listnumber)
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
        row.replace(":TNVED", tnved);
        row.replace(":isImport", tnved.size() == 4 ? "" : "<RXXXXG32 ROWNUM=\":i\">1</RXXXXG32>\n");
        row.replace(":Name", model->index(i, NAME_COLUMN_INDEX).data(Qt::DisplayRole).toString());
        row.replace(":UnitCode", UNIT_CODE[unit]);
        row.replace(":Unit", unit);
        row.replace(":Count", model->index(i, COUNT_COLUMN_INDEX).data(Qt::DisplayRole).toString());
        row.replace(":Price", QString::number(price, 'f', 2));
        row.replace(":Sum", QString::number(sum, 'f', 2));
        row.replace(":i", QString::number(i + 1));

        data += row + "\n";
    }

    // Calculating pdv
    const float pdv = all_sum * 0.2;
    const float all_sum_with_pdv = all_sum + pdv;

    xml_data.replace(":EDRPOY", seller.edrpoy);
    xml_data.replace(":ListNumber", listnumber);
    xml_data.replace(":Month", date.toString("MM"));
    xml_data.replace(":Year", date.toString("yyyy"));
    xml_data.replace(":Date_No_Dots", date.toString("ddMMyyyy"));

    xml_data.replace(":SellerName", seller.name);
    xml_data.replace(":CustomerName", customer.name);
    xml_data.replace(":IPN", seller.ipn);
    xml_data.replace(":c_IPN", customer.ipn);

    xml_data.replace(":All_with_Pdv", QString::number(all_sum_with_pdv));
    xml_data.replace(":Pdv", QString::number(pdv));
    xml_data.replace(":All", QString::number(all_sum));

    xml_data.replace(":Data", data);

    // Formatting SellerName for sign
    QStringList params { seller.name.split(" ") }; // 1 - "ФОП", 2 - "Прізвище", 3 - "Ім'я", 4 - "По-батькові"
    Q_ASSERT(params.size() == 4);
    const QString &formattedName = QString(":N. :B. :P").arg(params.at(2).at(0), params.at(3).at(0), params.at(1));
    xml_data.replace(":SellerFormattedName", formattedName);

    // SAVE TO FILE
    const QString fileName = QFileDialog::getSaveFileName(nullptr, "Вигрузити файл", "/", ("Xml-files (*.xml)"));
    QFile result(fileName);
    result.open(QIODevice::WriteOnly);
    QTextStream out(&result);
    out << xml_data;
}
