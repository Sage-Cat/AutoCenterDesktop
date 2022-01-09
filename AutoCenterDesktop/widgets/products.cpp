#include "products.h"
#include "ui_products.h"

#include <QSqlQuery>

Products::Products(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Products)
{
    ui->setupUi(this);
}

Products::~Products()
{
    delete ui;
}

void Products::insertProductToDb(QString code, QString catalog, QString tnved, QString name, QString unit, QString price)
{
    QSqlQuery qry;
    QString query_str =
            "INSERT INTO Product(code, catalog, tnved, name, unit, price) "
                "VALUES(%1, %2, %3, %4, %5, %6)";
    qry.exec(query_str.arg(code, catalog, tnved, name, unit, price));
}
