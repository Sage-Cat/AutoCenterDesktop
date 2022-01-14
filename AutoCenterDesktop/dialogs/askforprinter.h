#ifndef ASKFORPRINTER_H
#define ASKFORPRINTER_H

#include <QDialog>

namespace Ui {
class AskForPrinter;
}

class AskForPrinter : public QDialog
{
    Q_OBJECT

public:
    explicit AskForPrinter(QWidget *parent = nullptr);
    ~AskForPrinter();

    const QString &getSelectedPrinter() const;

private slots:
    void on_btn_accept_clicked();

private:
    Ui::AskForPrinter *ui;

    QString selectedPrinter;
};

#endif // ASKFORPRINTER_H
