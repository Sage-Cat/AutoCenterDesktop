/****************************************************************************
** Meta object code from reading C++ file 'records.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoCenterDesktop/widgets/records.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'records.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Records_t {
    QByteArrayData data[27];
    char stringdata0[497];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Records_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Records_t qt_meta_stringdata_Records = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Records"
QT_MOC_LITERAL(1, 8, 15), // "listDataChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 40), // "on_comboBox_Customer_currentI..."
QT_MOC_LITERAL(4, 66, 5), // "index"
QT_MOC_LITERAL(5, 72, 38), // "on_comboBox_Seller_currentInd..."
QT_MOC_LITERAL(6, 111, 18), // "on_btn_add_clicked"
QT_MOC_LITERAL(7, 130, 18), // "on_btn_del_clicked"
QT_MOC_LITERAL(8, 149, 16), // "handleDataChange"
QT_MOC_LITERAL(9, 166, 11), // "QModelIndex"
QT_MOC_LITERAL(10, 178, 7), // "topLeft"
QT_MOC_LITERAL(11, 186, 23), // "handleProductCodeChange"
QT_MOC_LITERAL(12, 210, 4), // "data"
QT_MOC_LITERAL(13, 215, 9), // "record_id"
QT_MOC_LITERAL(14, 225, 21), // "handleCountCellChange"
QT_MOC_LITERAL(15, 247, 21), // "handlePriceCellChange"
QT_MOC_LITERAL(16, 269, 22), // "handleSimpleCellChange"
QT_MOC_LITERAL(17, 292, 10), // "columnName"
QT_MOC_LITERAL(18, 303, 28), // "on_btn_print_barcode_clicked"
QT_MOC_LITERAL(19, 332, 29), // "on_btn_print_document_clicked"
QT_MOC_LITERAL(20, 362, 10), // "updateView"
QT_MOC_LITERAL(21, 373, 27), // "initDateTimeAndPrintButtons"
QT_MOC_LITERAL(22, 401, 14), // "initComboboxes"
QT_MOC_LITERAL(23, 416, 26), // "getFromDBCurrentListColumn"
QT_MOC_LITERAL(24, 443, 11), // "column_name"
QT_MOC_LITERAL(25, 455, 32), // "on_line_datetime_dateTimeChanged"
QT_MOC_LITERAL(26, 488, 8) // "dateTime"

    },
    "Records\0listDataChanged\0\0"
    "on_comboBox_Customer_currentIndexChanged\0"
    "index\0on_comboBox_Seller_currentIndexChanged\0"
    "on_btn_add_clicked\0on_btn_del_clicked\0"
    "handleDataChange\0QModelIndex\0topLeft\0"
    "handleProductCodeChange\0data\0record_id\0"
    "handleCountCellChange\0handlePriceCellChange\0"
    "handleSimpleCellChange\0columnName\0"
    "on_btn_print_barcode_clicked\0"
    "on_btn_print_document_clicked\0updateView\0"
    "initDateTimeAndPrintButtons\0initComboboxes\0"
    "getFromDBCurrentListColumn\0column_name\0"
    "on_line_datetime_dateTimeChanged\0"
    "dateTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Records[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,  100,    2, 0x08 /* Private */,
       5,    1,  103,    2, 0x08 /* Private */,
       6,    0,  106,    2, 0x08 /* Private */,
       7,    0,  107,    2, 0x08 /* Private */,
       8,    2,  108,    2, 0x08 /* Private */,
      11,    2,  113,    2, 0x08 /* Private */,
      14,    2,  118,    2, 0x08 /* Private */,
      15,    2,  123,    2, 0x08 /* Private */,
      16,    3,  128,    2, 0x08 /* Private */,
      18,    0,  135,    2, 0x08 /* Private */,
      19,    0,  136,    2, 0x08 /* Private */,
      20,    0,  137,    2, 0x08 /* Private */,
      21,    0,  138,    2, 0x08 /* Private */,
      22,    0,  139,    2, 0x08 /* Private */,
      23,    1,  140,    2, 0x08 /* Private */,
      25,    1,  143,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,   10,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   17,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QDateTime,   26,

       0        // eod
};

void Records::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Records *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listDataChanged(); break;
        case 1: _t->on_comboBox_Customer_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_comboBox_Seller_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_btn_add_clicked(); break;
        case 4: _t->on_btn_del_clicked(); break;
        case 5: _t->handleDataChange((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 6: _t->handleProductCodeChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->handleCountCellChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->handlePriceCellChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->handleSimpleCellChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 10: _t->on_btn_print_barcode_clicked(); break;
        case 11: _t->on_btn_print_document_clicked(); break;
        case 12: _t->updateView(); break;
        case 13: _t->initDateTimeAndPrintButtons(); break;
        case 14: _t->initComboboxes(); break;
        case 15: { QString _r = _t->getFromDBCurrentListColumn((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->on_line_datetime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Records::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Records::listDataChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Records::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Records.data,
    qt_meta_data_Records,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Records::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Records::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Records.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Records::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Records::listDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_NumberFormatDelegate_t {
    QByteArrayData data[1];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NumberFormatDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NumberFormatDelegate_t qt_meta_stringdata_NumberFormatDelegate = {
    {
QT_MOC_LITERAL(0, 0, 20) // "NumberFormatDelegate"

    },
    "NumberFormatDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NumberFormatDelegate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void NumberFormatDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject NumberFormatDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QStyledItemDelegate::staticMetaObject>(),
    qt_meta_stringdata_NumberFormatDelegate.data,
    qt_meta_data_NumberFormatDelegate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NumberFormatDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NumberFormatDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NumberFormatDelegate.stringdata0))
        return static_cast<void*>(this);
    return QStyledItemDelegate::qt_metacast(_clname);
}

int NumberFormatDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
