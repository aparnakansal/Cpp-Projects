# include<iostream>
#include<stdio.h>
# include "arrayListType.h"
using namespace std;

int main(){
	cout<<"hi";
int loc;
	arrayListType<int> list;
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);

	list.print();
	cout<<endl;

	loc=list.recursiveseqsearch(5);
	cout<<"loc is"<<loc;

}
