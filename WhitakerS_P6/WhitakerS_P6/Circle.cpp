#include "Circle.h"

// Default constructor initializes radius to 0 and passes "Circle" to Shape constructor
Circle::Circle() : Shape("Circle"), radius(0) {}

// Constructor that initializes radius to newRadius and passes "Circle" to Shape constructor
Circle::Circle(int newRadius) : Shape("Circle"), radius(newRadius) {}

// Mutator function sets radius to newRadius
void Circle::setRadius(int newRadius) {

	radius = newRadius;

}

// Accessor function returns radius
double Circle::getRadius() {

	return radius;

}

// Get area function returns the area of the circle (pi*r^2)
double Circle::getArea() {

	return 3.14159 * radius * radius;

}

