#include "info.h"
#include "ui_info.h"

#include <QSqlTableModel>

Info::Info(QWidget *parent, int id) :
    QWidget(parent),
    ui(new Ui::Info),
    id(id)
{
    ui->setupUi(this);

    // model for tableView
    model = new QSqlTableModel();
    model->setTable("info_customer");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setFilter("id=" + QString::number(id));
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Коли"));
    model->setHeaderData(2, Qt::Horizontal, tr("Код"));
    model->setHeaderData(3, Qt::Horizontal, tr("Каталог"));
    model->setHeaderData(4, Qt::Horizontal, tr("ТНВЕД"));
    model->setHeaderData(5, Qt::Horizontal, tr("Назва"));
    model->setHeaderData(6, Qt::Horizontal, tr("Ціна"));
    model->setHeaderData(7, Qt::Horizontal, tr("К-сть"));
    model->setHeaderData(8, Qt::Horizontal, tr("Одиниці"));
    model->setHeaderData(9, Qt::Horizontal, tr("Сума"));

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(ID_COLUMN_INDEX, true); // hide ID
    ui->tableView->setColumnHidden(3, true); // hide Catalog
    ui->tableView->setColumnHidden(4, true); // hide TNVED
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Info::~Info()
{
    delete ui;
}
