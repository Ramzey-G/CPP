#include "DVD.h"
/*
 Ramzey Ghanaim
 This file contains all the functions of the DVD's components
 that were declared in the DVD.h file
*/
 void DVD::setRating(string rate){
	 rating = rate;
 }
void DVD::setScreen(char type){
	screenType = type;
}
string DVD::getRate(){
	return rating;
}
char DVD::getType(){
	return screenType;
}
void DVD::printAll(ostream& ){ //print all info on a DVD
	cout<<"Medium type: "<<getMedium()<<endl;
	cout<<"Title: "<<getTitle()<<endl;
	cout<<"Rating: "<<getRate()<<endl;
	cout<<"Screen type: "<<screenType<<endl;
	if( getBorrowed() == true){
		cout<<"Status: Borrowed"<<endl;
		cout<<"Borrowed number: "<<getBNumber()<<endl;
	}
	else{
		cout<<"Status: not Borrowed"<<endl;
		cout<<"Borrow Number ID: "<<getBNumber()<<endl;
	}
}
