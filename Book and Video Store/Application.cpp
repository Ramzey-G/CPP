#include <iostream>
#include <string>
#include "DVD.h"
#include "Book.h"
#include <string>
#include <cctype>
#include <cstring>
using namespace std;
/*
 Ramzey Ghanaim
 Thi is the application file which allows users to rent DVD's and Books
 and gather all information on them. Users can also enter DVD's and Books 
 into the program.
*/


/*
 The declarations below were made outside main()
 so they can be accessed by all functions
*/

int main(){
	const int CAPACITY = 1000;
	DVD movies[CAPACITY];
	Book library[CAPACITY];
	int m = 0, b = 0; //m is the incrementer for Movies array. b is the incrementor for the book array
	bool found = false; //true if the item has been found in any array
	int input; //user input
	string title; //title that user provides
	string author; //author that user provides
	char cover; //cover type that user provides
	string rating;// rating that user provides
	char screenType; //screen type that user provides




	do{
	cout<<"What do you want to do: "<<endl;
	cout<< "1: Enter a new Book"<<endl<<"2:Enter a new DVD"<<endl<<"3:Borrow a book"<<endl<<"4:Borrow a DVD"<<endl;
	cout<<"5. Print out the title and borrowed status of all Books"<<endl<<"6. Print out the title and borrowed status of all DVD's currently stored"<<endl;
	cout<<"7. Check if an item is owned and if so tell user if he/she can borow it"<<endl<<"8. Find information on a title"<<endl;
	cout<<"9. Enter author name and recieve the title of all books by the author that are owned by the Marina"<<endl;
	cout<<"10. Output the name of all items that have been borrowed"<<endl<<"11. Exit "<<endl;
	cin>> input;
	cin.ignore();
	switch (input) {
                
            case 1:   //registering a new book
				cout<<"Enter a new book: ";
				getline(cin,title);
				cout<<"Enter the author: ";
				getline(cin,author);
				cout<<"Enter cover type (S or H): ";
				cin>>cover;
				cin.ignore();
				library[b]= Book (title, author, cover);//creates a new book and stores it to index b.
				library[b].setBNumber(b+1);
				b++;
				break;
			case 2: //enter a DVD
				cout<<"Enter a new DVD: ";
				getline(cin, title);
				cout<<"Enter rating: ";
				getline(cin, rating);
				cout<<"Enter screen type (W or F): ";
				cin>> screenType;
				cin.ignore();
				movies[m] = DVD(title, rating, screenType);
				movies[m].setBNumber(m+1);
				m++;
				cout<<"Done"<<endl<<endl<<endl;
				break;
			case 3: //borrow a Book
				found = false;
				cout<<"Enter the title of the book you want to borrow: ";
				getline(cin, title);
				for(int i = 0; i < b; i++)
				{
					if(  title.compare( library[ i ].getTitle() ) == 0 )
					{
						// borrows the matched title
						library[ i ].setBorrowed( true );
						found = true;
					}
				}
				if( found==false )
					cout << "Sorry, that book title was not found." <<endl<< endl;
				break;
			case 4: //borrow DVD
				found = false;
				cout<<"Enter the title of a DVD you want to borrow";
				getline(cin, title);
				for(int i = 0; i < m; i++)
				{
					if(  title.compare( movies[ i ].getTitle() ) == 0 )
					{
						// borrows the matched title
						movies[ i ].setBorrowed( true );
						found = true;
						cout<<"Done";
					}
				}
				if( found==false )
					cout << "Sorry, that book title was not found." << endl;
				break;
			case 5://Print out the title and borrowed status of all Books
				cout<<"           All Boks are as follow: "<<endl<<endl;
				for(int i = 0; i<b; i++){
					cout<<library[i].getTitle()<<": ";
					if(library[i].borrowed)
						cout<<"Borrowed"<<endl;
					else
						cout<<"Not Borrowed"<<endl;
				}
				cout<<"Done"<<endl<<endl;
				break;
			case 6:// Print out the title and borrowed status of all DVD's
				cout<<"           All DVDs are as follow: "<<endl<<endl;
				for(int i = 0; i<m; i++){
					cout<<movies[i].getTitle()<<": ";
					if(movies[i].getBorrowed())
						cout<<"Borrowed"<<endl;
					else
						cout<<"Not Borrowed"<<endl;
				}
				cout<<"Done"<<endl<<endl;
				break;
			case 7://Check if an item is owned tell user. If so tell user if it is available to borrow
				cout<<"Enter an item (DVD or movie): "<<endl;
				getline(cin, title);
				cout<<"             BOOKS: ";
				for(int i = 0; i < b; i++)
				{
					if(  title.compare( library[ i ].getTitle() ) == 0 )
					{
						cout << title << " is in our collection." << endl;
						if ( library[ i ].getBorrowed() )
							cout << title << " is unavailable to borrow." << endl;
						else 
							cout << title << " is available to borrow." << endl;
						found = true;
					}
				}
				cout<<"             DVD's: ";
				for(int i = 0; i < m; i++)
				{
					if(  title.compare( movies[ i ].getTitle() ) == 0 )
					{
						cout << title << " is in our collection." << endl;
						if ( movies[ i ].getBorrowed() )
							cout << title << " is unavailable to borrow." << endl;
						else 
							cout << title << " is available to borrow." << endl;
						found = true;
					}
				}
				if( !found )
					cout << "Sorry, that title was not found." << endl;
					 break;
			case 8: //Find information on a title
					found = false;
					cout<<"Enter a title: ";
					getline(cin, title);
					cout<<"             DVD's: ";
					for(int i = 0; i < m; i++)
					{
					if(  title.compare( movies[ i ].getTitle() ) == 0 )
						{
						movies[ i ].printAll( cout );
						found = true;
						}
					}
					cout<<"             BOOKS: ";
					for(int i = 0; i < b; i++)
					{
						if(  title.compare( library[ i ].getTitle() ) == 0 )
							{
								library[ i ].printAll( cout );
								found = true;
							}
					}
					if( !found ){
					cout << "Sorry, that title was not found." << endl;
					}
					break;
			case 9: //Enter author name and recieve the title of all books by the author
					cout<<"Please enter an Author name: ";
					getline(cin, author);
					cout<<"        Books from your author: "<<endl;
					for(int i = 0; i<b;i++)
					{
						if(library[i].getAuth().compare(author)==0){
							cout<<library[i].getTitle()<<endl;
						}

					}
					cout<<"Done"<<endl<<endl;
					break;
			case 10: //Output the name of all items that have been borrowed
					cout<<"            All Books that have been borrowed:"<<endl;
					for(int i=0;i<b;i++){
						if(library[i].borrowed ==true){
							cout<<library[i].getTitle()<<endl;
						}
					}
					cout<<"            All DVDs that have been borrowed:"<<endl;
					for(int i=0;i<m;i++){
						if(movies[i].borrowed ==true){
							cout<<movies[i].getTitle()<<endl;
						}
					}
					cout<<"Done"<<endl<<endl;
					break;
				}


	} while (input != 11);


	return 0;
}
