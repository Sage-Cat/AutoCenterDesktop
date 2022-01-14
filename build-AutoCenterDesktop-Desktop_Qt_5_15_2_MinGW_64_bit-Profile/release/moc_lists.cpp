/****************************************************************************
** Meta object code from reading C++ file 'lists.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoCenterDesktop/widgets/lists.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lists.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Lists_t {
    QByteArrayData data[18];
    char stringdata0[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Lists_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Lists_t qt_meta_stringdata_Lists = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Lists"
QT_MOC_LITERAL(1, 6, 19), // "tabRecordsRequested"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "list_id"
QT_MOC_LITERAL(4, 35, 18), // "on_btn_add_clicked"
QT_MOC_LITERAL(5, 54, 18), // "on_btn_del_clicked"
QT_MOC_LITERAL(6, 73, 20), // "on_radio_all_clicked"
QT_MOC_LITERAL(7, 94, 20), // "on_radio_org_clicked"
QT_MOC_LITERAL(8, 115, 24), // "on_radio_not_org_clicked"
QT_MOC_LITERAL(9, 140, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(10, 167, 11), // "QModelIndex"
QT_MOC_LITERAL(11, 179, 5), // "index"
QT_MOC_LITERAL(12, 185, 19), // "on_btn_load_clicked"
QT_MOC_LITERAL(13, 205, 21), // "on_btn_create_clicked"
QT_MOC_LITERAL(14, 227, 11), // "askListType"
QT_MOC_LITERAL(15, 239, 16), // "getNewListNumber"
QT_MOC_LITERAL(16, 256, 8), // "listType"
QT_MOC_LITERAL(17, 265, 10) // "updateView"

    },
    "Lists\0tabRecordsRequested\0\0list_id\0"
    "on_btn_add_clicked\0on_btn_del_clicked\0"
    "on_radio_all_clicked\0on_radio_org_clicked\0"
    "on_radio_not_org_clicked\0"
    "on_tableView_doubleClicked\0QModelIndex\0"
    "index\0on_btn_load_clicked\0"
    "on_btn_create_clicked\0askListType\0"
    "getNewListNumber\0listType\0updateView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Lists[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   77,    2, 0x08 /* Private */,
       5,    0,   78,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    1,   82,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,
      15,    1,   88,    2, 0x08 /* Private */,
      17,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Int, QMetaType::QString,   16,
    QMetaType::Void,

       0        // eod
};

void Lists::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Lists *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tabRecordsRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_btn_add_clicked(); break;
        case 2: _t->on_btn_del_clicked(); break;
        case 3: _t->on_radio_all_clicked(); break;
        case 4: _t->on_radio_org_clicked(); break;
        case 5: _t->on_radio_not_org_clicked(); break;
        case 6: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_btn_load_clicked(); break;
        case 8: _t->on_btn_create_clicked(); break;
        case 9: { QString _r = _t->askListType();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->getNewListNumber((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->updateView(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Lists::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Lists::tabRecordsRequested)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Lists::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Lists.data,
    qt_meta_data_Lists,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Lists::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Lists::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Lists.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Lists::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Lists::tabRecordsRequested(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
