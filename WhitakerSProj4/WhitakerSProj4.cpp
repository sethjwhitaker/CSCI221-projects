// WhitakerSProj4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "WhitakerSMoney.h"

using namespace std;

int main() {

	Money m = Money();
    
	// Test >>
	cout << "Testing extraction operator.";
	cout << "\nPlease enter an amount of money in the format: $ddd.cc\n";
	cout << "If negative, enter as: -$ddd.cc\n";

	cin >> m;
	
	// Test <<
	cout << "\nTesting insertion operator.";
	cout << "\nThe next line should be the same as what you input earlier:";
	cout << endl << m;

	cout << "\n\nTesting addition and subtraction operators.";

	// Test +
	cout << "\nThe next line should be what you input earlier + $100.10";

	Money test = Money(100, 10);

	cout << endl << m + test;

	// Test - (subtraction)
	cout << "\nThe next line should be what you input earlier - $100.10";

	cout << endl << m - test;

	// Test - (negation)
	cout << "\n\nTesting negation operator.";
	cout << "\nThe next line should be the negation of what you input earlier";

	cout << endl << -m;

	cout << "\n\nTesting bool operators.";

	// Test ==
	cout << "\nThe next line should be true";

	if (m == m)
		cout << "\nTrue";
	else
		cout << "\nFalse";

	// Test >
	cout << "\nIf " << m << " > " << test << ", then the next line should be true. Otherwise, it should be false.";

	if (m > test)
		cout << "\nTrue";
	else
		cout << "\nFalse";

	// Test <
	cout << "\nIf " << m << " < " << test << ", then the next line should be true. Otherwise, it should be false.";

	if (m < test)
		cout << "\nTrue";
	else
		cout << "\nFalse";

	// Test >=
	cout << "\nIf " << m << " >= " << test << ", then the next line should be true. Otherwise, it should be false.";

	if (m >= test)
		cout << "\nTrue";
	else
		cout << "\nFalse";

	// Test <=
	cout << "\nIf " << m << " <= " << test << ", then the next line should be true. Otherwise, it should be false.";

	if (m <= test)
		cout << "\nTrue";
	else
		cout << "\nFalse";


}