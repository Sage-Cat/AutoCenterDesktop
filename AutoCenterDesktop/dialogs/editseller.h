#ifndef EDITSELLER_H
#define EDITSELLER_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class EditSeller;
}

class EditSeller : public QDialog
{
    Q_OBJECT

public:
    explicit EditSeller(QWidget *parent = nullptr, QSqlTableModel *sellersModel = nullptr, int selected_row = 0);
    ~EditSeller();

private slots:
    void on_btn_accept_clicked();

private:
    Ui::EditSeller *ui;
    QSqlTableModel *sellersModel;
    int selected_row {};
    QVector<int> data_indexes {};
};

#endif // EDITSELLER_H
