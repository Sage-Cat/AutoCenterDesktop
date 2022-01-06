#ifndef LISTS_H
#define LISTS_H

#include <QWidget>

class QSqlTableModel;

namespace Ui {
class Lists;
}

class Lists : public QWidget
{
    Q_OBJECT

    const int ID_COLUMN_INDEX{ 0 };

public:
    explicit Lists(QWidget *parent = nullptr, bool isSale = true);
    ~Lists();

private slots:
    void on_btn_add_clicked();
    void on_btn_del_clicked();

    void on_radio_all_clicked();
    void on_radio_org_clicked();
    void on_radio_not_org_clicked();

signals:
    void tabRecordsRequested(int list_id);

private:
    Ui::Lists *ui;
    bool isSale;
    QSqlTableModel *model;
};

#endif // LISTS_H