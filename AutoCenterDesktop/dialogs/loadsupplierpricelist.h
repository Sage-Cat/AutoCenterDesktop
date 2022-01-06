#ifndef LOADSUPPLIERPRICELIST_H
#define LOADSUPPLIERPRICELIST_H

#include <QDialog>

namespace Ui {
class LoadSupplierPricelist;
}

class LoadSupplierPricelist : public QDialog
{
    Q_OBJECT

public:
    explicit LoadSupplierPricelist(QWidget *parent = nullptr);
    ~LoadSupplierPricelist();

private:
    Ui::LoadSupplierPricelist *ui;
};

#endif // LOADSUPPLIERPRICELIST_H
