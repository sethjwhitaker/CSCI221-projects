#include <fstream>
#include <iostream>

#include "WhitakerSMoney.h"


// ---- Helper Functions -----

namespace {

	// Returns the dollar value of an amount of cents
	long dollarsFromCents(long cents) {

		return cents / 100;

	}

	// Returns the leftover cents value of an amount of cents when the dollars are removed
	int centsFromCents(long cents) {

		return cents % 100;

	}

	// Returns true if c is a digit and false otherwise
	bool isDigit(char c) {

		if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
			|| c == '6' || c == '7' || c == '8' || c == '9' || c == '0')
			return true;
		else
			return false;

	}

	// Returns an integer containing the digit in c
	// Precondition: c is a digit
	int digitToInt(char c) {

		return c - '0';

	}

}



// ---- Constructors ----

// Default constructor. Sets allCents to 0
Money::Money() {

	allCents = 0;

}

// Constructor used when just a dollar amount is given
Money::Money(long dollars) {

	allCents = dollars * 100;

}

// Constructor used when a dollar amount and a cents amount are given
Money::Money(long dollars, int cents) {

	allCents = dollars * 100 + cents;

}



// ---- Member Functions ----

// Accessor function that returns the dollar value stored in this money object
long Money::getDollars() const {

	return dollarsFromCents(allCents);

}

// Accessor function that returns the cents value stored in this money object
int Money::getCents() const {

	return centsFromCents(allCents);

}

// Accessor funtion that returns the value stored as type double
double Money::getValue() const {

	return static_cast<double>(dollarsFromCents(allCents)) + static_cast<double>(centsFromCents(allCents)/100.0);

}


// Member function that returns a new Money object that contains the value of p-percent of this Money object
Money Money::percent(int p) const {

	long newCents = allCents * (p / 100.0);

	return Money(0, newCents);

}



// ---- Operators ----

// Returns a new Money object containing the sum of 2 Money objects
Money operator +(const Money& m1, const Money& m2) {

	long newCents = m1.allCents + m2.allCents;

	return Money(0, newCents);

}

// Returns a new Money object containing the difference between 2 Money objects
Money operator -(const Money& m1, const Money& m2) {

	long newCents = m1.allCents - m2.allCents;

	return Money(0, newCents);

}

// Returns a new Money object containing the negation of a Money object
Money operator -(const Money& m) {

	long newCents = -1 * m.allCents;

	return Money(0, newCents);

}

// Returns true if two Money objects are equal
bool operator ==(const Money& m1, const Money& m2) {

	return m1.allCents == m2.allCents;

}

// Returns true if the left Money object is less than the right Money object
bool operator <(const Money& m1, const Money& m2) {

	return m1.allCents < m2.allCents;

}

// Returns true if the left Money object is greater than the right Money object
bool operator >(const Money& m1, const Money& m2) {

	return m1.allCents > m2.allCents;

}

// Returns true if the left Money object is less than or equal to the right Money object
bool operator <=(const Money& m1, const Money& m2) {

	return m1.allCents <= m2.allCents;

}

// Returns true if the left Money object is greater than or equal to the right Money object
bool operator >=(const Money& m1, const Money& m2) {

	return m1.allCents >= m2.allCents;

}

// Extracts money value from istream and inputs into m 
// Requires input to be in the format: $ddd.cc 
// or if negative: -$ddd.cc
std::istream& operator >>(std::istream& in, Money& m) {

	char c, d, tenCent, oneCent;
	bool isNegative = false;
	long dollars;

	in >> c;

	if (c == '-') {				// Check if negative

		isNegative = true;
		in >> c;

	} else {

		isNegative = false;

	}	

	in >> dollars >> d >> tenCent >> oneCent;	// Extract data

	if (c != '$' || d != '.' || !isDigit(tenCent) || !isDigit(oneCent)) {	// Check formatting

		std::cout << "\nInvalid input format. Please input money values as such: $100.53\nIf negative, input as -$100.53\n";

	} else {					// If format is correct, then it is safe to input into m

		if (isNegative)
			dollars *= -1;

		m.allCents = dollars * 100 + digitToInt(tenCent) * 10 + digitToInt(oneCent);

	}

	return in;

}

// Inserts money value in ostream in the format $ddd.cc
std::ostream& operator <<(std::ostream& out, const Money& m) {

	long cents = m.allCents;

	if (cents < 0) {		// Check if a negative sign is necessary

		cents *= -1;
		out << '-';

	}

	out << '$';
	out << dollarsFromCents(cents);
	out << '.';
	
	if (centsFromCents(cents) < 10)	// Make sure that digits are formatted correctly on right side of decimal
		out << '0';
	out << centsFromCents(cents);

	return out;

}