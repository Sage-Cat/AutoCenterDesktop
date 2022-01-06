#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widgets/lists.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowState(Qt::WindowMaximized);

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
    ui->tabWidget->addTab(tab, QIcon(":/icons/page.png"), label);
    ui->tabWidget->setCurrentWidget(tab);
}

