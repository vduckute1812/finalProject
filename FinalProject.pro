#-------------------------------------------------
#
# Project created by QtCreator 2017-10-03T09:35:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FinalProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    findlinkpixel.cpp \
    camerasubtractor.cpp \
    calibratingcamera.cpp \
    subtractionhuman.cpp

HEADERS  += mainwindow.h \
    findlinkpixel.h \
    camerasubtractor.h \
    calibratingcamera.h \
    subtractionhuman.h

FORMS    += mainwindow.ui

INCLUDEPATH += '/local/include'
LIBS += `pkg-config --libs opencv`
