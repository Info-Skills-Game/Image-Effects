#pragma once
#ifndef BLUR_EFFECT
#define BLUR_IMAGE_EFFECT

#include "ImageEffect.h"
#include "Pixel.h"


//this image effect will rotate the photo 90 degrees
class BlurImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
				int red_avg = 0;
				int green_avg = 0;
				int blue_avg = 0;
				int operations = 0;
				
				Pixel& p = doc.getPixel(i, j);
				Pixel left_pixel = doc.getPixel(i,j+1);
				Pixel right_pixel = doc.getPixel(i,j-1);
				
				if(j < doc.getWidth()){
					red_avg = red_avg + right_pixel.getRed();
					green_avg = green_avg + right_pixel.getGreen();
					blue_avg = blue_avg + right_pixel.getBlue();
					operations++;
				}
				
				if(j != 0){
					red_avg = red_avg + left_pixel.getRed();
					green_avg = green_avg + left_pixel.getGreen();
					blue_avg = blue_avg + left_pixel.getBlue();
					operations++;
				}
				
				red_avg = red_avg + p.getRed();
				green_avg = green_avg + p.getGreen();
				blue_avg = blue_avg + p.getBlue();
				
				operations++;
				
				red_avg = red_avg/operations;
				green_avg = green_avg/operations;
				blue_avg = blue_avg/operations;
				
				p.setRed(red_avg);
				p.setGreen(green_avg);
				p.setBlue(blue_avg);
			}
        }
		
		/*
		for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
				int red_avg = 0;
				int green_avg = 0;
				int blue_avg = 0;
				int operations = 0;
				
				Pixel& p = doc.getPixel(i, j);

				Pixel above_pixel = doc.getPixel(i+1,j);
				Pixel below_pixel = doc.getPixel(i-1,j);
				
				if(i > 0){
					red_avg = red_avg + below_pixel.getRed();
					green_avg = green_avg + below_pixel.getGreen();
					blue_avg = blue_avg + below_pixel.getBlue();
					operations++;
				}
				
				if(i < doc.getHeight()-1){
					red_avg = red_avg + above_pixel.getRed();
					green_avg = green_avg + above_pixel.getGreen();
					blue_avg = blue_avg + above_pixel.getBlue();
					operations++;
				}
				
				red_avg = red_avg + p.getRed();
				green_avg = green_avg + p.getGreen();
				blue_avg = blue_avg + p.getBlue();
				
				operations++;
				
				red_avg = red_avg/operations;
				green_avg = green_avg/operations;
				blue_avg = blue_avg/operations;
				
				p.setRed(red_avg);
				p.setGreen(green_avg);
				p.setBlue(blue_avg);
			}
        }
		*/
    }
};

#endif // !BLUR_IMAGE_EFFECT

