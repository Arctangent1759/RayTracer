#include "ImgWriter.hpp"

//Include your libraries here
using namespace png;

//TODO: Your helper function preambles here

ImgWriter::ImgWriter(int width, int height){
  //TODO: Implement ImgWriter here
  picture = image<rgb_pixel>(width, height);
}

void ImgWriter::setPixel(int x, int y, const Color c){
  //TODO: Implement setPixel here
  picture[picture.get_height()-1-y][x] = rgb_pixel(c.getR(), c.getG(), c.getB());
}

void ImgWriter::write(string filepath){
  //TODO: Implement write here
  picture.write(filepath);
}

//TODO: Your helper functions here
