#include "setlisttype.h"
#include "ui_setlisttype.h"

SetListType::SetListType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetListType)
{
    ui->setupUi(this);
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

