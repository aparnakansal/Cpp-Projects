#include<iostream>
#include "unorderedLinkedList.h"
#include "linkedList.h"
using namespace std;

int main(){

	cout<<"Linked List Operation by Aparna"<<endl;

	unorderedLinkedList<int> list1;    //Creating a linked list
	cout<<"Example 1"<<endl;

	//inserting info into linked list
	list1.insertLast(15);
	list1.insertLast(65);
	list1.insertLast(27);
	list1.insertLast(65);
	list1.insertLast(12);

	cout<<"List 1 is:{ ";
	list1.print();    //printing the list
	cout<<"}";
	cout<<endl<<endl;

	cout<<"Case 1"<<endl;
	list1.deleteSmallest();     //Calling deleteSmallest function
	cout<<": length of list 1 after deleting smallest element"<<endl;
	cout<<"List 1 after deleting smallest element:{ ";
	list1.print();     //printing the list after deleting node with smallest element
	cout<<"}";
	cout<<endl<<endl;

	cout<<"Case 2"<<endl;
	list1.deleteSmallest();   //Calling deleteSmallest function again
	cout<<": length of list 1 after deleting smallest element"<<endl;
	cout<<"List 1 after deleting smallest element:{ ";
	list1.print();          //printing the list after deleting node with smallest element
	cout<<"}";
	cout<<endl<<endl;

	cout<<"Case 3"<<endl;
	list1.deleteAll(27);    //Calling deleteAll function
	cout<<": length of list 1 after delete all operation"<<endl;
	cout<<"List 1 after delete all operation:{ ";
	list1.print();        //Printing the list after deleting all occurrences of 12.
	cout<<"}";
	cout<<endl<<endl;

	cout<<"Case 4"<<endl;
	list1.deleteAll(65);    //Calling deleteAll function again
	cout<<": length of list 1 after delete all operation"<<endl;
	cout<<"List 1 after delete all operation:{ ";
	list1.print();      //Printing the list after deleting all occurrences of 65.
	cout<<"}";
	cout<<endl<<endl;

	unorderedLinkedList<int> myList, subList;   //Creating linked lists
	cout<<"Example 2"<<endl;

	//Inserting data into first linked list
	myList.insertLast(34);
	myList.insertLast(65);
	myList.insertLast(27);
	myList.insertLast(89);
	myList.insertLast(12);

	cout<<"myList is:{ ";
	myList.print();   //printing first linked list.
	cout<<"}";
	cout<<endl<<endl;

	cout<<"Case 1"<<endl;
	myList.split2(subList);  //Calling split2 function
	cout<<": Respective lengths of myList & subList after split2 operation"<<endl;
	cout<<"myList after split2 operation:{ ";
	myList.print();        //Printing first list after splitting.
	cout<<"}"<<endl;
	cout<<"subList after split2 operation:{ ";
	subList.print();      //Printing second list after splitting.
	cout<<"}";
	cout<<endl<<endl;

	return 0;
}

