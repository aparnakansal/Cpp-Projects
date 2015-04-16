//Chapter 6: Programming Exercise 9

#include <iostream>
#include <iomanip>

using namespace std;

int power(int base, int exponent);

int main()
{
	int x;
	int y;

	cout << fixed << showpoint;
	cout << setprecision(6);

	cout << "Enter base: ";
	cin >> x;
	cout << endl;

	cout << "Enter exponent: ";
	cin >> y;
	cout << endl;

	cout << x << " to the power " << y << " = ";

	if (y >= 0)
		cout << power(x,y) << endl;
	else
		cout << (1.0 / static_cast<double>(power(x, -y))) << endl;


	return 0;
}

int power(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    else if (exponent == 1)
        return base;
    else
        return base * power(base, exponent - 1);
}
