
/* Data:

78 23 90 67 200 892 100 131 250 350
130 506 289 800 390 600 299 12 46 900
170 666 283 458 732 770 111 832 450 45
80 15 87 26 62 734 555 821 700 211
345 245 54 98 37 100 72 456 888 347
289 456 39 57 102 1200 348 771 801 208
172 263 289 421 784 273 583 1300 2100 61
71 10 89 63 4 115 831 672 1111 352
789 743 8 284 563 890 724 8456 90 622
66 1 72 48 117 355 723 333 8888 122
-999

*/

#include <iostream>
#include "arrayListType.h"

using namespace std;

int main()
{
	arrayListType<int> list(1000);
	int num;

	cout << "Enter numbers ending with -999" << endl;

	cin >> num;

	while (num != -999)
	{
		list.insertEnd(num);
		cin >> num;
	}

	cout << "Line 8:The list before sorting:" << endl;
	list.print();
	cout << endl;

	list.shellSort();

	cout << "The list after sorting:" << endl;
	list.print();
    cout << endl;
	getchar();
	getchar();
	return 0;
}


