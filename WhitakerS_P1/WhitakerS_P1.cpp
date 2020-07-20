// WhitakerS_P1.cpp
// Author: Seth Whitaker
// Version: 01/28/20


#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void reverse(char* front, char* rear);
// Precondition: The front and rear are pointing to the front
//               and rear of a C-string, respectively
// Postcondition: The C-string is reversed

string* addEntry(string* dynamicArray, int& size, string newEntry);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array

void print(const string* dynamicArray, int size);
// Precondition: dynamicArray point to a array of strings with give size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line forllowed by its index

int main() {

	// ------Test Reverse Function ------

	char* s1 = new char[23]{ "This is an even string" };
	char* s2 = new char[22]{ "This is an odd string" };
	char* s3 = new char[17] { "Computer Science" };
	char* s4 = new char[8] { "CSCI221" };
	
	cout << "\nTest Reverse Function:\n";

	cout << "\nString 1:";						// Test on s1 (rear pointing to char before null char)
	cout << endl << s1;

	reverse(&s1[0], &s1[21]);					// Reverse string

	cout << "\nReversed:";
	cout << endl << s1;

	cout << "\n\nString 2:";					// Test on s2 (rear pointing to char before null char)
	cout << endl << s2;

	reverse(&s2[0], &s2[20]);					// Reverse string

	cout << "\nReversed:";
	cout << endl << s2;

	cout << "\n\nString 3:";					// Test on s3 (rear pointing to null char)
	cout << endl << s3;

	reverse(&s3[0], &s3[16]);					// Reverse string

	cout << "\nReversed:";
	cout << endl << s3;

	cout << "\n\nString 4:";					// Test on s4 (rear pointing to null char)
	cout << endl << s4;

	reverse(&s4[0], &s4[7]);					// Reverse string

	cout << "\nReversed:";
	cout << endl << s4;

	// ------Test addEntry and deleteEntry Functions------

	int namesSize = 5;
	string* names = new string[namesSize]{ "Mike", "John", "Chris", "Bill", "Rob" };
	
	cout << "\n\nTest addEntry and deleteEntry functions:\n";

	cout << "\nInitial Dynamic Array:";
	print(names, namesSize);

	names = addEntry(names, namesSize, "Ashton");				// Add "Ashton" to the end of the array

	cout << "\nArray after using addEntry to add Ashton:";
	print(names, namesSize);

	names = deleteEntry(names, namesSize, "Bill");				// Delete "Bill" from the array

	cout << "\nArray after using deleteEntry to delete Bill:";
	print(names, namesSize);

	names = deleteEntry(names, namesSize, "George");			// Delete "George" from the array (which doesn't exist)

	cout << "\nArray after using deleteEntry to delete George:";
	print(names, namesSize);

	return 0;
}

void reverse(char* front, char* rear) {
	
	int size = rear - front + 1;			// Find size of string

	if (*rear == '\0')						// Check if rear is a null char
		rear--;

	for (int i = 0; i < size / 2; i++) {	// Loop half the size of the array (if string size is odd, the middle char doesn't need to be swapped) 

		char temp = *(rear - i);			// Swap the chars i memory locations behind front, and i locations in front of rear.
		*(rear - i) = *(front + i);
		*(front + i) = temp;

	}

}

string* addEntry(string* dynamicArray, int& size, string newEntry) {

	size++;									// Increment size

	string* newA = new string[size];		// Create new dynamic array 1 element larger

	for (int i = 0; i < size - 1; i++)		// Copy old array to new array
		newA[i] = dynamicArray[i];

	newA[size - 1] = newEntry;				// Add newEntry to end of array

	delete[] dynamicArray;					// Delete old array

	return newA;							// Return pointer to first element of new array

}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete) {
	
	bool found = false;								// Bool to store whether entryToDelete is in dynamicArray
	int index = 0;									// Int to store the index of entryToDelete if it exists

	for (int i = 0; i < size; i++) {				// Search for entryToDelete

		if (dynamicArray[i] == entryToDelete) {		// If it exists, mark found as true, and store the index at which it is located
			found = true;
			index = i;
			break;
		}

	}

	if (!found)										// If entryToDelete is not found, return the original array
		return dynamicArray;
	else {											// Otherwise ...

		size--;										// Decrement size

		string* newA = new string[size];			// Create a new dynamic array

		for (int i = 0; i < index; i++)				// Copy elemnts up to entryToDelete 
			newA[i] = dynamicArray[i];

		for (int i = index; i < size; i++)			// Copy the rest of the elements, skipping over entryToDelete
			newA[i] = dynamicArray[i+1];

		return newA;								// Return the new array

	}

}

void print(const string* dynamicArray, int size) {
	
	cout << endl;
	for (int i = 0; i < size; i++)				// Iterate over the array and print each element on a separate line
		cout << dynamicArray[i] << endl;


}



/*

----------------------
        OUTPUT
----------------------

Test Reverse Function:

String 1:
This is an even string
Reversed:
gnirts neve na si sihT

String 2:
This is an odd string
Reversed:
gnirts ddo na si sihT

String 3:
Computer Science
Reversed:
ecneicS retupmoC

String 4:
CSCI221
Reversed:
122ICSC

Test addEntry and deleteEntry functions:

Initial Dynamic Array:
Mike
John
Chris
Bill
Rob

Array after using addEntry to add Ashton:
Mike
John
Chris
Bill
Rob
Ashton

Array after using deleteEntry to delete Bill:
Mike
John
Chris
Rob
Ashton

Array after using deleteEntry to delete George:
Mike
John
Chris
Rob
Ashton

******\WhitakerS_P1.exe (process 7148) exited with code 0.

*/