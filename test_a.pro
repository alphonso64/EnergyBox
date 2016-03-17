#-------------------------------------------------
#
# Project created by QtCreator 2016-03-14T14:02:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_a
TEMPLATE = app

DEFINES += QT_DLL QWT_DLL  
LIBS += -L"c:/Qt/4.8.4/lib" -lqwtd  
LIBS += -L"c:/Qt/4.8.4/lib" -lqwt  
INCLUDEPATH += c:\Qt\4.8.4\include\QWT

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    ../logo.png

RESOURCES +=
