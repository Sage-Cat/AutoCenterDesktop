#ifndef FINDPRODUCT_H
#define FINDPRODUCT_H

#include <QDialog>

namespace Ui {
class FindProduct;
}

class FindProduct : public QDialog
{
    Q_OBJECT

public:
    explicit FindProduct(QWidget *parent = nullptr);
    ~FindProduct();

    const QStringList &getFoundProductIDs() const;

private slots:
    void on_btn_search_clicked();

    void searchForEqual(QString column, QString data);
    void searchForSubstr(QString column, QString name);

private:
    Ui::FindProduct *ui;
    QStringList foundProductIDs;
};

#endif // FINDPRODUCT_H
