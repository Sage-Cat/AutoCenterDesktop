#ifndef _H
#define _H

#include <QTableWidgetItem>
#include <QVector>
#include <QWidget>

class QSqlTableModel;

namespace Ui {
class Records;
}

class Records : public QWidget {
    Q_OBJECT

    const int ID_COLUMN_INDEX { 0 };
    const int LIST_ID_COLUMN_INDEX { 1 };

public:
    explicit Records(QWidget* parent = nullptr, int list_id = 0);
    ~Records();

private slots:
    /* COMBOBOXES */
    void on_comboBox_Customer_currentIndexChanged(int index);
    void on_comboBox_Seller_currentIndexChanged(int index);

    /* BUTTONS */
    void on_btn_add_clicked();
    void on_btn_del_clicked();

    /* ACTION */
    void on_tableWidget_itemChanged(QTableWidgetItem* item);

    /* PRINT */
    void on_btn_print_barcode_clicked();
    void on_btn_print_document_clicked();

    /* UPDATE&INIT */
    void updateView();
    void initDateTime();
    void initComboboxes();

private:
    Ui::Records* ui;
    int list_id;
    QSqlTableModel* model;
};

#endif // _H
