#include "cars.h"
#include "ui_cars.h"

#include <QSqlTableModel>
#include <QSqlQuery>

Cars::Cars(QWidget *parent, int customer_id) :
    QWidget(parent),
    ui(new Ui::Cars),
    customer_id(customer_id)
{
    ui->setupUi(this);

    // model for tableView
    model = new QSqlTableModel();
    model->setTable("car");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setFilter("customer_id=" + QString::number(customer_id));
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Назва")); // only organizations will have ipn
    model->setHeaderData(2, Qt::Horizontal, tr("VIN-код"));
    model->setHeaderData(3, Qt::Horizontal, tr("customer_id"));

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(ID_COLUMN_INDEX, true); // hide ID
    ui->tableView->setColumnHidden(CUSTOMER_ID_COLUMN_INDEX, true); // hide customer_id
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Cars::~Cars()
{
    delete ui;
}

void Cars::on_btn_add_clicked()
{
    QSqlQuery qry;
    qry.exec("INSERT INTO car(customer_id) VALUES(" + QString::number(customer_id) + ")");

    model->select();

    emit carsCountChanged();
}

void Cars::on_btn_del_clicked()
{
    const auto selected_indexes = ui->tableView->selectionModel()->selectedIndexes();
    QSqlQuery qry;
    if (!selected_indexes.isEmpty())
    {
        for (int i = 0; i < selected_indexes.size(); ++i)
        {
            qry.exec("PRAGMA foreign_keys=ON");
            qry.exec("DELETE FROM car WHERE id=" + selected_indexes.at(i).siblingAtColumn(ID_COLUMN_INDEX)
                     .data(Qt::DisplayRole).toString()
                     );
        }
    }

    model->select();

    emit carsCountChanged();
}

