/*
 * driver.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: mehdi
 */
#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;

int main()
{
	BST bt;

	cout << "Testing insertion to the list: " << endl << endl;
	bt.insert(5);
	bt.insert(76);
	bt.insert(21);
	bt.insert(4);
	bt.insert(32);
	bt.insert(64);
	bt.insert(15);
	bt.insert(52);
	bt.insert(14);
	bt.insert(100);
	bt.insert(83);
	bt.insert(1);
	bt.insert(3);
	bt.insert(70);
	bt.insert(87);
	bt.insert(80);

	cout << "This print is to check that all the keys has been successfully added to the tree: " << endl;
	bt.print();
	cout << endl << endl;

	cout << "Test to find the smalles key in the tree: " << endl << endl;
	cout << "The smallest key in the tree is: " << bt.findSmallest() << endl << endl;

	cout << "Test to print in order between specified range(32-100): " << endl << endl;
	bt.printInOrder(32, 100);

	return 0;
}
