#pragma once
#ifndef ROTATE_IMAGE_EFFECT
#define ROTATE_IMAGE_EFFECT

#include "ImageEffect.h"

//this image effect will rotate the photo 90 degrees
class RotateImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
				Pixel& p = doc.getPixel(i, j);
				Pixel temp0 = doc.getPixel((doc.getHeight()-1-i),j);
				doc.setPixel((doc.getHeight()-1-i),j,p);
				Pixel temp1 = doc.getPixel((doc.getHeight()-1-i),(doc.getWidth()-j));
				doc.setPixel((doc.getHeight()-1-i),(doc.getWidth()-j),temp0);
				Pixel temp2 = doc.getPixel(i,(doc.getWidth()-j));
				doc.setPixel(i,(doc.getWidth()-j),temp1);
				doc.setPixel(i,j,temp1);
            }
        }
		int temp = doc.getHeight();
		doc.setHeight(doc.getWidth());
		doc.setWidth(temp);
    }
};

#endif // !ROTATE_IMAGE_EFFECT

