/*
 * lists.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: mehdi
 */
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "List.h"

using namespace std;

// Link class template implementation
template <typename E> class Link
{
private:
	static Link<E> *freelist; 	// Reference to freelist head
	static int freeNodes;		// Number of active nodes
	static int activeNodes;		// Number of free nodes

public:
	E value; 					// Value for this node
	Link *next; 				// Pointer to next node in list

	// Constructors
	Link() : next(NULL) {}
	Link(const E& elemval, Link *nextlink = NULL) : value(elemval), next(nextlink) {}

	// Destructor
	~Link() {}

	/* This is an overloaded NEW operator which grabs
	* a Link from the free list if not EMPTY;
	* otherwise it will allocate a new Link.
	* NOTE that this has been declared as STATIC member
	* function of the template class since only
	* static member function are allowed to acccess
	* static member variable of a class throghout the program.
	* The technique is usually called caching.
	*/
	void *operator new(size_t)
	{
		Link<E>* return_val;

		activeNodes++;

		if (freeNodes > 0)
		{
			freeNodes--;
			return_val = freelist;
			freelist = freelist->next;
		}
		else
			return_val = ::new Link;

		return return_val;
	}

	/* This is an overloaded DELETE operator that
	* puts the Link into the free list.
	*/
	void operator delete(void *ptr)
	{
		// keep track of(in the static variables) the total number of
		// active nodes and the total number of free nodes
		freeNodes++;
		activeNodes--;

		((Link<E> *)ptr)->next = freelist; // Put on freelist
		freelist = (Link<E> *)ptr;
	}

	static int getFreeNodeCount() { return freeNodes; }

	static int getActiveNodeCount() { return activeNodes; }
};

// Linked list class template implementation
template <typename E> class LinkedList : public List<E>
{
private:
	Link<E> *head; 		// Pointer to list header
	Link<E> *tail; 		// Pointer to last element
	Link<E> *curr; 		// Access to current element
	int count;			// Size of the LinkedList

	//Intialization helper method
	void init() { curr = tail = head = new Link<E>; count = 0; }

	void removeall()
	{
		// Return Link nodes to free store
		while(head != NULL)
		{
			curr = head;
			head = head->next;
			delete curr;
		}
	}

public:
	LinkedList() { init(); } 	// Constructor
	~LinkedList() { removeall(); } 	// Destructor

	//
	int getCount() { return count; }

	// This implementation overrides the base class CLEAR definition
	void clear()
	{
		while(head != NULL)
		{
			curr = head;
			head = head->next;
			delete curr;
			count--;
		}
		cout << "Executing from within the class template LinkedList\n";
		init();
	}


	/* This implementation overrides the base class definition.
	 * inserts to the beginning of the LinkedList.
	*/
	void prepend(const E& val)
	{
		Link<E> *temp = new Link<E>(val, head->next);
		head->next = temp;
		// Counting up the number of existing nodes in the LinkedList
		count++;
	}

	// Append "val" to list
	void append(const E& val)
	{
		tail = tail->next = new Link<E>(val, NULL);
		count++;
	}

	// Place curr at list start
	void moveToStart() { curr = head->next; }

	// Move curr one step right; no change if already at end
	bool next()
	{
		if (curr != tail)
		{
			curr = curr->next;
			return true;
		}
		return false;
	}

	//
	const E& getValue() const
	{
		// Return current element
		assert(curr != NULL && "No value");
		return curr->value;
	}

	//
	int numActive() { return Link<E>::getActiveNodeCount(); }

	//
	int numFree() { return Link<E>::getFreeNodeCount(); }
};
