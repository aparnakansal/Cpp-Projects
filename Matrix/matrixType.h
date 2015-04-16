#include<iostream>

using namespace std;

class matrixType{
	friend ostream& operator<<(ostream&,const matrixType&);
	//Overloading stream extraction (<<)
	//Purpose: To display the values stored in array of the object by overloading << operator;
	//Precondition: An object of matrixType is created and passed to the function.
	//Postcondition: The values stored in the dynamic array of the object is displayed on console.

	friend istream& operator>>(istream&,const matrixType&);
	//Overloading stream insertion (>>)
	//Purpose: To input the values of array for the object by overloading >> operator;
	//Precondition: An object of matrixType is created and passed to the function.
	//Postcondition: The values for the dynamic array of object is taken from the user and stored into it.
public:
	matrixType();
	matrixType(int row_size,int column_size);
	//Purpose: To create a two dimensional array by taking the size of row and column from the user;
	//Precondition: An object of matrixType is created and the size of row and column are passed to the constructor.
	//Postcondition: A two dimensional array with row size and column size equal to the values passed by the user is created.

	matrixType(const matrixType &c);
	//Copy Constructor
	//Purpose: To deep copy the member values of one object of matrixType to another object.
	//Precondition: An object of matrixType is created and passed as an argument to another constructor.
	//Postcondition: A deep copy of member variables is created in the matrixType object.

	void setMatrix();
	//Purpose: To set the values of dynamic array by taking values from the console.
	//Precondition: An object of matrixType is created and no. of rows and columns are specified.
	//Postcondition: The values from the console are set into the dynamic array, matrix.

	matrixType& operator=(const matrixType& equal);
	//Overloading = operator
	//Purpose: To store the values of array of one object to the other by overloading the = operator.
	//Precondition: Two objects of matrixType are created
	//Postondition:The values of array of one object are stored in the array of other object and that object is returned.

	matrixType operator+(const matrixType& add);
	//Overloading + operator.
	//Purpose:To add the matrix of two objects by overloading + operator;
	//Precondition: Two objects of matrixType are created, values of matrix are set into it.
	//Postcondition: The matrices of two objects are added, stored in the matrix of third object and third object is returned.

	matrixType operator-(const matrixType& subtract);
	//Overloading - operator.
	//Purpose:To subtract the matrix of two objects by overloading - operator;
	//Precondition: Two objects of matrixType are created, values of matrix are set into it.
	//Postcondition: The matrices of two objects are subtracted, stored in the matrix of third object and third object is returned.

	matrixType operator*(const matrixType& multiply);
	//Overloading * operator.
	//Purpose:To multiply the matrix of two objects by overloading * operator;
	//Precondition: Two objects of matrixType are created, values of matrix are set into it.
	//Postcondition: The matrices of two objects are multiplied, stored in the matrix of third object and third object is returned.

	~matrixType();
	//Destructor.
	//Purpose: To Destruct an object by deleting the member variables of the object and free the memory.
	//Precondition:An object of matrixType is created and the values of its member variables are initialized.
	//Postcondition: The object is deleted once its functions are over and its memory is freed.

private:
	int **matrix;
	int rowSize,columnSize;
};
