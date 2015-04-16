#include<iostream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include<vector>

using namespace std;
class HugeInteger{
public:
	static const short size=40;
	HugeInteger():vi(size)
	{

	}
	HugeInteger(long n );
	//Purpose: To convert a long int into HugeInteger Object
	//PreCondition: A long int is passed as an arguement in parameterized constructor
	//PostCondition: HugeInteger Object is created and each digit of long is stored in vector vi

	HugeInteger(const std::string &);
	//Purpose: To convert a string into HugeInteger Object
	//PreCondition: A string is passed as an arguement in parameterized constructor
	//PostCondition: HugeInteger Object is created and each character of string is stored in vector vi

	HugeInteger add( const HugeInteger & ) const;
	//Purpose: To add two HugeInteger
	//PreCondition: A HugeInteger object is passed as an arguement
	//PostCondition: The values stored in each HugeInteger's object's vector are added digit by digit and stored in another HugeInteger Object's vector and that object is returned by the function. The addition is displayed on console.
    //An Additon Overflow error is displayed if the number of digits after addition is greater than 40

	HugeInteger add( int ) const;
	//Purpose: To add a HugeInteger to an int
	//PreCondition: int value is passed as an arguement
	//PostCondition: The values stored in HugeInteger's object's vector are added digit by digit to the int value and stored in another HugeInteger Object's vector and that object is returned by the function. The addition is displayed on console
	//An Additon Overflow error is displayed if the number of digits after addition is greater than 40

	HugeInteger add(const std::string &)const;
	//Purpose: To add a HugeInteger to a string
	//PreCondition: string value is passed as an arguement
	//PostCondition: The values stored in HugeInteger's object's vector are added digit by digit to each character of string and stored in another HugeInteger Object's vector and that object is returned by the function. The addition is displayed on console
	//An Additon Overflow error is displayed if the number of digits after addition is greater than 40

	HugeInteger subtract( const HugeInteger & op2  ) const;
	//Purpose: To subtract a HugeInteger from another HugeInteger
	//PreCondition: A HugeInteger object is passed as an arguement
	//PostCondition: The values stored in each HugeInteger's object's vector are subtracted digit by digit and stored in another HugeInteger Object's vector and that object is returned by the function. The subtraction is displayed on console.
    //An error is displayed if the number in first HugeInteger Object is smaller than that in second HugeInteger Object.

	HugeInteger subtract(int op2) const;
	//Purpose: To subtract an integer from HugeInteger Object
	//PreCondition: int value is passed as an arguement
	//PostCondition: Each Digit of int value is subtracted digit by digit from HugeInteger's object's vector and stored in another HugeInteger Object's vector and that object is returned by the function. The subtraction is displayed on console.
	//An error is displayed if the number in  HugeInteger Object is smaller than the integer value.

	HugeInteger subtract(const std::string & op2) const;
	//Purpose: To subtract a string from HugeInteger
	//PreCondition: string value is passed as an arguement
	//PostCondition: Each character of string value is subtracted digit by digit from HugeInteger's object's vector and stored in another HugeInteger Object's vector and that object is returned by the function. The subtraction is displayed on console.
	//An error is displayed if the number in  HugeInteger Object is smaller than the string value.

	bool isEqualTo( const HugeInteger & ) const;
	//Purpose: To compare two HugeIntegers on the basis of value stored in their vectors.
	//PreCondition: A HugeInteger object is passed as an arguement
	//PostCondition: Value in both HugeInteger objects are compared and returned true if they are equal else return false.

	bool isNotEqualTo( const HugeInteger & ) const;
	//Purpose: To compare two HugeInteger on the basis of value stored in their vectors.
	//PreCondition: A HugeInteger object is passed as an arguement
	//PostCondition: Value in both HugeInteger objects are compared and returned false if they are equal else return false.

	bool isGreaterThan( const HugeInteger & ) const;
	//Purpose: To compare two HugeInteger on the basis of value stored in their vectors.
	//PreCondition: A HugeInteger object is passed as an arguement
	//PostCondition: Value in both HugeInteger objects are compared and returned true if value in first object is greater than that in second one else return false.

	bool isLessThan( const HugeInteger & ) const;
	//Purpose: To compare two HugeInteger on the basis of value stored in their vectors.
	//PreCondition: A HugeInteger object is passed as an arguement
	//PostCondition: Value in both HugeInteger objects are compared and returned true if value in first object is less than that in second one else return false.

	bool isGreaterThanOrEqualTo( const HugeInteger & ) const;
	//Purpose: To compare two HugeInteger on the basis of value stored in their vectors.
	//PreCondition: A HugeInteger object is passed as an arguement
	//PostCondition: Value in both HugeInteger objects are compared and returned true if value in first object is greater than or equal to that in second one else return false.

	bool isLessThanOrEqualTo( const HugeInteger & ) const;
	//Purpose: To compare two HugeInteger on the basis of value stored in their vectors.
	//PreCondition: A HugeInteger object is passed as an arguement
	//PostCondition: Value in both HugeInteger objects are compared and returned true if value in first object is less than or equal to that in second one else return false.

	bool isZero() const;
	//Purpose: To check if the value of HugeInteger is zero
	//PreCondition: Values are set in vector
	//PostCondition: Value in vector is checked and returned true if all values in vector are zero else return false.

	void input(const std::string &);
	//Purpose: To convert a string representing a large integer into a HugeInteger
	//PreCondition: string value is passed as an arguement
	//PostCondition: Each character of string is stored in vector vi

	void output() const;
	//Purpose: To display the HugeInteger, skip leading zeros
	//PreCondition: Values are set in vector
	//PostCondition:The values in vector are displayed on console skipping leading zeroes.

private:
	std::vector<short> vi;
	string temp,x;
	int number[40];
	int count;
};
