#include <iostream>

using namespace std;

// Node template for linked list 
template<class T>
struct Node {
	T item;
	Node<T>* link;
};

// Class template for Set
template<class T>
class Set {

public:
	Set();	// Constructor

	void addItem(T item);	// Adds an item to the head of the linked list
	void removeItem(T item);// Removes an item from the linked list
	bool contains(T item);  // Returns true if the item is in the list
	int getSize();			// Returns the size of the list
	T* getSet();			// Returns a dynamic array containing the items of the Set

private:
	Node<T>* head;			// Head of linked list
	int size;				// Size of the list
};

// Default constructor sets head to NULL and size to 0
template<class T>
Set<T>::Set() {
	head = NULL;
	size = 0;
}

// Adds item to the Set object. If item already exists in the set,it does nothing
template<class T>
void Set<T>::addItem(T item) {

	Node<T>* temp = head;	//temp node to traverse list

	// loop until item is found in list or end of list is reached
	while (temp != NULL && temp->item != item) { 
		temp = temp->link;	// move to next link
	}

	if (temp == NULL) {	// if end of list was reached 
						// (item does not exist already in the list)

		// Add new node to list containing item
		Node<T>* newNode = new Node<T>();
		newNode->item = item;
		newNode->link = head;
		head = newNode;

		size++; //increment size

	}

}

// This function item from the Set object if it exists
template<class T>
void Set<T>::removeItem(T item) {

	if (head == NULL)	// check for empty list
		return;
	else if (head->item == item) {	// if head node contains item
		Node<T>* toRemove = head;	// remove head node
		head = toRemove->link;
		delete toRemove;
		size--;						// decrement size
	}

	Node<T>* prev = head;	// Keep track of previous pointer

	// Check if current node is NULL or contains item
	while (prev->link != NULL && prev->link->item != item) {
		prev = prev->link;	// advance to next node
	}

	// If node is not NULL, then the item was found
	if (prev->link != NULL) {
		Node<T>* toRemove = prev->link;	// remove node
		prev->link = toRemove->link;
		delete toRemove;				// delete node
		size--;							// decrement size
	}

}

// This function returns true if Set object contains item
template<class T>
bool Set<T>::contains(T item) {
	Node<T>* temp = head;

	while (temp != NULL && temp->item != item) {
		temp = temp->link;	// move to next link
	}

	return temp != NULL;	// if end of list was reached, then the 
							// list does not contain item
	
}

// Returns the size of the list
template<class T>
int Set<T>::getSize() {
	return size;
}

// Returns a pointer to a dynamic array containing the items contained in the Set object
template<class T>
T* Set<T>::getSet() {
	
	T* a;				// initialize dynamic array
	a = new T[size];

	// Iterate over list until end is reached or size is reached
	Node<T>* temp = head;
	int i = 0;
	while (temp != NULL && i < size) {	
		a[i] = temp->item;	// copy current item to current array element
		temp = temp->link;	// move to next node
		i++;				// move to next array element
	}
	
	return a;			// return pointer to array
}

// Output the Set s to standard output
template<class T>
void outputSet(Set<T>& s) {

	T* a;
	a = s.getSet();
	for (int i = 0; i < s.getSize(); i++) {
		cout << endl << a[i];
	}

}

int main() {

	// Test add item
	cout << "Enter 5 integers:\n";

	Set<int> s = Set<int>();

	int a;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		s.addItem(a);
	}

	cout << endl << "Here is the set: ";
	outputSet(s);

	// Test remove item
	cout << "\nNow enter 2 integers to remove:\n";
	for (int i = 0; i < 2; i++) {
		cin >> a;
		s.removeItem(a);
	}

	cout << endl << "Here is the updated set: ";
	outputSet(s);

	// Test contains

	cout << endl << "Enter an integer to see if it exists in the set:\n";
	cin >> a;

	if (s.contains(a))
		cout << endl << "The set contains " << a;
	else
		cout << endl << "The set does not contain " << a;

	// Test get size

	cout << "\nThe set contains " << s.getSize() << " integers";

	// Test with chars

	cout << "\n\nNow we will test with characters.";

	Set<char> cSet = Set<char>();
	cout << "\nEnter 4 characters:\n";

	char c;
	for (int i = 0; i < 4; i++) {
		cin >> c;
		cSet.addItem(c);
	}

	cout << endl << "Here is the set: ";
	outputSet(cSet);

	cout << "\nNow enter a character to remove:\n";
	cin >> c;
	cSet.removeItem(c);

	cout << endl << "Here is the updated set: ";
	outputSet(cSet);

	// Test with double

	cout << "\n\nNow we will test with doubles.";

	Set<double> dSet = Set<double>();
	cout << "\nEnter 4 doubles:\n";

	double d;
	for (int i = 0; i < 4; i++) {
		cin >> d;
		dSet.addItem(d);
	}

	cout << endl << "Here is the set: ";
	outputSet(dSet);

	cout << "\nNow enter a double to remove:\n";
	cin >> d;
	dSet.removeItem(d);

	cout << endl << "Here is the updated set: ";
	outputSet(dSet);
	
}
