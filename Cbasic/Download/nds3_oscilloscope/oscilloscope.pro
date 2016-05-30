TEMPLATE = lib
QT = ""
CONFIG += dll

QMAKE_CXXFLAGS += -std=c++0x -O0 -rdynamic -Wall -Wextra -pedantic

LIBS += -lnds3

HEADERS += \
    include/oscilloscope.h

SOURCES += \
    src/oscilloscope.cpp
