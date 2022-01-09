#include "loadsupplierpricelist.h"
#include "ui_loadsupplierpricelist.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QThread>

#include "global.h"
#include "utils/pricelistparsertodb.h"

LoadSupplierPricelist::LoadSupplierPricelist(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::LoadSupplierPricelist)
{
    ui->setupUi(this);

    ui->btn_stop->setDisabled(true);

    ui->comboBox->addItem("");
    ui->comboBox->addItems(Suppliers);
}

LoadSupplierPricelist::~LoadSupplierPricelist()
{
    delete ui;
}

void LoadSupplierPricelist::on_btn_explorer_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, ("Відкрити файл"),
        "/",
        ("Xml-files (*.xml)"));

    ui->line_path->setText(fileName);
}

void LoadSupplierPricelist::handleParserWorkEnd()
{
    ui->label_status->setText("Готово");
    ui->btn_stop->setDisabled(true);
    ui->btn_cancel->setDisabled(false);

    QMessageBox::information(this, "Повідомлення", "Прайслист поставщика " + ui->comboBox->currentText() + " успішно завантажено!");
}

void LoadSupplierPricelist::on_btn_load_clicked()
{
    QString fileName = ui->line_path->text();
    if (!fileName.isEmpty()) {
        ui->btn_cancel->setDisabled(true);
        ui->btn_stop->setDisabled(false);

        QThread* thread = new QThread;
        PricelistParserToDB* parser = new PricelistParserToDB(this, fileName);

        parser->moveToThread(thread);

        // progressBar
        connect(parser, &PricelistParserToDB::progressChanged, ui->progressBar, &QProgressBar::setValue);

        // clean
        connect(parser, &PricelistParserToDB::workFinished, this, &LoadSupplierPricelist::handleParserWorkEnd);
        connect(parser, &PricelistParserToDB::workFinished, thread, &QThread::quit);
        connect(parser, &PricelistParserToDB::workFinished, parser, &PricelistParserToDB::deleteLater);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        // do right work
        if (ui->comboBox->currentText() == Suppliers.at(0)) // Omega
        {
            connect(thread, &QThread::started, parser, &PricelistParserToDB::parseAsOmegaPriceList);
            thread->start();
        }
    } else
        QMessageBox::information(this, "Попередження", "Уведіть, будь-ласка, шлях до файлу", QMessageBox::Ok);
}

void LoadSupplierPricelist::on_btn_stop_clicked()
{
}

void LoadSupplierPricelist::on_btn_cancel_clicked()
{
    this->reject();
}
