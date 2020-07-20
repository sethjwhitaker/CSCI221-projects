// SethWhitakerProj08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void get_scores(vector<int>& v);
// get integer scores from keyboard and store in v.
// we assume that the user will input scores in range
// of 0 to 100, inclusive. User enter a negative
// number to stop the input and end the function
void print_stats(vector<int>& v);
// print out the stats of data that are stored in v
// includes: max, min, total number of data,
// and the average

int minv(vector<int>& v);
// returns the minimum value in a vector of ints

int maxv(vector<int>& v);
// returns the maximum value in a vector of ints

float averagev(vector<int>& v);
// returns a float average of the values in a vector of ints

void get_sentence(string& s);
// get sentence from user to test if it is a palindrome

bool is_palindrome(string s);
// returns true if the string is a palindrome and false otherwise

string remove_spaces(string s);
// returns a string with spaces removed

string make_lowercase(string s);
// returns lowercase version of string

int main() {

	char cont = 'y';
	
	while (cont != 'n' && cont != 'N') {

		vector<int> scores;

		get_scores(scores);

		print_stats(scores);

		cout << "\nTry another set of scores? (y/n): ";
		cin >> cont;
	}

	cont = 'y';

	while (cont != 'n' && cont != 'N') {

		string s;

		get_sentence(s);

		if (is_palindrome(s))
			cout << "\nThe string: " << s << " is a palindrome.";
		else
			cout << "\nThe string: " << s << " is not a palindrome.";
		
		cout << "\nTry another sentence? (y/n): ";
		cin >> cont;

	}
	
	return 0;
    
}

void get_scores(vector<int>& v) {

	cout << "\nPlease enter a sequence of scores from 0 to 100.";
	cout << "\nTo stop, enter a negative integer.";

	int s = 0;

	while (s >= 0) {

		cout << "\nEnter score: ";
		cin >> s;

		if (s >= 0)
			v.push_back(s);

	}


}

void print_stats(vector<int>& v) {

	cout << "\n The total number of scores is: " << v.size();
	cout << "\n The min score is: " << minv(v);
	cout << "\n The max score is: " << maxv(v);
	cout << "\n The average of the scores is: " << averagev(v);

}

int minv(vector<int>& v) {

	int min = 0;

	for (int i = 0; i < v.size(); i++) {

		if (i == 0)
			min = v[i];
		else {

			if (v[i] < min)
				min = v[i];

		}

	}

	return min;

}

int maxv(vector<int>& v) {

	int max = 0;

	for (int i = 0; i < v.size(); i++) {

		if (i == 0)
			max = v[i];
		else {

			if (v[i] > max)
				max = v[i];

		}

	}

	return max;

}

float averagev(vector<int>& v) {

	int total = 0;

	for (int i = 0; i < v.size(); i++)
		total += v[i];

	return total / static_cast<float>(v.size());

}

void get_sentence(string& s) {

	cout << "\nEnter a sentence: \n";
	cin.ignore();
	getline(cin, s);
}

bool is_palindrome(string s) {

	s = remove_spaces(s);
	s = make_lowercase(s);

	for (int i = 0; i < s.length() / 2; i++) {

		if (s[i] != s[s.length() - i - 1])
			return false;

	}

	return true;


}

string remove_spaces(string s) {

	string newS;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] != ' ')
			newS = newS + s[i];

	}
	
	return newS;
}

string make_lowercase(string s) {

	for (int i = 0; i < s.length(); i++) {

		if (isupper(s[i])) {

			s[i] = tolower(s[i]);

		}

	}

	return s;

}

/*
--------------
	OUTPUT
--------------


Please enter a sequence of scores from 0 to 100.
To stop, enter a negative integer.
Enter score: 99

Enter score: 86

Enter score: 63

Enter score: 77

Enter score: -1

 The total number of scores is: 4
 The min score is: 63
 The max score is: 99
 The average of the scores is: 81.25
Try another set of scores? (y/n): n

Enter a sentence:
A nut for a jar of tuna

The string: A nut for a jar of tuna is a palindrome.
Try another sentence? (y/n): y

Enter a sentence:
this is not a palindrome

The string: this is not a palindrome is not a palindrome.
Try another sentence? (y/n): n

********\SethWhitakerProj08.exe (process 12696) exited with code 0.

*/