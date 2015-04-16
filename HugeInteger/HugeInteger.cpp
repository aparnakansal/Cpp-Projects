#include<iostream>
#include<vector>
#include<math.h>
#include "HugeInteger.h"

using namespace std;

HugeInteger::HugeInteger(long n )
: vi( size )
{
	long temp1 = n;
	int k=size-1;
	//insert each digit of long into vector vi.
	while (temp1 > 0) {
		short last = temp1 % 10;//Obtain last digit of number
		vi[k]=last;//inserting into vector
		k--;
		temp1 = (temp1 - last) / 10;
	}
}

HugeInteger::HugeInteger(const std::string &temp){
	count=temp.size(); //size of string
	for(int i=count-1;i>=0;i--){
		x=temp[i];
		istringstream buffer(x);
		buffer >> number[i];//convert string digit into int
	}

	//insert each character of long into vector vi.
	for(int k=0;k<size;k++){
		short m=number[k];
		vi.push_back(m);
	}

	int a=size-count;
	int b=0;
	for(int i=0;i<count;i++){//insert in vector in correct order
		vi[a]=number[b];
		a++;
		b++;
	}

	int c=size-count;
	for(int i=0;i<c;i++){//add zeroes to make a 40 digit vector.
		vi[i]=0;
	}
}

HugeInteger HugeInteger::add ( const HugeInteger &h2 ) const{
	HugeInteger temp;//Create a HugeInteger Object, temp
	int carry=0;

	//Adding each digit of both the vectors and carry and storing in temp
	for(int i=size-1;i>=0;i--){
		int total=vi[i]+h2.vi[i]+carry;
		temp.vi[i]=total%10;//insert in vector
		carry=total/10;
	}

	//Display error in case of addition overflow
	if(carry!=0){
		this->output();
		cout<<"+";
		h2.output();
		cout<<"=";
		cout<<"Addition overflow!"<<endl;
		return NULL;
	}
	else{
		//display addition in console by calling output function
		this->output();
		cout<<"+";
		h2.output();
		cout<<"=";
		temp.output();
	}
	cout<<endl;
	return temp;
}

HugeInteger HugeInteger::add (int n) const{
	HugeInteger temp;//Create a HugeInteger Object, temp
	long a=n;
	HugeInteger h1(a);//create another object h1 and call parameterized constructor by passing n
	int carry=0;
	for(int i=size-1;i>=0;i--){
		//Adding each digit of both the vectors and carry and storing in temp
		int total=vi[i]+h1.vi[i]+carry;
		temp.vi[i]=total%10; //insert in vector
		carry=total/10;
	}
	if(carry!=0){
		//Display error in case of addition overflow
		this->output();
		cout<<"+";
		h1.output();
		cout<<"=";
		cout<<"Addition overflow!"<<endl;
		return NULL;
	}
	else{
		//display addition in console by calling output function
		this->output();
		cout<<"+";
		h1.output();
		cout<<"=";
		temp.output();
	}
	cout<<endl;
return temp;
}

HugeInteger HugeInteger::add(const std::string &s)const{
	HugeInteger temp;//Create a HugeInteger Object, temp
	HugeInteger c(s);//create another object c and call parameterized constructor by passing s

	int carry=0;
	for(int i=size-1;i>=0;i--){
		//Adding each digit of both the vectors and carry and storing in temp
		int total=vi[i]+c.vi[i]+carry;
		temp.vi[i]=total%10;// insert in vector
        carry=total/10;
	}
	if(carry!=0){
		//Display error in case of addition overflow
		this->output();
		cout<<"+";
		c.output();
		cout<<"=";
		cout<<"Addition overflow!"<<endl;
		return NULL;
	}
	else{
		//display addition in console by calling output function
		this->output();
		cout<<"+";
		c.output();
		cout<<"=";
		temp.output();
	}
	cout<<endl;
	return temp;
}

HugeInteger HugeInteger::subtract( const HugeInteger & op2 ) const{
	HugeInteger temp;//Create a HugeInteger Object, temp
	int carry=0;
	if(isLessThan(op2)){//to check if 1st HugeInteger is less than second, if yes, display error
		this->output();
		cout<<"-";
		op2.output();
		cout<<"=";
		temp.output();
		cout<<"Error: Tried to subtract larger value from smaller value"<<endl;
		return NULL;
	}
	else {
		for(int i=size-1;i>=0;i--){
			if(carry==0){// in case there is no borrowed value
				if((this->vi[i])-carry>op2.vi[i]||(this->vi[i])-carry==op2.vi[i]){//in case digit in 1st vector is greater than or equal to than in 2nd
					temp.vi[i]=(vi[i]-carry)-op2.vi[i];
					carry=0;
				}
				else{//in case digit in 1st vector is smaller than in 2nd
					int a=vi[i];
					a=a+10;
					carry=1;
					temp.vi[i]=a-op2.vi[i];
				}
			}
			else{//in case there is borrowed value
				if((this->vi[i])-carry>op2.vi[i]||(this->vi[i])-carry==op2.vi[i]){//in case digit in 1st vector is greater than or equal to than in 2nd
					temp.vi[i]=(vi[i]-carry)-op2.vi[i];
					carry=0;
				}
				else{//in case digit in 1st vector is smaller than in 2nd
					int a=vi[i]-carry;
					a=a+10;
					carry=1;
					temp.vi[i]=a-op2.vi[i];
				}

			}
		}
		//display subtraction in console by calling output function
		this->output();
		cout<<"-";
		op2.output();
		cout<<"=";
		temp.output();
	}
	cout<<endl;
return temp;
}

HugeInteger HugeInteger::subtract(int op2) const{
	HugeInteger temp;//Create a HugeInteger Object, temp
	HugeInteger b(op2);//create another object b and call parameterized constructor by passing int op2
	int carry=0;
	if(isLessThan(b)){//to check if 1st HugeInteger is less than second, if yes, display error
		this->output();
		cout<<"-";
		b.output();
		cout<<"=";
		temp.output();
		cout<<"Error: Tried to subtract larger value from smaller value"<<endl;
		return NULL;
	}
	else {
		for(int i=size-1;i>=0;i--){
			if(carry==0){// in case there is no borrowed value
				if((this->vi[i])-carry>b.vi[i]||(this->vi[i])-carry==b.vi[i]){
					temp.vi[i]=(vi[i]-carry)-b.vi[i];
					carry=0;
				}
				else{//in case digit in 1st vector is smaller than in 2nd
					int a=vi[i];
					a=a+10;
					carry=1;
					temp.vi[i]=a-b.vi[i];
				}
			}
			else{// in case there is borrowed value
				if((this->vi[i])-carry>b.vi[i]||(this->vi[i])-carry==b.vi[i]){
					temp.vi[i]=(vi[i]-carry)-b.vi[i];
					carry=0;
				}
				else{//in case digit in 1st vector is smaller than in 2nd
					int a=vi[i]-carry;
					a=a+10;
					carry=1;
					temp.vi[i]=a-b.vi[i];
				}
			}
		}
		//display subtraction in console by calling output function
		this->output();
		cout<<"-";
		b.output();
		cout<<"=";
		temp.output();
	}
	cout<<endl;
	return temp;
}

HugeInteger HugeInteger::subtract(const std::string & op2) const{
	HugeInteger temp;//Create a HugeInteger Object, temp
	string s1=op2;
	HugeInteger d(s1);//create another object d and call parameterized constructor by passing string op2
	int carry=0;
	if(isLessThan(d)){//to check if 1st HugeInteger is less than second, if yes, display error
		this->output();
		cout<<"-";
		d.output();
		cout<<"=";
		temp.output();
		cout<<"Error: Tried to subtract larger value from smaller value"<<endl;
		return NULL;
	}
	else {
		for(int i=size-1;i>=0;i--){
			if(carry==0){// in case there is no borrowed value
				if((this->vi[i])-carry>d.vi[i]||(this->vi[i])-carry==d.vi[i]){
					temp.vi[i]=(vi[i]-carry)-d.vi[i];
					carry=0;
				}
				else{//in case digit in 1st vector is smaller than in 2nd
					int a=vi[i];
					a=a+10;
					carry=1;
					temp.vi[i]=a-d.vi[i];
				}
			}
			else{// in case there is borrowed value
				if((this->vi[i])-carry>d.vi[i]||(this->vi[i])-carry==d.vi[i]){
					temp.vi[i]=(vi[i]-carry)-d.vi[i];
					carry=0;
				}
				else{//in case digit in 1st vector is smaller than in 2nd
					int a=vi[i]-carry;
					a=a+10;
					carry=1;
					temp.vi[i]=a-d.vi[i];
				}
			}
		}
		//display subtraction in console by calling output function
		this->output();
		cout<<"-";
		d.output();
		cout<<"=";
		temp.output();
	}
	cout<<endl;
	return temp;
}

bool HugeInteger::isEqualTo( const HugeInteger &hh ) const{
	int i=0;
	while(vi[i]==hh.vi[i] && i<=size-1){//execute while loop till the corresponding digits of both the vectors are equal
		i++;
	}
	if(i==size){//if while loop executed till the end
		this->output();
		cout<<" & ";
		hh.output();
		cout<<" ";
		return true;//return true if loop reaches the end
	}
	else{//if while loop did not executed till the end
		this->output();
		cout<<" & ";
		hh.output();
		cout<<" ";
		return false;//return false if loop does not reach the end
	}
}

bool HugeInteger::isNotEqualTo( const HugeInteger &hh ) const{
	int i=0;
	while(vi[i]==hh.vi[i] && i<=size-1){//execute while loop till the corresponding digits of both the vectors are equal
		i++;
	}
	if(i==size){//if while loop executed till the end
		this->output();
		cout<<" & ";
		hh.output();
		cout<<" ";
		return false;//return false if loop reaches the end
	}
	else{//if while loop did not executed till the end
		this->output();
		cout<<" & ";
		hh.output();
		cout<<" ";
		return true;//return true if loop does not reach the end
	}
}

bool HugeInteger::isGreaterThan( const HugeInteger &hh ) const{
	for(int i=0;i<size;i++){
		if(vi[i]==0&&hh.vi[i]==0){//to check if all the digits in both the vectors are equal

		}
		else{
			if(vi[i]>hh.vi[i]){//if digit in first number is greater than that in second, return true
				this->output();
				cout<<" & ";
				hh.output();
				cout<<" ";
				return true;
			}
			else if(vi[i]==hh.vi[i]){

			}
			else{//if digit in first number is smaller than that in second, return false
				this->output();
				cout<<" & ";
				hh.output();
				cout<<" ";
				return false;
			}
		}
	}
	this->output();
	cout<<" & ";
	hh.output();
	cout<<" ";
	return false;//return false if all the digits in both the vectors are equal
}

bool HugeInteger::isLessThan( const HugeInteger &hh ) const{
	for(int i=0;i<size;i++){
		if(vi[i]==0&&hh.vi[i]==0){//to check if all the digits in both the vectors are equal

		}
		else{
			if(vi[i]<hh.vi[i]){//if digit in first number is smaller than that in second, return true
				this->output();
				cout<<" & ";
				hh.output();
				cout<<" ";
				return true;
			}
			else if(vi[i]==hh.vi[i]){
			}
			else{//if digit in first number is greater than that in second, return false
				this->output();
				cout<<" & ";
				hh.output();
				cout<<" ";
				return false;
			}
		}
	}
	this->output();
	cout<<" & ";
	hh.output();
	cout<<" ";
	return false;//return false if all the digits in both the vectors are equal
}

bool HugeInteger::isGreaterThanOrEqualTo( const HugeInteger &hh ) const{
	for(int i=0;i<size;i++){//to check if all the digits in both the vectors are equal
		if(vi[i]==0&&hh.vi[i]==0){

		}
		else{
			if(vi[i]>hh.vi[i]){//if digit in first number is greater than that in second, return true
				this->output();
				cout<<" & ";
				hh.output();
				cout<<" ";
				return true;
			}
			else if(vi[i]==hh.vi[i]) {

			}
			else {//if digit in first number is smaller than that in second, return false
				this->output();
				cout<<" & ";
				hh.output();
				cout<<" ";
				return false;
			}
		}
	}
	this->output();
	cout<<" & ";
	hh.output();
	cout<<" ";
	return true;//return true if all the digits in both the vectors are equal
}

bool HugeInteger:: isLessThanOrEqualTo( const HugeInteger &hh ) const{
	for(int i=0;i<size;i++){//to check if all the digits in both the vectors are equal
		if(vi[i]==0&&hh.vi[i]==0){
		}
		else{
			if(vi[i]<hh.vi[i]){//if digit in first number is smaller than that in second, return true
				this->output();
				cout<<" & ";
				hh.output();
				cout<<" ";
				return true;
			}
			else if(vi[i]==hh.vi[i]) {
			}
			else {//if digit in first number is greater than that in second, return false
				this->output();
				cout<<" & ";
				hh.output();
				cout<<" ";
				return false;
			}
		}
	}
	this->output();
	cout<<" & ";
	hh.output();
	cout<<" ";
	return true;//return true if all the digits in both the vectors are equal
}

bool HugeInteger:: isZero() const{
	int i=0;
	while(vi[i]==0 && i<size){//repeat the loop while digit in vector is zero
		i++;
	}

	if(i==size){//if the loop reaches the end of the vector, return true.That means all the digits in vector are zero.
		this->output();
		cout<<" ";
		return true;
	}
	else{//if the loop does not reach the end of the vector, return false.
		this->output();
		cout<<" ";
		return false;
	}
}

void HugeInteger::input(const std::string &s){
	string s1=s;//store the string in string s1
	HugeInteger c(s1);//Create another HugeInteger object and call parameterized constructor by passing the string
	cout<<endl<<"And value in its vector is: ";
	for(int i=0;i<size;i++){//Display the digits got stored in vector of HugeInteger object c
		cout<<c.vi[i];
	}
	cout<<endl;
}

void HugeInteger::output()const{
	int i=0;
	while(vi[i]==0){//repeat the while loop to determine the number of leading zeroes by traversing the vector
		i++;
	}
	for(int k=i;k<size;k++){//display the vector values removing all leading zeroes
		cout<<vi[k];
	}
}
