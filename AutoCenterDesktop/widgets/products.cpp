#include "products.h"
#include "ui_products.h"

#include <QSqlQuery>
#include <QSqlTableModel>

#include "dialogs/addproduct.h"
#include "dialogs/findproduct.h"
#include "dialogs/loadsupplierpricelist.h"

#include "widgets/records.h"

Products::Products(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Products)
{
    ui->setupUi(this);

    // model for tableView
    model = new QSqlTableModel();
    model->setTable("product");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setFilter("ID=NULL");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("К-сть на складі"));
    model->setHeaderData(2, Qt::Horizontal, tr("Код"));
    model->setHeaderData(3, Qt::Horizontal, tr("Каталог"));
    model->setHeaderData(4, Qt::Horizontal, tr("ТНВЕД"));
    model->setHeaderData(5, Qt::Horizontal, tr("Назва"));
    model->setHeaderData(6, Qt::Horizontal, tr("Одиниці"));
    model->setHeaderData(7, Qt::Horizontal, tr("Ціна закупки"));

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(ID_COLUMN_INDEX, true); // hide ID

    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView->setItemDelegateForColumn(7, new NumberFormatDelegate(this));

//    for (int i = 0; i < ui->tableView->model()->columnCount(); ++i)
//    {
//        if (i == 5)
//            ui->tableView->setColumnWidth(i, 700);
//        else if (i == 2 || i == 3 || i == 4)
//            ui->tableView->setColumnWidth(i, 200);
//        else
//            ui->tableView->setColumnWidth(i, 150);
//    }
}

Products::~Products()
{
    delete ui;
}

void Products::insertProductToDb(QString code, QString catalog, QString tnved, QString name, QString unit, QString price)
{
    QSqlQuery qry;
    QString query_str =
            "INSERT INTO product(code, catalog, tnved, name, unit, purchase_price) "
                "VALUES('%1', '%2', '%3', '%4', '%5', '%6')";
    qry.exec(query_str.arg(code, catalog, tnved, name, unit, price));
}

void Products::on_btn_add_clicked()
{
    AddProduct *dlg = new AddProduct;
    if (dlg->exec() == QDialog::Accepted)
    {
        QSqlQuery qry;
        qry.exec("SELECT MAX(id) FROM product");

        if (qry.next())
            model->setFilter("id=" + qry.value(0).toString());
    }
    delete dlg;
}

void Products::on_btn_del_clicked()
{
    const auto selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty())
        return;
    const QString record_id = selectedIndexes.at(0).siblingAtColumn(ID_COLUMN_INDEX)
            .data(Qt::DisplayRole).toString();

    QSqlQuery qry;
    qry.exec("PRAGMA foreign_keys=ON");
    qry.exec("DELETE FROM record WHERE id=" + record_id);

    model->setFilter("ID=NULL");
    model->select();
}

void Products::on_btn_load_clicked()
{
    LoadSupplierPricelist *dlg = new LoadSupplierPricelist;
    if (dlg->exec() == QDialog::Accepted)
    {
    }

    delete dlg;
}

void Products::on_btn_find_clicked()
{
    FindProduct *dlg = new FindProduct;
    if (dlg->exec() == QDialog::Accepted)
    {
        QStringList IDs = dlg->getFoundProductIDs();
        for (auto &id : IDs)
            id = "id=" + id;
        const QString newModelFilter =  IDs.join(" OR ");
        model->setFilter(newModelFilter);
    }
    delete dlg;
}

void Products::resizeEvent(QResizeEvent *event)
{
    const int columnsCount = ui->tableView->model()->columnCount();
    const int PARENT_WIDTH = this->width();
    const int NAME_COLUMN_WIDTH = PARENT_WIDTH / 3;
    const int CODES_COLUMN_WIDTH = PARENT_WIDTH / 8;
    const int OTHER_COLUMNS_WIDTH = (PARENT_WIDTH - NAME_COLUMN_WIDTH - CODES_COLUMN_WIDTH * 3) / (columnsCount - 4);
    for (int i = 0; i < ui->tableView->model()->columnCount(); ++i)
    {
        if (i == 5)
            ui->tableView->setColumnWidth(i, NAME_COLUMN_WIDTH);
        else if (i == 2 || i == 3 || i == 4)
            ui->tableView->setColumnWidth(i, CODES_COLUMN_WIDTH);
        else
            ui->tableView->setColumnWidth(i, OTHER_COLUMNS_WIDTH);
    }

    QWidget::resizeEvent(event);
}

