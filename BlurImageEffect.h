#pragma once
#ifndef BLUR_EFFECT
#define BLUR_IMAGE_EFFECT

#include "ImageEffect.h"
#include "Pixel.h"


//this image effect will blur the image
class BlurImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
            	int _operations = 0;
            	int _red_avg = 0;
            	int _green_avg = 0;
            	int _blue_avg = 0;
				Pixel& p = doc.getPixel(i,j);

				if(j < doc.getWidth()-1){
					Pixel right_p = doc.getPixel(i, j+1);
					_red_avg = _red_avg + right_p.getRed();
					_green_avg = _green_avg + right_p.getGreen();
					_blue_avg = _blue_avg + right_p.getBlue();
					_operations++;
				}

				if(j != 0){
					Pixel left_p = doc.getPixel(i, j-1);
					_red_avg = _red_avg + left_p.getRed();
					_green_avg = _green_avg + left_p.getGreen();
					_blue_avg = _blue_avg + left_p.getBlue();
					_operations++;
				}

				_red_avg = _red_avg + p.getRed();
				_green_avg = _green_avg + p.getGreen();
				_blue_avg = _blue_avg + p.getBlue();
				_operations++;

				_red_avg = _red_avg/_operations;
				_green_avg = _green_avg/_operations;
				_blue_avg = _blue_avg/_operations;

				p.setRed(_red_avg);
				p.setGreen(_green_avg);
				p.setBlue(_blue_avg);

			}
        }

        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
            	int _operations = 0;
            	int _red_avg = 0;
            	int _green_avg = 0;
            	int _blue_avg = 0;
				Pixel& p = doc.getPixel(i,j);

				if(i < doc.getHeight()-1){
					Pixel above_p = doc.getPixel(i+1, j);
					_red_avg = _red_avg + above_p.getRed();
					_green_avg = _green_avg + above_p.getGreen();
					_blue_avg = _blue_avg + above_p.getBlue();
					_operations++;
				}

				if(i != 0){
					Pixel below_p = doc.getPixel(i-1, j);
					_red_avg = _red_avg + below_p.getRed();
					_green_avg = _green_avg + below_p.getGreen();
					_blue_avg = _blue_avg + below_p.getBlue();
					_operations++;
				}

				_red_avg = _red_avg + p.getRed();
				_green_avg = _green_avg + p.getGreen();
				_blue_avg = _blue_avg + p.getBlue();
				_operations++;

				_red_avg = _red_avg/_operations;
				_green_avg = _green_avg/_operations;
				_blue_avg = _blue_avg/_operations;
				
				p.setRed(_red_avg);
				p.setGreen(_green_avg);
				p.setBlue(_blue_avg);

			}
        }
    }
};

#endif // !BLUR_IMAGE_EFFECT

