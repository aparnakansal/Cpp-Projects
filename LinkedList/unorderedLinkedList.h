#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an unordered linked list. This class is
// derived from the class linkedListType.
//***********************************************************

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
public:
	bool search(const Type& searchItem) const;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the
	//               list, otherwise the value false is
	//               returned.

	void insertFirst(const Type& newItem);
	//Function to insert newItem at the beginning of the list.
	//Postcondition: first points to the new list, newItem is
	//               inserted at the beginning of the list,
	//               last points to the last node in the
	//               list, and count is incremented by 1.

	void insertLast(const Type& newItem);
	//Function to insert newItem at the end of the list.
	//Postcondition: first points to the new list, newItem
	//               is inserted at the end of the list,
	//               last points to the last node in the
	//               list, and count is incremented by 1.

	void deleteNode(const Type& deleteItem);
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing
	//               deleteItem is deleted from the list.
	//               first points to the first node, last
	//               points to the last node of the updated
	//               list, and count is decremented by 1.

	void deleteAll(const Type& deleteItem);
	//Purpose: Function to delete all the occurrences of deleteItem in the linked list.
	//Precondition: an unordered linked list is created with first pointing to the first node,
	//last pointing to the last node and count equals to the number of elements in the linked list.
	//Postcondition: All the nodes containing deleteItem are deleted from the linked list and count
	//is decremented by the value equal to the number of occurrences of deleteItem in the linked list.first points
	//to the first node,last points to the last node of the updated linked list.

	void deleteSmallest();
	//Purpose: Function to delete the first occurrence of the smallest element from the linked list.
	//Precondition: an unordered linked list is created with first pointing to the first node,
	//last pointing to the last node and count equals to the number of elements in the linked list.
	//Postcondition:The node containing the first occurrence of the smallest element is deleted from the linked list.first points
	//to the first node,last points to the last node of the updated linked list. count is decremented by one.

};


template <class Type>
bool unorderedLinkedList<Type>::
search(const Type& searchItem) const
{
	nodeType<Type> *current; //pointer to traverse the list
	bool found = false;

	current = this->first; //set current to point to the first
	//node in the list

	while (current != NULL && !found)    //search the list
		if (current->info == searchItem) //searchItem is found
			found = true;
		else
			current = current->link; //make current point to
	//the next node
	return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	newNode->info = newItem;    //store the new item in the node
	newNode->link = this->first;      //insert newNode before first
	this->first = newNode;            //make first point to the
	//actual first node
	this->count++;                    //increment count

	if (this->last == NULL)   //if the list was empty, newNode is also
		//the last node in the list
		this->last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	newNode->info = newItem;  //store the new item in the node
	newNode->link = NULL;     //set the link field of newNode
	//to NULL

	if (this->first == NULL)  //if the list is empty, newNode is
		//both the first and last node
	{
		this->first = newNode;
		this->last = newNode;
		this->count++;        //increment count
	}
	else    //the list is not empty, insert newNode after last
	{
		this->last->link = newNode; //insert newNode after last
		this->last = newNode; //make last point to the actual
		//last node in the list
		this->count++;        //increment count
	}
}//end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	bool found;

	if (this->first == NULL)    //Case 1; the list is empty.
		cout << "Cannot delete from an empty list."
		<< endl;
	else
	{
		if (this->first->info == deleteItem) //Case 2
		{
			current = this->first;
			this->first = this->first->link;
			this->count--;
			if (this->first == NULL)    //the list has only one node
				this->last = NULL;
			delete current;
		}
		else //search the list for the node with the given info
		{
			found = false;
			trailCurrent = this->first;  //set trailCurrent to point
			//to the first node
			current = this->first->link; //set current to point to
			//the second node

			while (current != NULL && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current-> link;
				}
				else
					found = true;
			}//end while

			if (found) //Case 3; if found, delete the node
			{
				trailCurrent->link = current->link;
				this->count--;

				if (this->last == current)   //node to be deleted
					//was the last node
					this->last = trailCurrent; //update the value
				//of last
				delete current;  //delete the node from the list
			}
			else
				cout << "The item to be deleted is not in "
				<< "the list." << endl;
		}//end else
	}//end else
}//end deleteNode



template <class Type>
void unorderedLinkedList<Type>::deleteSmallest(){
	cout<<"Delete Smallest operation by Aparna"<<endl;
	nodeType<Type> *current;   //pointer to traverse the linked list.
	nodeType<Type> *pre;      //pointer just before the node which contains smallest element.
	nodeType<Type> *smallest; //pointer to the node which contains smallest element.
	nodeType<Type> *next;   //pointer just before the pointer current.

	if(this->first==NULL){  //to check if list is empty.
		cout<<"List is empty. Not able to delete"<<endl;
	}
	if(this->first->link==NULL){ //to check if list has only one node.
		this->first=NULL;       //delete the only node in the list, which contains the smallest element.
		delete this->last;
		this->last=NULL;
	}
	else{
		smallest=this->first;
		next=this->first;
		current=this->first->link; //pointing to second node.

		while(current!=NULL){
			if(smallest->info>=current->info){ //compare the values at two nodes
				pre=next;
				smallest=current;
			}
			next=current;      //traversing the list.
			current=current->link;  //traversing the list.
		}
		if(smallest==this->first){   //to check if smallest element is at first node.
			this->first=this->first->link; //moving first to second node.
			this->count--; //decrementing the list size.
		}
		else{
			pre->link=smallest->link;
			if(smallest==this->last){ //to check if smallest element is at last node.
				this->last=pre;
				this->count--;
			}
		}
		delete smallest; //Deleting smallest element from the list.
	}
	cout<<this->count;
}

template <class Type>
void unorderedLinkedList<Type>::deleteAll(const Type& deleteItem){
	cout<<"Delete All operation by Aparna"<<endl;
	nodeType<Type> *current;           // pointer to traverse the linked list.
	nodeType<Type> *trailCurrent;      //pointer just before the pointer current.
	if(this->first==NULL){             //to check if the list is empty.
		cout<<"The list is empty. Nothing can be deleted";
	}
	else{

		current=this->first; //pointing to first node.
		while(current!=NULL){
			if(current->info==deleteItem){ //to check if the node contains deleteItem
				if(current==this->first){   //if deleteItem exists at first node
					this->first=this->first->link;
					this->count--;
					delete current;      //deleting the node.
					current=current->link;
					if(this->first==NULL){  //to check if there was only one element in the list.
						this->last=NULL;
					}
				}
				else{
					trailCurrent->link=current->link;
					if(current==this->last){    //if pointer is at last node
						this->last=trailCurrent;
					}
					delete current;         //deleting the node
					this->count--;         //decrementing list size
					current=trailCurrent->link;

				}
			}
			else{
				trailCurrent=current;  //Traversing the list.
				current=current->link;
			}
		}

	}
	cout<<this->count;
}
#endif
