#include "addproduct.h"
#include "ui_addproduct.h"

#include "widgets/products.h"

AddProduct::AddProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProduct)
{
    ui->setupUi(this);
}

AddProduct::~AddProduct()
{
    delete ui;
}

void AddProduct::on_btn_add_clicked()
{
    Products::insertProductToDb(
                ui->line_code->text(),
                ui->line_catalog->text(),
                ui->line_tnved->text(),
                ui->line_name->text(),
                ui->line_unit->text(),
                "0.0"
                );

    this->accept();
}

