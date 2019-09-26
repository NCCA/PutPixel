#!/usr/bin/env python

from __future__ import print_function # python 3 style printin
from PIL import Image,ImageDraw # import the Python Image Library

# Set the size of the image (width,height)
size=(100,100)
# we now create a new image and set all the pixels to white
image = Image.new('RGB', size, color = 'white')
print("Width {} Height {} ".format(image.height,image.width ))
#  create an instance of the ImageDraw Module called canvas
canvas=ImageDraw.Draw(image)
# This uses the same dimensions and co-ordinates as the image
# first draw from top left to bottom right using red
canvas.line((0,0,image.height,image.width),(255,0,0))
# now the other diagonal in green
canvas.line((image.width,0,0,image.height),(0,255,0))
# horizontal  in blue
canvas.line((0,image.height/2,image.width,image.height/2),(0,0,255))
# vertical in  black
canvas.line((image.width/2,0,image.width/2,image.height),(0,0,0))

# finally save image to a file (not image type is inferred from the extension)
image.save('drawline.png')


