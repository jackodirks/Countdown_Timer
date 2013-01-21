#-------------------------------------------------
#
# Project created by QtCreator 2013-01-19T17:03:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Countdown_Timer
TEMPLATE = app

PRECOMPILED_HEADER  = stable.h

SOURCES += main.cpp\
        mainwindow.cpp \
    XMLClass.cpp

HEADERS  += mainwindow.h \
    XMLClass.h \
    stable.h

FORMS    += mainwindow.ui
