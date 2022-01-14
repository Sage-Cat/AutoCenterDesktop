#include "askforprinter.h"
#include "ui_askforprinter.h"

#include <QPrinterInfo>

AskForPrinter::AskForPrinter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AskForPrinter)
{
    ui->setupUi(this);

    ui->comboBox->addItems(QPrinterInfo::availablePrinterNames());
    ui->comboBox->addItem("Друк у PDF");
}

AskForPrinter::~AskForPrinter()
{
    delete ui;
}

void AskForPrinter::on_btn_accept_clicked()
{
    selectedPrinter = ui->comboBox->currentText();
    this->accept();
}

const QString &AskForPrinter::getSelectedPrinter() const
{
    return selectedPrinter;
}

