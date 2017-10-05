/****************************************************************************
** Meta object code from reading C++ file 'mainsudoku.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../sudoku (QT)/mainsudoku.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainsudoku.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainSudoku_t {
    QByteArrayData data[10];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainSudoku_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainSudoku_t qt_meta_stringdata_MainSudoku = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainSudoku"
QT_MOC_LITERAL(1, 11, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 58, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(5, 82, 26), // "on_tableSudoku_cellChanged"
QT_MOC_LITERAL(6, 109, 3), // "row"
QT_MOC_LITERAL(7, 113, 6), // "column"
QT_MOC_LITERAL(8, 120, 23), // "on_actionSair_triggered"
QT_MOC_LITERAL(9, 144, 28) // "on_actionReiniciar_triggered"

    },
    "MainSudoku\0on_pushButton_3_clicked\0\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_tableSudoku_cellChanged\0row\0column\0"
    "on_actionSair_triggered\0"
    "on_actionReiniciar_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainSudoku[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    2,   47,    2, 0x08 /* Private */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainSudoku::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainSudoku *_t = static_cast<MainSudoku *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_3_clicked(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_tableSudoku_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_actionSair_triggered(); break;
        case 5: _t->on_actionReiniciar_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainSudoku::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainSudoku.data,
      qt_meta_data_MainSudoku,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainSudoku::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainSudoku::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainSudoku.stringdata0))
        return static_cast<void*>(const_cast< MainSudoku*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainSudoku::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
