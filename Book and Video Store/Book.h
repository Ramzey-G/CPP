
#include "LendItem.h"
/*
 Ramzey Ghanaim
 This file defines a Book and provides neccessary 
 components of a DVD (ex: author, cover type)
*/
#ifndef BOOK_CODE
#define BOOK_CODE
class Book: public LendItem {

private:
	string author;
	char coverType; //'S' or 'H'

public:
	Book(): LendItem("Unknown", 'B') { //title, item type are declared in the parent class
	 author = "unkown";
	 coverType = '?';
	}
	Book(string titl, string auth, char cover){
          setTitle(titl);
		  author = auth;
		  coverType = cover;
		  mediumType = 'B'; 

	}

	void setAuthor(string auth);
	void setCover(char type);
	string getAuth();
	char getCover();
	void printAll(ostream& out);


};
#endif