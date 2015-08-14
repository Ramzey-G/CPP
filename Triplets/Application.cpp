#include <iostream>
using namespace std;
#include "Triplet.h"
#include <string>
/*
 Ramzey Ghanaim
 
 This is the main application which creates a triplet thanks to a user's input
 many operations can be performed with the triplet including:
 *
 +
 -
 ++
 --

 The getTriplet() function takes a triplet input in the form (XX,YY,ZZ)
 The parenthesis and must be include in user input. From this input a Triplet is created
 and returned
*/
Triplet getTriplet();
int main(){
	//PART A
	Triplet t1; //from user (uses constructor with 3 inputs)
	Triplet t2;// from user (uses constructor with 3 inputs)
	Triplet t3; //uses default constructor (no inputs)
	Triplet t4(5); //uses val, val, val (1 input)
	Triplet t5= t4; //t5 is the same as t1

	cout<<"First Triplet input";
	cin>> t1;//gets firs triplet input from user
	
	cout<<"Second Triplet input"<<endl;
	cin>>t2; //gets second triplet input from user
	//displays all triplets
	cout<<"TRIPLETS DISPLAY"<<endl<<endl<<"Triplet 1"<<endl;
	cout<<t1; 
	cout<<"Triplet 2"<<endl;
	cout<<t2; 
	cout<<"Triplet 3"<<endl;
	cout<<t3;
	cout<<"Triplet 4"<<endl;
	cout<<t4;
	cout<<"Triplet 5"<<endl;
	cout<<t5;
	//mathmatical operation uses oveloaded operators
	t5 = (t1*2)+(t3+t2) ; //Overides t5 with the mathmatical function 
	 cout << "t4 is " << t5 << endl;



	//PART B
	Triplet t = getTriplet(); //gets a triplet
	t.print(cout); //prints out a triplet

	return 0;
}
Triplet operator*(const Triplet& operand, const Triplet& operand2 ){ //calcs  product of two Triplets
	int val1 = operand.getFirst() *operand2.getFirst();
	int val2 = operand.getSecond() *operand2.getSecond();
	int val3 = operand.getThird() * operand2.getThird();
	Triplet temp(val1, val2, val3);
	return temp; //returns a triplet that is the product of the first two triplets
}
Triplet getTriplet(){
	std::string val1;
	std::string val2;
	std::string val3;
	string str;
	string p = ")";
	cout<<"Enter a triplet in the form (XX,YY,ZZ): ";
	getline(cin, str);
	string comma = ",";
	int pos = str.find_first_of(comma); //pos is the first indext of comma
	int secondComma = str.find_first_of(comma, pos+1);///gets second comma
	val1= str.substr(1, pos-1);//gets the first digit, from '(' (0 index)  to comma (pos-1)
	val2 = str.substr(pos+1, secondComma-1); //gets second digiit from after comma, until 2 positions after
	int pos2 = str.find_first_of(p);
	val3 = str.substr(secondComma+1,pos2-2);
	//cout<<val3<<endl;
	
	//val.substr(1,val.length() -1);
	//cout<<"val 1 "<<val1<<"val2 "<<val2<< "val3 "<< val3;  this line is for debugging
	int value1 = atoi(val1.c_str());
	int value2 = atoi(val2.c_str());
	int value3 = atoi(val3.c_str());
	Triplet temp(value1, value2, value3);
	return temp;
}