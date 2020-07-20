
#include "Circle.h"
#include "Rectangle.h"

#include <iostream>
#include <string>
using namespace std;

void outputCircle(Circle& c);

void outputRectangle(Rectangle& r);

int main() {

	// Test Circle constructor
	int r;

	// Get radius from user
	cout << "\nEnter integer radius of a circle: ";
	cin >> r;

	Circle c = Circle(r);

	// Output name, radius and area
	// Tests accessors and getArea
	outputCircle(c);

	// Test the mutator functions
	// Get radius again
	cout << "\nEnter another integer radius of a circle: ";
	cin >> r;

	c.setRadius(r);

	// Output name radius and area again (should be different)
	outputCircle(c);


	// Test Rectangle constructor
	int w, h;

	// Get dimensions from user
	cout << "\nEnter integer width and height: ";
	cin >> w >> h;

	Rectangle rec = Rectangle(w, h);
	
	// Output name, dimensions, and area
	// Tests accessors and getArea
	outputRectangle(rec);

	// Test mutator functions

	// Get new dimensions from user
	cout << "\nEnter new integer width and height: ";
	cin >> w >> h;

	rec.setWidth(w);

	rec.setHeight(h);

	// Output data again, should be different
	outputRectangle(rec);

	return 0;
}

// Outputs the name, radius, and area of a circle c
void outputCircle(Circle& c) {

	cout << c.getName() << " has radius " << c.getRadius() << " and area " << c.getArea();

}

// Outputs the name, width, height, and area of a rectangle r
void outputRectangle(Rectangle& r) {

	cout << r.getName() << " has width " << r.getWidth() << ", has height " << r.getHeight() << ", and has area " << r.getArea();

}