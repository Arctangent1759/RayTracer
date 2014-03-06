#ifndef IMGWRITER_H
#define IMGWRITER_H

#include "Color.hpp"

#include "png++/png.hpp"

class ImgWriter{
  public:

    /**
     *
     * Creates an image writer for an width by height image
     * @parm width the width of the image to be written
     * @parm height the height of the image to be written
     * 
     **/
    ImgWriter(int width, int height);

    /**
     *
     * Sets the pixel located at (x,y) to color c.
     *
     * @param x the x coordinate of the pixel, on range [0,width)
     * @param y the y coordinate of the pixel, on range [0,height)
     * @param c the c color pixel. Contains floats x,y,z.
     *
     **/
    void setPixel(int x,int y, const Color c);

    /**
     *
     * Writes the image to the file located at filepath.
     * @param filepath the file to write to
     *
     **/
    void write(string fileName);
  protected:
    //Use this space as needed. Just implement the interface.
    png::image<png::rgb_pixel> picture;
};

#endif
