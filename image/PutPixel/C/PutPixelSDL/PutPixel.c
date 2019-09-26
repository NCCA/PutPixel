// clang `sdl2-config --cflags --libs` -lSDL2_image PutPixel.c -o PutPixel
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>

// function to set pixels
void setPixel(SDL_Surface *surface, int x, int y, unsigned char _red, unsigned char _green, unsigned char _blue);

int main()
{
  // Initialize SDL's Video subsystem
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    // Or die on error
    printf("Unable to initialize SDL");
    exit(EXIT_FAILURE);
  }
  const int width=100;
  const int height=100;
  // these masks represent the different pixel values for the 32 bit int used to store the image
  unsigned int rmask = 0x000000ff;
  unsigned int gmask = 0x0000ff00;
  unsigned int bmask = 0x00ff0000;
  unsigned int amask = 0xff000000;
  // create a surface 
  SDL_Surface *surface = SDL_CreateRGBSurface(0, width, height, 32,rmask, gmask, bmask, amask);
  // we are now going to set all the pixels to 255 for white using a memset
  // if we need other colours we need to use SDL_FillRect
  SDL_memset(surface->pixels, 255, surface->h * surface->pitch);
  // make sure the surface was created
  if (surface == NULL) 
  {
    SDL_Log("SDL_CreateRGBSurface() failed: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  // set the pixel at the top left (0,0) to Red
  setPixel(surface,0,0,255,0,0);
  // set the next pixel to green
  setPixel(surface,1,0,0,255,0);
  // and blue
  setPixel(surface,2,0,0,0,255);
  // save the image as a PNG note this is a hard coded function if you want another image format
  // you will have to use the other functions in SDL2_image.
  IMG_SavePNG(surface, "PutPixel.png");
  // clean up the surface.
  SDL_FreeSurface(surface);
  exit(EXIT_SUCCESS);
}



void setPixel(SDL_Surface *surface, int x, int y, unsigned char _red, unsigned char _green, unsigned char _blue)
{
  // get an index into the pixel data, we are using an offset of 4 as RGBA data encoded into an int
  Uint8 *index = (Uint8 *)surface->pixels + y * surface->pitch + x * 4;
  // now we pack the pixel data by ORing and shifting the char data
  //    24    16    8      0
  // [alpha][blue][green][red] 

  unsigned int pixel=_red | (_green << 8) | (_blue << 16) | (255 << 24);
  *(Uint32 *)index = pixel;
}