/****************************************************************************
** Meta object code from reading C++ file 'souissi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../INTEGS/Samar/souissi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'souissi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_souissi_t {
    QByteArrayData data[16];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_souissi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_souissi_t qt_meta_stringdata_souissi = {
    {
QT_MOC_LITERAL(0, 0, 7), // "souissi"
QT_MOC_LITERAL(1, 8, 20), // "on_ajouterCl_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 21), // "on_modifierCl_clicked"
QT_MOC_LITERAL(4, 52, 16), // "on_pdfCl_clicked"
QT_MOC_LITERAL(5, 69, 8), // "sendMail"
QT_MOC_LITERAL(6, 78, 8), // "mailSent"
QT_MOC_LITERAL(7, 87, 6), // "browse"
QT_MOC_LITERAL(8, 94, 22), // "on_supprimerCl_clicked"
QT_MOC_LITERAL(9, 117, 21), // "on_chercherCl_clicked"
QT_MOC_LITERAL(10, 139, 24), // "on_statistiqueCl_clicked"
QT_MOC_LITERAL(11, 164, 20), // "on_ContratCl_clicked"
QT_MOC_LITERAL(12, 185, 19), // "on_triageCl_clicked"
QT_MOC_LITERAL(13, 205, 17), // "on_ref_Cl_clicked"
QT_MOC_LITERAL(14, 223, 17), // "on_homeCl_clicked"
QT_MOC_LITERAL(15, 241, 22) // "on_deconnectCl_clicked"

    },
    "souissi\0on_ajouterCl_clicked\0\0"
    "on_modifierCl_clicked\0on_pdfCl_clicked\0"
    "sendMail\0mailSent\0browse\0"
    "on_supprimerCl_clicked\0on_chercherCl_clicked\0"
    "on_statistiqueCl_clicked\0on_ContratCl_clicked\0"
    "on_triageCl_clicked\0on_ref_Cl_clicked\0"
    "on_homeCl_clicked\0on_deconnectCl_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_souissi[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       7,    0,   91,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void souissi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        souissi *_t = static_cast<souissi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ajouterCl_clicked(); break;
        case 1: _t->on_modifierCl_clicked(); break;
        case 2: _t->on_pdfCl_clicked(); break;
        case 3: _t->sendMail(); break;
        case 4: _t->mailSent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->browse(); break;
        case 6: _t->on_supprimerCl_clicked(); break;
        case 7: _t->on_chercherCl_clicked(); break;
        case 8: _t->on_statistiqueCl_clicked(); break;
        case 9: _t->on_ContratCl_clicked(); break;
        case 10: _t->on_triageCl_clicked(); break;
        case 11: _t->on_ref_Cl_clicked(); break;
        case 12: _t->on_homeCl_clicked(); break;
        case 13: _t->on_deconnectCl_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject souissi::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_souissi.data,
      qt_meta_data_souissi,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *souissi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *souissi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_souissi.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int souissi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
