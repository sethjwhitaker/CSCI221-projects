#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {

public:
	// Constructors set name to "Rectangle"
	Rectangle();	// Default constructor initializes height and width to 0
	Rectangle(int newWidth, int newHeight);	// Constructor initializes width to newWidth and height to newHeight

	int getWidth();					// Returns the width
	void setWidth(int newWidth);	// Sets the width to newWidth
	int getHeight();				// Returns the height
	void setHeight(int newHeight);	// Sets height to newHeight
	virtual double getArea();		// Returns the area of the rectangle (w*h)


private:
	int width;
	int height;

};

#endif