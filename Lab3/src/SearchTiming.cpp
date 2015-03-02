/*
 * SearchTiming.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: mehdi
 */
#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <cmath>

using namespace std;

void SequentialSearch(long int[], long int, long int);
void BinarySearch(long int[], int, long int, long int);

int main()
{
	const int Size = 1000;
	int searchArr[Size];

	clock_t tS, tB;
	for (int count = 1; count < 8; count++)
	{
		// Generating power N and initializing the array of size N
		long int N = pow(10, count);
		long int arr[N];
		for (long int i = 0; i < N; i++)
			arr[i] = i;

		//
		srand(time(NULL));
		for (long int j = 0; j < Size; j++)
			searchArr[j] = (rand()%N + 1);

		// Actual search here
		tS = clock();
		for (int k = 0; k < Size; k++)
			SequentialSearch(arr, N, searchArr[k]);

		tS = clock() - tS;
		cout << "It took: " << tS << " Clicks, and "
				<< (((double)tS)*1000)/CLOCKS_PER_SEC
				<< " milliseconds for Sequential Search to finish." << endl;

		cout << endl;

		tB = clock();
		for (int k = 0; k < Size; k++)
			BinarySearch(arr, 0, N, searchArr[k]);

		tB = clock() - tB;
		cout << "It took: " << tB << " Clicks, and "
				<< (((double)tB)*1000)/CLOCKS_PER_SEC
				<< " milliseconds for Binary Search to finish." << endl;

		cout << endl;
	}
return 0;

}

//SequentialSearch
void SequentialSearch(long int array[], long int size, long int value)
{
    int index = 0;
    bool found = false;

    // begin searching
    while (index < size && !found)
    {
        if (array[index] == value)
        {
            found = true;
        }
        index++;
    }
}

//BinarySearch
void BinarySearch(long int array[], int first, long int last, long int value)
{
	int position = 0;
	position = (first + last) / 2;

	// Begin searching
    while((array[position] != value) && (first <= last))
    {
        if (array[position] > value)
        	last = position - 1;
        else
        	first = position + 1;
        position = (first + last) / 2;
    }
}

