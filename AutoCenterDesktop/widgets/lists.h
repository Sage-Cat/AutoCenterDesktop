#ifndef LISTS_H
#define LISTS_H

#include <QWidget>

namespace Ui {
class Lists;
}

class Lists : public QWidget
{
    Q_OBJECT

public:
    explicit Lists(QWidget *parent = nullptr, bool isSale = true);
    ~Lists();

private slots:
    void on_btn_add_clicked();
    void on_btn_del_clicked();

    void on_radio_all_clicked();
    void on_radio_org_clicked();
    void on_radio_not_org_clicked();

private:
    Ui::Lists *ui;
    bool isSale;
};

#endif // LISTS_H
