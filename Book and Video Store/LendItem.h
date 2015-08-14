#ifndef LENDITEM_H
#define LENDITEM_H


#include <string>
#include <cctype>
#include <cstring>
#include <stdio.h>

#include <iostream>
using namespace std;
/*
 Ramzey Ghanaim
 This header file declares a LendItem and initializes all of its components
*/
class LendItem{
private:
	string title; //storage of triplet values
	
public: //function declarations go here
	char mediumType; //type can be 'B' or 'D'
	bool borrowed;
	int borrowNumber;
	LendItem();
    LendItem(string titl, char med);
	void setTitle(string manu);
	void setMedium(char med);
	void setBNumber(int bNumber);
	void setBorrowed(bool bstatus);
	bool getBorrowed();
	string getTitle();
	char getMedium();
	int getBNumber();

	virtual void printAll(ostream& ) = 0;
	friend ostream& operator<< (ostream& out, const LendItem& obj);



};

#endif

