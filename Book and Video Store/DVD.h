#include "LendItem.h"
#include <string>
#ifndef VID_CODE
#define VID_CODE
/*
 Ramzey Ghanaim
 This file defines a DVD and provides neccessary 
 components of a DVD (ex: rating, screen type)
*/
class DVD: public LendItem {

private:
	string rating;
	char screenType; //'W' or 'F'

public:
	DVD() : LendItem("Unknown", 'D') {//title, item type are declared in the parent class
		setRating("unkown");
		setScreen('?');
	}
	DVD(string titl, string rat, char stype){
          setTitle(titl);
		  rating = rat;
		  screenType = stype;
		  mediumType = 'D';
	}

	void setRating(string rate = "PG");
	void setScreen(char type);
	string getRate();
	char getType();
	void printAll(ostream&);

};

#endif