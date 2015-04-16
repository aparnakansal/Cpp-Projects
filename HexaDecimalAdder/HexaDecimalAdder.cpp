/*
 * HexaDecimalAdder.cpp
 *
 *  Created on: Sep 19, 2014
 *      Author: aparna
 */

#include <iostream>
#include<string>
#include<fstream>
#include "HexaDecimalAdder.h"
using namespace std;

int main() {
	int choice;
	char response = 'Y';
	while ((response == 'y') || (response == 'Y')) {
		check=0;
		// Initialize the arrays in each iteration.
		char a[ARRAY_LENGTH] = { '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0' };
		char b[ARRAY_LENGTH] = { '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0' };

		cout << "Hexadecimal Adder by Aparna.Please enter 1 or 2:" << endl;
		cout << "1.Input from Keyboard" << endl;
		cout << "2.Input from file" << endl;
		cin >> choice;

		if (choice == 1) {
			keyboard_input(a, b, sum);
		} else if (choice == 2) {
			file_input(a,b,sum);
		} else {
			cout << "Entered choice is not valid, do you want to try again?";
		}

		cout << endl;
		cout << "continue(y/n)"<<endl;
		cin >> response;
	}
	cout << "bye!";
	return 0;
}

