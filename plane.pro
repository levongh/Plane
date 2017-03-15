QT       += core gui widgets
CONFIG +=c++11

TARGET = cube
TEMPLATE = app

SOURCES += main.cpp \
    antenna.cpp \
    plane.cpp \
    MainWindow.cpp \
    threedimentionalscene.cpp \
    twodimentionalscene.cpp



HEADERS += \
    antenna.h \
    plane.h \
    MainWindow.h \
    threedimentionalscene.h \
    twodimentionalscene.h

RESOURCES += \
    resource.qrc

