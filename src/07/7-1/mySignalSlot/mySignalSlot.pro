#-------------------------------------------------
#
# Project created by QtCreator 2011-04-23T11:05:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mySignalSlot
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mydialog.cpp

HEADERS  += widget.h \
    mydialog.h

FORMS    += widget.ui \
    mydialog.ui
