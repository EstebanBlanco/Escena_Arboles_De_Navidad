/*
    image.cpp

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
*/

//#include <cmath>
#include <math.h>
#include "image.h"

namespace Imager
{
    Image::Image(
        double _innerSize,
        double _xBorderSize,
        double _yBorderSize,
        double _thickness,
        const Color&_borderColor,
        const char* _texture)
            : Cuboid(
                _innerSize/2.0 + _xBorderSize,
                _innerSize/2.0 + _yBorderSize,
                _thickness/2.0)
            , innerSize(_innerSize)
            , xBorderSize(_xBorderSize)
            , yBorderSize(_yBorderSize)
            , thickness(_thickness)
            , borderColor(_borderColor)
    {
        //std::cout << "." << std::endl;
        Image::LoadTexture(_texture);
        //std::cout << "." << std::endl;
    }


    int Image::SquareCoordinate(double xy) const
    {
        double s = floor(8.0 * (xy/innerSize + 0.5));
        if (s < 0.0)
        {
            return 0;
        }
        else if (s > 7.0)
        {
            return 7;
        }
        else
        {
            return static_cast<int>(s);
        }
    }


    Optics Image::ObjectSpace_SurfaceOptics(
        const Vector& surfacePoint,
        const void *context) const
    {
        // Start with the uniform optics this class inherits,
        // and modify the colors as needed.
        // This allows us to inherit gloss, refraction, etc.
        Optics optics = GetUniformOptics();

        // First figure out which part of the board this is.
        // If the t-coordinate (z in class Vector)
        // is significantly below the top surface,
        // use the border color.
        if (surfacePoint.z < thickness/2.0 - EPSILON)
        {
            optics.SetMatteColor(borderColor);
        }
        else
        {
            const double half = innerSize / 2.0;

            // Assume this is on the top surface of the board.
            // Figure out whether we are inside the checkered part.
            if (fabs(surfacePoint.x) < half &&
                fabs(surfacePoint.y) < half)
            {
                // We are definitely inside the checkered part
                // of the top surface.
                // Figure out which square we are on, so we
                // can in turn figure out whether it is a light or
                // dark square, so we know how to color it.
                const double x = surfacePoint.x;//SquareCoordinate(surfacePoint.x);
                const double y = surfacePoint.y;//SquareCoordinate(surfacePoint.y);
                int surface = 2*half, r,g,b;
                //std::cout << texture.size() << std::endl;
                //std::cout << width << std::endl;
                int yPos = round(((1-(((double)y+(double)half)/(double)surface))*(double)height))*(double)width*4;
                int xPos = round(((1-((double)x+(double)half)/(double)surface))*(double)width)*4;
                //std::cout << yPos+xPos << std::endl;
                r = (int)texture[yPos+xPos];
                //std::cout << yPos+xPos+1 << std::endl;
                g = (int)texture[yPos+xPos+1];
                //std::cout << yPos+xPos+2 << std::endl;
                b = (int)texture[yPos+xPos+2];
                //std::cout << "/" << std::endl;
                //std::cout << r << " | " << g << " | " << b << std::endl;
                optics.SetMatteColor(Color((double)r/(double)255,(double)g/(double)255,(double)b/(double)255));
            }
            else
            {
                // Outside the checkered part, so use border color.
                optics.SetMatteColor(borderColor);
            }
        }

        return optics;
    }
}
