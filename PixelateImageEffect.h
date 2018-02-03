#pragma once
#ifndef PIXELATE_IMAGE_EFFECT
#define PIXELATE_IMAGE_EFFECT

#include "ImageEffect.h"

//this image effect will give the image a pixelated effect
class PixelateImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        int size = 4; //Set to whatever pixel size you want
        for (int i = 0; i < doc.getHeight(); i+=size)
        {
            for (int j = 0; j < doc.getWidth(); j+=size)
            {
                //Grab the Holy Source Pixel
				Pixel& p = doc.getPixel(i, j);

                if((i < doc.getHeight()-(size-1)) && (j < doc.getWidth()-(size-1)))
                {
                    for(int k = 0; k < size; k++)
                    {
                        for(int l = 0; l < size; l++)
                        {
                            doc.setPixel(i+k,j+l,p);
                        }
                    }
                }
            }
        }
    }
};

#endif // !PIXELATE_IMAGE_EFFECT

