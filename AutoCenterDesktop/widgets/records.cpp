#include "records.h"
#include "ui_records.h"

#include <QSqlQuery>
#include <QSqlTableModel>

#include <QVector>
#include <QMessageBox>

#include <QPainter>
#include "utils/barcodelabelprinter.h"

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
    model->setHeaderData(6, Qt::Horizontal, tr("Ціна"));
    model->setHeaderData(7, Qt::Horizontal, tr("К-сть"));
    model->setHeaderData(8, Qt::Horizontal, tr("Одиниці"));
    model->setHeaderData(9, Qt::Horizontal, tr("Сума"));

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(ID_COLUMN_INDEX, true); // hide ID
    ui->tableView->setColumnHidden(LIST_ID_COLUMN_INDEX, true); // hide ID
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setItemDelegateForColumn(6, new NumberFormatDelegate(this));
    ui->tableView->setItemDelegateForColumn(9, new NumberFormatDelegate(this));

    // Comboboxes
    initComboboxes();

    // Datetime
    initDateTime();

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
    qry.exec("INSERT INTO record(count, price, list_id) VALUES(1, '0.0', " + QString::number(list_id) + ")");

    updateView();
}

void Records::on_btn_del_clicked()
{
    const auto selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty())
        return;
    const QString record_id = selectedIndexes.at(0).siblingAtColumn(ID_COLUMN_INDEX)
            .data(Qt::DisplayRole).toString();

    QSqlQuery qry;
    qry.exec("PRAGMA foreign_keys=ON");
    qry.exec("DELETE FROM record WHERE id=" + record_id);

    updateView();
}

void Records::handleDataChange(const QModelIndex& topLeft, const QModelIndex&)
{
    const QVector<int> editableColumns = {
        2 /* code */, 6 /* price */, 7 /* count */
    };
    const int column = topLeft.column();
    const QString data = topLeft.data(Qt::DisplayRole).toString();
    const QString record_id = topLeft.siblingAtColumn(ID_COLUMN_INDEX).data(Qt::DisplayRole).toString();

    if (editableColumns.contains(column)) {
        switch (column) {
        case 2: {
            handleProductCodeChange(data, record_id);
        } break;
        case 6: {
            handleSimpleCellChange("price", data, record_id);
        } break;
        case 7: {
            handleSimpleCellChange("count", data, record_id);
        } break;
        }
    }

    updateView();
}

void Records::handleProductCodeChange(const QString& data, const QString& record_id)
{
    // #1 Find product_id by code
    QSqlQuery qry;
    qry.exec("SELECT id, price FROM product WHERE code='" + data + "'");
    if (qry.next())
    {
        // #2 Change product_id cell and price
        handleSimpleCellChange("product_id", qry.value(0).toString(), record_id);
        handleSimpleCellChange("price", qry.value(1).toString(), record_id);
    }
    else
        QMessageBox::information(this, "Повідомляю", "Товару з даним кодом у базі данних не знайдено", QMessageBox::Ok);
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
    if (!selectedRows.isEmpty())
    {
        QVector<BarcodeLabelPrinter::Label> labels;
        for (const QModelIndex &code : selectedRows)
        {
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
    ui->line_sum->setText(QString::number(sum, 'G', 12));
}

void Records::initDateTime()
{
    QSqlQuery qry;
    qry.exec("SELECT datetime FROM list WHERE id=" + QString::number(list_id));
    QString datetime {};
    if (qry.next())
        datetime = qry.value(0).toString();
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
    customer_index_to_id[index] = NULL_STR; // for empty (default)
    ui->comboBox_Customer->insertItem(index, "");
    index++;
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
    seller_index_to_id[index] = NULL_STR; // for empty (default)
    ui->comboBox_Seller->insertItem(index, "");
    index++;
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
