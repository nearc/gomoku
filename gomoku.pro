#-------------------------------------------------
#
# Project created by QtCreator 2013-05-29T14:06:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gomoku
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    judgeRule.cpp


HEADERS  += mainwindow.hpp \
    judgeRule.hpp

FORMS    += mainwindow.ui
RESOURCES += board.qrc
