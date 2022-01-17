#include "comboboxitemdelegateforunit.h"

#include <QComboBox>

#include "global.h"

QWidget *ComboBoxItemDelegateForUnit::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // Create the combobox and populate it
    QComboBox *cb = new QComboBox(parent);
    const auto unit_types = UNIT_CODE.keys();
    for (auto it = unit_types.rbegin(); it != unit_types.rend(); ++it)
        cb->addItem(*it, Qt::DisplayRole);

    return cb;
}

void ComboBoxItemDelegateForUnit::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);
    // get the index of the text in the combobox that matches the current value of the item
    const QString currentText = index.data(Qt::DisplayRole).toString();
    const int cbIndex = cb->findText(currentText);
    // if it is valid, adjust the combobox
    if (cbIndex >= 0)
       cb->setCurrentIndex(cbIndex);
}

void ComboBoxItemDelegateForUnit::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);
    model->setData(index, cb->currentText(), Qt::EditRole);
}
