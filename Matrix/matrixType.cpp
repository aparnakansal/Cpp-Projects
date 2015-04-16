#include <iostream>
#include "matrixType.h"

using namespace std;
matrixType::matrixType(){
	//Default Constructor
	rowSize=0;//Initializing row size
	columnSize=0;//Initializing column size
	for(int i=0;i<rowSize;i++){     // Initialize array, matrix
		for(int j=0;j<columnSize;j++){
			matrix[i][j]=0;
		}
	}

}

matrixType::matrixType(int row_size,int column_size){
	// Taking row size and column size from the user through constructor and member variables.
	rowSize=row_size;
	columnSize=column_size;
// Creating two dimensional array
	matrix=new int* [rowSize];
	for (int a=0;a<rowSize;a++){
		matrix[a]=new int[columnSize];
	}
}

void matrixType::setMatrix(){
	//int element;
	cout<<"Enter values to be inserted in Matrix of size "<< rowSize <<"*"<< columnSize << endl;
	for (int m = 0; m < rowSize; m++){ // Setting the values of rows and columns of matrix by taking the values from user.
	for (int n= 0; n < columnSize; n++){
			cin>>matrix[m][n];
			//cout<<endl;
	}
}

}
ostream& operator<<(ostream& out,const matrixType &m){
	//Display the values of matrix
for(int i=0;i<m.rowSize;i++){
	for(int j=0;j<m.columnSize;j++){// displaying values one by one.
		out<<m.matrix[i][j];
		cout<<" ";
	}
	cout<<endl;
}
return out;// Returning output stream object.
}



matrixType::matrixType(const matrixType &c){
	//Copy Constructor
	rowSize=c.rowSize; // Initializing row size
	columnSize=c.columnSize;  // Initializing column size

	matrix=new int*[rowSize];

	for(int i=0;i<rowSize;i++){
	matrix[i]=new int[columnSize];
	}
	for(int m=0;m<rowSize;m++){ //Deep Copying the values of one matrix to another.
		for(int n=0;n<columnSize;n++){
			matrix[m][n]=c.matrix[m][n];
		}
	}
}
istream& operator>>(istream& in,const matrixType &m){
	cout<<"Enter values to be inserted in Matrix of size "<< m.rowSize <<"*"<< m.columnSize<<endl;
for(int b=0;b<m.rowSize;b++){//Inputting the values into matrix by taking values from the user
	for(int c=0;c<m.columnSize;c++){
		in>>m.matrix[b][c];
	}
}
return in;// Returning input stream object.
}

matrixType matrixType::operator+(const matrixType& add){
	cout<<"ADDITION OF TWO MATRICES BY APARNA"<<endl;
	matrixType final_add(add.rowSize,add.columnSize);// Creating new object to store the values of addition.

		for(int i=0;i<rowSize;i++){
			for(int j=0;j<columnSize;j++){// Adding the values of matrix one by one and storing into final_add.
			final_add.matrix[i][j]=this->matrix[i][j]+add.matrix[i][j];
			}
		}
		//cout<<final_add;

	return final_add;// Returning matrixType object that holds the addition values.
}

matrixType matrixType::operator-(const matrixType& subtract){
	cout<<"SUBTRACTION OF TWO MATRICES BY APARNA"<<endl;
	matrixType final_subtract(subtract.rowSize,subtract.columnSize);// Creating new object to store the values of subtraction.

		for(int i=0;i<rowSize;i++){
			for(int j=0;j<columnSize;j++){// Subtracting the values of matrix one by one and storing into final_subtract.
			final_subtract.matrix[i][j]=this->matrix[i][j]-subtract.matrix[i][j];
			}
		}
	return final_subtract;// Returning matrixType object that holds the subtraction values.
}

matrixType matrixType::operator*(const matrixType& multiply){
	cout<<"MULTIPLICATION OF TWO MATRICES BY APARNA"<<endl;
	matrixType final_multiply(rowSize,multiply.columnSize);// Creating new object to store the values of multiplication.


		for(int i=0;i<rowSize;i++){// Multiplying the values of matrix one by one and storing into final_multiply.
			for(int j=0;j<multiply.columnSize;j++){
				final_multiply.matrix[i][j]=0;
				for(int m=0;m<columnSize;m++){
			final_multiply.matrix[i][j]=final_multiply.matrix[i][j]+(matrix[i][m]*multiply.matrix[m][j]);
			}
		}
		}

	return final_multiply;// Returning matrixType object that holds the multiplication values.
}

matrixType& matrixType::operator=(const matrixType& equal){
	if(&equal!=this){// To check if a copy of the object already exists or not
		rowSize=equal.rowSize;// Initialize row size
		columnSize=equal.columnSize;// Initialize column size
		for(int i=0;i<rowSize;i++){// Storing values in the matrix one by one.
			for(int j=0;j<columnSize;j++){
				this->matrix[i][j]=equal.matrix[i][j];
			}
		}
	}
	return *this;
}


matrixType::~matrixType(){
	//Destructor
	for(int a=0;a<rowSize;a++){
		// Deleting the matrix values.
		delete[] matrix[a];
	}
	//cout<<"object is destroyed"<<endl;
}
