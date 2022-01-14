/****************************************************************************
** Meta object code from reading C++ file 'customers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoCenterDesktop/widgets/customers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Customers_t {
    QByteArrayData data[16];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Customers_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Customers_t qt_meta_stringdata_Customers = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Customers"
QT_MOC_LITERAL(1, 10, 24), // "tabCustomerInfoRequested"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "customer_id"
QT_MOC_LITERAL(4, 48, 16), // "tabCarsRequested"
QT_MOC_LITERAL(5, 65, 18), // "on_btn_add_clicked"
QT_MOC_LITERAL(6, 84, 18), // "on_btn_del_clicked"
QT_MOC_LITERAL(7, 103, 19), // "on_btn_info_clicked"
QT_MOC_LITERAL(8, 123, 19), // "on_btn_cars_clicked"
QT_MOC_LITERAL(9, 143, 16), // "handleDataChange"
QT_MOC_LITERAL(10, 160, 11), // "QModelIndex"
QT_MOC_LITERAL(11, 172, 7), // "topLeft"
QT_MOC_LITERAL(12, 180, 22), // "handleSimpleCellChange"
QT_MOC_LITERAL(13, 203, 10), // "columnName"
QT_MOC_LITERAL(14, 214, 4), // "data"
QT_MOC_LITERAL(15, 219, 10) // "updateView"

    },
    "Customers\0tabCustomerInfoRequested\0\0"
    "customer_id\0tabCarsRequested\0"
    "on_btn_add_clicked\0on_btn_del_clicked\0"
    "on_btn_info_clicked\0on_btn_cars_clicked\0"
    "handleDataChange\0QModelIndex\0topLeft\0"
    "handleSimpleCellChange\0columnName\0"
    "data\0updateView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Customers[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   65,    2, 0x08 /* Private */,
       6,    0,   66,    2, 0x08 /* Private */,
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    2,   69,    2, 0x08 /* Private */,
      12,    3,   74,    2, 0x08 /* Private */,
      15,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10,   11,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   13,   14,    3,
    QMetaType::Void,

       0        // eod
};

void Customers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Customers *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tabCustomerInfoRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->tabCarsRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_btn_add_clicked(); break;
        case 3: _t->on_btn_del_clicked(); break;
        case 4: _t->on_btn_info_clicked(); break;
        case 5: _t->on_btn_cars_clicked(); break;
        case 6: _t->handleDataChange((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 7: _t->handleSimpleCellChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 8: _t->updateView(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Customers::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Customers::tabCustomerInfoRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Customers::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Customers::tabCarsRequested)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Customers::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Customers.data,
    qt_meta_data_Customers,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Customers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Customers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Customers.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Customers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Customers::tabCustomerInfoRequested(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Customers::tabCarsRequested(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
