#-------------------------------------------------
#
# Project created by QtCreator 2016-11-28T09:47:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AniClip
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    centralstackwidget.cpp \
    startscreenwidget.cpp \
    stackedwidget.cpp \
    addscreenwidget.cpp

HEADERS  += mainwindow.h \
    centralstackwidget.h \
    startscreenwidget.h \
    stackedwidget.h \
    addscreenwidget.h

FORMS    += mainwindow.ui
