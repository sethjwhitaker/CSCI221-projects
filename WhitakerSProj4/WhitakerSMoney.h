#include <fstream>

class Money {

public:

	// ---- Constructors ----

	Money();														// Default constructor

	Money(long dollars);											// Constructor for just dollars given

	Money(long dollars, int cents);									// Constructor for dollars and cents given



	// ---- Member Functions ----

	long getDollars() const;										// Get dollar amount of allCents

	int getCents() const;											// Get cents amount of allCents

	double getValue() const;										// Get double value of Money

	Money percent(int p) const;										// Get a percentage of allCents
	// Precondition: p is an integer
	// Postcondition: returns a new Money object with a value of 
	//		p-percent of this Money object (p / 100 * Money)



	// ---- Operators ----

	friend Money operator +(const Money& m1, const Money& m2);		// Addition operator

	friend Money operator -(const Money& m1, const Money& m2);		// Subtraction operator

	friend Money operator -(const Money& m);						// Negation operator

	friend bool operator ==(const Money& m1, const Money& m2);		// Equal to operator

	friend bool operator <(const Money& m1, const Money& m2);		// Less than operator

	friend bool operator >(const Money& m1, const Money& m2);		// Greater than operator

	friend bool operator <=(const Money& m1, const Money& m2);		// Less than or equal to operator

	friend bool operator >=(const Money& m1, const Money& m2);		// Greater than or equal to operator

	friend std::istream& operator >>(std::istream& in, Money& m);	// Extraction operator
	// Precondition: in is connected to a file if it is an fstream
	// Postcondition: overloads the extraction operator to allow 
	//		inputs of values of Money ($100.05 is 100 dollars 
	//		and 5 cents) 

	friend std::ostream& operator <<(std::ostream& out, const Money& m);	// Insertion operator
	// Precondition: out is connected to a file if it is an fstream
	// Postcondition: overloads the insertion operator to allow
	//		outputs of values of Money. Each value is preceded with 
	//		a dollar sign ($100.05)



private:

	long allCents;													// Private member variable that stores the value of money in cents

};
