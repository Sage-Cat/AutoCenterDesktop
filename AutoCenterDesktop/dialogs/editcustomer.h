#ifndef EDITCUSTOMER_H
#define EDITCUSTOMER_H

#include <QDialog>
#include <QSqlTableModel>
#include <QVector>

namespace Ui {
class EditCustomer;
}

class EditCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit EditCustomer(QWidget *parent = nullptr, QSqlTableModel *customersModel = nullptr, int selected_row = 0);
    ~EditCustomer();

private slots:
    void on_btn_accept_clicked();

private:
    Ui::EditCustomer *ui;
    QSqlTableModel *customersModel;
    int selected_row {};
    QVector<int> data_indexes {};
};

#endif // EDITCUSTOMER_H
