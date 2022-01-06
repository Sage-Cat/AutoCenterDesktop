#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widgets/lists.h"
#include "widgets/records.h"

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
        isSale ? QIcon(":/icons/sale.png") : QIcon(":/icons/goods.png"),
        label);
    ui->tabWidget->setCurrentWidget(tab);
}

void MainWindow::openTabRecords(int list_id)
{
    Records *tab = new Records(this, list_id);
    ui->tabWidget->addTab(tab, QIcon(":/icons/page.png"), "Редагування списку");
    ui->tabWidget->setCurrentWidget(tab);
}


void MainWindow::on_act_receipts_triggered()
{
    openTabLists(false, "Надходження");
}

