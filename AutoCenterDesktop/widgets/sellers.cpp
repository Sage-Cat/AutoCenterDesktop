#include "sellers.h"
#include "ui_sellers.h"

#include <QSqlTableModel>
#include <QSqlQuery>

#include <QComboBox>

#include "dialogs/editseller.h"

Sellers::Sellers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sellers)
{
    ui->setupUi(this);

    // model for tableView
    model = new QSqlTableModel();
    model->setTable("seller");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    updateView();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Ім'я")); // only organizations will have ipn
    model->setHeaderData(2, Qt::Horizontal, tr("ІБАН"));
    model->setHeaderData(3, Qt::Horizontal, tr("Банк"));
    model->setHeaderData(4, Qt::Horizontal, tr("ЄДРПОУ"));
    model->setHeaderData(5, Qt::Horizontal, tr("ІПН"));
    model->setHeaderData(6, Qt::Horizontal, tr("Адреса"));
    model->setHeaderData(7, Qt::Horizontal, tr("Номер"));
    model->setHeaderData(8, Qt::Horizontal, tr("Платник ПДВ"));

    ComboBoxItemDelegate *comboDelegate = new ComboBoxItemDelegate(this);
    ui->tableView->setItemDelegateForColumn(8,comboDelegate);

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(ID_COLUMN_INDEX, true); // hide ID
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setColumnHidden(5, true);
    ui->tableView->setColumnHidden(6, true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Sellers::~Sellers()
{
    delete ui;
}

void Sellers::updateView()
{
    model->select();
}

void Sellers::on_btn_add_clicked()
{
    QSqlQuery qry;
    qry.exec("INSERT INTO seller(name) VALUES(NULL)");

    updateView();
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

    updateView();
}


ComboBoxItemDelegate::ComboBoxItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

ComboBoxItemDelegate::~ComboBoxItemDelegate()
{
}

QWidget *ComboBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // Create the combobox and populate it
    QComboBox *cb = new QComboBox(parent);
    cb->addItem(QStringLiteral("Ні"));
    cb->addItem(QStringLiteral("Так"));
    return cb;
}

void ComboBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);
    // get the index of the text in the combobox that matches the current value of the item
    const QString currentText = index.data(Qt::EditRole).toString();
    const int cbIndex = cb->findText(currentText);
    // if it is valid, adjust the combobox
    if (cbIndex >= 0)
       cb->setCurrentIndex(cbIndex);
}

void ComboBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);
    model->setData(index, cb->currentText() == "Так" ? true : false, Qt::EditRole);
}

QString ComboBoxItemDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
    return value.toBool() ? "Так" : "Ні";
}

void Sellers::on_btn_edit_clicked()
{
    const auto selected_indexes = ui->tableView->selectionModel()->selectedIndexes();
    if (!selected_indexes.isEmpty())
    {
        EditSeller *dlg = new EditSeller(this, model, selected_indexes.front().row());
        dlg->exec();
    }
}

