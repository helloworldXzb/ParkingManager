/****************************************************************************
** Meta object code from reading C++ file 'parkingwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../parkingwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parkingwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSparkingwindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSparkingwindowENDCLASS = QtMocHelpers::stringData(
    "parkingwindow",
    "finishOrder",
    "",
    "firstId",
    "recordSource",
    "showParkSettings",
    "requestCheckCarId",
    "carId",
    "requestInsertNonRegisteredCar",
    "parkingName",
    "carType",
    "carPos",
    "startTime",
    "on_pushButton_clicked",
    "on_scanButton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSparkingwindowENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[14];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[13];
    char stringdata5[17];
    char stringdata6[18];
    char stringdata7[6];
    char stringdata8[30];
    char stringdata9[12];
    char stringdata10[8];
    char stringdata11[7];
    char stringdata12[10];
    char stringdata13[22];
    char stringdata14[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSparkingwindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSparkingwindowENDCLASS_t qt_meta_stringdata_CLASSparkingwindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "parkingwindow"
        QT_MOC_LITERAL(14, 11),  // "finishOrder"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 7),  // "firstId"
        QT_MOC_LITERAL(35, 12),  // "recordSource"
        QT_MOC_LITERAL(48, 16),  // "showParkSettings"
        QT_MOC_LITERAL(65, 17),  // "requestCheckCarId"
        QT_MOC_LITERAL(83, 5),  // "carId"
        QT_MOC_LITERAL(89, 29),  // "requestInsertNonRegisteredCar"
        QT_MOC_LITERAL(119, 11),  // "parkingName"
        QT_MOC_LITERAL(131, 7),  // "carType"
        QT_MOC_LITERAL(139, 6),  // "carPos"
        QT_MOC_LITERAL(146, 9),  // "startTime"
        QT_MOC_LITERAL(156, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(178, 21)   // "on_scanButton_clicked"
    },
    "parkingwindow",
    "finishOrder",
    "",
    "firstId",
    "recordSource",
    "showParkSettings",
    "requestCheckCarId",
    "carId",
    "requestInsertNonRegisteredCar",
    "parkingName",
    "carType",
    "carPos",
    "startTime",
    "on_pushButton_clicked",
    "on_scanButton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSparkingwindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   50,    2, 0x06,    1 /* Public */,
       5,    0,   55,    2, 0x06,    4 /* Public */,
       6,    1,   56,    2, 0x06,    5 /* Public */,
       8,    5,   59,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    0,   70,    2, 0x08,   13 /* Private */,
      14,    0,   71,    2, 0x08,   14 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QDateTime,    7,    9,   10,   11,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject parkingwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSparkingwindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSparkingwindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSparkingwindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<parkingwindow, std::true_type>,
        // method 'finishOrder'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showParkSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestCheckCarId'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'requestInsertNonRegisteredCar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_scanButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void parkingwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<parkingwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finishOrder((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->showParkSettings(); break;
        case 2: _t->requestCheckCarId((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->requestInsertNonRegisteredCar((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[5]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_scanButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (parkingwindow::*)(const QString & , const QString & );
            if (_t _q_method = &parkingwindow::finishOrder; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (parkingwindow::*)();
            if (_t _q_method = &parkingwindow::showParkSettings; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (parkingwindow::*)(const QString & );
            if (_t _q_method = &parkingwindow::requestCheckCarId; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (parkingwindow::*)(const QString & , const QString & , const QString & , int , const QDateTime & );
            if (_t _q_method = &parkingwindow::requestInsertNonRegisteredCar; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *parkingwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *parkingwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSparkingwindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int parkingwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void parkingwindow::finishOrder(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void parkingwindow::showParkSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void parkingwindow::requestCheckCarId(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void parkingwindow::requestInsertNonRegisteredCar(const QString & _t1, const QString & _t2, const QString & _t3, int _t4, const QDateTime & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
