QT       += sql

QT       += charts

QT       += printsupport
QT       += core gui charts
QT      += network


QT       += core gui charts sql network serialport

QT       += core gui
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    Samar/client.cpp \
    Samar/smtp.cpp \
    Samar/souissi.cpp \
    ghaya/arduino.cpp \
    jaafer/facture.cpp \
    jaafer/jaaferwindows.cpp \
    jaafer/qrcodegen.cpp \
    main.cpp \
    ghaya/conection.cpp\
    ghaya/employe.cpp\
    ghaya/login.cpp\
    ghaya/mainwindow.cpp\
    ghaya/oublier.cpp\
    selim/dialog.cpp\
    selim/exportexcelobject.cpp\
    selim/produit.cpp\
    skander/MainWindow1.cpp \
    skander/commande.cpp\
    widget.cpp

HEADERS += \
    Samar/client.h \
    Samar/smtp.h \
    Samar/souissi.h \
    ghaya/arduino.h \
    ghaya/conection.h\
    ghaya/employe.h\
    ghaya/login.h\
    ghaya/mainwindow.h\
    ghaya/oublier.h\
    jaafer/facture.h \
    jaafer/jaaferwindows.h \
    jaafer/qrcodegen.hpp \
    selim/dialog.h\
    selim/exportexcelobject.h\
    selim/produit.h\
    skander/MainWindow1.h \
    skander/commande.h\
    widget.h

FORMS += \
    Samar/souissi.ui \
    ghaya/login.ui\
    ghaya/mainwindow.ui\
    ghaya/oublier.ui\
    jaafer/jaaferwindows.ui \
    skander/MainWindow1.ui \
    selim/interface.ui\
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
SUBDIRS += \
    ghaya/app2.pro \
    jaafer/jaafer.pro
    selim/projetmain.pro
    skander/app.pro
DISTFILES += \
    Samar/mailing samar/libeay32.dll \
    Samar/mailing samar/ssleay32.dll \
    aziz/app2.pro.user\
    selim/projetmain.pro,user\
    skander/app.pro.user\

RESOURCES += \
    ghaya/img.qrc\
