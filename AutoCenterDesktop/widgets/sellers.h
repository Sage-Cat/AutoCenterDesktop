#ifndef SELLERS_H
#define SELLERS_H

#include <QWidget>
#include <QStyledItemDelegate>

class QSqlTableModel;

namespace Ui {
class Sellers;
}

class Sellers : public QWidget
{
    Q_OBJECT

    const int ID_COLUMN_INDEX{ 0 };

public:
    explicit Sellers(QWidget *parent = nullptr);
    ~Sellers();

public slots:
    void updateView();

private slots:
    void on_btn_add_clicked();
    void on_btn_del_clicked();
    void on_btn_edit_clicked();

private:
    Ui::Sellers *ui;
    QSqlTableModel *model;
};

class ComboBoxItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ComboBoxItemDelegate(QObject *parent = nullptr);
    ~ComboBoxItemDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    // QStyledItemDelegate interface
public:
    QString displayText(const QVariant &value, const QLocale &locale) const;
};

#endif // SELLERS_H
