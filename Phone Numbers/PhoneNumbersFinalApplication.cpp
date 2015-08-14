#include <iostream>
using namespace std;
/**
Ramzey Ghanaim

This project keeps track of phone number and their properties.
THIS IS THE FINAL APPLICATION. 

**/
class PhoneNumber { //phone number class defines a phone number
private:
	
	int countryCode; //the country code of a phone number
	int areaCode; //area code of a phone number
	int number; //7 digit phone number
	char type; //H, C or B for home, cell or business
	int year;// year the entry was made

public:
	//declare method prototypes so you can use them in the main method and constructors
	PhoneNumber () { //constructor's default values are as follows:
	countryCode = 43;
	areaCode = 800;
	number = 8675309;
	type = 'H';
	year = 1981;
}
	PhoneNumber(int ccode, int acode, int num, char t, int yr); //constructor when user gives all information
	PhoneNumber(int num, char itype = 'H'); //constructor when user provides number
	PhoneNumber(int acode, int num, char itype = 'C');//constructor when user proviedes number and areacode
	void setCountry(int ccode); //mutator function used to set the country code
	void setArea(int acode); //mutator function used to set the area code
	void setType(char t);//mutator function used to set the type of number
	void setYear(int yr);//mutator function used to set the year
	void setNumber(int num);//mutator function used to set the number

	int getCountry() const; //accessor function, gets the country code
	int getArea() const;//accessor function, gets the area code
	int getNumber() const;//accessor function, gets the number
	char getType() const;//accessor function, gets the type
	int getYear() const;//accessor function, gets the year


	bool doubleDigits() const; //returns true if there are double digits in the 7 digit number
	void printNumber(ostream& out) const; // area code and phone number only
	void printNumberStats(ostream& out) const; // prints all phone information

};



PhoneNumber::PhoneNumber(int ccode, int acode, int num, char t, int yr){ //constructor for an input of all values
countryCode = ccode;
areaCode = acode;
number = num;
type = t;
year = yr;
}

PhoneNumber::PhoneNumber(int num, char itype){ //constructor for input of two values (num and type)
	countryCode = 43;
	areaCode = 800;
	number = num;
	type = itype;
	year = 1981;
}

PhoneNumber::PhoneNumber(int acode, int num, char itype){ //constructor for input of three values (num, areacode, type)
	countryCode = 43;//non specified by user is left as default value
	areaCode = acode;
	number = num;
	type = itype;
	year = 1981; //default
}


void PhoneNumber::setCountry(int ccode) { //sets the country code;
	
	countryCode = ccode; //otherwise ssign wha user put
	
}

void PhoneNumber::setArea(int acode){ //sets area code
	areaCode = acode;
}

void PhoneNumber::setNumber(int num){ //sets number num should be number
	number = num;
}

void PhoneNumber::setType(char t){//sets type of number t should be type
	type = t;
}

void PhoneNumber::setYear(int yr){ //sets year
	year = yr;
}





int PhoneNumber::getCountry() const{ // accessor function
	return countryCode;
}

int PhoneNumber:: getArea() const { //accessor function
	return areaCode;
}

int PhoneNumber::getNumber() const{ //accessor function
	return number;
}

char PhoneNumber::getType() const{ //accessor function
	return type;
}

int PhoneNumber::getYear() const{ //accessor function
	return year;
}

bool PhoneNumber::doubleDigits() const{ //checks to see if a digit occurs in the number more than once
	int count[10]; //create an array with 10 spots each index represents a counter for each number(0-9)
	int temp = number; //don't want to mess with original number so I store it into a temp variable
	int num;
	for(int i =0; i<10;i++){//initilize to zero
		count[i]=0;
	}
		while (temp !=0) //cycleing through the number
		{
			num = temp%10; //gets digit, calls it number
			count[num] += 1; //the number of occurences of num gets added once
			temp = temp/10; //divid the number by 10 to get access to the next digit
		}   
	for(int i =0; i<10;i++){ //cycles through array
		if(count[i]>1){ //if a digit occured more than once....
			return true;//...return true
		}
	}
		return false; //otherwise return false;
}


void PhoneNumber:: printNumber(ostream& out) const{ //area code and phone number only
	out<< "Phone number is: (" << getArea() <<") "<<getNumber()<<endl; //prints out area code and phone number
}
void PhoneNumber::printNumberStats(ostream& out) const{ //prints all phone information
	out<<"Printing out number stats on all numbers!! /n/n";
	out<<"Phone number is: ("<<getArea()<<") "<<getNumber()<<endl; //prints out area code and number
	out<<"Country code is: "<<getCountry()<<endl;
	out<<"This number is of type: "<<getType()<<endl;
	out<<"The year the entry was made was: "<<getYear()<<endl;//prints out year the entry was made
	if(doubleDigits() ==true){
		out<<"There are double digits "<<endl;
	}
	else
		out<<"There are no double digits"<<endl;
}

/*
The main function asks user how many numbers they want to enter. 
They willl enter the information on the phone numbers one at a time.
Next the values they just entered will be printed out.

*/



int main(){
	//initilizaion
	int country;
	int area;
	int number;
	int yr;
	char type;
	int i;
	cout<<"How many phone numbers do you want to be entered? Max is 25 "; //prompt
	cin>> i; //takes in number of phone numbers

	PhoneNumber pnums[25]; //max of 25
	for(int x =0; x<i; x++){ //increments through the array i number of times (user specified)
		cout<<"               Phone number "<<x+1<<":"<<endl<<endl; //lets user know which phone number they are entering
		cout<<"Please enter the Country code: "; 
		cin>> country;
		pnums[x].setCountry(country); //gets country code form user and sets it to a spcefic object "x"


		cout<< "Enter Area code: ";
		cin>> area;
		pnums[x].setArea(area); //gets area code form user and sets it to specific object "x"


		cout<<"Enter current year: ";
		cin>> yr;
		pnums[x].setYear(yr); //same as previous 2 comments, but with year


		cout<<"Enter the type of number (H, C, or B): ";
		cin>>type;
		pnums[x].setType(type); //sets type

		cout<<"Enter the 7 digit number: ";
		cin>>number;
		pnums[x].setNumber(number); //sets the actuall phone number
		cout<<endl<<endl;

	}
	cout<<endl<<endl<<"Printing out all the information: "<<endl<<endl; //now comes the printiong out functions
	for (int x=0; x<i; x++){ //incrementing through the array i number of times (user specfied)
		cout<<"               Phone number "<<x+1<<":"<<endl<<endl; //tells user which number is being displayed
		pnums[x].printNumber(cout); //prints out only the phone number and area code or anything else
		cout<<endl<<endl;
		pnums[x].printNumberStats(cout);//prints all the number information, includiong double digits
		cout<<endl<<endl;
	}

	return 0;
}
