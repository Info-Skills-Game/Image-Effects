#pragma once
#ifndef PIXELATE_IMAGE_EFFECT
#define PIXELATE_IMAGE_EFFECT

#include "ImageEffect.h"

//this image effect will rotate the photo 90 degrees
class PixelateImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
				Pixel& p = doc.getPixel(i, j);

            }
        }
    }
};

#endif // !PIXELATE_IMAGE_EFFECT

