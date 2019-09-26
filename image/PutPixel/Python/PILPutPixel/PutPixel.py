#!/usr/bin/env python

from __future__ import print_function # python 3 style printin
from PIL import Image # import the Python Image Library

# Set the size of the image (width,height)
size=(100,100)
# we now create a new image and set all the pixels to white
image = Image.new('RGB', size, color = 'white')
print("Width {} Height {} ".format(image.height,image.width ))

# image can access pixels directly using the putpixel method (not this is slow)
# Parameter 0 is the location of the pixel with 0,0 being top left, we then pass an RGB(A) Tuple
# with 0 being off and 255 being full for each channel.
# In this case we set Pixel 0,0 to Red
image.putpixel( (0,0) ,(255,0,0) )
# we can also get a PixelAccess object and manipulate it directly
pixels=image.load()
# We will now set the pixel at 1,0 to green
pixels[1,0]=(0,255,0)
# We will now set the pixel at 2,0 to blue
pixels[2,0]=(0,0,255)
# finally save image to a file (not image type is inferred from the extension)
image.save('putpixel.png')


