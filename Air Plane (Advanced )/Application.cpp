#include "JetBlue.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <stdio.h>
using namespace std;

/*
 Ramzey Ghanaim

 This file is the main applicatin where the main function takes place. 
 This program will allow user to make reservations, cancelations and see
 all aspects of an airplane. The user decieds how big the plane is.
*/

int main(){
	string response; //what the user wants to do
	int seat;//seat user selects
	int capacity; //user sets capacity to jetblue

	string CF = "CF";//initializes responses the Computer is looking for
	string CE = "CE";
	string R = "R";
	string RF = "RF";
	string RB = "RB";
	string P = "P";
	string E = "E";
	string C = "C";
	//prompt
	cout<<"How many seats do you want on your plane? ";
	cin>> capacity;
	JetBlue flight(capacity); //creates a JetBlue with size that user entered
	do{
	//prompt: What does user want to do
	cout<<"What would you like to do? \n Check if full (CF) \n Check if empty (CE) \n Reserve a specific seat (R) \n Reserve seat closest to front (RF)";
	cout<<"\n Reserve seat closest to back (RB) \n (C)ancel a reservation \n (P)rint out information on all seats \n or (E)xit: ";
	cin>> response; //gets user response
	if(response.compare(CF)==0) //check if full
	{
		if (flight.isFull()) { //if seats are full...
			cout << "\n The plane is full \n \n";//..tell the user
		}
		else //seats must be not full
			cout << "\n The plane is not full \n \n"; //tell the user

	}

	if(response.compare(CE)==0) //Check if empty
	{
		if(flight.isEmpty()){ //if seats are empty...
			cout<<"\n The plane is empty \n \n"; //...tell the user
		}
		else //seats must not be empty
			cout<<"\n The plane is not empty \n \n";//tell the user
	}

	if(response.compare(R)==0)// Reserve a particular seat
	{
		if(flight.isFull())
			cout<<"Sorry, flight is full ";
		else //if seat is not full
				cout<<"\n Please enter a seat you would like to reserve \n";
				cin>>seat;
				if(flight.validSeatNum(seat)==true){ //if a valid number is entered
					if(flight.seatVacant(seat) ==true){//and if the seat is empty...
						flight.reserveSeat(seat); //...reserves the seat
						cout<<"Your seat is reserved"<<endl<<endl;
					}
					else
						cout<<"Sorry. Seat is already reserved."<<endl;
				}
		else //if the user entered an invalid seat....
		cout<<"\n Invalid seat number. Please try again. "<<endl<<endl; //...tell the user
		}
		
	if(response.compare(RF)==0) //Reserve Front
	{
		if( flight.isFull()== false){ //if the plane is not full...
			seat = flight.furthestFront();
			flight.reserveSeat(seat);
			cout<<"\n Seat number "<< seat <<" is reserved for you! \n \n";//tell the user
		}
		else//if the seat is full, tell user
			cout<<"\n Sorry the flight is full"<<endl<<endl;
	}	

	if(response.compare(RB)==0)// Reserve Back seat
	{
		if( flight.isFull()== false){ //if the plane is not full...
			seat = flight.furthestRear();
			flight.reserveSeat(seat);
			cout<<"Seat number "<< seat<<" is reserved for you!"<<endl<<endl;//tell the user
		}
		else// reserve the seat farthest to the back
			cout <<"\n Sorry no more seats left anywhere on the plane\n \n";//...tell the user
	}
		
	if(response.compare(C)==0)// Cancel seat
	{
		if (flight.isEmpty()==true)
				cout << "Error: Plane is empty and can't cancel a seat \n";
		else{ //get a seat number
			cout<<"Enter a seat number: ";
			cin>>seat;
			if(flight.validSeatNum(seat)==true){
				if(flight.seatVacant(seat)==true){
					cout<<"Seat is already reserved."<<endl;
				}
				else{
					flight.cancelSeat(seat); // cancell the seat
					cout<<"Your seat is cancelled"<<endl<<endl;
				}

			}
			else
				cout<<"Invalid seat number. Please try again. "<<endl<<endl; //tell the user
		}
	}


	if(response.compare(P)==0)// print activity on all seats
	{
		cout<<"\n Seat information: "<<endl<<endl;
		for (int i = 0; flight.validSeatNum(i); i++) {
                    cout << "Seat number " << i << " is ";
                    if (flight.seatVacant(i)) {
                        cout << "vacant."<<endl;
                    } else {
                        cout << "reserved."<<endl;
                    }
                }
		cout <<"There are "<<flight.seatsLeft() << " seats left.\n"; //outputs number of seats left on the plane
	}

	if(response.compare(E)==0) //Exit
			cout<<endl<<"See you next time";
	}
	while(response.compare(E)!=0); //do the program until the user wants to exit
	return 0;
}