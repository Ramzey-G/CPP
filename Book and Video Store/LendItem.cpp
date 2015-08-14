#include "LendItem.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;
/*
 Ramzey Ghanaim
*/
LendItem::LendItem(){
	title = "N/A";
	mediumType = 'N';// N for nothing
	borrowed = false;
	borrowNumber = 0;
};

LendItem::LendItem(string titl, char med){
	title = titl;
	mediumType = med;
	borrowed = false; //defaults
	borrowNumber = 0; //defaults

}

void LendItem::setTitle(string manu){
	title = manu;
}

void LendItem::setMedium(char med){
	mediumType = med;

}

void LendItem::setBNumber(int bNumber){
	borrowNumber = bNumber;

}

void LendItem:: setBorrowed (bool bstatus){
	borrowed = bstatus;

}

bool LendItem:: getBorrowed(){
	return borrowed;

}

string LendItem::getTitle(){
	return title;
}
char LendItem::getMedium(){
	return mediumType;
}

int LendItem:: getBNumber (){
	return borrowNumber;
}

ostream& operator<< (ostream& out, const LendItem& obj) //Outputs object to ostream object
{
    out << "Title: " << obj.title << endl;
    out << "Status: ";
    if (obj.borrowed)
    {
        out << "Borrowed" << endl;
        out << "ID: " << obj.borrowNumber;
    }
    else
    {
        out << "Not Borrowed";
    }

    out << endl;
    return out;
}