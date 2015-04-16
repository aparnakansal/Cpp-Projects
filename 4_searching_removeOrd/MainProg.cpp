# include<iostream>
# include<stdio.h>
# include "orderedArrayListType.h"
using namespace std;

int main(){
	cout<<"hi";

	orderedArrayListType<int> list;
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);
	list.print();
	list.removeOrd(2);
	cout<<endl;
	list.print();
}
