/****************************************************************************
** Meta object code from reading C++ file 'lobbywidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../desktop/include/gui/widget/lobbywidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lobbywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_gui__widget__LobbyWidget_t {
    QByteArrayData data[23];
    char stringdata0[427];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gui__widget__LobbyWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gui__widget__LobbyWidget_t qt_meta_stringdata_gui__widget__LobbyWidget = {
    {
QT_MOC_LITERAL(0, 0, 24), // "gui::widget::LobbyWidget"
QT_MOC_LITERAL(1, 25, 18), // "needToGlobalSearch"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 6), // "prefix"
QT_MOC_LITERAL(4, 52, 28), // "needToSendToGroupTextMessage"
QT_MOC_LITERAL(5, 81, 7), // "groupId"
QT_MOC_LITERAL(6, 89, 11), // "textMessage"
QT_MOC_LITERAL(7, 101, 21), // "needToJoinUserToGroup"
QT_MOC_LITERAL(8, 123, 9), // "groupName"
QT_MOC_LITERAL(9, 133, 19), // "displayCreatedGroup"
QT_MOC_LITERAL(10, 153, 23), // "displayFriendsAndGroups"
QT_MOC_LITERAL(11, 177, 26), // "displayGlobalSearchResults"
QT_MOC_LITERAL(12, 204, 28), // "QVector<QPair<int,QString> >"
QT_MOC_LITERAL(13, 233, 19), // "globalSearchResults"
QT_MOC_LITERAL(14, 253, 29), // "displayReceivedMessageToGroup"
QT_MOC_LITERAL(15, 283, 6), // "userId"
QT_MOC_LITERAL(16, 290, 9), // "userLogin"
QT_MOC_LITERAL(17, 300, 18), // "displayJoinedGroup"
QT_MOC_LITERAL(18, 319, 28), // "on_searchLineEdit_textEdited"
QT_MOC_LITERAL(19, 348, 4), // "text"
QT_MOC_LITERAL(20, 353, 23), // "_displayGroupChatDialog"
QT_MOC_LITERAL(21, 377, 35), // "_displayGlobalSearchGroupChat..."
QT_MOC_LITERAL(22, 413, 13) // "groupNameText"

    },
    "gui::widget::LobbyWidget\0needToGlobalSearch\0"
    "\0prefix\0needToSendToGroupTextMessage\0"
    "groupId\0textMessage\0needToJoinUserToGroup\0"
    "groupName\0displayCreatedGroup\0"
    "displayFriendsAndGroups\0"
    "displayGlobalSearchResults\0"
    "QVector<QPair<int,QString> >\0"
    "globalSearchResults\0displayReceivedMessageToGroup\0"
    "userId\0userLogin\0displayJoinedGroup\0"
    "on_searchLineEdit_textEdited\0text\0"
    "_displayGroupChatDialog\0"
    "_displayGlobalSearchGroupChatDialog\0"
    "groupNameText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gui__widget__LobbyWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    2,   72,    2, 0x06 /* Public */,
       7,    2,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   82,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    1,   86,    2, 0x0a /* Public */,
      14,    4,   89,    2, 0x0a /* Public */,
      17,    1,   98,    2, 0x0a /* Public */,
      18,    1,  101,    2, 0x08 /* Private */,
      20,    1,  104,    2, 0x08 /* Private */,
      21,    2,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    5,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,   15,    5,   16,    6,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    5,   22,

       0        // eod
};

void gui::widget::LobbyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LobbyWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->needToGlobalSearch((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->needToSendToGroupTextMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->needToJoinUserToGroup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->displayCreatedGroup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->displayFriendsAndGroups(); break;
        case 5: _t->displayGlobalSearchResults((*reinterpret_cast< const QVector<QPair<int,QString> >(*)>(_a[1]))); break;
        case 6: _t->displayReceivedMessageToGroup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 7: _t->displayJoinedGroup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_searchLineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->_displayGroupChatDialog((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->_displayGlobalSearchGroupChatDialog((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LobbyWidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LobbyWidget::needToGlobalSearch)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LobbyWidget::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LobbyWidget::needToSendToGroupTextMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LobbyWidget::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LobbyWidget::needToJoinUserToGroup)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject gui::widget::LobbyWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_gui__widget__LobbyWidget.data,
    qt_meta_data_gui__widget__LobbyWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *gui::widget::LobbyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::widget::LobbyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gui__widget__LobbyWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int gui::widget::LobbyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void gui::widget::LobbyWidget::needToGlobalSearch(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void gui::widget::LobbyWidget::needToSendToGroupTextMessage(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void gui::widget::LobbyWidget::needToJoinUserToGroup(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
