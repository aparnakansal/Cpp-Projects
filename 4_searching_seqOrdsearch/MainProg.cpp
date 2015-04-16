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
int a=list.seqOrdSearch(3);
cout<<endl<<"a"<<a;
int b=list.seqOrdSearch(9);
cout<<endl<<"b"<<b;


	return 0;
}
