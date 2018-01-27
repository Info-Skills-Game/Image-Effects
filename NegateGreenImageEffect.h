#pragma once
#ifndef NEGATE_GREEN_IMAGE_EFFECT 
#define NEGATE_GREEN_IMAGE_EFFECT 

#include "ImageEffect.h"

//this image effect will negate all green from a picture
class NegateGreenImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
				Pixel& p = doc.getPixel(i, j);
				p.setGreen(255-p.getGreen());
            }
        }
    }

};

#endif // !NEGATE_GREEN_IMAGE_EFFECT 

