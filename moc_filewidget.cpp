/****************************************************************************
** Meta object code from reading C++ file 'filewidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "filewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FileWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   29,   34,   34, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   34,   34,   34, 0x08,
      61,   34,   34,   34, 0x08,
      85,   34,   34,   34, 0x08,
     111,   34,   34,   34, 0x08,
     137,   34,   34,   34, 0x08,
     163,   34,   34,   34, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FileWidget[] = {
    "FileWidget\0fileopen(QString)\0path\0\0"
    "on_pushButton_3_pressed()\0"
    "on_pushButton_pressed()\0"
    "on_pushButton_2_pressed()\0"
    "on_pushButton_4_pressed()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_4_clicked()\0"
};

void FileWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FileWidget *_t = static_cast<FileWidget *>(_o);
        switch (_id) {
        case 0: _t->fileopen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_3_pressed(); break;
        case 2: _t->on_pushButton_pressed(); break;
        case 3: _t->on_pushButton_2_pressed(); break;
        case 4: _t->on_pushButton_4_pressed(); break;
        case 5: _t->on_pushButton_3_clicked(); break;
        case 6: _t->on_pushButton_4_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FileWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FileWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FileWidget,
      qt_meta_data_FileWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileWidget))
        return static_cast<void*>(const_cast< FileWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int FileWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FileWidget::fileopen(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
