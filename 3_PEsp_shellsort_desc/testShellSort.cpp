// CMPE 180-92 PE3 SPRING 2014

#define	LENGTH	40
#include <iostream>
#include "arrayListType.h"

using namespace std;

int main()
{
	cout << "testShellSort by YourFirstName" << endl;

	arrayListType<int> list(100);
	int input[LENGTH] = {8,  3, 18, 44, 32, 17, 28, 99,  0, 22,\
						 7, 21, 11, 29, 31,  2,  1,  4,  6,  9,\
						12, 13, 39, 16, 34, 72, 41, 71, 38, 27,\
					    36, 33, 42, 24, 23, 26, 19, 37, 14, 43};
	int i;
	for (i = 0; i < LENGTH; ++i) list.insert(input[i]);

	cout << "Before sorting:" << endl;
	list.print();
	cout << endl;

	list.shellSort();

	cout << "After sorting:" << endl;
	list.print();
    cout << "***over***" << endl;

	return 0;
}
