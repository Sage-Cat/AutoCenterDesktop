#include "lists.h"
#include "ui_lists.h"

#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>

#include <QMessageBox>

#include "dialogs/setlisttype.h"
#include "mainwindow.h"

#include "global.h"

#include <QDebug>

/*!
 * \brief Lists::setModelFilter sets complex filter system. We need it due to number of characteristics
 * like isSale and comboboxes
 * \param filterState
 */
void Lists::setModelFilter(FilterFlag flag)
{
    // #1 Check for isSale
    QString filter {
        isSale ? "type <> " : "type == "
    };
    filter += "'" + DOC_TYPES_NAMES.at(DOC_TYPES::Nakladna_na_nadhodjennya) + "'";

    // #2 Check for combobox filters
    if (flag == FilterFlag::ShowOrganizationsOnly)
        filter += " AND ipn IS NOT NULL";
    else if (flag == FilterFlag::ShowCustomersOnly)
        filter += " AND ipn IS NULL";

    model->setFilter(filter);
    model->select();
}

Lists::Lists(QWidget* parent, bool isSale)
    : QWidget(parent)
    , ui(new Ui::Lists)
    , isSale(isSale)
{
    ui->setupUi(this);

    // model for tableView
    model = new QSqlTableModel();
    model->setTable("list_view");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("ІПН")); // only organizations will have ipn
    model->setHeaderData(2, Qt::Horizontal, tr("Коли"));
    model->setHeaderData(3, Qt::Horizontal, tr("Номер"));
    model->setHeaderData(4, Qt::Horizontal, tr("Тип"));
    model->setHeaderData(5, Qt::Horizontal, tr("Покупець"));
    model->setHeaderData(6, Qt::Horizontal, tr("Продавець"));

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(ID_COLUMN_INDEX, true); // hide ID
    ui->tableView->setColumnHidden(IPN_COLUMN_INDEX, true); // hide IPN

    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    for (int i = 0; i < ui->tableView->model()->columnCount(); ++i) {
        if (i == 5 || i == 6)
            ui->tableView->setColumnWidth(i, 600);
        else if (i == 2 || i == 4)
            ui->tableView->setColumnWidth(i, 300);
        else
            ui->tableView->setColumnWidth(i, 150);
    }

    setModelFilter(FilterFlag::ShowAll);
}

Lists::~Lists()
{
    delete ui;
}

void Lists::on_btn_add_clicked()
{
    QSqlQuery qry;
    // #1 Get MAX+1 id to insert new row
    qry.exec("SELECT MAX(id) FROM list");
    int next_id {};
    if (!qry.next()) {
        QMessageBox::warning(this,
            "Попередження",
            "Не вдалося знайти жодного запису у базі даних. Почато рахунок з початку",
            QMessageBox::Ok);
    } else {
        next_id = qry.value(0).toInt() + 1;
    }

    // #2 Get list type from user and count it's number
    QString listType = askListType();
    if (listType.isEmpty())
        return;
    int newNumber = getNewListNumber(listType);

    // #3 Add new empty list to db + refresh
    qry.exec("INSERT INTO list(id, number, type) VALUES(" + QString::number(next_id) + ", " + QString::number(newNumber) + ", '" + listType + "')");
    model->select();

    // #4 Open new tab for created list
    emit tabRecordsRequested(next_id);
}

void Lists::on_btn_del_clicked()
{
    const auto selectedRows = ui->tableView->selectionModel()->selectedRows(ID_COLUMN_INDEX);
    if (!selectedRows.isEmpty()) {

        auto result = QMessageBox::warning(this, "Попередження", "Ви впевненні, що хочете видалити запис " + selectedRows.front().siblingAtColumn(4).data(Qt::DisplayRole).toString() + "?",
            QMessageBox::Yes | QMessageBox::No);

        if (result == QMessageBox::Yes)
        {
            const QString id = selectedRows.front().data(Qt::DisplayRole).toString();
            QSqlQuery qry;
            qry.exec("PRAGMA foreign_keys=ON");
            qry.exec("DELETE FROM list WHERE id=" + id);
            qDebug() << qry.lastError().text();
            model->select();
        }
    }
}

void Lists::on_radio_all_clicked()
{
    setModelFilter(FilterFlag::ShowAll);
}

void Lists::on_radio_org_clicked()
{
    setModelFilter(FilterFlag::ShowOrganizationsOnly);
}

void Lists::on_radio_not_org_clicked()
{
    setModelFilter(FilterFlag::ShowCustomersOnly);
}

void Lists::on_tableView_doubleClicked(const QModelIndex& index)
{
    const int list_id = index.siblingAtColumn(ID_COLUMN_INDEX).data(Qt::DisplayRole).toInt();
    emit tabRecordsRequested(list_id);
}

void Lists::on_btn_load_clicked()
{
}

void Lists::updateView()
{
    model->select();
}

void Lists::on_btn_create_clicked()
{
    const auto selectedRow = ui->tableView->selectionModel()->selectedRows(ID_COLUMN_INDEX);
    if (!selectedRow.isEmpty()) {
        const int list_id = selectedRow.at(0).data(Qt::DisplayRole).toInt();
        QSqlQuery qry;

        // #1 Create new list with the same params and different type&number (if is needed)
        QString listType = askListType();
        if (listType.isEmpty())
            return;
        int newNumber = getNewListNumber(listType);

        QString query_str = "INSERT INTO list(number, type, customer_id, seller_id) "
                            "SELECT '%1', '%2', customer_id, seller_id FROM list WHERE ID='%3'";
        query_str = query_str.arg(QString::number(newNumber), listType, QString::number(list_id));
        if (qry.exec(query_str)) {
            // #2 Get created list's id
            qry.exec("SELECT MAX(id) FROM list");
            if (qry.next()) {
                const QString created_list_id = qry.value(0).toString();

                // #3 Copy all records to new list
                query_str = "INSERT INTO record(count, price, product_id, list_id) "
                            "SELECT count, price, product_id, %1 FROM record WHERE list_id=%2";
                qry.exec(query_str.arg(created_list_id, QString::number(list_id)));

                emit tabRecordsRequested(list_id);
            }
        }
        updateView();
    }
}

QString Lists::askListType()
{
    QString listType = DOC_TYPES_NAMES.at(DOC_TYPES::Nakladna_na_nadhodjennya);
    if (isSale) {
        SetListType* dlg = new SetListType;
        if (dlg->exec() != QDialog::Accepted)
            return {};
        listType = dlg->getSelectedType();
    }
    return listType;
}

int Lists::getNewListNumber(const QString& listType)
{
    QSqlQuery qry;
    qry.exec("SELECT MAX(number) FROM list WHERE type == '" + listType + "'");
    int newNumber {};
    if (!qry.next()) {
        QMessageBox::warning(this,
            "Попередження",
            "Не вдалося знайти жодного списку типу " + listType + " у базі даних. Почато рахунок з початку",
            QMessageBox::Ok);
    } else {
        newNumber = qry.value(0).toInt() + 1;
    }

    return newNumber;
}
