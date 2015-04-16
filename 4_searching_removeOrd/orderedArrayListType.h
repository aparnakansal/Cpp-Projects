# include<iostream>
# include<stdio.h>
# include "arrayListType.h"
using namespace std;

template <class elemType>
class orderedArrayListType:public arrayListType<elemType>{
public:

void removeOrd(const elemType& item);
int binarySearch(const elemType& item) const;

};

template <class elemType>
int orderedArrayListType<elemType>::binarySearch(const elemType& item) const{
int first=0;
int last=this->length-1;
bool found=false;
int mid;

while(first!=last&& !found){

mid=(first+last)/2;

if(this->list[mid]==item){
	found=true;
}
else if(this->list[mid]<item){
	first=mid+1;
}
else{
	last=mid-1;
}

}
if(found){
	return mid;
}
else return -1;
}

template <class elemType>
void orderedArrayListType<elemType>::removeOrd(const elemType& item){
	int loc;
	if(this->length==0)
{
		cout<<"can't delete from an empty list";
		}
	else{
		loc=binarySearch(item);
		if(loc!=-1){
			this->removeAt(loc);
		}
		else{
			cout<<"not present in the list";
		}
	}
}
