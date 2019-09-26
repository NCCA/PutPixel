# ImageMagick

This demo uses the ImageMagick C++ API to write a char buffer to disk. It is using modern C++ including smart pointers.

There are 3 build methods

We can use the command line and use either clang++ or g++

```
clang++ -std=c++14 `Magick++-config --cflags --libs` PutPixel.cpp -o PutPixel
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