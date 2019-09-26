TARGET = PutPixel 
CONFIG -= app_bundle
DEPENDPATH += .
INCLUDEPATH += .

QMAKE_CFLAGS+=$$system(sdl2-config --cflags )
LIBS+=$$system(sdl2-config  --libs )
LIBS+= -lSDL2_image
# Input
SOURCES += PutPixel.c
