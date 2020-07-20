#include "Rectangle.h"

// Default constructor initializes width and height to 0 and passes "Rectangle" to Shape constructor
Rectangle::Rectangle() : Shape("Rectangle"), width(0), height(0) {}

// Constructor initializes width to newWidth and height to newHeight and passes "Rectangle to Shape constructor
Rectangle::Rectangle(int newWidth, int newHeight) : Shape("Rectangle"), 
	width(newWidth), height(newHeight) {}

// Accessor function that returns the width 
int Rectangle::getWidth() {

	return width;

}

// Mutator function that sets the width to newWidth
void Rectangle::setWidth(int newWidth) {

	width = newWidth;

}

// Accessor function that returns the height
int Rectangle::getHeight() {

	return height;

}

// Mutator function that sets the height to newHeight
void Rectangle::setHeight(int newHeight) {

	height = newHeight;

}

// Function that returns the area of the rectangle (w*h)
double Rectangle::getArea() {

	// Cast to type double before multiplication to avoid overflow
	return static_cast<double>(width) * static_cast<double>(height);	

}