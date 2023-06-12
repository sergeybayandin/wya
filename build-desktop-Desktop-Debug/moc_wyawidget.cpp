/****************************************************************************
** Meta object code from reading C++ file 'wyawidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../desktop/include/gui/widget/wyawidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wyawidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_gui__widget__WyaWidget_t {
    QByteArrayData data[29];
    char stringdata0[528];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gui__widget__WyaWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gui__widget__WyaWidget_t qt_meta_stringdata_gui__widget__WyaWidget = {
    {
QT_MOC_LITERAL(0, 0, 22), // "gui::widget::WyaWidget"
QT_MOC_LITERAL(1, 23, 25), // "needToDisplayCreatedGroup"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 7), // "groupId"
QT_MOC_LITERAL(4, 58, 29), // "needToDisplayFriendsAndGroups"
QT_MOC_LITERAL(5, 88, 32), // "needToDisplayGlobalSearchResults"
QT_MOC_LITERAL(6, 121, 28), // "QVector<QPair<int,QString> >"
QT_MOC_LITERAL(7, 150, 19), // "globalSearchResults"
QT_MOC_LITERAL(8, 170, 35), // "needToDisplayReceivedMessageT..."
QT_MOC_LITERAL(9, 206, 6), // "userId"
QT_MOC_LITERAL(10, 213, 9), // "userLogin"
QT_MOC_LITERAL(11, 223, 11), // "textMessage"
QT_MOC_LITERAL(12, 235, 24), // "needToDisplayJoinedGroup"
QT_MOC_LITERAL(13, 260, 14), // "_authorizeUser"
QT_MOC_LITERAL(14, 275, 5), // "login"
QT_MOC_LITERAL(15, 281, 8), // "password"
QT_MOC_LITERAL(16, 290, 13), // "_registerUser"
QT_MOC_LITERAL(17, 304, 12), // "_createGroup"
QT_MOC_LITERAL(18, 317, 9), // "groupName"
QT_MOC_LITERAL(19, 327, 13), // "_globalSearch"
QT_MOC_LITERAL(20, 341, 6), // "prefix"
QT_MOC_LITERAL(21, 348, 21), // "_handleWebSocketError"
QT_MOC_LITERAL(22, 370, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(23, 399, 5), // "error"
QT_MOC_LITERAL(24, 405, 25), // "_handleWebSocketConnected"
QT_MOC_LITERAL(25, 431, 37), // "_handleWebSocketBinaryMessage..."
QT_MOC_LITERAL(26, 469, 13), // "binaryMessage"
QT_MOC_LITERAL(27, 483, 23), // "_sendToGroupTextMessage"
QT_MOC_LITERAL(28, 507, 20) // "_sendJoinUserToGroup"

    },
    "gui::widget::WyaWidget\0needToDisplayCreatedGroup\0"
    "\0groupId\0needToDisplayFriendsAndGroups\0"
    "needToDisplayGlobalSearchResults\0"
    "QVector<QPair<int,QString> >\0"
    "globalSearchResults\0"
    "needToDisplayReceivedMessageToGroup\0"
    "userId\0userLogin\0textMessage\0"
    "needToDisplayJoinedGroup\0_authorizeUser\0"
    "login\0password\0_registerUser\0_createGroup\0"
    "groupName\0_globalSearch\0prefix\0"
    "_handleWebSocketError\0"
    "QAbstractSocket::SocketError\0error\0"
    "_handleWebSocketConnected\0"
    "_handleWebSocketBinaryMessageReceived\0"
    "binaryMessage\0_sendToGroupTextMessage\0"
    "_sendJoinUserToGroup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gui__widget__WyaWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    0,   87,    2, 0x06 /* Public */,
       5,    1,   88,    2, 0x06 /* Public */,
       8,    4,   91,    2, 0x06 /* Public */,
      12,    1,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    2,  103,    2, 0x08 /* Private */,
      16,    2,  108,    2, 0x08 /* Private */,
      17,    1,  113,    2, 0x08 /* Private */,
      19,    1,  116,    2, 0x08 /* Private */,
      21,    1,  119,    2, 0x08 /* Private */,
      24,    0,  122,    2, 0x08 /* Private */,
      25,    1,  123,    2, 0x08 /* Private */,
      27,    2,  126,    2, 0x08 /* Private */,
      28,    2,  131,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    9,    3,   10,   11,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,   18,

       0        // eod
};

void gui::widget::WyaWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WyaWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->needToDisplayCreatedGroup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->needToDisplayFriendsAndGroups(); break;
        case 2: _t->needToDisplayGlobalSearchResults((*reinterpret_cast< const QVector<QPair<int,QString> >(*)>(_a[1]))); break;
        case 3: _t->needToDisplayReceivedMessageToGroup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 4: _t->needToDisplayJoinedGroup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->_authorizeUser((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->_registerUser((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->_createGroup((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->_globalSearch((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->_handleWebSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 10: _t->_handleWebSocketConnected(); break;
        case 11: _t->_handleWebSocketBinaryMessageReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 12: _t->_sendToGroupTextMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 13: _t->_sendJoinUserToGroup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WyaWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WyaWidget::needToDisplayCreatedGroup)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WyaWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WyaWidget::needToDisplayFriendsAndGroups)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WyaWidget::*)(const QVector<QPair<int,QString>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WyaWidget::needToDisplayGlobalSearchResults)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WyaWidget::*)(int , int , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WyaWidget::needToDisplayReceivedMessageToGroup)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WyaWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WyaWidget::needToDisplayJoinedGroup)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject gui::widget::WyaWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_gui__widget__WyaWidget.data,
    qt_meta_data_gui__widget__WyaWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *gui::widget::WyaWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::widget::WyaWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gui__widget__WyaWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int gui::widget::WyaWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void gui::widget::WyaWidget::needToDisplayCreatedGroup(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void gui::widget::WyaWidget::needToDisplayFriendsAndGroups()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void gui::widget::WyaWidget::needToDisplayGlobalSearchResults(const QVector<QPair<int,QString>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void gui::widget::WyaWidget::needToDisplayReceivedMessageToGroup(int _t1, int _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void gui::widget::WyaWidget::needToDisplayJoinedGroup(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
