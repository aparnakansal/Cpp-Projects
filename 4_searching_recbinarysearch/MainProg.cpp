#include <iostream>
#include<stdio.h>
#include "orderedArrayListType.h"
using namespace std;

int main(){
	cout<<"hi";

	orderedArrayListType<int> list;
	list.insert(1);
	list.insert(2);
	list.insert(9);
	list.insert(13);

	list.print();
	list.insertOrd(7);
	cout<<endl;
	list.print();
	int c=list.binarySearch(7);
	cout<<"c= "<<c<<endl;
	int d=list.recursiveBinarySearch(13);
	cout<<"d= "<<d;
	return 0;
}
