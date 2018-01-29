#pragma once
#ifndef VERTICAL_FLIP_IMAGE_EFFECT
#define VERTICAL_FLIP_IMAGE_EFFECT

#include "ImageEffect.h"

//this image effect will flip the photo vertically
class VerticalFlipImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight()/2; i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
				Pixel& p = doc.getPixel(i, j);
				Pixel temp = doc.getPixel(doc.getHeight()-1-i,j);
                doc.setPixel((doc.getHeight()-1-i),j,p);
                doc.setPixel(i,j,temp);
            }
        }
    }
};

#endif // !VERTICAL_FLIP_IMAGE_EFFECT

