######################################################################
# Automatically generated by qmake (2.01a) Thu Jan 24 19:42:29 2013
######################################################################

TARGET = PutPixel 
CONFIG -= app_bundle
DEPENDPATH += .
INCLUDEPATH += .

QMAKE_CXXFLAGS+=$$system(Magick++-config --cppflags )
LIBS+=$$system(Magick++-config --ldflags --libs )
CONFIG+=c++14
# Input
SOURCES += PutPixel.cpp
