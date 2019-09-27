
TARGET = PutPixel 
CONFIG -= app_bundle
DEPENDPATH += .
INCLUDEPATH += .
LIBS += -L/usr/local/lib64
LIBS+=-lOpenImageIO -lOpenImageIO_Util
CONFIG+=c++14
# Input
SOURCES += PutPixel.cpp
