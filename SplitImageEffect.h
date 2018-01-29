#pragma once
#ifndef VERTICAL_SPLIT_IMAGE_EFFECT
#define VERTICAL_SPLIT_IMAGE_EFFECT

#include "ImageEffect.h"

//this image effect will make the image weird
class VerticalSplitImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth()/2; j++)
            {
				Pixel& p = doc.getPixel(i, j);
				Pixel& temp = doc.getPixel(i,(doc.getWidth()-j));
                doc.setPixel(i,(doc.getWidth()-j),p);
                doc.setPixel(i,j,temp);
            }
        }
    }

};

#endif // !VERTICAL_SPLIT_IMAGE_EFFECT

