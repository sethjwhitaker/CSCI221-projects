#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape {

public:
	Shape(); // Default Constructor: sets name to empty string
	Shape(string newName); // Constructor: sets name to newName

	string getName();	// Returns name
	void setName(string newName);	// Sets name
	virtual double getArea() = 0;	// Returns area of shapes derived from this class

private:
	string name;

};

#endif