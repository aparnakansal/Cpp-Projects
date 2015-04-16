//Chapter 6: Programming Exercise 7

#include <iostream>
#include <string>

using namespace std;

void printReverse(string str);
void printStringReverse(string str,int pos, int length);

int main()
{
	string str;

	cout << "Enter a string: ";
	getline(cin, str);
	cout << endl;

	cout << str << " printed backward is: ";
	printReverse(str);
	cout << endl;

	return 0;
}


void printReverse(string str)
{
	printStringReverse(str, 0, str.length());
}

void printStringReverse(string str, int pos, int length)
{
	if (length - pos > 0)
	{
		printStringReverse(str, pos + 1, length);
		cout << str[pos];
	}
}
