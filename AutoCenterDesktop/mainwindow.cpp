#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widgets/lists.h"
#include "widgets/records.h"
#include "widgets/customers.h"
#include "widgets/sellers.h"
#include "widgets/info.h"
#include "widgets/cars.h"
#include "widgets/products.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowState(Qt::WindowMaximized);

    QFont font;
    font.setStyleHint(QFont::Monospace);
    font.setPixelSize(18);
    QApplication::setFont(font);


    /* Authorization and Registration */
//    this->setHidden(true);

//    this->setHidden(false);

    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeTab(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::on_act_sales_triggered()
{
    openTabLists(true, "Реалізації");
}

void MainWindow::openTabLists(bool isSale, QString label)
{
    Lists *tab = new Lists(this, isSale);
    connect(tab, &Lists::tabRecordsRequested, this, &MainWindow::openTabRecords);

    ui->tabWidget->addTab(tab,
        isSale ? QIcon(":/icons/sale.png") : QIcon(":/icons/goods.ico"),
        label);
    ui->tabWidget->setCurrentWidget(tab);
}

void MainWindow::openTabRecords(int list_id)
{
    Records *tab = new Records(this, list_id);
    Lists *sender_tab = qobject_cast<Lists *>(sender());
    if (sender_tab)
        connect(tab, &Records::listDataChanged, sender_tab, &Lists::updateView);

    ui->tabWidget->addTab(tab, QIcon(":/icons/page.png"), "Редагування списку");
    ui->tabWidget->setCurrentWidget(tab);
}

void MainWindow::openTabInfo(int id)
{
    Info *tab = new Info(this, id);
    ui->tabWidget->addTab(tab, QIcon(":/icons/info.png"), "Інформація");
    ui->tabWidget->setCurrentWidget(tab);
}

void MainWindow::openTabCars(int customer_id)
{
    Cars *tab = new Cars(this, customer_id);
    Customers *sender_tab = qobject_cast<Customers *>(sender());
    if (sender_tab)
        connect(tab, &Cars::carsCountChanged, sender_tab, &Customers::updateView);

    ui->tabWidget->addTab(tab, QIcon(":/icons/info.png"), "Інформація");
    ui->tabWidget->setCurrentWidget(tab);
}

void MainWindow::on_act_receipts_triggered()
{
    openTabLists(false, "Надходження");
}

void MainWindow::on_act_customers_triggered()
{
    Customers *tab = new Customers(this);
    connect(tab, &Customers::tabCustomerInfoRequested, this, &MainWindow::openTabInfo);
    connect(tab, &Customers::tabCarsRequested, this, &MainWindow::openTabCars);

    ui->tabWidget->addTab(tab, QIcon(":/icons/customer.png"), "Клієнти");
    ui->tabWidget->setCurrentWidget(tab);
}

void MainWindow::on_act_sellers_triggered()
{
    Sellers *tab = new Sellers(this);
    // TODO: connet to method for info widget opening

    ui->tabWidget->addTab(tab, QIcon(":/icons/seller.png"), "Продавці");
    ui->tabWidget->setCurrentWidget(tab);
}

void MainWindow::on_act_goods_triggered()
{
    Products *tab = new Products(this);
    ui->tabWidget->addTab(tab, QIcon(":/icons/goods.ico"), "Товари");
    ui->tabWidget->setCurrentWidget(tab);
}

