#include <iostream>
#include <string>

using namespace std;

class TimeFormatMistake {
public:
	TimeFormatMistake();
	TimeFormatMistake(string s);
	string getInputString();
	void displayErrorMessage();

private:
	string inputString;

};

void verifyInput(string input) throw(TimeFormatMistake);

void standardTime(int hour, int minute);

bool isDigit(char c);

int digitToInt(char c);

int main() {

	char c = 'y';

	while (c != 'N' && c != 'n') {	// Check if user wants to repeat

		string input;

		// Get 24-hour time from user
		cout << "Enter time in 24-hour notation: ";
		getline(cin, input);
		
		// Convert 24-hour time to standard time
		try {

			verifyInput(input);	// Verify and convert

			cout << "Would you like to try again? (Y/N): ";
			cin >> c;

		} catch (TimeFormatMistake e) {	// Incorrect format exception is caught here

			e.displayErrorMessage();	// Display error message

			cout << "Try again\n";

		}


	}
}

// Default Constructor for TimeFormatMistake class. Preferably, a string should be provided on instantiation
TimeFormatMistake::TimeFormatMistake() {

	inputString = "";

}

// Constructor for TimeFormatMistake class. Accepts the incorrecty formatted input as a string.
TimeFormatMistake::TimeFormatMistake(string s) {

	inputString = s;

}

// Accessor method that returns the input string
string TimeFormatMistake::getInputString() {

	return inputString;

}

// Method that displays an error message to standard output that incorporates the input string
void TimeFormatMistake::displayErrorMessage() {

	cout << "There is no such time as " << inputString << "\n";

}

// Function that verifies if the time input string is formatted correctly.
// If input is formatted correctly, calls standard time function. Otherwise, throws an exception.
// Correct format is length 4-5, with : between hour and minute. Hour must be between 0 and 23 (inclusive)
// and minute must be between 0 and 59 (inclusive) Example: 22:47
void verifyInput(string input) throw(TimeFormatMistake) {

	int hour = 0, minute = 0;

	if (input.length() == 5) {	// Check if length 5

		// Check to see if characters are digits or : and throw exception if not
		if (!isDigit(input[0]) || !isDigit(input[1]) || input[2] != ':' || !isDigit(input[3]) || !isDigit(input[4]))
			throw(TimeFormatMistake(input));

		// Convert to hours and minutes
		hour += digitToInt(input[0]) * 10 + digitToInt(input[1]);
		minute += digitToInt(input[3]) * 10 + digitToInt(input[4]);

	} else if(input.length() == 4) {	// Check if length 4

		// Check to see if characters are digits or : and throw exception if not
		if (!isDigit(input[0]) || input[1] != ':' || !isDigit(input[2]) || !isDigit(input[3]))
			throw(TimeFormatMistake(input));

		// Convert to hours and minutes
		hour += digitToInt(input[0]);
		minute += digitToInt(input[2]) * 10 + digitToInt(input[3]);

	} else {	// The string is not length 4 or 5 so throw exception

		throw(TimeFormatMistake(input));

	}

	// Check to see if the hours and minutes fall in possible time range
	if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
		throw(TimeFormatMistake(input));

	// If the function reaches this point, everything has passed verification
	// Therefore, convert the valid 24 hour time to standard time
	standardTime(hour, minute);

}

// Converts 24-hour time (22:06) to standard time (10:06 PM) 
// and outputs result to standard output
void standardTime(int hour, int minute) {

	bool isAM = true;	// used to determine whether to output AM or PM

	if (hour >= 12) {	// Checks if time is afternoon (PM) or morning (AM)

		isAM = false;

		if (hour > 12)	// Subtract 12 hours if time is 1:00 PM or later
			hour -= 12;

	}

	if (hour == 0)	// Add 12 hours if time is between 12 AM and 1 AM
		hour += 12;


	// Output results to standard output
	// Output hour
	cout << "That is the same as\n";
	cout << hour << ':';
	
	// Make sure minutes are formatted correctly (:06 instead of :6)
	if (minute < 10)
		cout << '0' << minute;
	else
		cout << minute;

	// Output AM or PM
	if (isAM)
		cout << " AM\n";
	else
		cout << " PM\n";

}

// Returns true if c is a digit
bool isDigit(char c) {

	if (c >= '0' && c <= '9')
		return true;

	return false;

}

// Returns an int of the digit contained in c. 
int digitToInt(char c) {

	return c - '0';

}