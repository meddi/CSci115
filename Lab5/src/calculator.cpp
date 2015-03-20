/*
 * calculator.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: mehdi
 */
#include <iostream>
#include <string>
#include <ctype.h>
#include "lists.cpp"

using namespace std;

template<typename E> Link<E> *Link<E>::freelist = NULL;
template<typename E> int Link<E>::activeNodes = -1;
template<typename E> int Link<E>::freeNodes = 0;

//
void tLeft(string& str) { str.erase(0, str.find_first_not_of(" ")); }

void tRight(string& str) { str.erase(str.length(), str.find_first_of(" ")); }

//
bool validate_digits_string(const string& str)
{
	for (string::size_type i = 0; i < str.length(); i++)
	{
		if(!isdigit(str[i]))
			return false;
	}
	return true;
}

//
void chunkify(LinkedList<string> *llist, string& str)
{
	for (size_t t = 0; t < str.length(); t+=4)
	{
		llist->prepend(&str[str.length()%t]);
	}
}

//
long int exp(int base, int power)
{
	if (power == 1)
		return base;
	if (power == 2)
		return base*base;
	if (power%2 == 0)
		return exp(exp(base, power/2), 2);
	else
		return base * exp(exp(base, (power-1)/2), 2);
}

// Was not able to implement this
int addition(LinkedList<std::string> *llist1, LinkedList<std::string> *llist2)
{

	return 0;
}

// Was not able to implement this
int subtraction(LinkedList<std::string> *llist1, LinkedList<std::string> *llist2)
{
	return 0;
}

// Was not able to implement this
int multiplication(LinkedList<std::string> *llist1, LinkedList<std::string> *llist2)
{
	return 0;
}

int main()
{
	string str("a = 123434534 + 5678435234 ");
	//getline(cin, str);

	// Checks if the assignment exists in the input string
	try {
		if (str.find('=') == string::npos)
			throw "assignment expected!";
	} catch(const char* msg) { cout << "Bad Input: " << msg << endl; return -1; }

	/*Split the string into two segments:
	* 1. before the assignment
	* 2. after the assignmet*/
	size_t pos = str.find("=");
	string bef_equal = str.substr(0, pos);
	string aft_equal = str.substr(pos+1);

	// Parsing the substring before assignment
	tLeft(bef_equal);
	tRight(bef_equal);
	try {
		size_t i = 0;
		if (!isalpha(bef_equal[i]))
			throw "variable expected!";
	} catch(const char* msg) { cout << "Bad Input: " << msg << endl; return -1; }

	// Parsing the substring after assignment
	// Removes any leading spaces
	size_t plus_pos = aft_equal.find("+");
	size_t minus_pos = aft_equal.find("-");
	size_t times_pos = aft_equal.find("*");
	size_t power_pos = aft_equal.find("^");
	//
	string aft_eq_bef_op = "";
	string aft_eq_aft_op = "";

	//<var> = <var or digits> + <var or digits>
	if (plus_pos != string::npos)
	{
		aft_eq_bef_op = aft_equal.substr(0, plus_pos);
		aft_eq_aft_op = aft_equal.substr(plus_pos + 1);

		try {
			tLeft(aft_eq_bef_op);
			size_t p = aft_eq_bef_op.find_first_of(" ");

			if (isdigit(aft_eq_bef_op[p+1]) || isalpha(aft_eq_bef_op[p+1]))
					throw "operator expected!";
		} catch(const char* msg) { cout << "Bad Input: " << msg << endl; return -1; }

		cout << "Test Passed!" << endl;

		tLeft(aft_eq_aft_op);
		if (aft_eq_aft_op.find(" ") == string::npos)
		{
			try {
				size_t t = aft_eq_aft_op.find_first_of(" ");

				if (isdigit(aft_eq_aft_op[t+1]))
					throw "operator expected!";
				if (isalpha(aft_eq_aft_op[t+1]))
					throw "end of line expected!";
			} catch(const char* msg) { cout << "Bad Input: " << msg << endl; return -1; }
		}

		// Trimings
		tLeft(aft_eq_bef_op);
		tRight(aft_eq_bef_op);
		//
		tLeft(aft_eq_aft_op);
		tRight(aft_eq_aft_op);

		// Creating LinkedList to place the numbers in.
		LinkedList<std::string> *var1 = new LinkedList<std::string>;
		LinkedList<std::string> *var2 = new LinkedList<std::string>;
		chunkify(var1, aft_eq_bef_op);
		chunkify(var2, aft_eq_aft_op);

		addition(var1, var2);

		cout << "testing:\nNumber of active nodes: " << var1->numActive() << "\n";
		cout << "Number of free nodes: " << var1->numFree() << "\n";
		cout << "The Value is : " << var1->getValue() << "\n";

	}
	//<var> = <var or digits> - <var or digits>
	else if (minus_pos != string::npos)
	{
		aft_eq_bef_op = aft_equal.substr(0, minus_pos);
		aft_eq_aft_op = aft_equal.substr(minus_pos + 1);

		try {
			tLeft(aft_eq_bef_op);
			size_t p = aft_eq_bef_op.find_first_of(" ");

			if (isdigit(aft_eq_bef_op[p+1]) || isalpha(aft_eq_bef_op[p+1]))
					throw "operator expected!";
		} catch(const char* msg) { cout << "Bad Input: " << msg << endl; return -1; }

		tLeft(aft_eq_aft_op);
		if (aft_eq_aft_op.find(" ") == string::npos)
		{
			try {
				size_t t = aft_eq_aft_op.find_first_of(" ");

				if (isdigit(aft_eq_aft_op[t+1]))
					throw "operator expected!";
				if (isalpha(aft_eq_aft_op[t+1]))
					throw "end of line expected!";
			} catch(const char* msg) { cout << "Bad Input: " << msg << endl; return -1; }
		}

		// Trimings
		tLeft(aft_eq_bef_op);
		tRight(aft_eq_bef_op);
		//
		tLeft(aft_eq_aft_op);
		tRight(aft_eq_aft_op);

		if (aft_eq_bef_op.length() < aft_eq_aft_op.length())
			cout << "Subtraction Truncated!" << endl;

		// Creating LinkedList to place the numbers in.
		LinkedList<std::string> *var1 = new LinkedList<std::string>;
		LinkedList<std::string> *var2 = new LinkedList<std::string>;
		chunkify(var1, aft_eq_bef_op);
		chunkify(var2, aft_eq_aft_op);

		subtraction(var1, var2);


	}
	//<var> = <var or digits> * <var or digits>
	else if (times_pos != string::npos)
	{
		aft_eq_bef_op = aft_equal.substr(0, times_pos);
		aft_eq_aft_op = aft_equal.substr(times_pos + 1);

		try {
			tLeft(aft_eq_bef_op);
			size_t p = aft_eq_bef_op.find_first_of(" ");

			if (isdigit(aft_eq_bef_op[p+1]) || isalpha(aft_eq_bef_op[p+1]))
					throw "operator expected!";
		} catch(const char* msg) { cout << "Bad Input: " << msg << endl; return -1; }

		tLeft(aft_eq_aft_op);
		if (aft_eq_aft_op.find(" ") == string::npos)
		{
			try {
				size_t t = aft_eq_aft_op.find_first_of(" ");

				if (isdigit(aft_eq_aft_op[t+1]))
					throw "operator expected!";
				if (isalpha(aft_eq_aft_op[t+1]))
					throw "end of line expected!";
			} catch(const char* msg) { cout << "Bad Input: " << msg << endl; return -1; }
		}

		// Trimings
		tLeft(aft_eq_bef_op);
		tRight(aft_eq_bef_op);
		//
		tLeft(aft_eq_aft_op);
		tRight(aft_eq_aft_op);

		// Creating LinkedList to place the numbers in.
		LinkedList<std::string> *var1 = new LinkedList<std::string>;
		LinkedList<std::string> *var2 = new LinkedList<std::string>;
		chunkify(var1, aft_eq_bef_op);
		chunkify(var2, aft_eq_aft_op);

		multiplication(var1, var2);


	}
	//<var> = <var or digits> ^ <var or digits>
	else if (power_pos != string::npos)
	{
		aft_eq_bef_op = aft_equal.substr(0, power_pos);
		aft_eq_aft_op = aft_equal.substr(power_pos + 1);

		try {
			tLeft(aft_eq_bef_op);
			size_t p = aft_eq_bef_op.find_first_of(" ");

			if (isdigit(aft_eq_bef_op[p+1]) || isalpha(aft_eq_bef_op[p+1]))
					throw "operator expected!";
		} catch(const char* msg) { cout << "Bad Input: " << msg << endl; return -1; }

		tLeft(aft_eq_aft_op);
		tRight(aft_eq_aft_op);
		try {
			size_t t = 0;

			if (!isdigit(aft_eq_aft_op[t]))
				throw "integer expected!";
		} catch(const char* msg) { cout << "Bad Input: " << msg << endl; return -1; }

		// Trimings
		tLeft(aft_eq_bef_op);
		tRight(aft_eq_bef_op);
		//
		tLeft(aft_eq_aft_op);
		tRight(aft_eq_aft_op);

		// Creating LinkedList to place the numbers in.
		LinkedList<std::string> *var1 = new LinkedList<std::string>;
		LinkedList<std::string> *var2 = new LinkedList<std::string>;
		chunkify(var1, aft_eq_bef_op);
		chunkify(var2, aft_eq_aft_op);

		size_t t = 0;
		exp((int)aft_eq_bef_op, (int)aft_eq_aft_op);

	}
	// by this point, we have the first and second <var or digits>
	//<var> = <digits>
	else
	{
		tLeft(aft_equal);
		tRight(aft_equal);
		aft_eq_bef_op = aft_equal;
		LinkedList<std::string> *var1 = new LinkedList<std::string>;
		chunkify(var1, aft_eq_bef_op);

	}
	return 0;
}
