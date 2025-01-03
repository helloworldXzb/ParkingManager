#-------------------------------------------------
#
# Project created by QtCreator 2020-06-22T08:57:39
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Parkingmanager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    parkingsettings.cpp \
    registered.cpp \
    userwindow.cpp \
    edit_info.cpp \
    record.cpp \
    topup.cpp \
    update_password.cpp \
    parkingwindow.cpp

HEADERS += \
        mainwindow.h \
    parkingsettings.h \
    registered.h \
    userwindow.h \
    edit_info.h \
    record.h \
    topup.h \
    update_password.h \
    parkingwindow.h

FORMS += \
        mainwindow.ui \
    parkingsettings.ui \
    registered.ui \
    userwindow.ui \
    edit_info.ui \
    record.ui \
    topup.ui \
    update_password.ui \
    parkingwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

QT += network
QT += core gui widgets network

# win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../opencv/opencv/MinGWbuild/install/x64/mingw/release/ -llibopencv_world4100.dll
# else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../opencv/opencv/MinGWbuild/install/x64/mingw/debug/ -llibopencv_world4100.dll
# else:unix: LIBS += -L$$PWD/../../opencv/opencv/MinGWbuild/install/x64/mingw/ -llibopencv_world4100.dll

# INCLUDEPATH += $$PWD/../../opencv/opencv/MinGWbuild/install/include
# DEPENDPATH += $$PWD/../../opencv/opencv/MinGWbuild/install/include
