#pragma once
#ifndef ADD_NOISE_IMAGE_EFFECT 
#define ADD_NOISE_IMAGE_EFFECT 

#include "ImageEffect.h"

//this image effect will add random noise to the image
class AddNoiseImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
				Pixel& p = doc.getPixel(i, j);
				p.setRed(p.getRed()+(rand() % 20 + -10));
				if (p.getRed() > 255) {
					p.setRed(255);
				}
				else if (p.getRed() < 0) {
					p.setRed(0);
				}

				p.setBlue(p.getBlue()+(rand() % 20 + -10));
				if (p.getBlue() > 255) {
					p.setBlue(255);
				}
				else if (p.getBlue() < 0) {
					p.setBlue(0);
				}

				p.setGreen(p.getGreen()+(rand() % 20 + -10));
				if (p.getGreen() > 255) {
					p.setGreen(255);
				}
				else if (p.getGreen() < 0) {
					p.setGreen(0);
				}
            }
        }
    }

};

#endif // !ADD_NOISE_IMAGE_EFFECT 

