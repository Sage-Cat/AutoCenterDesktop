#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QWidget>

class QSqlTableModel;

namespace Ui {
class Customers;
}

class Customers : public QWidget
{
    Q_OBJECT

    const int ID_COLUMN_INDEX{ 0 };

public:
    explicit Customers(QWidget *parent = nullptr);
    ~Customers();

private slots:
    void on_btn_add_clicked();
    void on_btn_del_clicked();
    void on_btn_info_clicked();
    void on_btn_cars_clicked();

    void handleDataChange(const QModelIndex& topLeft, const QModelIndex&);
    void handleSimpleCellChange(const QString& columnName, const QString &data, const QString &customer_id);

public slots:
    void updateView();

signals:
    void tabCustomerInfoRequested(int customer_id);
    void tabCarsRequested(int customer_id);

private:
    Ui::Customers *ui;
    QSqlTableModel *model;
};

#endif // CUSTOMERS_H
