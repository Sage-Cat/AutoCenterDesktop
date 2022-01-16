#include "editseller.h"
#include "ui_editseller.h"

EditSeller::EditSeller(QWidget *parent, QSqlTableModel *sellersModel, int selected_row) :
    QDialog(parent),
    ui(new Ui::EditSeller),
    sellersModel(sellersModel),
    selected_row(selected_row)
{
    ui->setupUi(this);

    const QStringList fieldNames {
        "Ім'я",
        "ІБАН",
        "Банк",
        "ЕДРПОУ",
        "ІПН",
        "Адреса",
        "Номер"
    };

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setRowCount(fieldNames.size());
    ui->tableWidget->setVerticalHeaderLabels(fieldNames);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->hide();

    // loading data from model
    data_indexes = {
        1, 2, 3, 4, 5, 6, 7
    };

    Q_ASSERT (fieldNames.size() == data_indexes.size());
    for (int i = 0; i < data_indexes.size(); ++i)
        ui->tableWidget->setItem(i, 0,
                                 new QTableWidgetItem(
                                     sellersModel->index(
                                         selected_row,
                                         data_indexes[i]
                                         ).data(Qt::DisplayRole).toString()
                                     )
                                 );
}

EditSeller::~EditSeller()
{
    delete ui;
}

void EditSeller::on_btn_accept_clicked()
{
    for (int i = 0; i < data_indexes.size(); ++i)
    sellersModel->setData(
                    sellersModel->index(selected_row, data_indexes[i]),
                    ui->tableWidget->item(i, 0)->text()
                    );

    this->accept();
}

