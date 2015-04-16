#ifndef H_orderedListType
#define H_orderedListType

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an ordered linked list. This class is
// derived from the class linkedListType.
//***********************************************************

#include "linkedList.h"

using namespace std;

template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the list,
      //               otherwise the value false is returned.

    void insert(const Type& newItem);
      //Function to insert newItem in the list.
      //Postcondition: first points to the new list, newItem
      //               is inserted at the proper place in the
      //               list, and count is incremented by 1.

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
      //               deleteItem is deleted from the list;
      //               first points to the first node of the
      //               new list, and count is decremented by 1.
      //               If deleteItem is not in the list, an
      //               appropriate message is printed.

	void mergeLists(orderedLinkedList<Type> &list1,
				    orderedLinkedList<Type> &list2);
		//This operation creates a new list by merging the elements
     	//of list1 and list2.
        //Precondition: Both lists list1 and list2 are ordered.
        //Postcondition: first points to the merged list.
		//    list1 and list2 are empty.


};


template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current; //pointer to traverse the list

    current = this->first;  //start the search at the first node

    while (current != NULL && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;

    if (found)
       found = (current->info == searchItem); //test for equality

    return found;
}//end search


template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    nodeType<Type> *newNode;  //pointer to create a node

    bool  found;

    newNode = new nodeType<Type>; //create the node
    newNode->info = newItem;   //store newItem in the node
    newNode->link = NULL;      //set the link field of the node
                               //to NULL

    if (this->first == NULL)  //Case 1
    {
    	this->first = newNode;
    	this->last = newNode;
    	this->count++;
    }
    else
    {
        current = this->first;
        found = false;

        while (current != NULL && !found) //search the list
           if (current->info >= newItem)
               found = true;
           else
           {
               trailCurrent = current;
               current = current->link;
           }

        if (current == this->first)      //Case 2
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else                       //Case 3
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if (current == NULL)
            	this->last = newNode;

            this->count++;
        }
    }//end else
}//end insert

template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}//end insertFirst

template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}//end insertLast

template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (this->first == NULL) //Case 1
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = this->first;
        found = false;

        while (current != NULL && !found)  //search the list
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == NULL)   //Case 4
            cout << "The item to be deleted is not in the "
                 << "list." << endl;
        else
            if (current->info == deleteItem) //the item to be
                                   //deleted is in the list
            {
                if (this->first == current)       //Case 2
                {
                	this->first = this->first->link;

                    if (this->first == NULL)
                    	this->last = NULL;

                    delete current;
                }
                else                         //Case 3
                {
                    trailCurrent->link = current->link;

                    if (current == this->last)
                    	this->last = trailCurrent;

                    delete current;
                }
                this->count--;
            }
            else                            //Case 4
                cout << "The item to be deleted is not in the "
                     << "list." << endl;
    }
}//end deleteNode

template <class Type>
void orderedLinkedList<Type>::mergeLists(orderedLinkedList<Type> &list1, orderedLinkedList<Type> &list2){
	nodeType<Type> *lastMerge;
	nodeType<Type> *first1;
	nodeType<Type> *first2;

	first1=list1.first;
	first2=list2.first;
	//this->count=list1.count+list2.count;

	if(list1.first==NULL){
		this->first=list2.first;
		list2.first=NULL;
		this->count=list2.count;

	}

	else if(list2.first==NULL){
			this->first=list1.first;
			list1.first=NULL;
			this->count=list1.count;

		}
	else{
		if(first1->info<first2->info){
			this->first=first1;
			first1=first1->link;
			lastMerge=this->first;
		}
		else{
			this->first=first2;
			first2=first2->link;
			lastMerge=this->first;
		}

		while(first1!=NULL && first2!=NULL){
			if(first1->info<first2->info){
				lastMerge->link=first1;
				lastMerge=lastMerge->link;
				first1=first1->link;
			}
			else{
				lastMerge->link=first2;
				lastMerge=lastMerge->link;
				first2=first2->link;
			}
		}
		if(first1==NULL){
			lastMerge->link=first2;
		}
		else{
			lastMerge->link=first1;
		}
		list1.first=NULL;
		list1.last=NULL;
		list2.first=NULL;
		list2.last=NULL;
		//this->count=list1.count+list2.count;

	}
}



#endif
