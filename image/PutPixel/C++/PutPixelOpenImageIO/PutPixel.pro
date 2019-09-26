
TARGET = PutPixel 
CONFIG -= app_bundle
DEPENDPATH += .
INCLUDEPATH += .

LIBS+=-lOpenImageIO -lOpenImageIO_Util
CONFIG+=c++14
# Input
SOURCES += PutPixel.cpp
