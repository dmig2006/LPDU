/****************************************************************************
** Meta object code from reading C++ file 'validparceljpeg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/validparceljpeg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'validparceljpeg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_validParcelJPEG_t {
    QByteArrayData data[7];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_validParcelJPEG_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_validParcelJPEG_t qt_meta_stringdata_validParcelJPEG = {
    {
QT_MOC_LITERAL(0, 0, 15), // "validParcelJPEG"
QT_MOC_LITERAL(1, 16, 9), // "newLogMsg"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "sendFrameJpeg"
QT_MOC_LITERAL(4, 41, 9), // "startDraw"
QT_MOC_LITERAL(5, 51, 15), // "sendDataOfFrame"
QT_MOC_LITERAL(6, 67, 16) // "reciveParcelJPEG"

    },
    "validParcelJPEG\0newLogMsg\0\0sendFrameJpeg\0"
    "startDraw\0sendDataOfFrame\0reciveParcelJPEG"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_validParcelJPEG[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,
       4,    0,   45,    2, 0x06 /* Public */,
       5,    5,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,

       0        // eod
};

void validParcelJPEG::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        validParcelJPEG *_t = static_cast<validParcelJPEG *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newLogMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendFrameJpeg((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->startDraw(); break;
        case 3: _t->sendDataOfFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 4: _t->reciveParcelJPEG((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (validParcelJPEG::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&validParcelJPEG::newLogMsg)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (validParcelJPEG::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&validParcelJPEG::sendFrameJpeg)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (validParcelJPEG::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&validParcelJPEG::startDraw)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (validParcelJPEG::*_t)(int , double , double , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&validParcelJPEG::sendDataOfFrame)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject validParcelJPEG::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_validParcelJPEG.data,
      qt_meta_data_validParcelJPEG,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *validParcelJPEG::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *validParcelJPEG::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_validParcelJPEG.stringdata0))
        return static_cast<void*>(const_cast< validParcelJPEG*>(this));
    return QObject::qt_metacast(_clname);
}

int validParcelJPEG::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void validParcelJPEG::newLogMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void validParcelJPEG::sendFrameJpeg(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void validParcelJPEG::startDraw()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void validParcelJPEG::sendDataOfFrame(int _t1, double _t2, double _t3, int _t4, int _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
