//Chapter 6: Programming Exercise 10

#include <iostream>

using namespace std;

int gcd(int first, int second);

int main()
{
	int firstNum;
	int secondNum;

	cout << "Enter first number: ";
	cin >> firstNum;
	cout << endl;

	cout << "Enter second number: ";
	cin >> secondNum;
	cout << endl;

	cout << "The gcd of " << firstNum << " and " << secondNum
		 << " = " << gcd(firstNum, secondNum) << endl;

	return 0;
}

int gcd(int first, int second)
{
	if (second == 0)
		return first;
	else
		return gcd(second, first % second);
}
