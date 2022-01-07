#include "records.h"
#include "ui_records.h"

#include <QSqlTableModel>
#include <QSqlQuery>

#include <QMessageBox>

Records::Records(QWidget *parent, int list_id) :
    QWidget(parent),
    ui(new Ui::Records),
    list_id(list_id)
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
}

void Records::on_comboBox_Seller_currentIndexChanged(int index)
{
}

void Records::on_btn_add_clicked()
{
}

void Records::on_btn_del_clicked()
{
}

void Records::on_tableWidget_itemChanged(QTableWidgetItem *item)
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
    ui->tableView->update();

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
    // Customers
    QSqlQuery qry;
    qry.exec("SELECT id, name FROM customer");
    while (qry.next())
        ui->comboBox_Customer->insertItem(
                    qry.value(0).toInt(),
                    qry.value(1).toString()
                    );

    // Sellers
    qry.exec("SELECT id, name FROM seller");
    while (qry.next())
        ui->comboBox_Seller->insertItem(
                    qry.value(0).toInt(),
                    qry.value(1).toString()
                    );
}

