#include "loadsupplierpricelist.h"
#include "ui_loadsupplierpricelist.h"

LoadSupplierPricelist::LoadSupplierPricelist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadSupplierPricelist)
{
    ui->setupUi(this);
}

LoadSupplierPricelist::~LoadSupplierPricelist()
{
    delete ui;
}
