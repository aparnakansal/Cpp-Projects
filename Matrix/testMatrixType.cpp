#include <iostream>
#include "matrixType.h"

using namespace std;

int main(){

	cout<<"Matrix Operation by Aparna"<<endl;
	int choice;
	char answer = 'Y';
	while ((answer == 'y') || (answer == 'Y'))
	{

		int r1,r2,c1,c2;// To store the values of row size and column size.

		cout<<"Enter 1 for matrix addition, 2 for matrix subtraction and 3 for matrix multiplication";
	    cin>>choice;

	    if(choice==1){
	    	// Taking row size and column size from user.
	             cout<<"Enter the number of rows for matrix addition for matrix m1";
	             cin>>r1;

	             cout<<"Enter the number of columns for matrix addition for matrix m1";
	             cin>>c1;

	             cout<<"Enter the number of rows for matrix addition for matrix m2";
	             cin>>r2;

	             cout<<"Enter the number of columns for matrix addition for matrix m2";
	             cin>>c2;
// Checking if matrices can be added or not.
	                  if(r1!=r2||c1!=c2){
		                cout<<"Matrices can not be added.Either row size or column size is different";
	                       }

	                 else{
	                       matrixType m1(r1,c1); // Creating matrix 1.
	                        m1.setMatrix();// Setting values in matrix 1
	                        cout<<"Displaying values of matrix m1"<<endl;
                            cout<<m1;

	                        matrixType m2(r2,c2);// Creating matrix 2.
	                        m2.setMatrix();// Setting values in matrix 2
	                        cout<<"Displaying values of matrix m2"<<endl;
	                        cout<<m2;

	                        matrixType m3(r1,c1);// Creating matrix 3.
	                        m3=m1+m2;// Adding m1 and m2 and storing result in m3
                            cout<<m3;// displaying m3.
	                     }
	            }


	    else if(choice==2){
	    	// Taking row size and column size from user.
	    	             cout<<"Enter the number of rows for matrix subtraction for matrix m1";
	    	             cin>>r1;

	    	             cout<<"Enter the number of columns for matrix subtraction for matrix m1";
	    	             cin>>c1;

	    	             cout<<"Enter the number of rows for matrix subtraction for matrix m2";
	    	             cin>>r2;

	    	             cout<<"Enter the number of columns for matrix subtraction for matrix m2";
	    	             cin>>c2;
	    	             // Checking if matrices can be subtracted or not.
	    	                  if(r1!=r2||c1!=c2){
	    		                cout<<"Matrices can not be subtracted.Either row size or column size is different";
	    	                       }

	    	                 else{
	    	                       matrixType m1(r1,c1);// Creating matrix 1
	    	                        m1.setMatrix();// Setting values in matrix 1
	    	                        cout<<"Displaying values of matrix m1"<<endl;
	    	                        cout<<m1;

	    	                        matrixType m2(r2,c2);//Creating matrix 2
	    	                        cin>>m2;// Setting values in matrix 2
	    	                        cout<<"Displaying values of matrix m2"<<endl;
	    	                        cout<<m2;
cout<<endl<< "copied the values of second matrix (m2) into third matrix (m3)"<<endl;

	    	                        matrixType m3(m2);// copy constructor
	    	                        cout<<"m3 values now are:"<<endl;
	    	                        cout<<m3;
	    	                        cout<<endl;
	    	                     cout<<"Holding the subtraction result in matrix m2 and displaying values of m2"<<endl;
	    	                        m2=m1-m3;// Subtracting the matrices and storing result in matrix 2.
	    	                        cout<<m2<<endl;
cout<<"Displaying values of m3 again to show that it's not changed after changing values of m2"<<endl;
cout<<m3;

	    	                     }
	    	            }

	      else if(choice==3){
	    	  // Taking row size and column size from user.
	    	    	             cout<<"Enter the number of rows for matrix multiplication for matrix m1";
	    	    	             cin>>r1;

	    	    	             cout<<"Enter the number of columns for matrix multiplication for matrix m1";
	    	    	             cin>>c1;

	    	    	             cout<<"Enter the number of rows for matrix multiplication for matrix m2";
	    	    	             cin>>r2;

	    	    	             cout<<"Enter the number of columns for matrix multiplication for matrix m2";
	    	    	             cin>>c2;
	    	    	             // Checking if matrices can be multiplied or not.
	    	    	                  if(c1!=r2){
	    	    		                cout<<"Matrices can not be multiplied. Column size of first matrix is not equal to row size of second matrix.";
	    	    	                       }

	    	    	                 else{
	    	    	                       matrixType m1(r1,c1);// Creating matrix 1
	    	    	                        m1.setMatrix();// Setting values matrix 1
	    	    	                        cout<<"Displaying values of matrix m1"<<endl;
	    	    	                        cout<<m1;

	    	    	                        matrixType m2(r2,c2);// Creating matrix 2
	    	    	                        m2.setMatrix();// Setting val;ues in matrix 2
	    	    	                        cout<<"Displaying values of matrix m2"<<endl;
	    	    	                        cout<<m2;

	    	    	                        matrixType m3(r1,c2);// Creating matrix 3
	    	    	                        m3=m1*m2;// Multiplying the matrices and storing the result in matrix 3
	    	                                cout<<m3;

	    	    	                     }
	    	    	            }

	    cout<<endl;
	    cout << "continue(y/n)"<<endl;
	    cin >> answer;
	    }
	    cout << "bye!";

		return 0;
}
