/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../DesktopManager/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "threadStart"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 17), // "reDrawViewDisplay"
QT_MOC_LITERAL(4, 42, 7), // "setting"
QT_MOC_LITERAL(5, 50, 4), // "quit"
QT_MOC_LITERAL(6, 55, 14), // "getImgFinished"
QT_MOC_LITERAL(7, 70, 12), // "palyerToggle"
QT_MOC_LITERAL(8, 83, 17), // "onAddImgsBtnClick"
QT_MOC_LITERAL(9, 101, 17), // "on_cancel_clicked"
QT_MOC_LITERAL(10, 119, 19), // "on_addVideo_clicked"
QT_MOC_LITERAL(11, 139, 17), // "on_addGif_clicked"
QT_MOC_LITERAL(12, 157, 16), // "on_apply_clicked"
QT_MOC_LITERAL(13, 174, 23), // "on_activatedSysTrayIcon"
QT_MOC_LITERAL(14, 198, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(15, 232, 22), // "on_volume_valueChanged"
QT_MOC_LITERAL(16, 255, 5) // "value"

    },
    "MainWindow\0threadStart\0\0reDrawViewDisplay\0"
    "setting\0quit\0getImgFinished\0palyerToggle\0"
    "onAddImgsBtnClick\0on_cancel_clicked\0"
    "on_addVideo_clicked\0on_addGif_clicked\0"
    "on_apply_clicked\0on_activatedSysTrayIcon\0"
    "QSystemTrayIcon::ActivationReason\0"
    "on_volume_valueChanged\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   83,    2, 0x08 /* Private */,
       5,    0,   86,    2, 0x08 /* Private */,
       6,    1,   87,    2, 0x08 /* Private */,
       7,    1,   90,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    0,   94,    2, 0x08 /* Private */,
      10,    0,   95,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    1,   98,    2, 0x08 /* Private */,
      15,    1,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->threadStart(); break;
        case 1: _t->reDrawViewDisplay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->quit(); break;
        case 4: _t->getImgFinished((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->palyerToggle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->onAddImgsBtnClick(); break;
        case 7: _t->on_cancel_clicked(); break;
        case 8: _t->on_addVideo_clicked(); break;
        case 9: _t->on_addGif_clicked(); break;
        case 10: _t->on_apply_clicked(); break;
        case 11: _t->on_activatedSysTrayIcon((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 12: _t->on_volume_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::threadStart)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::reDrawViewDisplay)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::threadStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::reDrawViewDisplay(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
