#include<iostream>
#include "unorderedLinkedList.h"
using namespace std;


int main(){
	cout<<"hi"<<endl;
	unorderedLinkedList<int> a,b;
	a.insertLast(1);
	a.insertLast(2);
	a.insertLast(3);
	a.insertLast(4);
	a.insertLast(5);
	a.insertLast(6);
	a.insertLast(7);
	a.print();
a.divideAt(b,3);
cout<<"a value";
a.print();
cout<<endl;
cout<<"b value";
b.print();
	return 0;
}
