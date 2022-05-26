QT -= gui
QT += core network
CONFIG+= c++11

SOURCES += src/worker.cpp \
    src/main.cpp \
    src/connection.cpp


HEADERS += \
    include/worker.h \
    include/connection.h

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/../shared/include

LIBS += -L$$PWD/../shared/lib -lDB
LIBS += -L$$PWD/../shared/lib -lPackage



