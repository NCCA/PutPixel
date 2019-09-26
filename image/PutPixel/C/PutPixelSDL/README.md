# SDL_image / SDL_Surface

This demo uses SDL2 and the SDL2_image library to write a pixel to a png file. Note that SDL_surface stores pixel data as an array of integers packed as RGBA

There are 3 build methods

We can use the command line and use either clang++ or g++

```
clang `sdl2-config --cflags --libs` -lSDL2_image PutPixel.c -o PutPixel
``` 

The qmake project by either loading with QtCreator or 

```
qmake
make
```

Using cmake

```
cmake CMakeLists.txt
make
```