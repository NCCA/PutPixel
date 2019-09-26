# PutPixel (a curated repository of simple graphics demos)

The idea behind this repository is to gather together the simplest demos to draw graphics primitives using a number of languages and libraries. The repository is split into three core areas 

- image (writing to image files)
- screen (displaying to a framebuffer / screen window)
- web (drawing into a webpage)

Within each of these directories we will have folders for different programming languages and then for demos with different libraries.

## Basic Demo Structure

## PutPixel

The PutPixel demos will create an image buffer 100x100 using RGB pixels in the range of 0-255 (char pixels)

It will set all the pixels to White (255,255,255) then set the pixel at 0,0 (top left) to Red, the next to green and then blue.

More complex demos will be presented to use floating point images (HDRI) and RGBA images.

## DrawLine

These demos will use any of the built in line drawing functions the library has to draw a series of lines.