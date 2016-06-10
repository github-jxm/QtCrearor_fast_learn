/****************************************************************************
** Meta object code from reading C++ file 'myaction.h'
**
** Created: Tue Dec 8 09:43:53 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myaction.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myaction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyAction[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyAction[] = {
    "MyAction\0\0string\0getText(QString)\0"
    "sendText()\0"
};

void MyAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyAction *_t = static_cast<MyAction *>(_o);
        switch (_id) {
        case 0: _t->getText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sendText(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyAction::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyAction::staticMetaObject = {
    { &QWidgetAction::staticMetaObject, qt_meta_stringdata_MyAction,
      qt_meta_data_MyAction, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyAction::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyAction))
        return static_cast<void*>(const_cast< MyAction*>(this));
    return QWidgetAction::qt_metacast(_clname);
}

int MyAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidgetAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MyAction::getText(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
