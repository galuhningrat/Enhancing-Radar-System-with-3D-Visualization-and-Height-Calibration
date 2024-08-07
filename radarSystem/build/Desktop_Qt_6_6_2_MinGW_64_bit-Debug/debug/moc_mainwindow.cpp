/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
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
struct qt_meta_stringdata_CLASSHeightTrackingChartENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSHeightTrackingChartENDCLASS = QtMocHelpers::stringData(
    "HeightTrackingChart",
    "updateServo",
    "",
    "command",
    "readSerial",
    "processRadarData",
    "data",
    "on_button0_clicked",
    "on_button45_clicked",
    "on_button90_clicked",
    "on_button135_clicked",
    "on_button180_clicked",
    "on_verticalSlider_valueChanged",
    "value",
    "on_button_auto_clicked",
    "updateServoAuto",
    "clearOldDetectionPoints",
    "updateDetectionPoint",
    "angle",
    "distance",
    "height",
    "handleLaserActivation",
    "deactivateLaser",
    "resumeOperation",
    "updateLaserStatus",
    "status",
    "setSliderEnabled",
    "enabled",
    "handleLaserStatus",
    "addHeightDataPoint"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSHeightTrackingChartENDCLASS_t {
    uint offsetsAndSizes[60];
    char stringdata0[20];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[11];
    char stringdata5[17];
    char stringdata6[5];
    char stringdata7[19];
    char stringdata8[20];
    char stringdata9[20];
    char stringdata10[21];
    char stringdata11[21];
    char stringdata12[31];
    char stringdata13[6];
    char stringdata14[23];
    char stringdata15[16];
    char stringdata16[24];
    char stringdata17[21];
    char stringdata18[6];
    char stringdata19[9];
    char stringdata20[7];
    char stringdata21[22];
    char stringdata22[16];
    char stringdata23[16];
    char stringdata24[18];
    char stringdata25[7];
    char stringdata26[17];
    char stringdata27[8];
    char stringdata28[18];
    char stringdata29[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSHeightTrackingChartENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSHeightTrackingChartENDCLASS_t qt_meta_stringdata_CLASSHeightTrackingChartENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "HeightTrackingChart"
        QT_MOC_LITERAL(20, 11),  // "updateServo"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 7),  // "command"
        QT_MOC_LITERAL(41, 10),  // "readSerial"
        QT_MOC_LITERAL(52, 16),  // "processRadarData"
        QT_MOC_LITERAL(69, 4),  // "data"
        QT_MOC_LITERAL(74, 18),  // "on_button0_clicked"
        QT_MOC_LITERAL(93, 19),  // "on_button45_clicked"
        QT_MOC_LITERAL(113, 19),  // "on_button90_clicked"
        QT_MOC_LITERAL(133, 20),  // "on_button135_clicked"
        QT_MOC_LITERAL(154, 20),  // "on_button180_clicked"
        QT_MOC_LITERAL(175, 30),  // "on_verticalSlider_valueChanged"
        QT_MOC_LITERAL(206, 5),  // "value"
        QT_MOC_LITERAL(212, 22),  // "on_button_auto_clicked"
        QT_MOC_LITERAL(235, 15),  // "updateServoAuto"
        QT_MOC_LITERAL(251, 23),  // "clearOldDetectionPoints"
        QT_MOC_LITERAL(275, 20),  // "updateDetectionPoint"
        QT_MOC_LITERAL(296, 5),  // "angle"
        QT_MOC_LITERAL(302, 8),  // "distance"
        QT_MOC_LITERAL(311, 6),  // "height"
        QT_MOC_LITERAL(318, 21),  // "handleLaserActivation"
        QT_MOC_LITERAL(340, 15),  // "deactivateLaser"
        QT_MOC_LITERAL(356, 15),  // "resumeOperation"
        QT_MOC_LITERAL(372, 17),  // "updateLaserStatus"
        QT_MOC_LITERAL(390, 6),  // "status"
        QT_MOC_LITERAL(397, 16),  // "setSliderEnabled"
        QT_MOC_LITERAL(414, 7),  // "enabled"
        QT_MOC_LITERAL(422, 17),  // "handleLaserStatus"
        QT_MOC_LITERAL(440, 18)   // "addHeightDataPoint"
    },
    "HeightTrackingChart",
    "updateServo",
    "",
    "command",
    "readSerial",
    "processRadarData",
    "data",
    "on_button0_clicked",
    "on_button45_clicked",
    "on_button90_clicked",
    "on_button135_clicked",
    "on_button180_clicked",
    "on_verticalSlider_valueChanged",
    "value",
    "on_button_auto_clicked",
    "updateServoAuto",
    "clearOldDetectionPoints",
    "updateDetectionPoint",
    "angle",
    "distance",
    "height",
    "handleLaserActivation",
    "deactivateLaser",
    "resumeOperation",
    "updateLaserStatus",
    "status",
    "setSliderEnabled",
    "enabled",
    "handleLaserStatus",
    "addHeightDataPoint"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSHeightTrackingChartENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  134,    2, 0x08,    1 /* Private */,
       4,    0,  137,    2, 0x08,    3 /* Private */,
       5,    1,  138,    2, 0x08,    4 /* Private */,
       7,    0,  141,    2, 0x08,    6 /* Private */,
       8,    0,  142,    2, 0x08,    7 /* Private */,
       9,    0,  143,    2, 0x08,    8 /* Private */,
      10,    0,  144,    2, 0x08,    9 /* Private */,
      11,    0,  145,    2, 0x08,   10 /* Private */,
      12,    1,  146,    2, 0x08,   11 /* Private */,
      14,    0,  149,    2, 0x08,   13 /* Private */,
      15,    0,  150,    2, 0x08,   14 /* Private */,
      16,    0,  151,    2, 0x08,   15 /* Private */,
      17,    3,  152,    2, 0x08,   16 /* Private */,
      21,    0,  159,    2, 0x08,   20 /* Private */,
      22,    0,  160,    2, 0x08,   21 /* Private */,
      23,    0,  161,    2, 0x08,   22 /* Private */,
      24,    1,  162,    2, 0x08,   23 /* Private */,
      26,    1,  165,    2, 0x08,   25 /* Private */,
      28,    1,  168,    2, 0x08,   27 /* Private */,
      29,    1,  171,    2, 0x08,   29 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,   18,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::Float,   20,

       0        // eod
};

Q_CONSTINIT const QMetaObject HeightTrackingChart::staticMetaObject = { {
    QMetaObject::SuperData::link<QChartView::staticMetaObject>(),
    qt_meta_stringdata_CLASSHeightTrackingChartENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSHeightTrackingChartENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSHeightTrackingChartENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<HeightTrackingChart, std::true_type>,
        // method 'updateServo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'readSerial'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processRadarData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_button0_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button45_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button90_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button135_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button180_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_verticalSlider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_button_auto_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateServoAuto'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearOldDetectionPoints'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateDetectionPoint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'handleLaserActivation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deactivateLaser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resumeOperation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateLaserStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setSliderEnabled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'handleLaserStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addHeightDataPoint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>
    >,
    nullptr
} };

void HeightTrackingChart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HeightTrackingChart *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateServo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->readSerial(); break;
        case 2: _t->processRadarData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_button0_clicked(); break;
        case 4: _t->on_button45_clicked(); break;
        case 5: _t->on_button90_clicked(); break;
        case 6: _t->on_button135_clicked(); break;
        case 7: _t->on_button180_clicked(); break;
        case 8: _t->on_verticalSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_button_auto_clicked(); break;
        case 10: _t->updateServoAuto(); break;
        case 11: _t->clearOldDetectionPoints(); break;
        case 12: _t->updateDetectionPoint((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[3]))); break;
        case 13: _t->handleLaserActivation(); break;
        case 14: _t->deactivateLaser(); break;
        case 15: _t->resumeOperation(); break;
        case 16: _t->updateLaserStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->setSliderEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->handleLaserStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->addHeightDataPoint((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *HeightTrackingChart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HeightTrackingChart::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSHeightTrackingChartENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QChartView::qt_metacast(_clname);
}

int HeightTrackingChart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QChartView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
