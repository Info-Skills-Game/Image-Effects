#pragma once
#ifndef NEGATE_BLUE_IMAGE_EFFECT 
#define NEGATE_BLUE_IMAGE_EFFECT 

#include "ImageEffect.h"

//this image effect will negate all blue from a picture
class NegateBlueImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
				Pixel& p = doc.getPixel(i, j);
				p.setBlue(255-p.getBlue());
            }
        }
    }

};

#endif // !NEGATE_BLUE_IMAGE_EFFECT 

