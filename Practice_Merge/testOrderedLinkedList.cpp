#include<iostream>
#include "orderedLinkedList.h"
using namespace std;

int main(){
	cout<<"hi";
	orderedLinkedList<int> a,b,c;
	//linkedListType<int> a;
	a.insertLast(1);
	a.insertLast(2);
	a.insertLast(3);
	a.insertLast(4);
	//a.print();
	cout<<endl;
	b.insertLast(1);
	b.insertLast(2);
	b.insertLast(3);
	b.insertLast(4);
	//b.print();
	//c.mergeLists(a,b);
	//c.print();
	cout<<"Mean"<<endl;
	int d;
	d=a.mean();
	cout<<d;
	return 0;
}
