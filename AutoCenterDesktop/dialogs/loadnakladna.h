#ifndef LOADNAKLADNA_H
#define LOADNAKLADNA_H

#include <QDialog>

namespace Ui {
class LoadNakladna;
}

class LoadNakladna : public QDialog
{
    Q_OBJECT

public:
    explicit LoadNakladna(QWidget *parent = nullptr);
    ~LoadNakladna();

private slots:
    void on_btn_explorer_clicked();

    void on_btn_load_clicked();

private:
    Ui::LoadNakladna *ui;
};

#endif // LOADNAKLADNA_H
