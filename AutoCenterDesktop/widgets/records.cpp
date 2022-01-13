#include "records.h"
#include "ui_records.h"

#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>

#include <QMessageBox>
#include <QVector>

#include "global.h"
#include "utils/barcodelabelprinter.h"
#include "utils/documentprinter.h"

#include "dialogs/addproduct.h"

Records::Records(QWidget* parent, int list_id)
    : QWidget(parent)
    , ui(new Ui::Records)
    , list_id(list_id)
{
    ui->setupUi(this);

    // model for tableView
    model = new QSqlTableModel();
    model->setTable("record_view");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setFilter("list_id=" + QString::number(list_id));
    updateView();

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("List ID"));
    model->setHeaderData(2, Qt::Horizontal, tr("Код"));
    model->setHeaderData(3, Qt::Horizontal, tr("Каталог"));
    model->setHeaderData(4, Qt::Horizontal, tr("ТНВЕД"));
    model->setHeaderData(5, Qt::Horizontal, tr("Назва"));
    model->setHeaderData(6, Qt::Horizontal, tr("К-сть"));
    model->setHeaderData(7, Qt::Horizontal, tr("Одиниці"));
    model->setHeaderData(8, Qt::Horizontal, tr("Ціна"));
    model->setHeaderData(9, Qt::Horizontal, tr("Сума"));

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(ID_COLUMN_INDEX, true); // hide ID
    ui->tableView->setColumnHidden(LIST_ID_COLUMN_INDEX, true); // hide list_id
    ui->tableView->setColumnHidden(3, true); // hide catalog
    ui->tableView->setColumnHidden(4, true); // hide tnved
    ui->tableView->setItemDelegateForColumn(8, new NumberFormatDelegate(this));
    ui->tableView->setItemDelegateForColumn(9, new NumberFormatDelegate(this));

    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    for (int i = 0; i < ui->tableView->model()->columnCount(); ++i) {
        if (i == NAME_COLUMN_INDEX)
            ui->tableView->setColumnWidth(i, 800);
        else if (i == CODE_COLUMN_INDEX)
            ui->tableView->setColumnWidth(i, 300);
        else
            ui->tableView->setColumnWidth(i, 150);
    }

    // Comboboxes
    initComboboxes();

    // Datetime and enable or disable print buttons
    initDateTimeAndPrintButtons();

    connect(model, &QSqlTableModel::dataChanged, this, &Records::handleDataChange);
}

Records::~Records()
{
    delete ui;
}

void Records::on_comboBox_Customer_currentIndexChanged(int index)
{
    QSqlQuery qry;
    qry.exec("UPDATE list SET customer_id=" + customer_index_to_id[index] + " WHERE id=" + QString::number(list_id));

    emit listDataChanged();
}

void Records::on_comboBox_Seller_currentIndexChanged(int index)
{
    QSqlQuery qry;
    qry.exec("UPDATE list SET seller_id=" + seller_index_to_id[index] + " WHERE id=" + QString::number(list_id));

    emit listDataChanged();
}

void Records::on_btn_add_clicked()
{
    QSqlQuery qry;
    qry.exec("INSERT INTO record(count, price, list_id) VALUES(0, '0.0', " + QString::number(list_id) + ")");

    updateView();
}

void Records::on_btn_del_clicked()
{
    const auto selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty())
        return;
    const QString record_id = selectedIndexes.at(0).siblingAtColumn(ID_COLUMN_INDEX).data(Qt::DisplayRole).toString();

    QSqlQuery qry;
    qry.exec("PRAGMA foreign_keys=ON");
    qry.exec("DELETE FROM record WHERE id=" + record_id);

    updateView();
}

void Records::handleDataChange(const QModelIndex& topLeft, const QModelIndex&)
{
    const QVector<int> editableColumns = {
        CODE_COLUMN_INDEX /* code */, PRICE_COLUMN_INDEX /* price */, COUNT_COLUMN_INDEX /* count */
    };
    const int column = topLeft.column();
    const QString data = topLeft.data(Qt::DisplayRole).toString();
    const QString record_id = topLeft.siblingAtColumn(ID_COLUMN_INDEX).data(Qt::DisplayRole).toString();

    if (editableColumns.contains(column)) {
        switch (column) {
        case 2: {
            handleProductCodeChange(data, record_id);
        } break;
        case 8: {
            handlePriceCellChange(data, record_id);
        } break;
        case 6: {
            handleCountCellChange(data, record_id);
        } break;
        }
    }

    updateView();
}

void Records::handleProductCodeChange(const QString& data, const QString& record_id)
{
    // #1 Find product_id by code
    QSqlQuery qry;
    qry.exec("SELECT id, purchase_price FROM product WHERE code='" + data + "'");
    if (qry.next()) {
        // #2 Change product_id cell and price

        // SPECIAL for price +30% if not receipt
        float price = qry.value(1).toFloat();
        if (docType != DOC_TYPES_NAMES[DOC_TYPES::Nakladna_na_nadhodjennya])
            price *= 1.3;

        handleSimpleCellChange("product_id", qry.value(0).toString(), record_id);
        handleSimpleCellChange("price", QString::number(price, 'f', 2), record_id);
    } else {
        auto result = QMessageBox::information(this, "Повідомляю",
            "Товару з даним кодом у базі данних не знайдено.\n"
            "Можливо ви хочете додати новий вид товару?",
            QMessageBox::Yes | QMessageBox::No);

        if (result == QMessageBox::Yes)
        {
            AddProduct *dlg = new AddProduct;
            dlg->setCodeToLineEdit(data);
            if (dlg->exec() == QDialog::Accepted)
                handleProductCodeChange(data, record_id);
        }
    }
}

void Records::handleCountCellChange(const QString &data, const QString &record_id)
{
    // get previos value
    QSqlQuery qry;
    qry.exec("SELECT count, product_id FROM record WHERE id=" + record_id);
    bool isNumber { true };
    data.toInt(&isNumber);
    if (qry.next() && isNumber)
    {
        // 5(new) - 3(old) -> amount became bigger on 2
        const int difference = data.toInt() - qry.value(0).toInt();

        const QString product_id = qry.value(1).toString();
        if (product_id.isEmpty())
        {
            QMessageBox::warning(this, "Попередження", "Встановіть будь-ласка спочатку код товару.", QMessageBox::Ok);
            return;
        }

        qry.exec("SELECT amount FROM product WHERE id=" + product_id);
        if (qry.next() && difference != 0)
        {
            int newAmount {};
            if (docType == DOC_TYPES_NAMES[DOC_TYPES::Nakladna_na_nadhodjennya])
                newAmount = qry.value(0).toInt() + difference; // plus goods to storage
            else if (docType == DOC_TYPES_NAMES[DOC_TYPES::Vydatkova_nakladna]
                     || docType == DOC_TYPES_NAMES[DOC_TYPES::Tovarniy_chek])
                newAmount = qry.value(0).toInt() - difference; // minus goods

            if (qry.exec("UPDATE product SET amount=" + QString::number(newAmount) + " WHERE id=" + product_id))
                handleSimpleCellChange("count", data, record_id);
            else
                QMessageBox::critical(this, "Помилка", "Не вдалося змінити к-сть товару на складі. \nLog: " +
                                      qry.lastError().text(), QMessageBox::Ok);
        }
    }
}

void Records::handlePriceCellChange(const QString &data, const QString &record_id)
{
    bool isNumber { true };
    data.toFloat(&isNumber);
    if (isNumber)
    {
        if (docType == DOC_TYPES_NAMES[DOC_TYPES::Nakladna_na_nadhodjennya])
        {
            QSqlQuery qry;
            qry.exec("SELECT product_id FROM record WHERE id=" + record_id);
            if (qry.next())
            {
                const QString product_id = qry.value(0).toString();
                if (!qry.exec("UPDATE product SET purchase_price='" + data + "' WHERE id=" + product_id))
                    QMessageBox::critical(this, "Помилка", "Не вдалося встановити ціну закупки. \nLog: " +
                                          qry.lastError().text(), QMessageBox::Ok);
            }
        }
        handleSimpleCellChange("price", data, record_id);
    }
}

void Records::handleSimpleCellChange(const QString& columnName, const QString& data, const QString& record_id)
{
    QSqlQuery qry;
    const QString query_str = "UPDATE record SET %1=%2 WHERE id=%3";
    qry.exec(query_str.arg(columnName, data, record_id));
}

void Records::on_btn_print_barcode_clicked()
{
    const auto selectedRows = ui->tableView->selectionModel()->selectedRows(CODE_COLUMN_INDEX);
    if (!selectedRows.isEmpty()) {
        QVector<BarcodeLabelPrinter::Label> labels;
        for (const QModelIndex& code : selectedRows) {
            BarcodeLabelPrinter::Label label;
            label.barcodeData = code.data(Qt::DisplayRole).toString();
            label.labelText = code.siblingAtColumn(NAME_COLUMN_INDEX).data(Qt::DisplayRole).toString();
            label.timesToPrint = code.siblingAtColumn(COUNT_COLUMN_INDEX).data(Qt::DisplayRole).toInt();

            labels.push_back(label);
        }

        BarcodeLabelPrinter::printLabels(labels);
    }
}

void Records::on_btn_print_document_clicked()
{
    QSqlQuery qry;
    qry.exec("SELECT number FROM list WHERE id=" + QString::number(list_id));
    if (!qry.next())
        return;
    const QString listNumber = qry.value(0).toString();

    qry.exec("SELECT name, iban, bank, edrpoy, number, ipn FROM seller WHERE id=" + seller_index_to_id[ui->comboBox_Seller->currentIndex()]);
    Seller seller;
    if (!qry.next())
        return;
    seller.name = qry.value(0).toString();
    seller.iban = qry.value(1).toString();
    seller.bank = qry.value(2).toString();
    seller.edrpoy = qry.value(3).toString();
    seller.number = qry.value(4).toString();
    seller.ipn = qry.value(5).toString();

    DocumentPrinter* printer = new DocumentPrinter();
    if (docType == DOC_TYPES_NAMES[DOC_TYPES::Rahunok])
        printer->printPdvRahunok(seller, ui->comboBox_Customer->currentText(), model,
            ui->line_datetime->text(), listNumber);
}

void Records::updateView()
{
    // Update tableView
    model->select();

    // Update line_sum
    QSqlQuery qry;
    qry.exec("SELECT SUM(sum) FROM record WHERE list_id=" + QString::number(list_id));
    float sum {};
    if (qry.next())
        sum = qry.value(0).toFloat();
    ui->line_sum->setText(QString::number(sum, 'G'));
}

void Records::initDateTimeAndPrintButtons()
{
    QSqlQuery qry;
    qry.exec("SELECT datetime, type FROM list WHERE id=" + QString::number(list_id));
    QString datetime {};
    if (qry.next()) {
        datetime = qry.value(0).toString();

        docType = qry.value(1).toString();
        if (docType == DOC_TYPES_NAMES.at(DOC_TYPES::Nakladna_na_nadhodjennya))
            ui->btn_print_document->setDisabled(true);
    }
    ui->line_datetime->setText(datetime);
}

void Records::initComboboxes()
{
    const QString NULL_STR = "NULL";
    const QString currentCustomerID = getFromDBCurrentListColumn("customer_id");
    const QString currentSellerID = getFromDBCurrentListColumn("seller_id");

    // Customers
    QSqlQuery qry;
    qry.exec("SELECT id, name FROM customer");
    int index {};
    while (qry.next()) {
        customer_index_to_id[index] = qry.value(0).toString() /*id*/;
        ui->comboBox_Customer->insertItem(
            index,
            qry.value(1).toString() /*name*/
        );

        // Correct index setup
        if (customer_index_to_id[index] == currentCustomerID)
            ui->comboBox_Customer->setCurrentIndex(index);

        index++;
    }

    // Sellers
    qry.exec("SELECT id, name FROM seller");
    index = 0;
    while (qry.next()) {
        seller_index_to_id[index] = qry.value(0).toString() /*id*/;
        ui->comboBox_Seller->insertItem(
            index,
            qry.value(1).toString() /*name*/
        );

        // Correct index setup
        if (seller_index_to_id[index] == currentSellerID)
            ui->comboBox_Seller->setCurrentIndex(index);

        index++;
    }
}

QString Records::getFromDBCurrentListColumn(QString column_name)
{
    QSqlQuery qry;
    qry.exec("SELECT " + column_name + " FROM list WHERE id=" + QString::number(list_id));
    QString res {};
    if (qry.next())
        res = qry.value(0).toString();
    return res;
}
