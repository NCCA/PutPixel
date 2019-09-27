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
# This uses the same dimensions and co-ordinates as the image
# first draw from top left to bottom right using red

oiio.ImageBufAlgo.render_line(buf, 0, 0, width, height, (255,0,0))
# now the other diagonal in green
oiio.ImageBufAlgo.render_line(buf, width, 0, 0, height, (0,255,0))
# horizontal  in blue
oiio.ImageBufAlgo.render_line(buf, 0,image.height/2,image.width,image.height/2, (0,0,255))
# vertical in  black
oiio.ImageBufAlgo.render_line(buf, image.width/2,0,image.width/2,image.height, (255,0,0))





