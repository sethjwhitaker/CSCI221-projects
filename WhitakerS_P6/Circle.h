#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {	// Circle class derived from Shape class

public:
	// Constructors set name to "Circle"
	Circle();				// Default constructor sets radius to 0
	Circle(int newRadius);	// Constructor sets radius to newRadius
	
	void setRadius(int newRadius);	// Sets radius to newRadius
	double getRadius();				// Returns radius
	virtual double getArea();		// Returns area of circle (pi*r^2)

private:
	int radius;

};

#endif