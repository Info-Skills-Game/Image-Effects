#pragma once
#ifndef HORIZONTAL_FLIP_IMAGE_EFFECT
#define HORIZONTAL_FLIP_IMAGE_EFFECT

#include "ImageEffect.h"

//this image effect will negate all blue from a picture
class HorizontalFlipImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth()/2; j++)
            {
				Pixel& p = doc.getPixel(i, j);
				Pixel temp = doc.getPixel(i,(doc.getWidth()-j));
                doc.setPixel(i,(doc.getWidth()-j),p);
                doc.setPixel(i,j,temp);
            }
        }
    }
};

#endif // !HORIZONTAL_FLIP_IMAGE_EFFECT

