#include<iostream>
#include "unorderedLinkedList.h"
using namespace std;


int main(){
	cout<<"hi";
	unorderedLinkedList<int> a;
	a.insertLast(1);
	a.insertLast(3);
    a.insertLast(5);
	a.insertLast(6);
	a.insertLast(2);
	a.print();
	cout<<endl;
	a.deleteKThElement(1);
	a.print();
	cout<<"my element deleted";
	return 0;
}
