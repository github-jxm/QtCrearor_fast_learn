#-------------------------------------------------
#
# Project created by QtCreator 2011-07-14T09:43:27
#
#-------------------------------------------------

QT       += core gui
QT       += phonon
TARGET = myPlayer
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    myplaylist.cpp \
    mylrc.cpp

HEADERS  += mywidget.h \
    myplaylist.h \
    mylrc.h

FORMS    += mywidget.ui

RESOURCES += \
    myImages.qrc
