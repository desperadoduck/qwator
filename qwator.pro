TEMPLATE = app
TARGET = qwator

#CONFIG += warn_on qt uic
CONFIG += c++11 debug uic

QT += gui core widgets svg

SOURCES += main.cpp fish.cpp lifeform.cpp ocean.cpp shark.cpp qwatorapp.cpp mainwindow.cpp licensedialog.cpp
HEADERS += fish.h lifeform.h ocean.h shark.h qwatorapp.h mainwindow.h licensedialog.h

FORMS += mainwindow.ui licensedialog.ui codelicensewidget.ui graphicslicensewidget.ui

RESOURCES += qwator.qrc

DESTDIR = build
OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = build
UI_DIR = build
