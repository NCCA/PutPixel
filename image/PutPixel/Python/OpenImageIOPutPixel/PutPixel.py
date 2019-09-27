#!/usr/bin/env python

from __future__ import print_function # python 3 style printing
import OpenImageIO as oiio

width=100
height=100
channels=3
# build our image specification
spec= oiio.ImageSpec(width,height, channels,oiio.UINT8)
# create a buffer for out image data
buf=oiio.ImageBuf(spec)

oiio.ImageBufAlgo.fill (buf, (255,255,255))

# set top left to red
buf.setpixel(0,0,(255,0,0));
# next green
buf.setpixel(1,0,(0,255,0));
# and blue
buf.setpixel(2,0,(0,0,255));



buf.write('PutPixel.png')





