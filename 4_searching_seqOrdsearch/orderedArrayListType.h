# include<iostream>
# include<stdio.h>
# include "arrayListType.h"
using namespace std;

template <class elemType>
class orderedArrayListType:public arrayListType<elemType>{
public:

int seqOrdSearch(const elemType& item) const;


};

template <class elemType>
int orderedArrayListType<elemType>::seqOrdSearch(const elemType& item) const{
	int i;
	bool found=false;
	for(i=0;i<this->length;i++){
		if(this->list[i]>=item){
			found=true;
			break;
		}

	}
	if(found){
		if(this->list[i]==item){
			return i;}
			else
				return -1;

	}
	else
		cout<<"not found";
		return -1;
}
