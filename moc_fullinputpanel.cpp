/****************************************************************************
** Meta object code from reading C++ file 'fullinputpanel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fullinputpanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fullinputpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FullInputPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   45,   55,   55, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,   91,   55,   55, 0x08,
     109,  133,   55,   55, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FullInputPanel[] = {
    "FullInputPanel\0fullcharacterGenerated(QChar)\0"
    "character\0\0saveFocusWidget(QWidget*,QWidget*)\0"
    "oldFocus,newFocus\0buttonClicked(QWidget*)\0"
    "w\0"
};

void FullInputPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FullInputPanel *_t = static_cast<FullInputPanel *>(_o);
        switch (_id) {
        case 0: _t->fullcharacterGenerated((*reinterpret_cast< QChar(*)>(_a[1]))); break;
        case 1: _t->saveFocusWidget((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 2: _t->buttonClicked((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FullInputPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FullInputPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FullInputPanel,
      qt_meta_data_FullInputPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FullInputPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FullInputPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FullInputPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FullInputPanel))
        return static_cast<void*>(const_cast< FullInputPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int FullInputPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FullInputPanel::fullcharacterGenerated(QChar _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
