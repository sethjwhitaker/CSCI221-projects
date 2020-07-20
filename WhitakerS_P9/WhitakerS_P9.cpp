#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

#include "Book.h"

using namespace std;

int menu();

void addBook(vector<Book>& database);
void printList(vector<Book>& database);

int main() {

	vector<Book> database = vector<Book>();	// Vector storing a list of all the books

	int choice = menu();	// Choose option

	while (choice > 0 && choice < 3) {	// If choice is 1 or 2 execute block

		switch (choice) {

		case 1:

			addBook(database);	// if 1 add a book to the database

			break;

		case 2:

			printList(database);	// if 2 print the list of books

			break;

		default:
			break;

		}

		choice = menu();		// Ask user for their next choice

	}

}

// Function that outputs a menu to user and returns their choice
int menu() {

	int in;

	// Output menu
	cout << "\n-----------------";
	cout << "\n      MENU       ";
	cout << "\n-----------------";
	cout << "\n1.  Add Book";
	cout << "\n2.  Print List";
	cout << "\n3.  Quit\n";

	cin >> in;	// Get user input

	return in;	// Return choice

}

// Function that gets a title author and date of a book from standard output,
//     and adds a new Book object intialied to those values to the database
void addBook(vector<Book>& database) {

	string title, author, date;

	cin.get();	// Get rid of the return symbol from previous input

	// Get title from user
	cout << "\nEnter title: ";
	getline(cin, title);

	// Get author from user
	cout << "\nEnter author: ";
	getline(cin, author);

	// Get date from user
	cout << "\nEnter date: ";
	getline(cin, date);

	Book b = Book(title, author, date); // Create new book

	database.push_back(b);	// Add to the database

}

// Function that prints a sorted list of books contained in the database
void printList(vector<Book>& database) {

	vector<Book>::iterator p = database.begin();
	
	// Sort the database. NOTE: Only works if the authors are all capitalized or lowercase
	sort<vector<Book>::iterator>(database.begin(), database.end());

	// Output the books in the database

	cout << "\nThe books entered so far, sorted alphabetically, are:\n";

	for (p = database.begin(); p < database.end(); p++) {	// Iterate over the database

		cout << "\n\t" << *p;	// Output book

	}

}