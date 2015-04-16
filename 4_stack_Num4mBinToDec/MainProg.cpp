//This is another soultion to Exercise 7

#include <iostream>
#include <cmath>
#include "myStack.h"

using namespace std;

int main()
{
	stackType<int> stack;

	int decimalNum;
	int num;
	int bitWeight = 0;
	int binaryNum;
	int bit;

	cout << "Enter a binary number: ";
	cin >> binaryNum;
	cout << endl;

	while( binaryNum > 0)
	{
		bit = binaryNum % 10;
		stack.push(bit * static_cast<int>(pow(2.0, bitWeight)));
		binaryNum = binaryNum / 10;
		bitWeight++;
	}

	decimalNum = 0;

	while (!stack.isEmptyStack())
    {
		num = stack.top();
		stack.pop();
		decimalNum = decimalNum + num;
	}

	cout << "The equivalent decimal num is: " << decimalNum << endl;

	return 0;
}
