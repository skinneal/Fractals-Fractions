/***************************************************************************************************
Name: Assignment 3 Fractals.cpp 
Description: The longest line of the pattern has num starts beginning in column col of the output
Pre-Condition: num is a positive odd number
Post-Condition: A pattern based on the above example has been printed
*******************************************************************************************************/

#include "pch.h"
#include <iostream>

using namespace std;

/***********************************
Function: pattern
Description: prints a fractal based on user input
Parameters: int num, int col
Returns: nothing (void)
Pre-Conditions: num is a positive odd number
Post-Conditions: a pattern based on the user input is printed
***********************************/

void pattern(int num, int col) {
	if (num > 1) {
		pattern((num / 2), col);
	}
	for (int i = 0; i < col; i++) {
		cout << " ";
	}
	for (int i = 0; i < num; i++) {
		cout << "*";
	}
	cout << endl;

	if (num > 1) {
		pattern((num / 2), col + (num));
	}

}

int main()
{
	int number, col = 0;
	cout << "Enter a number: " << endl;
	cin >> number;
	cout << "Enter the amount of columns: " << endl;
	cin >> col;
	cout << endl;

	pattern(number, col);
}

