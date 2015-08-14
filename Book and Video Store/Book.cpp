#include "Book.h"
/*
 Ramzey Ghanaim
 This file contains all the functions of a Book's components
 that were declared in the Book.h file
*/
void Book::setAuthor(string auth){
	author = auth;

}
void Book::setCover(char type){
	coverType = type;

}
string Book::getAuth(){
	return author;
}
char Book:: getCover(){
	return coverType;
} 
void Book::printAll(ostream& out){ //prints all info on book
	
	cout<<"Title: "<<getTitle()<<endl;
	cout<<"Author: ";
	cout<<author<<endl;
	cout<<"Cover type: "<<coverType<<endl;
	if( getBorrowed() == true){
		cout<<"Status: Borrowed"<<endl;
		cout<<"Borrowed number: "<<getBNumber()<<endl;
	}
	else
		cout<<"Status: not Borrowed"<<endl;
	cout<<"Medium type: "<<getMedium()<<endl;

}