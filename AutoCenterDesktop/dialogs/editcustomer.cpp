#include "editcustomer.h"
#include "ui_editcustomer.h"

EditCustomer::EditCustomer(QWidget *parent, QSqlTableModel *customersModel, int selected_row) :
    QDialog(parent),
    ui(new Ui::EditCustomer),
    customersModel(customersModel),
    selected_row(selected_row)
{
    ui->setupUi(this);

    const QStringList fieldNames {
        "Ім'я",
        "Адреса",
        "Номер",
        "Ел. пошта",
        "ІБАН",
        "Банк",
        "ЕДРПОУ",
        "ІПН"
    };

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setRowCount(fieldNames.size());
    ui->tableWidget->setVerticalHeaderLabels(fieldNames);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->hide();

    // loading data from model
    data_indexes = {
        1, 3, 4, 5, 6, 7, 8, 9
    };

    Q_ASSERT (fieldNames.size() == data_indexes.size());
    for (int i = 0; i < data_indexes.size(); ++i)
        ui->tableWidget->setItem(i, 0,
                                 new QTableWidgetItem(
                                     customersModel->index(
                                         selected_row,
                                         data_indexes[i]
                                         ).data(Qt::DisplayRole).toString()
                                     )
                                 );

}

EditCustomer::~EditCustomer()
{
    delete ui;
}

void EditCustomer::on_btn_accept_clicked()
{
    for (int i = 0; i < data_indexes.size(); ++i)
    customersModel->setData(
                    customersModel->index(selected_row, data_indexes[i]),
                    ui->tableWidget->item(i, 0)->text()
                    );

    this->accept();
}

