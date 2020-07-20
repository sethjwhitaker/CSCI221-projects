#pragma once

#include <iostream>

using namespace std;

class Book {	// Class used to store title, author, and date information of a book

public:
	// ---Constructors---

	Book(); // Default constructor
	Book(string newTitle, string newAuthor, string newDate); 

	// ---Accessors---

	string getTitle();
	string getAuthor();
	string getDate();

	// ---Mutators---

	void setTitle(string newTitle);
	void setAuthor(string newAuthor);
	void setDate(string newDate);

	// ---Operators---

	friend ostream& operator <<(ostream& out, const Book& book); // Outputs "author. title. date"
	friend bool operator <(const Book& b1, const Book& b2);		// Compares books based on author
	friend bool operator >(const Book& b1, const Book& b2);		// Compares books based on author

private:

	// ---Member Variables---

	string title;
	string author;
	string date;

};