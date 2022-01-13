#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <QWidget>

class QSqlTableModel;

namespace Ui {
class Products;
}

class Products : public QWidget {
    Q_OBJECT

    const int ID_COLUMN_INDEX{ 0 };

public:
    explicit Products(QWidget* parent = nullptr);
    ~Products();

    static void insertProductToDb(QString code, QString catalog, QString tnved,
        QString name, QString unit, QString price);

private slots:
    void on_btn_add_clicked();
    void on_btn_del_clicked();
    void on_btn_load_clicked();
    void on_btn_find_clicked();

private:
    Ui::Products* ui;
    QSqlTableModel *model;

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // PRODUCTS_H
