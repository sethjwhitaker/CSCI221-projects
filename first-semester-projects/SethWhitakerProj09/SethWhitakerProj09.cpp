// Author: Seth Whitaker
// Date: 12/01/19
// Project 14

#include <iostream>

using namespace std;

void do_sum();
// Handles the input/output for sum

void do_str_length();
// Handles the input/output for str_length

int sum(int n);
// Recursive version to calculate the sum of
// 1 + 2 + .... + n

int str_length(char s[], int counter);
// Recursive version of strlen in C strings.
// It returns the length of the string s[].
// (the null character, '\0', is not counted in the length)

int main() {

	// Loop to determine if the user wants to repeat the program
	
	char cont = 'y';

	while (cont != 'n' && cont != 'N') {

		do_sum();

		do_str_length();

		cout << "\nWould you like another run? (Y/N): ";
		cin >> cont;

	}
}

void do_sum() {

	int x;

	cout << "\nEnter a positive integer: ";
	cin >> x;
	cout <<"\nThe sum of 1 + 2 + ... + " << x << " is " << sum(x);

}

void do_str_length() {

	char s[140];

	cout << "\nEnter a sentence (less than 140 characters): ";

	cin.ignore();
	cin.getline(s, 140);

	cout << "\nIt contains " << str_length(s, 0) << " chars, including whitespace.";

}

int sum(int n) {

	int total = 0;

	if(n > 0)						// Stop condition: if n <= 0, return 0
		total += n + sum(n - 1);	// Otherwise, add the current number to the
									// total and repeat for n-1

	return total;

}

int str_length(char s[], int counter) {
	
	if (s[counter] == '\0')					// Stop condition: if the current char == \0
		return counter;
	else									// Otherwise, repeat with the next character
		return str_length(s, counter + 1);
	
}

/*

---------------
	OUTPUT
---------------

Enter a positive integer: 8

The sum of 1 + 2 + ... + 8 is 36
Enter a sentence (less than 140 characters): It's time to get funky

It contains 22 chars, including whitespace.
Would you like another run? (Y/N): y

Enter a positive integer: 1000

The sum of 1 + 2 + ... + 1000 is 500500
Enter a sentence (less than 140 characters): This is a sentence.

It contains 19 chars, including whitespace.
Would you like another run? (Y/N): n

******\SethWhitakerProj09.exe (process 2360) exited with code 0.

*/