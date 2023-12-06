QT       += core gui printsupport
QT       += core gui sql
QT       += core gui network
QT += charts
QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT+=sql

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calendrier.cpp \
    conection.cpp \
    employe.cpp \
    events.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    oublier.cpp

HEADERS += \
    calendrier.h \
    conection.h \
    employe.h \
    events.h \
    login.h \
    mainwindow.h \
    oublier.h
    ui_login.h
    ui_calendrier.h
    ui_oublier.h

FORMS += \
    calendrier.ui \
    login.ui \
    mainwindow.ui \
    oublier.ui
    ui_login.ui
    ui_oublier.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target