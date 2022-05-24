QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bosodalardialog.cpp \
    hotel.cpp \
    main.cpp \
    mainwindow.cpp \
    misafirdialog.cpp \
    odabilgileridialog.cpp \
    odatemizlikdialog.cpp \
    rezervasyondialog.cpp

HEADERS += \
    bosodalardialog.h \
    hotel.h \
    mainwindow.h \
    misafirdialog.h \
    odabilgileridialog.h \
    odatemizlikdialog.h \
    rezervasyondialog.h

FORMS += \
    bosodalardialog.ui \
    mainwindow.ui \
    misafirdialog.ui \
    odabilgileridialog.ui \
    odatemizlikdialog.ui \
    rezervasyondialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
