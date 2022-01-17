#ifndef COMBOBOXITEMDELEGATEFORUNIT_H
#define COMBOBOXITEMDELEGATEFORUNIT_H

#include <QStyledItemDelegate>

/*!
 * \brief The ComboBoxItemDelegate class created for combobox editing of Unit column
 */
class ComboBoxItemDelegateForUnit : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ComboBoxItemDelegateForUnit(QObject *parent = nullptr) : QStyledItemDelegate(parent) {};
    ~ComboBoxItemDelegateForUnit(){};

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
};
#endif // COMBOBOXITEMDELEGATEFORUNIT_H
