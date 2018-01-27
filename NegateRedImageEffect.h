#pragma once
#ifndef NEGATE_RED_IMAGE_EFFECT 
#define NEGATE_RED_IMAGE_EFFECT 

#include "ImageEffect.h"

//this image effect will negate all red from a picture
class NegateRedImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
				Pixel& p = doc.getPixel(i, j);
				p.setRed(255-p.getRed());
            }
        }
    }

};

#endif // !NEGATE_RED_IMAGE_EFFECT 

