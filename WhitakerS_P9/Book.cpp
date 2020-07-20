#include "Book.h"

// Default constructor. Initializes all data members to empty strings
Book::Book() {

	title = "";
	author = "";
	date = "";

}

// Alternate constructor. Initializes data members to corresponding arguments
Book::Book(string newTitle, string newAuthor, string newDate) {

	// Initialize title, author, and date

	title = newTitle;
	author = newAuthor;
	date = newDate;

}

// Returns value of title
string Book::getTitle() {

	return title;

}

// Returns value of author
string Book::getAuthor() {

	return author;

}

// Returns value of date
string Book::getDate() {

	return date;

}

// Sets title to newTitle
void Book::setTitle(string newTitle) {

	title = newTitle;

}

// Sets author to newAuthor
void Book::setAuthor(string newAuthor) {

	author = newAuthor;

}

// Sets date to newDate
void Book::setDate(string newDate) {

	date = newDate;

}

// Overloaded << operator outputs book information
ostream& operator <<(ostream& out, const Book& book) {

	// Output "author.  title.  date."
	out << book.author << ".  " << book.title << ".  " << book.date << ".";

	return out;

}

// Overloaded < operator compares two book objects based on author. Used for sorting
bool operator <(const Book& b1, const Book& b2) {

	// True if b1 is less than b2. False otherwise
	return b1.author < b2.author;

}

// Overlaoded > operator compares two book objects based on author. Used for sorting
bool operator >(const Book& b1, const Book& b2) {

	// True if b1 is greater than b2. False otherwise
	return b1.author > b2.author;

}