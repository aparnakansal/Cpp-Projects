#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "HugeInteger.h"
using namespace std;



int main(){

	int n1=1234567;
	int n2=9876543;
	int n3=2147483640;

	string s3="123456789";
	string s1="1234567890123456789012345678901234567890";
	string s2="9000000000000000000000000000000000000000";
	string s4="9999999999999999999999999999999999999999";

	//Case 1: Convert long into a HugeInteger Object
	HugeInteger h1(n1);


	// Case 2: Convert a string representing a long int into HugeInteger Object
	HugeInteger h2(s1);


	//Case 3: Addition operator: HugeInteger + HugeInteger
	cout<<"Addition HugeInteger+HugeInteger by Aparna:"<<endl;
	HugeInteger h3(n1);
	HugeInteger h4(n2);
	h3.add(h4);

	HugeInteger h5(s1);
	HugeInteger h6(s2);
	h5.add(h6);


	//Case 4: Addition operator: HugeInteger + int
	cout<<endl<<"Addition HugeInteger+int by Aparna:"<<endl;
	HugeInteger h7(n1);
	h7.add(1234);

	HugeInteger h8(s4);
	h8.add(2147483640);


	//Case 5:Addition operator: HugeInteger + string representing large integer value
	cout<<endl<<"Addition HugeInteger+string by Aparna:"<<endl;
	HugeInteger h9(n1);
	h9.add("123456789");

	HugeInteger h10(n3);
	h10.add("9999999999999999999999999999999999999999");


	//Case 6: subtraction operator (subtract op2 from *this); op1 – op2; op1 & op2 are HugeInteger
	cout<<endl<<"Subtraction HugeInteger-HugeInteger by Aparna:"<<endl;
	HugeInteger h11(n1);
	HugeInteger h12(n2);
	h11.subtract(h12);

	HugeInteger h13(n2);
	HugeInteger h14(n1);
	h13.subtract(h14);


	//Case 7: subtraction operator (subtract op2 from *this); op1 – op2; op1 is HugeInteger & op2 is integer
	cout<<endl<<"Subtraction HugeInteger-int by Aparna:"<<endl;
	HugeInteger h15(n1);
	h15.subtract(99999);

	HugeInteger h16(n1);
	h16.subtract(12345678);


	//Case 8: subtraction operator; subtract op2 from *this); op1 – op2; op1 is HugeInteger & op2 is string
	cout<<endl<<"Subtraction HugeInteger-string by Aparna:"<<endl;
	HugeInteger h17(n1);
	h17.subtract("123456");

	HugeInteger h18(n1);
	h18.subtract("12345678");


	//Case 9: is equal to
	cout<<endl<<"is equal to check by Aparna:"<<endl;
	HugeInteger h19(n1);
	HugeInteger h20(n2);

	bool c=h19.isEqualTo(h20);
	if(c==0){
		cout<<"False! HugeIntegers are not equal"<<endl;
	}
	else{
		cout<<"True! HugeIntegers are equal"<<endl;
	}

	HugeInteger h21(n1);
	HugeInteger h22(n1);

	bool d=h21.isEqualTo(h22);
	if(d==0){
		cout<<"False! HugeIntegers are not equal"<<endl;
	}
	else{
		cout<<"True! HugeIntegers are equal"<<endl;
	}


	//Case 10: not equal to
	cout<<endl<<"is not equal to check by Aparna:"<<endl;
	bool l=h19.isNotEqualTo(h20);
	if(l==0){
		cout<<"False! HugeIntegers are equal"<<endl;
	}
	else{
		cout<<"True! HugeIntegers are not equal"<<endl;
	}


	//Case 11: greater than
	cout<<endl<<"is greater than check by Aparna:"<<endl;
	bool e=h20.isGreaterThan(h19);
	if(e==0){
		cout<<"False! First HugeInteger is not Greater than Second HugeInteger"<<endl;
	}
	else{
		cout<<"True! First HugeInteger is Greater than Second HugeInteger"<<endl;
	}


	//Case 12: less than
	cout<<endl<<"is less than check by Aparna:"<<endl;
	bool f=h19.isLessThan(h20);
	if(f==0){
		cout<<"False! First HugeInteger is not Less than Second HugeInteger"<<endl;
	}
	else{
		cout<<"True! First HugeInteger is Less than Second HugeInteger"<<endl;
	}


	//Case 13: greater than or equal to
	cout<<endl<<"is Greater than or equal to check by Aparna:"<<endl;
	bool g=h20.isGreaterThanOrEqualTo(h19);
	if(g==0){
		cout<<"False! First HugeInteger is not Greater than or equal to Second HugeInteger"<<endl;
	}
	else{
		cout<<"True! First HugeInteger is Greater or equal to Second HugeInteger"<<endl;
	}
	bool h=h21.isGreaterThanOrEqualTo(h22);
	if(h==0){
		cout<<"False! First HugeInteger is not Greater than or equal to Second HugeInteger"<<endl;
	}
	else{
		cout<<"True! First HugeInteger is Greater or equal to Second HugeInteger"<<endl;
	}


	//Case 14: less than or equal
	cout<<endl<<"is Less than or equal to check by Aparna:"<<endl;
	bool i=h19.isLessThanOrEqualTo(h20);
	if(i==0){
		cout<<"False! First HugeInteger is not Less than or equal to Second HugeInteger"<<endl;
	}
	else{
		cout<<"True! First HugeInteger is Less or equal to Second HugeInteger"<<endl;
	}
	bool j=h21.isLessThanOrEqualTo(h22);
	if(j==0){
		cout<<"False! First HugeInteger is not Less than or equal to Second HugeInteger"<<endl;
	}
	else{
		cout<<"True! First HugeInteger is Less or equal to Second HugeInteger"<<endl;
	}


	//Case 15:  is zero?
	cout<<endl<<"is Zero check by Aparna:"<<endl;
	HugeInteger h24("123456");
	bool k=h24.isZero();
	if(k==0){
		cout<<"False! HugeInteger is  not Zero"<<endl;
	}
	else{
		cout<<"True! HugeInteger is Zero"<<endl;
	}


	//Case 16:convert a string representing a large integer into a HugeInteger
	cout<<endl<<"converting string to HugeInteher object by Aparna:";
	h20.input("99994254136712434261");


	//Case 17: display the HugeInteger, skip leading zeros
	cout<<endl<<"Output:Displaying HugeInteger skipping leading zeroes by Aparna:"<<endl;
	string s5="0000000000000000000000012345678765432";
	cout<<s5<<" after skipping leading zeroes:";
	HugeInteger h23(s5);
	h23.output();


	return 0;
}
