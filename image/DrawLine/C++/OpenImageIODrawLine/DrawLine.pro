
TARGET = DrawLine 
CONFIG -= app_bundle
DEPENDPATH += .
INCLUDEPATH += .

LIBS+=-lOpenImageIO -lOpenImageIO_Util
CONFIG+=c++14
# Input
SOURCES += DrawLine.cpp
