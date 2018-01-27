#pragma once
#ifndef GRAYSCALE_IMAGE_EFFECT 
#define GRAYSCALE_IMAGE_EFFECT 

#include "ImageEffect.h"

//this image effect will add a gray filter to the image
class GrayscaleImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
				Pixel& p = doc.getPixel(i, j);
				int pxlAvg = ((p.getBlue() + p.getRed() + p.getGreen()) / 3);
				p.setRed(pxlAvg);
				p.setBlue(pxlAvg);
				p.setGreen(pxlAvg);
            }
        }
    }

};

#endif // !GRAYSCALE_IMAGE_EFFECT 

