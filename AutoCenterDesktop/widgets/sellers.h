#ifndef SELLERS_H
#define SELLERS_H

#include <QWidget>

class QSqlTableModel;

namespace Ui {
class Sellers;
}

class Sellers : public QWidget
{
    Q_OBJECT

    const int ID_COLUMN_INDEX{ 0 };

public:
    explicit Sellers(QWidget *parent = nullptr);
    ~Sellers();

private slots:
    void on_btn_add_clicked();
    void on_btn_del_clicked();
    void on_btn_info_clicked();

signals:
    void tabSellerInfoRequested(int seller_id);

private:
    Ui::Sellers *ui;
    QSqlTableModel *model;
};

#endif // SELLERS_H
