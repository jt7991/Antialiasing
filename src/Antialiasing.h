#pragma once
#include <math.h>
#include "of3dGraphics.h"
#include "ofImage.h"
class Antialiasing
{
public:
	Antialiasing();
	~Antialiasing();
	double functionFromBook(double x, double y);
	double startAntialiasingMethod1(int numPixels, double x, double y, double dx, double dy);
	ofImage calculatePixels(double minX, double maxX, double minY, double maxY, ofImage img, bool antialiasingEnabled);
};

