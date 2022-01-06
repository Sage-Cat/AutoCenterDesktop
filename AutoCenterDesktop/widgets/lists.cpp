#include "lists.h"
#include "ui_lists.h"

#include <QSqlTableModel>
#include <QSqlQuery>

#include "mainwindow.h"

Lists::Lists(QWidget *parent, bool isSale) :
    QWidget(parent),
    ui(new Ui::Lists),
    isSale(isSale)
{
    ui->setupUi(this);

    // model for tableView
    model = new QSqlTableModel();
    model->setTable("list_view");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Коли"));
    model->setHeaderData(2, Qt::Horizontal, tr("Номер"));
    model->setHeaderData(3, Qt::Horizontal, tr("Тип"));
    model->setHeaderData(4, Qt::Horizontal, tr("Покупець"));
    model->setHeaderData(5, Qt::Horizontal, tr("Продавець"));

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(ID_COLUMN_INDEX, true); // hide ID column
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Lists::~Lists()
{
    delete ui;
}

void Lists::on_btn_add_clicked()
{
    QSqlQuery qry;
    // Get MAX+1 id to insert new row
    qry.exec("SELECT MAX(ID) FROM list");
    qry.next();
    const int next_id = qry.value(0).toInt() + 1;

    // #1 Add new empty list to db + refresh
    qry.exec("INSERT INTO list(ID) VALUES(" + QString::number(next_id) + ")");
    model->select();

    // #2 Open new tab for created list
    emit tabRecordsRequested(next_id);
}

void Lists::on_btn_del_clicked()
{
    const auto selectedRows = ui->tableView->selectionModel()->selectedRows(ID_COLUMN_INDEX);
    if (!selectedRows.isEmpty())
    {
        const QString id = selectedRows.front().data(Qt::DisplayRole).toString();
        QSqlQuery qry;
        qry.exec("DELETE FROM list WHERE id=" + id);
        model->select();
    }
}

void Lists::on_radio_all_clicked()
{
}

void Lists::on_radio_org_clicked()
{
}

void Lists::on_radio_not_org_clicked()
{
}

