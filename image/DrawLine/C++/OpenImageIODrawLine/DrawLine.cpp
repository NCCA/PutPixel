// clang++ -std=c++14 DrawLine.cpp -lOpenImageIO -lOpenImageIO_Util -o DrawLine
#include <memory>
#include <string>
#include <OpenImageIO/imageio.h>
#include <OpenImageIO/imagebuf.h>
#include <OpenImageIO/imagebufalgo.h>



int main( int argc, char* argv[] )
{
  constexpr unsigned int           WIDTH     = 100;
  constexpr unsigned int           HEIGHT    = 100;
  using namespace OIIO;

  const int channels = 3; // RGB
  ImageSpec spec (WIDTH, HEIGHT, channels, TypeDesc::UINT8);
  auto buf=ImageBuf(spec);
  // note the algorithms use float values for parameters, here we create an array of 1,1,1 
  ImageBufAlgo::fill(buf,{1.0f,1.0f,1.0f});
//  This uses the same dimensions and co-ordinates as the image
//  first draw from top left to bottom right using red

  ImageBufAlgo::render_line(buf, 0, 0, WIDTH, HEIGHT, {1.0f,0.0f,0.0f});
  // now the other diagonal in green
  ImageBufAlgo::render_line(buf, WIDTH, 0, 0, HEIGHT, {0.0f,1.0f,0.0f});
  // horizontal  in blue
  ImageBufAlgo::render_line(buf, 0,HEIGHT/2,WIDTH,HEIGHT/2, {0.0f,0.0f,1.0f});
  // vertical in  black
  ImageBufAlgo::render_line(buf, WIDTH/2,0,WIDTH/2,HEIGHT, {0.0f,0.0f,0.0f});

  buf.write("DrawLine.png");
}