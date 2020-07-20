#include "Shape.h"

using namespace std;

// Default constructor that initializes name to an empty string
Shape::Shape() : name("") {}

// Constructor that initializes name to newName
Shape::Shape(string newName) : name(newName) {}

// Accessor function that returns name
string Shape::getName() {

	return name;

}

// Mutator function that sets name to newName
void Shape::setName(string newName) {

	name = newName;

}