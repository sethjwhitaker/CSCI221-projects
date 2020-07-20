

#include "CSCI221Proj5.h"
#include <stdlib.h>

using namespace FHSULINKEDLIST;

// Function that returns the length of a linked list
size_t FHSULINKEDLIST::list_length(const Node* head_ptr) {

	const Node* temp_ptr = head_ptr;	// Temp pointer used to iterate over the linked list

	size_t size = 0;

	while (temp_ptr != NULL) {			// Move temp_ptr over each link in the list until NULL is reached

		temp_ptr = temp_ptr->link;	
		size++;							// Count each link

	}

	return size;

}

// Function that inserts a new node at the head of a linked list
void FHSULINKEDLIST::list_head_insert(Node*& head_ptr, const Node::Item& entry) {

	Node * new_ptr = new Node;	// Create new node

	new_ptr->data = entry;		// Add entry to new node
	new_ptr->link = head_ptr;	// Insert at the front of the list
	head_ptr = new_ptr;
}

// Function that inserts a new node after the given node in a linked list
void FHSULINKEDLIST::list_insert(Node* previous_ptr, const Node::Item& entry) {

	Node* new_ptr = new Node;			// Create new node
	

	new_ptr->data = entry;				// Add entry to new node
	new_ptr->link =previous_ptr->link;	// Insert after specified pointer
	previous_ptr->link = new_ptr;

}

// Function that returns a pointer to the first node containing target in a linked list
Node* FHSULINKEDLIST::list_search(Node* head_ptr, const Node::Item& target) {

	Node* temp_ptr = head_ptr;		// Pointer that will point to the node containing target

	while (temp_ptr != NULL && temp_ptr->data != target) {	// Repeat until temp_ptr is NULL or contains target

		temp_ptr = temp_ptr->link;	// Move up one link

	}

	return temp_ptr;

}

// Function that returns a pointer to the node at the specified position where the head node is position 1
Node* FHSULINKEDLIST::list_locate(Node* head_ptr, size_t position) {

	Node* temp_ptr = head_ptr;		// Temp pointer used to iterate over the linked list

	size_t current_pos = 1;			// Current (head) pointer is position 1

	while (temp_ptr != NULL && current_pos < position) { // Move temp_ptr over each link in the list until NULL or position is reached

		temp_ptr = temp_ptr->link;
		current_pos++;				// Keep track of current link

	}

	return temp_ptr;

}

// Function that removes and deletes the head node
void FHSULINKEDLIST::list_head_remove(Node*& head_ptr) {

	Node* temp = head_ptr->link;	// Temp pointer that points to the new head node

	delete head_ptr;				// Delete head node

	head_ptr = temp;				// Assign new head node

}

// Function that removes the node after the specified location in a linked list
void FHSULINKEDLIST::list_remove(Node* previous_ptr) {

	Node* temp = previous_ptr->link;	// Pointer to the node that will be deleted

	previous_ptr->link = temp->link;	// Link previous and following nodes together

	delete temp;						// Delete node

}

// Function that removes and deletes every node from a linked list
void FHSULINKEDLIST::list_clear(Node*& head_ptr) {

	// Deletes the head node and assigns the following node to be the head
	// until the head is NULL
	while (head_ptr != NULL) {		

		Node* temp = head_ptr->link;

		delete head_ptr;

		head_ptr = temp;

	}

}

// Function that copies the linked list from source_ptr to head_ptr
void FHSULINKEDLIST::list_copy(Node* source_ptr, Node*& head_ptr) {

	if (source_ptr == NULL) {			// If source is an empty list

		head_ptr = NULL;				// Assign head_ptr to empty list

	} else {							// If source list has at least 1 item

		head_ptr = new Node;			// Create a new linked list

		head_ptr->data = source_ptr->data;	// Copy data from source to new head node
		head_ptr->link = NULL;

		Node* previous = head_ptr;		// Pointer to keep track of previous node
		Node* temp = source_ptr;		// Pointer to traverse the source linked list

		while (temp->link != NULL) {	// Repeat until tail node is reached or n nodes are copied

			temp = temp->link;			// Move temp through the list by 1

			Node* copy = new Node;		// Create a copy of temp
			copy->data = temp->data;
			copy->link = NULL;

			previous->link = copy;		// Attatch the copy to the previous node

			previous = previous->link;	// Move previous node forward

		}

	}

}

// Function that returns the number of occurrences of the target in a linked list
size_t FHSULINKEDLIST::list_occurrences(Node* head_ptr, const Node::Item& target) {

	Node* temp_ptr = head_ptr;			// Temp pointer used to traverse the linked list

	size_t occurrences = 0;				// Size variable that will contain number of occurrences

	while (temp_ptr != NULL) {			// Repeat until temp_ptr is NULL

		if (temp_ptr->data == target)	// Increment occurrences if current node contains target
			occurrences++;

		temp_ptr = temp_ptr->link;		// Move up one link

	}

	return occurrences;

}

// Function that attatches a new node to the tail of a linked list
void FHSULINKEDLIST::list_tail_attach(Node*& head_ptr, const Node::Item& entry) {

	// Find the tail node in the list
	if (head_ptr == NULL) {			// If list is empty

		head_ptr = new Node;		// Create new node

		head_ptr->data = entry;		// Assign entry to head
		head_ptr->link = NULL;
		
	} else {						// If list contains at least 1 node

		Node* temp_ptr = head_ptr;

		while (temp_ptr->link != NULL) {	// Move temp_ptr over each link in the list until the next node is NULL

			temp_ptr = temp_ptr->link;

		}

		Node* new_ptr = new Node;	// Create new node

		new_ptr->data = entry;		// Assign entry
		new_ptr->link = NULL;

		temp_ptr->link = new_ptr;	// Attatch to tail node

	}
	

}

// Function that removes and deletes the tail node from the list
void FHSULINKEDLIST::list_tail_remove(Node*& head_ptr) {

	// Find the tail node in the list

	Node* prev_ptr = NULL;				// Previous pointer used to remove link to tail node

	Node* temp_ptr = head_ptr;			// Temp pointer used to iterate over the linked list

	while (temp_ptr->link != NULL) {	// Move temp_ptr over each link in the list until the next node is NULL

		prev_ptr = temp_ptr;
		temp_ptr = temp_ptr->link;

	}

	if (prev_ptr != NULL)				// Remove node from list
		prev_ptr->link = NULL;			
	else
		head_ptr = NULL;				

	delete temp_ptr;					// Delete node
	

}

// Function that copies the first n nodes in a list
Node* FHSULINKEDLIST::list_copy_front(Node* source_ptr, size_t n) {

	if (source_ptr == NULL) {	// If source is an empty list

		Node* head = NULL;		// Create a new empty list

		return head;

	} else {							// If source list has at least 1 item

		Node* head = new Node;			// Create a new linked list

		head->data = source_ptr->data;	// Copy data from source to new head node
		head->link = NULL;

		Node* previous = head;			// Pointer to keep track of previous node
		Node* temp = source_ptr;		// Pointer to traverse the source linked list

		size_t pos = 1;					// Keep track of position in the list

		while (temp->link != NULL && pos < n) {	// Repeat until tail node is reached or n nodes are copied

			temp = temp->link;			// Move temp through the list by 1

			Node* copy = new Node;		// Create a copy of temp
			copy->data = temp->data;
			copy->link = NULL;

			previous->link = copy;		// Attatch the copy to the previous node

			previous = previous->link;	// Move previous node forward

			pos++;						// Keep track of position

		}

		return head;

	}

}



