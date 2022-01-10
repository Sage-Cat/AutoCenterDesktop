#ifndef LOADSUPPLIERPRICELIST_H
#define LOADSUPPLIERPRICELIST_H

#include <QDialog>
#include <QQueue>

class QThread;
class PricelistParserToDB;
class Product;

namespace Ui {
class LoadSupplierPricelist;
}

class LoadSupplierPricelist : public QDialog {
    Q_OBJECT

public:
    explicit LoadSupplierPricelist(QWidget* parent = nullptr);
    ~LoadSupplierPricelist();

private slots:
    void on_btn_explorer_clicked();
    void on_btn_load_clicked();
    void on_btn_cancel_clicked();

public slots:
    void loadParsedDataToDB();
signals:
    void endParsing();

private:
    Ui::LoadSupplierPricelist* ui;
    QThread *thread;
    PricelistParserToDB *parser;
    QQueue<Product *> products_queue;
};

#endif // LOADSUPPLIERPRICELIST_H
