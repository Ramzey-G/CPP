#include "Triplet.h"

/*
 Ramzey Ghanaim

 This is the implementation file which has triplet constructors and deffinitions for
 overloading operators such as:
 +
 -
 ++
 --


*/

Triplet::Triplet(){//deafault constructor
	data[0]=0;
	data[1]=0;
	data[2]= 0;
}
Triplet::Triplet(int value){ //constructor with one input value
	data[0]=value;
	data[1]=value;
	data[2]= value;
}

Triplet::Triplet(int value1, int value2, int value3){//constructor with three inputs
		
			data [0]= value1;
			data[1]= value2;
			data [2] = value3;
	}
int Triplet::getFirst() const{ //gets first number
	return data[0];
}
int Triplet::getSecond() const{ //gets second number
	return data[1];
}
int Triplet::getThird() const{ //gets third number
	return data[2];
}
const Triplet Triplet:: operator+(const Triplet& operand) const{ //defines addition for triplets
	int newVal1= data[0] + operand.data[0];
	int newVal2 = data[1] + operand.data[1];
	int newVal3 = data[2] + operand.data[2];
	Triplet temp(newVal1, newVal2, newVal3);
	return temp; //returns the new triplet that contains the sum
}
const Triplet Triplet:: operator-(const Triplet& operand) const{ //defines subtraction for Triplets
	int newVal1= data[0] - operand.data[0]; //val1 is the implied obj
	int newVal2 = data[1] - operand.data[1];
	int newVal3 = data[2] - operand.data[2];
	Triplet temp(newVal1, newVal2, newVal3);
	return temp; //returns the new triplet which contains subtracted value
}
const Triplet Triplet:: operator++(int){ //defines the incrementor for triplets
	data[0]++;
	data[1]++;
	data[2]++;
	Triplet temp(data[0], data[1], data[2]);
	return temp; //returns an incremented triplet
}

const Triplet Triplet:: operator++(){ //defines the incrementor for triplets
	data[0]++;
	data[1]++;
	data[2]++;
	Triplet temp(data[0], data[1], data[2]);
	return temp;//returns an incremented triplet
}

bool Triplet::operator==(const Triplet& operand) const{ //defines the operator == for triplets
	if(data[0] ==operand.data[0] && data[1] == operand.data[1] && data[2] ==operand.data[2])//ensures that all 3 values equal all 3 values of second tirplet equal the first triplet's values
		return true; //returns true if two triplets are equal
	else //otherwise it returns false
		return false;
}

bool Triplet::operator>(const Triplet& operand) const { //defines the operator > for triplets
	if(data[0]>operand.data[0] && data[1]>operand.data[1] && data[2]>operand.data[2]) //checks to see if all of the numbers in first triplet are >than values in triplet 2
		return true; //returns true if first triplet is gigger than the second triplet
	else
		return false;
}

int& Triplet::operator[](int index){//defines [index] for tirplets . (0,1,2 are legal indicies)
	return data[index]; //returnes the indexted value 
}

void Triplet:: print(ostream& out) const{ //outputs a triplet
	out<<"Triplet value 1 is "<<data[0]<<endl<<"Triplet value 2 is "<<data[1]<<endl
		<<"Triplet value 3 is "<<data[2]<<endl;
}
ostream& operator<< (ostream& out, const Triplet& robject){ //defines getting input for triplets with the "<<" operator
	out<<"First value is ";
	out<<robject.data[0]; //outputs first value
	out<<endl<<"Second value is ";
	out	<< robject.data[1]; //outputs second value
	out<<endl<<"Third value is ";
	out<< robject.data[2]; //outputs third value
	out<<endl;
	return out;

}
istream& operator>> (istream& in,  Triplet& robject){  //gets user input with the ">>" operator
	cout<<"Enter value 1 ";
	in >>robject.data[0]; //gets first value
	cout<<"Enter value 2 ";
	in >> robject.data[1];//gets second value
	cout<<"Enter value 3 ";
	in >>robject.data[2]; //gets third value
	return in;
}

