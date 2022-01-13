#include "findproduct.h"
#include "ui_findproduct.h"

#include <QSqlQuery>
#include <QMessageBox>

FindProduct::FindProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindProduct)
{
    ui->setupUi(this);

    QStringList searchBy {
        "Пошук за кодом",
        "Пошук за каталожним номером",
        "Пошук за ТНВЕД",
        "За назвою"
    };

    ui->comboBox->addItems(searchBy);
}

FindProduct::~FindProduct()
{
    delete ui;
}

void FindProduct::on_btn_search_clicked()
{
    foundProductIDs.clear();
    const QString searchBy = ui->comboBox->currentText();
    const QString data = ui->line_search->text();

    if (data.isEmpty())
    {
        QMessageBox::information(this, "Повідомлення", "Уведіть, будь-ласка, те, що хочете знайти", QMessageBox::Ok);
        return;
    }

    if (searchBy == "Пошук за кодом") // code
        searchForEqual("code", data);
    else if (searchBy == "Пошук за каталожним номером") // catalog
        searchForEqual("catalog", data);
    else if (searchBy == "Пошук за ТНВЕД") // tnved
        searchForEqual("tnved", data);
    else if (searchBy == "За назвою") // name
        searchForSubstr("name", data);

    if (!foundProductIDs.isEmpty())
        this->accept();
    else
        QMessageBox::information(this, "Повідомлення", "За введеним запитом не знайдено жодного товару", QMessageBox::Ok);
}

void FindProduct::searchForEqual(QString column, QString data)
{
    QSqlQuery qry;
    qry.exec("SELECT id FROM product WHERE " + column + "='" + data + "'");

    while (qry.next())
        foundProductIDs.push_back(qry.value(0).toString());
}

void FindProduct::searchForSubstr(QString column, QString name)
{
    QSqlQuery qry;
    qry.exec("SELECT id FROM product WHERE " + column + " LIKE '%" + name + "%'");

    while (qry.next())
        foundProductIDs.push_back(qry.value(0).toString());
}

const QStringList &FindProduct::getFoundProductIDs() const
{
    return foundProductIDs;
}

