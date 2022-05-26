QT -= gui
QT+= core sql
CONFIG+= c++11
TEMPLATE = lib
DESTDIR = $$PWD/../shared/lib/


HEADERS += include/databaseconnection.h \
    include/executor.h \
    include/manipulator.h \
    include/mapper.h \
    include/processor.h \
    include/selector.h

INCLUDEPATH += $$PWD/include

SOURCES += src/databaseconnection.cpp \
    src/executor.cpp \
    src/manipulator.cpp \
    src/processor.cpp \
    src/selector.cpp

headers.path = ../shared/include
headers.files = include/processor.h
INSTALLS += headers
