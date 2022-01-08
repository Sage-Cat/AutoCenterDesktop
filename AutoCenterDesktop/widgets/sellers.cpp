#include "sellers.h"
#include "ui_sellers.h"

#include <QSqlTableModel>
#include <QSqlQuery>

Sellers::Sellers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sellers)
{
    ui->setupUi(this);

    // model for tableView
    model = new QSqlTableModel();
    model->setTable("seller");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Ім'я")); // only organizations will have ipn
    model->setHeaderData(2, Qt::Horizontal, tr("ІБАН"));
    model->setHeaderData(3, Qt::Horizontal, tr("Банк"));
    model->setHeaderData(4, Qt::Horizontal, tr("ЄДРПОУ"));
    model->setHeaderData(5, Qt::Horizontal, tr("ІПН"));
    model->setHeaderData(6, Qt::Horizontal, tr("Адреса"));

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(ID_COLUMN_INDEX, true); // hide ID
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Sellers::~Sellers()
{
    delete ui;
}

void Sellers::on_btn_add_clicked()
{
    QSqlQuery qry;
    qry.exec("INSERT INTO seller(name) VALUES(NULL)");

    model->select();
}

void Sellers::on_btn_del_clicked()
{
    const auto selected_indexes = ui->tableView->selectionModel()->selectedIndexes();
    QSqlQuery qry;
    if (!selected_indexes.isEmpty())
    {
        qry.exec("PRAGMA foreign_keys=ON");
        qry.exec("DELETE FROM seller WHERE id=" + selected_indexes.at(0).siblingAtColumn(ID_COLUMN_INDEX)
                 .data(Qt::DisplayRole).toString()
                 );
    }

    model->select();
}

void Sellers::on_btn_info_clicked()
{
    const auto selected_rows = ui->tableView->selectionModel()->selectedRows(ID_COLUMN_INDEX);
    if (!selected_rows.isEmpty())
        emit tabSellerInfoRequested(selected_rows.at(0).data(Qt::DisplayRole).toInt());
}

