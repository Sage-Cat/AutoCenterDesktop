#ifndef SETLISTTYPE_H
#define SETLISTTYPE_H

#include <QDialog>

namespace Ui {
class SetListType;
}

class SetListType : public QDialog
{
    Q_OBJECT

public:
    explicit SetListType(QWidget *parent = nullptr);
    ~SetListType();

    const QString &getSelectedType() const;

private slots:
    void on_btn_apply_clicked();

private:
    Ui::SetListType *ui;
    QString selectedType;
};

#endif // SETLISTTYPE_H
