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
    const int IPN_COLUMN_INDEX{ 1 };

    enum class FilterFlag{
        ShowAll,
        ShowOrganizationsOnly,
        ShowCustomersOnly
    };

    void setModelFilter(FilterFlag flag);

public:
    explicit Lists(QWidget *parent = nullptr, bool isSale = true);
    ~Lists();

private slots:
    void on_btn_add_clicked();
    void on_btn_del_clicked();
    void on_radio_all_clicked();
    void on_radio_org_clicked();
    void on_radio_not_org_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_btn_load_clicked();
    void on_btn_create_clicked();

    QString askListType();
    int getNewListNumber(const QString &listType);

public slots:
    void updateView();

signals:
    void tabRecordsRequested(int list_id);

private:
    Ui::Lists *ui;
    bool isSale;
    QSqlTableModel *model;
};

#endif // LISTS_H
