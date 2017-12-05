/*
    image.h

    Copyright (C) 2013 by Don Cross  -  http://cosinekitty.com/raytrace

    This software is provided 'as-is', without any express or implied
    warranty. In no event will the author be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
       claim that you wrote the original software. If you use this software
       in a product, an acknowledgment in the product documentation would be
       appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
       misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
       distribution.

    -------------------------------------------------------------------------

    Example of overriding the surface optics to make a variety of colors
    on the surface of a single solid object.
    Implements a image board with alternately colored squares.
    The checkered part has a common width and height, along with
    a separate border dimension in the x and y directions.
    The board has a thickness too.  The sides and bottom of the board
    have the same color as the border around the top.
*/

#ifndef __DDC_IMAGER_IMAGE_H
#define __DDC_IMAGER_IMAGE_H

#include "imager.h"
#include "lodepng.h"
#include <iostream>

namespace Imager
{
    class Image: public Cuboid
    {
    public:
        Image(
            double _innerSize,
            double _xBorderSize,
            double _yBorderSize,
            double _thickness,
            const Color&_borderColor,
            const char* _texture);

    protected:
        // This method override provides the variety of colors
        // for the light squares, dark squares, and border.
        virtual Optics ObjectSpace_SurfaceOptics(
            const Vector& surfacePoint,
            const void *context) const;

        int SquareCoordinate(double xy) const;

        void LoadTexture(const char* filename)
        {
            //std::vector<unsigned char> image; //the raw pixels

            //std::cout << "-" << std::endl;
            //decode
            unsigned error = lodepng::decode(texture, width, height, filename);

            //if there's an error, display it
            if(error)
            {
                std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
                //return image;
            }


            //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
            //Image::texture = image;
        }

    private:
        double innerSize;
        double xBorderSize;
        double yBorderSize;
        double thickness;
        const Color&borderColor;
        std::vector <unsigned char> texture;
        unsigned width, height;
    };
}

#endif // __DDC_IMAGER_IMAGE_H
