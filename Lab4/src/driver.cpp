/*
 * driver.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: mehdi
 */
#include <iostream>
#include <cstdlib>
#include "lists.cpp"

using namespace std;

template<typename E> Link<E> *Link<E>::freelist = NULL;
// Assigning activeNodes to -1 will exclude HEAD to be counted as an active node.
template<typename E> int Link<E>::activeNodes = -1;
template<typename E> int Link<E>::freeNodes = 0;

int main()
{
	cout << "testing:\nLinkedList<int> *llist = new LinkedList<int>();\n";
	LinkedList<int> *llist = new LinkedList<int>();
	cout << "The Address of the LinkedList: " << &(*llist) << "\n";
	cout << "The size of the LinkedList is: " << llist->getCount() << "\n";
	cout << "finished successfully\n\n";

	cout << "testing:\nNumber of active nodes: " << llist->numActive() << "\n";
	cout << "Number of free nodes: " << llist->numFree() << "\n";
	cout << "The size of the LinkedList is: " << llist->getCount() << "\n";
	cout << "finished successfully\n\n";

	cout << "testing: append(3)\n";
	llist->append(3);
	cout << "testing:\nNumber of active nodes: " << llist->numActive() << "\n";
	cout << "Number of free nodes: " << llist->numFree() << "\n";
	cout << "The size of the LinkedList is: " << llist->getCount() << "\n";
	cout << "finished successfully\n\n";

	cout << "testing: prepend(3)\n";
	llist->prepend(3);
	cout << "testing:\nNumber of active nodes: " << llist->numActive() << "\n";
	cout << "Number of free nodes: " << llist->numFree() << "\n";
	cout << "The size of the LinkedList is: " << llist->getCount() << "\n";
	cout << "finished successfully\n\n";

	cout << "testing: CLEAR function\n";
	llist->clear();
	cout << "finished successfully\n\n";

	cout << "testing:\nNumber of active nodes: " << llist->numActive() << "\n";
	cout << "Number of free nodes: " << llist->numFree() << "\n";
	cout << "The size of the LinkedList is: " << llist->getCount() << "\n";
	cout << "finished successfully\n\n";

	cout << "testing: append(1)\n";
	llist->append(1);
	cout << "testing: Number of active nodes: " << llist->numActive() << "\n";
	cout << "Number of free nodes: " << llist->numFree() << "\n";
	cout << "The size of the LinkedList is: " << llist->getCount() << "\n";
	cout << "finished successfully\n\n";

	cout << "testing: append(2)\n";
	llist->append(2);
	cout << "testing: Number of active nodes: " << llist->numActive() << "\n";
	cout << "Number of free nodes: " << llist->numFree() << "\n";
	cout << "The size of the LinkedList is: " << llist->getCount() << "\n";
	cout << "finished successfully\n\n";

	cout << "testing: prepend(3)\n";
	llist->prepend(3);
	cout << "testing: Number of active nodes: " << llist->numActive() << "\n";
	cout << "Number of free nodes: " << llist->numFree() << "\n";
	cout << "The size of the LinkedList is: " << llist->getCount() << "\n";
	cout << "finished successfully\n\n";

	cout << "testing: append(4)\n";
	llist->append(4);
	cout << "testing: Number of active nodes: " << llist->numActive() << "\n";
	cout << "Number of free nodes: " << llist->numFree() << "\n";
	cout << "The size of the LinkedList is: " << llist->getCount() << "\n";
	cout << "finished successfully\n\n";

	cout << "testing: moveToStart() function\n";
	llist->moveToStart();
	cout << "The beginning of the LinkedList has value: " << llist->getValue() << "\n";
	cout << "finished successfully\n\n";

	/*This is both to test out the getValue function as well as
	 * next() function which returns a boolean if reaches the end of the LinkedList*/
	cout << "testing: iterating through LinkedList\n";
	do
	{
		cout << "The Value is : " << llist->getValue() << "\n";
	}while (llist->next());

	system("PAUSE");
	return 0;
}
