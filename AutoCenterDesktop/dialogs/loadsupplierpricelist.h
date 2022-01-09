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

private slots:
    void on_btn_explorer_clicked();
    void on_btn_load_clicked();
    void on_btn_stop_clicked();
    void on_btn_cancel_clicked();

public slots:
    void handleParserWorkEnd();

signals:
    void endParsing();

private:
    Ui::LoadSupplierPricelist *ui;
};

#endif // LOADSUPPLIERPRICELIST_H
