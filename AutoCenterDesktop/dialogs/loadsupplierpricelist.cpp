#include "loadsupplierpricelist.h"
#include "ui_loadsupplierpricelist.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QThread>

#include "global.h"
#include "widgets/products.h"
#include "utils/pricelistparsertodb.h"

LoadSupplierPricelist::LoadSupplierPricelist(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::LoadSupplierPricelist)
{
    ui->setupUi(this);

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

void LoadSupplierPricelist::on_btn_load_clicked()
{
    QString fileName = ui->line_path->text();

    ui->label_status->setText("Розархівування...");

    if (!fileName.isEmpty()) {
        ui->btn_cancel->setDisabled(true);

        thread = new QThread;
        parser = new PricelistParserToDB(this, fileName, &products_queue);

        parser->moveToThread(thread);

        // progressBar
        connect(parser, &PricelistParserToDB::progressChanged, ui->progressBar, &QProgressBar::setValue);

        // clean
        connect(parser, &PricelistParserToDB::workFinished, this, &LoadSupplierPricelist::loadParsedDataToDB);
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

void LoadSupplierPricelist::on_btn_cancel_clicked()
{
    this->reject();
}

void LoadSupplierPricelist::loadParsedDataToDB()
{
    ui->label_status->setText("Завантаження до бази даних...");

    const int productsCountForOnePercent = products_queue.size() / 100;
    int counter {}, progressBarValue {};
    while (!products_queue.empty())
    {
        Product *product = products_queue.dequeue();
        Products::insertProductToDb(
                    product->code,
                    product->catalog, product->tnved,
                    product->name,
                    product->unit,
                    product->price
                    );
        delete product;

        counter++;
        if (counter == productsCountForOnePercent)
        {
            progressBarValue++;
            ui->progressBar->setValue(progressBarValue);

            counter = 0;
        }
    }

    ui->label_status->setText("Готово");
    ui->btn_cancel->setDisabled(false);

    QMessageBox::information(this, "Повідомлення", "Прайслист поставщика " + ui->comboBox->currentText() + " успішно завантажено!");
}
