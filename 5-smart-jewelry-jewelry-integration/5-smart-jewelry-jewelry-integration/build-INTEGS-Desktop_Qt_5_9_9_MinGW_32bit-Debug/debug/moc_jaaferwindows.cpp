/****************************************************************************
** Meta object code from reading C++ file 'jaaferwindows.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../INTEGS/jaafer/jaaferwindows.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jaaferwindows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_jaaferwindows_t {
    QByteArrayData data[15];
    char stringdata0[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_jaaferwindows_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_jaaferwindows_t qt_meta_stringdata_jaaferwindows = {
    {
QT_MOC_LITERAL(0, 0, 13), // "jaaferwindows"
QT_MOC_LITERAL(1, 14, 23), // "on_ajout_button_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 26), // "on_modifier_button_clicked"
QT_MOC_LITERAL(4, 66, 31), // "on_pushButton_supprimer_clicked"
QT_MOC_LITERAL(5, 98, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 120, 14), // "on_all_clicked"
QT_MOC_LITERAL(7, 135, 12), // "update_label"
QT_MOC_LITERAL(8, 148, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(9, 172, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(10, 196, 22), // "on_tableView_activated"
QT_MOC_LITERAL(11, 219, 5), // "index"
QT_MOC_LITERAL(12, 225, 33), // "on_idsearch_cursorPositionCha..."
QT_MOC_LITERAL(13, 259, 4), // "arg1"
QT_MOC_LITERAL(14, 264, 4) // "arg2"

    },
    "jaaferwindows\0on_ajout_button_clicked\0"
    "\0on_modifier_button_clicked\0"
    "on_pushButton_supprimer_clicked\0"
    "on_pushButton_clicked\0on_all_clicked\0"
    "update_label\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0on_tableView_activated\0"
    "index\0on_idsearch_cursorPositionChanged\0"
    "arg1\0arg2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_jaaferwindows[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      12,    2,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,

       0        // eod
};

void jaaferwindows::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        jaaferwindows *_t = static_cast<jaaferwindows *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ajout_button_clicked(); break;
        case 1: _t->on_modifier_button_clicked(); break;
        case 2: _t->on_pushButton_supprimer_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_all_clicked(); break;
        case 5: _t->update_label(); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->on_pushButton_3_clicked(); break;
        case 8: _t->on_tableView_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_idsearch_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject jaaferwindows::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_jaaferwindows.data,
      qt_meta_data_jaaferwindows,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *jaaferwindows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *jaaferwindows::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_jaaferwindows.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int jaaferwindows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
