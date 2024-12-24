/****************************************************************************
** Meta object code from reading C++ file 'userwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../userwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSuserwindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSuserwindowENDCLASS = QtMocHelpers::stringData(
    "userwindow",
    "sendquit",
    "",
    "sendprint",
    "send_main_updateinfo",
    "send_main_updatepass",
    "send_main_balance",
    "send_main_yearmember",
    "send_main_monthmember",
    "send_main_reservation",
    "send_main_payment",
    "send_main_consumption"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSuserwindowENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[11];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[21];
    char stringdata5[21];
    char stringdata6[18];
    char stringdata7[21];
    char stringdata8[22];
    char stringdata9[22];
    char stringdata10[18];
    char stringdata11[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSuserwindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSuserwindowENDCLASS_t qt_meta_stringdata_CLASSuserwindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "userwindow"
        QT_MOC_LITERAL(11, 8),  // "sendquit"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 9),  // "sendprint"
        QT_MOC_LITERAL(31, 20),  // "send_main_updateinfo"
        QT_MOC_LITERAL(52, 20),  // "send_main_updatepass"
        QT_MOC_LITERAL(73, 17),  // "send_main_balance"
        QT_MOC_LITERAL(91, 20),  // "send_main_yearmember"
        QT_MOC_LITERAL(112, 21),  // "send_main_monthmember"
        QT_MOC_LITERAL(134, 21),  // "send_main_reservation"
        QT_MOC_LITERAL(156, 17),  // "send_main_payment"
        QT_MOC_LITERAL(174, 21)   // "send_main_consumption"
    },
    "userwindow",
    "sendquit",
    "",
    "sendprint",
    "send_main_updateinfo",
    "send_main_updatepass",
    "send_main_balance",
    "send_main_yearmember",
    "send_main_monthmember",
    "send_main_reservation",
    "send_main_payment",
    "send_main_consumption"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSuserwindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,
       3,    0,   75,    2, 0x06,    2 /* Public */,
       4,    4,   76,    2, 0x06,    3 /* Public */,
       5,    2,   85,    2, 0x06,    8 /* Public */,
       6,    1,   90,    2, 0x06,   11 /* Public */,
       7,    0,   93,    2, 0x06,   13 /* Public */,
       8,    0,   94,    2, 0x06,   14 /* Public */,
       9,    4,   95,    2, 0x06,   15 /* Public */,
      10,    0,  104,    2, 0x06,   20 /* Public */,
      11,    0,  105,    2, 0x06,   21 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QDateTime, QMetaType::QDateTime,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject userwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSuserwindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSuserwindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSuserwindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<userwindow, std::true_type>,
        // method 'sendquit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendprint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'send_main_updateinfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'send_main_updatepass'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'send_main_balance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'send_main_yearmember'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'send_main_monthmember'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'send_main_reservation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>,
        // method 'send_main_payment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'send_main_consumption'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void userwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<userwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendquit(); break;
        case 1: _t->sendprint(); break;
        case 2: _t->send_main_updateinfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 3: _t->send_main_updatepass((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->send_main_balance((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->send_main_yearmember(); break;
        case 6: _t->send_main_monthmember(); break;
        case 7: _t->send_main_reservation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[4]))); break;
        case 8: _t->send_main_payment(); break;
        case 9: _t->send_main_consumption(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (userwindow::*)();
            if (_t _q_method = &userwindow::sendquit; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (userwindow::*)();
            if (_t _q_method = &userwindow::sendprint; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (userwindow::*)(QString , QString , QString , QString );
            if (_t _q_method = &userwindow::send_main_updateinfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (userwindow::*)(QString , QString );
            if (_t _q_method = &userwindow::send_main_updatepass; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (userwindow::*)(int );
            if (_t _q_method = &userwindow::send_main_balance; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (userwindow::*)();
            if (_t _q_method = &userwindow::send_main_yearmember; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (userwindow::*)();
            if (_t _q_method = &userwindow::send_main_monthmember; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (userwindow::*)(QString , int , QDateTime , QDateTime );
            if (_t _q_method = &userwindow::send_main_reservation; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (userwindow::*)();
            if (_t _q_method = &userwindow::send_main_payment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (userwindow::*)();
            if (_t _q_method = &userwindow::send_main_consumption; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject *userwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *userwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSuserwindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int userwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void userwindow::sendquit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void userwindow::sendprint()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void userwindow::send_main_updateinfo(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void userwindow::send_main_updatepass(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void userwindow::send_main_balance(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void userwindow::send_main_yearmember()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void userwindow::send_main_monthmember()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void userwindow::send_main_reservation(QString _t1, int _t2, QDateTime _t3, QDateTime _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void userwindow::send_main_payment()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void userwindow::send_main_consumption()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
