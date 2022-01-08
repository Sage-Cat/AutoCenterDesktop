#include "customers.h"
#include "ui_customers.h"

#include <QSqlTableModel>
#include <QSqlQuery>

Customers::Customers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Customers)
{
    ui->setupUi(this);

    // model for tableView
    model = new QSqlTableModel();
    model->setTable("customer_view");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    updateView();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Ім'я")); // only organizations will have ipn
    model->setHeaderData(2, Qt::Horizontal, tr("К-сть авто"));
    model->setHeaderData(3, Qt::Horizontal, tr("Адреса"));
    model->setHeaderData(4, Qt::Horizontal, tr("Номер"));
    model->setHeaderData(5, Qt::Horizontal, tr("Ел.пошта"));
    model->setHeaderData(6, Qt::Horizontal, tr("ІБАН"));
    model->setHeaderData(7, Qt::Horizontal, tr("Банк"));
    model->setHeaderData(8, Qt::Horizontal, tr("ЄДРПОУ"));
    model->setHeaderData(9, Qt::Horizontal, tr("ІПН"));

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(ID_COLUMN_INDEX, true); // hide ID
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(model, &QSqlTableModel::dataChanged, this, &Customers::handleDataChange);
}

Customers::~Customers()
{
    delete ui;
}

void Customers::on_btn_add_clicked()
{
    QSqlQuery qry;
    qry.exec("INSERT INTO customer(name) VALUES(NULL)");

    updateView();
}

void Customers::on_btn_del_clicked()
{
    const auto selected_rows = ui->tableView->selectionModel()->selectedRows(ID_COLUMN_INDEX);
    QSqlQuery qry;
    if (!selected_rows.isEmpty())
        qry.exec("DELETE FROM seller WHERE id=" + selected_rows.at(0).data(Qt::DisplayRole).toString());

    updateView();
}

void Customers::on_btn_info_clicked()
{
    const auto selected_rows = ui->tableView->selectionModel()->selectedRows(ID_COLUMN_INDEX);
    if (!selected_rows.isEmpty())
        emit tabCustomerInfoRequested(selected_rows.at(0).data(Qt::DisplayRole).toInt());
}

void Customers::on_btn_cars_clicked()
{

}

void Customers::on_tableView_doubleClicked(const QModelIndex &index)
{
    emit tabCustomerInfoRequested(index.siblingAtColumn(ID_COLUMN_INDEX).data(Qt::DisplayRole).toInt());
}

void Customers::handleDataChange(const QModelIndex &topLeft, const QModelIndex &)
{
    const QVector<int> notEditableColumns = {
        2 /* Cars count is NOT EDITABLE */
    };
    const int column = topLeft.column();
    const QString data = topLeft.data(Qt::DisplayRole).toString();
    const QString customer_id = topLeft.siblingAtColumn(ID_COLUMN_INDEX).data(Qt::DisplayRole).toString();

    if (!notEditableColumns.contains(column)) {
        switch (column) {
        case 1: {
            handleSimpleCellChange("name", data, customer_id);
        } break;
        case 3: {
            handleSimpleCellChange("address", data, customer_id);
        } break;
        case 4: {
            handleSimpleCellChange("number", data, customer_id);
        } break;
        case 5: {
            handleSimpleCellChange("email", data, customer_id);
        } break;
        case 6: {
            handleSimpleCellChange("iban", data, customer_id);
        } break;
        case 7: {
            handleSimpleCellChange("bank", data, customer_id);
        } break;
        case 8: {
            handleSimpleCellChange("edrpoy", data, customer_id);
        } break;
        case 9: {
            handleSimpleCellChange("ipn", data, customer_id);
        } break;
        }
    }

    updateView();
}

void Customers::handleSimpleCellChange(const QString &columnName, const QString &data, const QString &customer_id)
{
    QSqlQuery qry;
    const QString query_str = "UPDATE customer SET %1=%2 WHERE id=%3";
    qry.exec(query_str.arg(columnName, data, customer_id));
}

void Customers::updateView()
{
    model->select();
}

