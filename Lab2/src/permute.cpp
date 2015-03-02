/*
 * permute.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: mehdi
 */
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

void print(list<int>& List)
{
	list<int>::iterator it = List.begin();
	for (; it != List.end(); ++it)
		cout << *it << ' ';
	cout << endl;
}

int main()
{
	int num;
	cout << "Enter the number:";
	cin >> num;
	list<int> L;

	for (int i = 0; i < num; i++)
		L.push_back(i+1);

	print(L);
	while (next_permutation(L.begin(), L.end()))
		print(L);

	return 0;
}
