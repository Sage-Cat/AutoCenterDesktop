#include "records.h"
#include "ui_records.h"

#include <QSqlQuery>
#include <QSqlTableModel>

#include <QMessageBox>

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

    // Comboboxes
    initComboboxes();

    // Datetime
    initDateTime();
}

Records::~Records()
{
    delete ui;
}

void Records::on_comboBox_Customer_currentIndexChanged(int index)
{
    QSqlQuery qry;
    qry.exec("UPDATE list SET customer_id=" + customer_index_to_id[index] + " WHERE id=" + QString::number(list_id));
}

void Records::on_comboBox_Seller_currentIndexChanged(int index)
{
    QSqlQuery qry;
    qry.exec("UPDATE list SET seller_id=" + customer_index_to_id[index] + " WHERE id=" + QString::number(list_id));
}

void Records::on_btn_add_clicked()
{
}

void Records::on_btn_del_clicked()
{
}

void Records::on_btn_print_barcode_clicked()
{
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
    ui->line_sum->setText(QString::number(sum));
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
