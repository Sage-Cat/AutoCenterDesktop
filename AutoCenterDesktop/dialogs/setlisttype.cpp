#include "setlisttype.h"
#include "ui_setlisttype.h"

#include "global.h"

SetListType::SetListType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetListType)
{
    ui->setupUi(this);

    ui->comboBox->addItem("");
    ui->comboBox->addItems(DOC_TYPES_NAMES.mid(0, DOC_TYPES_NAMES.size() - 1)); // without receipt
}

SetListType::~SetListType()
{
    delete ui;
}

void SetListType::on_btn_apply_clicked()
{
    selectedType = ui->comboBox->currentText();
    this->accept();
}

const QString &SetListType::getSelectedType() const
{
    return selectedType;
}

