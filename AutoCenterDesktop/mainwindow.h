#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void closeTab(int index);

    void on_act_sales_triggered();

    void openTabLists(bool isSale, QString label);
    void openTabRecords(int list_id);
    void openTabInfo(int id);
    void openTabCars(int customer_id);

    void on_act_receipts_triggered();
    void on_act_customers_triggered();
    void on_act_sellers_triggered();

    void on_act_goods_triggered();

    void on_act_exit_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
