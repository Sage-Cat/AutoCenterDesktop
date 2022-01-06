#include "lists.h"
#include "ui_lists.h"

#include <QSqlTableModel>

#include "mainwindow.h"

Lists::Lists(QWidget *parent, bool isSale) :
    QWidget(parent),
    ui(new Ui::Lists),
    isSale(isSale)
{
    ui->setupUi(this);

    // model for tableView
    QSqlTableModel *model = new QSqlTableModel();
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
    ui->tableView->setColumnHidden(0, true); // hide ID column
}

Lists::~Lists()
{
    delete ui;
}

void Lists::on_btn_add_clicked()
{
}

void Lists::on_btn_del_clicked()
{
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

