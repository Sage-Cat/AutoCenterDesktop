#include "loadnakladna.h"
#include "ui_loadnakladna.h"

#include <QFileDialog>

#include "global.h"

#include "utils/xmldocumentloader.h"
#include "widgets/lists.h"

LoadNakladna::LoadNakladna(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadNakladna)
{
    ui->setupUi(this);

    ui->comboBox->addItems(Suppliers);
}

LoadNakladna::~LoadNakladna()
{
    delete ui;
}

void LoadNakladna::on_btn_explorer_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, ("Відкрити файл"),
        "/",
        ("Xml-files (*.xml)"));

    ui->line_path->setText(fileName);
}


void LoadNakladna::on_btn_load_clicked()
{
    XmlDocumentLoader *loader = new XmlDocumentLoader;
    Lists *parent_widget = qobject_cast<Lists*>(this->parent());
    connect(loader, &XmlDocumentLoader::tabRecordsRequested, parent_widget, &Lists::handleChildTabRecordsRequest);

    if (ui->comboBox->currentText() == Suppliers.at(0))
        loader->loadOmegaNakladnaToDB(ui->line_path->text());

    delete loader;

    accept();
}

