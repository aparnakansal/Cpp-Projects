#include<iostream>
#include<stdio.h>
#include "myStack.h"
using namespace std;

int main(){
	cout<<"hi";
	stackType<int> list1, list2;
	list1.push(1);
	list1.push(2);
	list1.push(3);
	list1.push(4);

	list1.reverseStack(list2);



	while(!list1.isEmptyStack()){
		cout<<list1.top();
		list1.pop();
	}
cout<<endl;
	while(!list2.isEmptyStack()){
			cout<<list2.top();
			list2.pop();
		}

	return 0;
}

