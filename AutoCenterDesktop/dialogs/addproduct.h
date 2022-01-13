#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QDialog>

namespace Ui {
class AddProduct;
}

class AddProduct : public QDialog
{
    Q_OBJECT

public:
    explicit AddProduct(QWidget *parent = nullptr);
    ~AddProduct();

    void setCodeToLineEdit(QString code);

private slots:
    void on_btn_add_clicked();

private:
    Ui::AddProduct *ui;
};

#endif // ADDPRODUCT_H
