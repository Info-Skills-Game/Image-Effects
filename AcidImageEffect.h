#pragma once
#ifndef ACID_IMAGE_EFFECT
#define ACID_IMAGE_EFFECT

#include "ImageEffect.h"
#include "Pixel.h"


//this image effect will make the image really damn weird
class AcidImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
    	for(int a = 0; a < 9; a++)
    	{
	        for (int i = 0; i < doc.getHeight(); i++)
	        {
	            for (int j = 0; j < doc.getWidth(); j++)
	            {
	            	int _operations = 0;
	            	int _red_avg = 0;
					Pixel& p = doc.getPixel(i,j);

					if(j < doc.getWidth()-1){
						Pixel right_p = doc.getPixel(i, j+1);
						_red_avg = _red_avg + right_p.getRed();
						_operations++;
					}

					if(j != 0){
						Pixel left_p = doc.getPixel(i, j+1);
						_red_avg = _red_avg + left_p.getRed();
						_operations++;
					}

					_red_avg = _red_avg + p.getRed();
					_operations++;
					_red_avg = _red_avg/_operations;
					p.setRed(_red_avg);

				}
	        }
    	}
    }
};

#endif // !ACID_IMAGE_EFFECT

