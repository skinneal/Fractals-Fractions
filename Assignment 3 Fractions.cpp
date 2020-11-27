/* Name: Assignment 3 Fractions.cpp
Description: Takes 2 integers (numerator and denominator) and reduces the fraction to its lowest terms
Pre-Conditions: take 2 integer parameters (numerator and denominator)
Post-Conditions: Reduce the fraction to its lowest terms
*/

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int get_int(string prompt) {
	int final = 0;
	int neg = 0;
	if (prompt[0] == '-') {
		neg = 1;
	}
	for (int i = neg; i < prompt.size(); i++) {
		if ((prompt[i] > 57 || prompt[i] < 48)) { //numbers
			return -1174;
		}
		final += int(prompt[i] - 48) * pow(10, (prompt.size() - 1 - i));
	}
	if(neg)
		return final * -1;
	return final;
}
	//return the greatest common divisor of num1 and num2
	int g_c_d(int num1, int num2) {
		if (num2 == 0)
			return num1;
		return g_c_d(num2, num1 % num2);
	}

	bool to_lowest_terms(int *numerator, int *denominator) {
		if (*denominator == 0) //return false if denominator is 0
			return false;
		else {
			int gcd = g_c_d((*numerator), (*denominator)); //reduce both numerator and denominator to lowest terms
			(*numerator) = (*numerator) / gcd;
			(*denominator) = (*denominator) / gcd;
			return true; //return true otherwise
		}
	}

	bool is_whole_number(string number) {
		for (int i = 0; i < number.length(); i++) {
			if (number.at(i) == '.') {
				return false;
			}
		}
		return true;
	}

	bool is_good_denominator(string number) {
		if (!is_whole_number(number) || get_int(number) == 0) 
			return false;
		return true;
	}

	bool is_good_numerator(string number) {
		if (!is_whole_number(number)) 
			return false;
		return true;
	}

	int main()
	{
		int numerator = 1;
		int denominator = 1;
		int again;
		string numer = "1", deno = "1", s_again = "1";
		do {
			do {
				if (!is_good_numerator(numer)) {
					cout << "Please enter a valid whole number!" << endl;
				}
				cout << "Enter the numerator: " << endl;
				getline(cin, numer);
				numerator = get_int(numer);
			} while (!is_good_numerator(numer));

			do {
				if (!is_good_denominator(deno)) {
					cout << "Please enter a valid whole number!" << endl;
				}
				cout << "Enter the denominator" << endl;
				getline(cin, deno);
				denominator = get_int(deno);
			} while (!is_good_denominator(deno));

				cout << "The Greatest Common Denominator of: " << numerator << " and " << denominator << " is " << g_c_d(numerator, denominator) << endl;
				to_lowest_terms(&numerator, &denominator);
				cout << "Your reduced numerator: " << numerator << endl;
				cout << "Your reduced denominator: " << denominator << endl;
				cout << "Do you want to do another conversion? (0-no, 1-yes): " << endl;
				getline(cin, s_again);
				again = get_int(s_again);

			} while (again == 1);
			return 0;
		}
	