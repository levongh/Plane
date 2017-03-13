QT       += core gui widgets
CONFIG +=c++11

TARGET = cube
TEMPLATE = app

SOURCES += main.cpp \
    antenna.cpp \
    plane.cpp \
    MainWindow.cpp \
    graphicsScene.cpp



HEADERS += \
    antenna.h \
    plane.h \
    MainWindow.h \
    graphicsScene.h

RESOURCES += \
    resource.qrc

