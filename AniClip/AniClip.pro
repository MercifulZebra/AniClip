#-------------------------------------------------
#
# Project created by QtCreator 2016-11-28T09:47:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = AniClip
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    centralstackwidget.cpp \
    startscreenwidget.cpp \
    stackedwidget.cpp \
    addscreenwidget.cpp \
    transitionscreenwidget.cpp

HEADERS  += mainwindow.h \
    centralstackwidget.h \
    startscreenwidget.h \
    stackedwidget.h \
    addscreenwidget.h \
    transitionscreenwidget.h

FORMS    += mainwindow.ui

DISTFILES += \
    toBeDone_list
