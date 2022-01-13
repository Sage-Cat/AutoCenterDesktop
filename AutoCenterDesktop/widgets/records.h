#ifndef _H
#define _H

#include <QTableWidgetItem>
#include <QMap>
#include <QWidget>

#include <QStyledItemDelegate>

class QSqlTableModel;

namespace Ui {
class Records;
}

class Records : public QWidget {
    Q_OBJECT

    const int ID_COLUMN_INDEX { 0 };
    const int LIST_ID_COLUMN_INDEX { 1 };
    const int CODE_COLUMN_INDEX { 2 };
    const int NAME_COLUMN_INDEX { 5 };
    const int COUNT_COLUMN_INDEX { 6 };
    const int UNIT_COLUMN_INDEX { 7 };
    const int PRICE_COLUMN_INDEX { 8 };
    const int SUM_COLUMN_INDEX { 9 };

public:
    explicit Records(QWidget* parent = nullptr, int list_id = 0);
    ~Records();

private slots:
    /* COMBOBOXES */
    void on_comboBox_Customer_currentIndexChanged(int index);
    void on_comboBox_Seller_currentIndexChanged(int index);

    /* BUTTONS */
    void on_btn_add_clicked();
    void on_btn_del_clicked();

    /* ACTION */
    void handleDataChange(const QModelIndex& topLeft, const QModelIndex&);
    void handleProductCodeChange(const QString &data, const QString &record_id);
    void handleCountCellChange(const QString &data, const QString &record_id);
    void handlePriceCellChange(const QString &data, const QString &record_id);
    void handleSimpleCellChange(const QString& columnName, const QString &data, const QString &record_id);

    /* PRINT */
    void on_btn_print_barcode_clicked();
    void on_btn_print_document_clicked();

    /* UPDATE&INIT */
    void updateView();
    void initDateTimeAndPrintButtons();
    void initComboboxes();

    /* CUSTOM */
    QString getFromDBCurrentListColumn(QString column_name);

signals:
    void listDataChanged();

private:
    Ui::Records* ui;
    int list_id;
    QSqlTableModel* model;
    QMap<int, QString> customer_index_to_id, seller_index_to_id;
    QString docType {};
};

/*!
 * \brief The NumberFormatDelegate special class for preventing tableView's number's convertion to exponential form
 */
class NumberFormatDelegate : public QStyledItemDelegate{
    Q_OBJECT
    Q_DISABLE_COPY(NumberFormatDelegate)
public:
    NumberFormatDelegate(QObject *parent = Q_NULLPTR)
        :QStyledItemDelegate(parent)
    {}
    QString displayText(const QVariant &value, const QLocale &locale) const Q_DECL_OVERRIDE{
        switch(value.type()){
        case QMetaType::Float:
            return locale.toString(value.toFloat(),'f', 2);
        case QMetaType::Double:
            return locale.toString(value.toDouble(),'f', 2);
        default:
            return QStyledItemDelegate::displayText(value,locale);
        }
    }
};

#endif // _H
