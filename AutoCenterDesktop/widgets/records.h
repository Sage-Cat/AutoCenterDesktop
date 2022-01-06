#ifndef _H
#define _H

#include <QWidget>
#include <QTableWidgetItem>
#include <QVector>

namespace Ui {
class Records;
}

class Records : public QWidget
{
    Q_OBJECT

public:
    explicit Records(QWidget *parent = nullptr, int ID_List = 0);
    ~Records();

private slots:
    /* COMBOBOXES */
    void on_comboBox_Customer_currentIndexChanged(int index);
    void on_comboBox_Seller_currentIndexChanged(int index);

    /* BUTTONS */
    void on_btn_add_clicked();
    void on_btn_del_clicked();

    /* ACTION */
    void on_tableWidget_itemChanged(QTableWidgetItem *item);

    /* PRINT */
    void on_btn_print_barcode_clicked();
    void on_btn_print_document_clicked();

private:
    Ui::Records *ui;
    int ID_List;
};

#endif // _H
