#include<iostream>
#include<stdio.h>
#include "linkedStack.h"
using namespace std;

int main(){
	cout<<"hi";
	linkedStackType<int> list1, list2;
	list1.push(1);
	list1.push(2);
	list1.push(3);
	list1.push(4);

	list2.push(1);
		list2.push(2);
		list2.push(3);
		list2.push(4);
bool a=list1==list2;
cout<<"result"<<a<<endl;
	while(!list1.isEmptyStack()){
		cout<<list1.top();
		list1.pop();
	}

	return 0;
}
