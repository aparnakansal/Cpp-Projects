/*
 * HexaDecimalAdder.h
 *
 *  Created on: Sep 22, 2014
 *      Author: aparna
 */

#include <iostream>
#include<string>
#include<fstream>

using namespace std;

const int ARRAY_LENGTH = 12;
int carry = 0;
int check=0;
char sum[ARRAY_LENGTH] = { '0', '0', '0', '0', '0', '0', '0', '0','0', '0', '0', '0' };


void keyboard_input(char a[], char b[], char sum[]);
//Purpose:Processes the summation of two hexadecimal numbers when the input is given through keyboard.
//Precondition:All the three char arrays are initialized.
//Postcondition:User inputs are stored in strings 's1' & 's2'.Input hexadecimal numbers are stored in char arrays 'a' & 'b' and their sum is stored in char array 'sum'.

int HexaDecAdd(string s1, string s2, char a[], char b[], char sum[]);
// Purpose:Calculates sum of two hexadecimal numbers entered by the user and stores the result to char array sum.
// Precondition:Both hexadecimal numbers are entered by the user and stored in two strings 's1' & 's2'. All the three char arrays are initialized.
// Postcondition: Two input hexadecimal numbers are stored in char arrays 'a' & 'b' and their sum is stored in char array 'sum', prints error in case of addition overflow.

void answer(ostream& out,const char a[],const char b[],const char c[],int check);
// Purpose:Send both hexadecimal numbers and their sum to the output stream 'out'.
// Precondition: Output Stream 'out' is opened, char arrays 'a' & 'b' stores input hexadecimal numbers and char array 'c' contains the sum.
// Postcondition: input and the result is sent to the output stream 'out'. Returns int value 0 for addition overflow error.


void file_input(char a[],char b[],char sum[]);
//Purpose:Processes the summation of two hexadecimal numbers when the input is given through a file.
//Precondition:Input file has two hexadecimal numbers stored in it. All the three char arrays are initialized.
//Postcondition:Two hexadecimal numbers are stored in char arrays 'a' & 'b' and their sum is stored in char array 'sum'.

int convert(char g);
//Purpose:Processes the Decimal equivalent of Hexadecimal digit.
//Precondition: Each digit of input hexadecimal number is stored in char arrays 'a' & 'b'.
//Postcondition: hexadecimal digit converted into integer and returned.

char convert_again(int g);
//Purpose: Processes the hexadecimal equivalent of decimal digit.
//Precondition:sum of decimal equivalents of hexadecimal digits is performed and provided as a parameter.
//Postcondition: decimal sum of hexadecimal digits is converted into character and returned.



int convert(char g) {
	switch (g) {
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	case '0':
		return 0;
		break;
	case 'A':
		return 10;
		break;
	case 'B':
		return 11;
		break;
	case 'C':
		return 12;
		break;
	case 'D':
		return 13;
		break;
	case 'E':
		return 14;
		break;
	case 'F':
		return 15;
		break;
	default:
		return 0;
		break;

	}

}

char convert_again(int g) {
	switch (g) {
	case 1:
		return '1';
		break;
	case 2:
		return '2';
		break;
	case 3:
		return '3';
		break;
	case 4:
		return '4';
		break;
	case 5:
		return '5';
		break;
	case 6:
		return '6';
		break;
	case 7:
		return '7';
		break;
	case 8:
		return '8';
		break;
	case 9:
		return '9';
		break;
	case 0:
		return '0';
		break;
	case 10:
		return 'A';
		break;
	case 11:
		return 'B';
		break;
	case 12:
		return 'C';
		break;
	case 13:
		return 'D';
		break;
	case 14:
		return 'E';
		break;
	case 15:
		return 'F';
		break;
	}

}



void keyboard_input(char a[], char b[], char sum[]) {
	string s1;
	string s2;

	cout << "please enter a hexadecimal number of 12 or fewer hex digits"<<endl;
	cin >> s1;// Takes first input from the user.
	cout << "please enter a hexadecimal number of 12 or fewer hex digits"<<endl;
	cin >> s2;// Takes second input from the user.

	HexaDecAdd(s1, s2, a, b, sum);
}

void file_input(char a[],char b[],char sum[]){
	string in_path;
	string out_path;
	string string1;
	string string2;

	ifstream instream;
	ofstream outstream;

	cout << "Enter input file path:" << endl;
	cin >> in_path;
	out_path = in_path + "-out"; //appends input file name to output file name.

	instream.open(in_path.c_str());
	outstream.open(out_path.c_str());

	if (instream.fail()) {
		//checks if input file exists
		cout << "Input file does not exist:" << in_path << endl;
		return;
	}

	else{
		cout<<"Input file is found"<<endl;
		while(!instream.eof()){
			if((instream>>string1>>string2)==NULL) break;
			//put two hexadecimal numbers in input file to two strings.
			HexaDecAdd(string1,string2,a,b,sum);
			answer(outstream,a,b,sum,check);

		}
		instream.close();
		outstream.close();
	}
}
int HexaDecAdd(string s1, string s2, char a[], char b[], char sum[]) {
	carry=0;
	int len_s1 = s1.length();
	int len_s2 = s2.length();
	char temp1[len_s1];
	char temp2[len_s2];


	for (int i = 0; i < len_s1; i++) {
		temp1[i] = toupper(s1[len_s1 - 1 - i]);
		if ((temp1[i] != '0') && (temp1[i] != '1') && (temp1[i] != '2')
				&& (temp1[i] != '3') && (temp1[i] != '4') && (temp1[i] != '5')
				&& (temp1[i] != '6') && (temp1[i] != '7') && (temp1[i] != '8')
				&& (temp1[i] != '9') && (temp1[i] != 'A') && (temp1[i] != 'B')
				&& (temp1[i] != 'C') && (temp1[i] != 'D') && (temp1[i] != 'E')
				&& (temp1[i] != 'F')) {
			//checks if the first input string contains digits other than 0-9 & A-F.
			cout << "Sorry! Atleast one of the number typed is not a hexadecimal number.";
			 check=1;
			 return 0;
		}
	}

	if (len_s1 > 12) {
		//checks if the length of the first input string is greater than 12.
		cout
		<< "Invalid entry!Atleast one of the number is greater than 12 digits"<< endl;
		check=1;
					 return 0;
	}

	for (int i = 0; i < len_s2; i++) {
		temp2[i] = toupper(s2[len_s2 - 1 - i]);
		if ((temp2[i] != '0') && (temp2[i] != '1') && (temp2[i] != '2')
				&& (temp2[i] != '3') && (temp2[i] != '4') && (temp2[i] != '5')
				&& (temp2[i] != '6') && (temp2[i] != '7') && (temp2[i] != '8')
				&& (temp2[i] != '9') && (temp2[i] != 'A') && (temp2[i] != 'B')
				&& (temp2[i] != 'C') && (temp2[i] != 'D') && (temp2[i] != 'E')
				&& (temp2[i] != 'F')) {
			//checks if the second input string contains digits other than 0-9 & A-F.
			cout << "Sorry! Atleast one of the number typed is not a hexadecimal number.";
			check=1;
						 return 0;
		}
	}

	if (len_s2 > 12) {
		//checks if the length of the second input string is greater than 12
		cout
		<< "Invalid entry!Atleast one of the number is greater than 12 digits"<< endl;
		check=1;
					 return 0;
	}

	else {
		for (int i = 0; i < len_s1; i++) {
			a[i] = toupper(s1[len_s1 - 1 - i]);
		}
		//Converts the first input string to upper case and stores in char array 'a' in reversed order.

		cout << endl;
		for (int i = 0; i < len_s2; i++) {
			b[i] = toupper(s2[len_s2 - 1 - i]);
		}
		//Converts the second input string to upper case and stores in char array 'b' in reversed order.

		cout << endl;

		for (int i = 0; i < ARRAY_LENGTH; i++) {
			int temp1 = convert(a[i]);//converts each character of char array 'a' in integer.
			int temp2 = convert(b[i]);//converts each character of char array 'b' in integer.
			int total = temp1 + temp2 + carry;
			if (i < ARRAY_LENGTH - 1) {
				//checks for the index value
				if (total< 16) {
					sum[i] = convert_again(total);//converts sum of two integers into char and stores in char array 'sum' if total is less than 16.
					carry = 0;
				} else {

					sum[i] = (convert_again(total - 16));
					carry = 1;//carry is for next digit if the total is greater than 16.
					//
				}
			} else {

				if (total < 16) {
					sum[i] = convert_again(total);
					carry = 0;
				} else {
					cout << "Addition Overflow Error";//throws error if number of digits is greater than 12.
					check=2;
					return 0;
				}
			}

		}
		cout << endl;
		answer(cout,a,b,sum,check);//sends output stream and three char arrays to another function to print the output.
	}
}
void answer(ostream& out,const char a[],const char b[],const char c[],int check){
if(check==2){
	out<<"Addition Overflow Error";//prints Addition overflow error in output file if number of digits in output is greater than 12.
}
else{
	for(int i=ARRAY_LENGTH-1;i>=0;i--){
		out<<a[i];
	}
	//prints first input hexadecimal number.
	out<<"+";

	for(int i=ARRAY_LENGTH-1;i>=0;i--){
		out<<b[i];
	}
	//prints second input hexadecimal number.
	out<<"=";

	for(int i=ARRAY_LENGTH-1;i>=0;i--){
		out<<c[i];
	}
	//prints the sum of two hexadecimal numbers.
	out<<endl;
}
}



