# OpenImageIO

This demo uses the [OpenImageIO](https://github.com/OpenImageIO/oiio) C++ library it is the recommended library to use for VfX work as it used with many DCC tools and projects.

There are 3 build methods

We can use the command line and use either clang++ or g++ (this assumes a default install)

```
clang++ -std=c++14 PutPixel.cpp -lOpenImageIO -lOpenImageIO_Util -o PutPixel
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