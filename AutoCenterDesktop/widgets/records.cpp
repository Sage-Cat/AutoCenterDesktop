#include "records.h"
#include "ui_records.h"

#include <QVector>

Records::Records(QWidget *parent, int ID_List) :
    QWidget(parent),
    ui(new Ui::Records),
    ID_List(ID_List)
{
    ui->setupUi(this);
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

