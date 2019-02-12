#include "Antialiasing.h"
#include "of3dGraphics.h"
#include "ofImage.h"
Antialiasing::Antialiasing()
{
}


Antialiasing::~Antialiasing()
{
}

double Antialiasing::functionFromBook(double x, double y) {
	return ((.5)*(1 + sin(x*x*y*y)));
}
double Antialiasing::startAntialiasingMethod1(int numPixels, double x, double y, double dx, double dy) {
	double darkness = 0;
	for (int i = 0; i < numPixels; i++) {
		double r = ((double)rand() / (RAND_MAX+1));
		double sampleX = x + r * (dx*8/9);
		r = ((double)rand() / (RAND_MAX+1));
		double sampleY = y + r * (dy*8/9);
		darkness += functionFromBook(sampleX, sampleY);
	}
	return (darkness / numPixels);
}
ofImage Antialiasing::calculatePixels(double minX, double maxX, double minY, double maxY,
	ofImage img, bool antialiasingEnabled) {
	double pixelWidth = img.getWidth();
	double pixelHeight = img.getHeight();
	double dx = (maxX - minX) / pixelWidth;
	double dy = (maxY - minY) / pixelHeight;
	ofPixels& pixels = img.getPixels();

	for (double i = minY; i < maxY; i += dy) {
		for (double j = minX; j < maxX; j+=dx) {
			double darkness;
			if(!antialiasingEnabled) darkness= functionFromBook(j, i);
			else darkness = startAntialiasingMethod1(20, j, i, dx, dy);
			ofColor color(darkness*255);
			int pixelXVal = (j / maxX) * pixelWidth;
			int pixelYVal = (i / maxY) * pixelHeight;
			pixels.setColor(pixelXVal, pixelYVal, color);
		}
	}
	img.update();
	return img;
}