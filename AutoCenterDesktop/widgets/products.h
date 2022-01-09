#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <QWidget>

namespace Ui {
class Products;
}

class Products : public QWidget {
    Q_OBJECT

public:
    explicit Products(QWidget* parent = nullptr);
    ~Products();

    static void insertProductToDb(QString code, QString catalog, QString tnved,
        QString name, QString unit, QString price);

private:
    Ui::Products* ui;
};

#endif // PRODUCTS_H
