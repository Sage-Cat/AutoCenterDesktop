#ifndef CARS_H
#define CARS_H

#include <QWidget>

class QSqlTableModel;

namespace Ui {
class Cars;
}

class Cars : public QWidget
{
    Q_OBJECT

    const int ID_COLUMN_INDEX{ 0 };
    const int CUSTOMER_ID_COLUMN_INDEX{ 3 };

public:
    explicit Cars(QWidget *parent = nullptr, int customer_id = 0);
    ~Cars();

private slots:
    void on_btn_add_clicked();
    void on_btn_del_clicked();

signals:
    void carsCountChanged();

private:
    Ui::Cars *ui;
    int customer_id {};
    QSqlTableModel *model;
};

#endif // CARS_H
