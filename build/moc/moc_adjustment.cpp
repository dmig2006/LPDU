/****************************************************************************
** Meta object code from reading C++ file 'adjustment.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/adjustment.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adjustment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Adjustment_t {
    QByteArrayData data[16];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Adjustment_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Adjustment_t qt_meta_stringdata_Adjustment = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Adjustment"
QT_MOC_LITERAL(1, 11, 7), // "newPosX"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "pFlag"
QT_MOC_LITERAL(4, 26, 7), // "newPosY"
QT_MOC_LITERAL(5, 34, 9), // "newPosX_Y"
QT_MOC_LITERAL(6, 44, 5), // "pPosX"
QT_MOC_LITERAL(7, 50, 5), // "pPosY"
QT_MOC_LITERAL(8, 56, 9), // "newLogMsg"
QT_MOC_LITERAL(9, 66, 7), // "pString"
QT_MOC_LITERAL(10, 74, 21), // "on_leftButton_clicked"
QT_MOC_LITERAL(11, 96, 22), // "on_rightButton_clicked"
QT_MOC_LITERAL(12, 119, 19), // "on_upButton_clicked"
QT_MOC_LITERAL(13, 139, 21), // "on_downButton_clicked"
QT_MOC_LITERAL(14, 161, 23), // "on_centerButton_clicked"
QT_MOC_LITERAL(15, 185, 21) // "on_exitButton_clicked"

    },
    "Adjustment\0newPosX\0\0pFlag\0newPosY\0"
    "newPosX_Y\0pPosX\0pPosY\0newLogMsg\0pString\0"
    "on_leftButton_clicked\0on_rightButton_clicked\0"
    "on_upButton_clicked\0on_downButton_clicked\0"
    "on_centerButton_clicked\0on_exitButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Adjustment[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       5,    2,   70,    2, 0x06 /* Public */,
       8,    1,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,
      14,    0,   82,    2, 0x08 /* Private */,
      15,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Adjustment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Adjustment *_t = static_cast<Adjustment *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newPosX((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->newPosY((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->newPosX_Y((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->newLogMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_leftButton_clicked(); break;
        case 5: _t->on_rightButton_clicked(); break;
        case 6: _t->on_upButton_clicked(); break;
        case 7: _t->on_downButton_clicked(); break;
        case 8: _t->on_centerButton_clicked(); break;
        case 9: _t->on_exitButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Adjustment::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Adjustment::newPosX)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Adjustment::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Adjustment::newPosY)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Adjustment::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Adjustment::newPosX_Y)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Adjustment::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Adjustment::newLogMsg)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Adjustment::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Adjustment.data,
      qt_meta_data_Adjustment,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Adjustment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Adjustment::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Adjustment.stringdata0))
        return static_cast<void*>(const_cast< Adjustment*>(this));
    return QDialog::qt_metacast(_clname);
}

int Adjustment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Adjustment::newPosX(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Adjustment::newPosY(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Adjustment::newPosX_Y(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Adjustment::newLogMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
