#include <iostream>
using namespace std;
/*
 Ramzey Ghanaim
 
 This is the header file which defines a triplet and defines triplet operators
 many operations can be performed with the triplet including:
 *
 +
 -
 ++
 --

 Also, friends of Triplet are used for I/O.
*/
class Triplet{
private:
	int data[3]; //storage of triplet values
	int val1;
	int val2;
	int val3;
public:
	Triplet(); //default constructor
	Triplet(int);
	Triplet(int val1, int val2, int val3);//constructor with three inputs
	int getFirst() const; //gets first val
	int getSecond() const;//gets second val
	int getThird() const; //gets third val
	const Triplet operator+(const Triplet& operand) const; //operator overload
	const Triplet operator-(const Triplet& operand) const; //returns difference 
	const Triplet operator++(int); //  post increment of this Triplet – all ints are incremented
	const Triplet operator++() ;//  pre increment of  this Triplet – all ints are incremented
	bool operator==(const Triplet& operand) const; //returns true if theis object is equal to operand
	bool operator>(const Triplet& operand) const ; //returns true if all three ints in this object are greater than ints in the Triplet operand
	int& operator[](int index);// returns the indexed value (0,1,2 legal indices)
	void print(ostream& out) const;

	friend istream& operator>> (istream& in,  Triplet& robject);
	friend ostream& operator<< (ostream& out, const Triplet& robject);


};

/*
This next definition must be defined outside class since this the * operator is part of the main application file
it is basically a protype defintion.

*/
Triplet operator*(const Triplet& operand, const Triplet& operand2 ); //calcs  product of two Triplets 
