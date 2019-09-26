#include <Magick++.h>
#include <string.h> // for memset
#include <iostream>
#include <cstdlib>
#include <memory>
#include <algorithm>


int main()
{
  constexpr unsigned int           WIDTH     = 100;
  constexpr unsigned int           HEIGHT    = 100;
  constexpr auto                   imageSize = WIDTH * HEIGHT * 3 * sizeof(unsigned char);
  // c++ 14 we are going to use a smart pointer to create a buffer for our pixel data
  // this will clear up once finished this is a contiguous block of memort.
  auto image=std::make_unique<unsigned char []>(imageSize);
  // set all the pixels to 255 to make the image white. Note that is you need coloured background you will
  // need to set each pixel not use memset!
  memset(image.get(),255,imageSize);
  // set pixel as lambda this function gets the x,y offset into the buffer and sets the pixel values
  auto setPixel = [&image](size_t _x, size_t _y, unsigned char _r, unsigned char _g, unsigned char _b)
  {
    size_t index           = (_y * WIDTH * 3) + _x * 3;
    image.get()[index]     = _r;
    image.get()[index + 1] = _g;
    image.get()[index + 2] = _b;
  };

  // set top left pixel (0,0)to Red 
  setPixel(0,0,255,0,0);
  // set next pixel (1,0)to Green 
  setPixel(1,0,0,255,0);
  // set next pixel (2,0)to Blue 
  setPixel(2,0,0,0,255);
  
  // we now write the image using ImageMagick 
 	Magick::Image output(WIDTH,HEIGHT,"RGB",Magick::CharPixel,image.get());
	output.depth(16);
  output.write("PutPixel.png");
	return EXIT_SUCCESS;
}
