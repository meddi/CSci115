/*
 * hanoi.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: mehdi
 */
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

void print_elem(int elem) { cout << elem << endl; }

struct Stack
{
	vector<int> t;
	void push(int d) { t.push_back(d); }
	int pop()
	{
		int d = t.back();
		t.pop_back();
		return d;
	}
	void display() { for_each(t.rbegin(), t.rend(), print_elem); }
};

//
void hanoi(int n, Stack* p1, Stack* p2, Stack* p3)
{
	// check if Hanoi tower restriction holds
	if (n <= 1)
	{
		p3->push(p1->pop());
	}
	else
	{
		hanoi(n-1, p1, p3, p2);
		p3->push(p1->pop());
		hanoi(n-1, p2, p1, p3);
	}

}

int main()
{
	Stack* p1 = new Stack();
	Stack* p2 = new Stack();
	Stack* p3 = new Stack();
	int n;
	cout << "Enter the number N: ";
	cin >> n;

	for (int i = 0; i < n; i++)
		p1->push(i+1);

	for (int j = n; j < 2*n; j++)
		p2->push(j+1);

	hanoi(2*n, p1, p2, p3);

	p3->display();

	delete p1;
	delete p2;
	delete p3;

	return 0;
}
