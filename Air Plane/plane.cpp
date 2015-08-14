
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <stdio.h>
using namespace std;



/*
 Ramzey Ghanaim
 CIS 278 Project 3
 This program will allow the user to keep track of seat reservations on an air plane.
 The seats are ordered in an array which range from 1-25 which can be modified by the user.
 To allow the program to make better sense to users in practical use I used my array range
 from 1-25 rather than 0-24. I had to account for this by adding and subtracting 1 from the output/input.
 After I did this was when I realized the prompt said 0-24! sorry about that
 User Options for Reservations on a plane:
 Check if full
 Check if empty
 Reserve specific seat
 Cancel a specific seat
 Reserve furthest front
 reserve furthest back
 print out info on all seats
*/
bool isFull(int seats[], int size);//prototype
bool isEmpty(int seats[], int size);//prototype
int seatsLeft(int seats[], int size);//prototype
bool validSeatNum(int size, int seatNo);//prototype
bool seatVacant(int seats[], int seatNo);//prototype
void reserveSeat(int seats[], int seatNo);//prototype
void cancelSeat(int seats[], int seatNo);//prototype
int furthestFront(int seats[], int size);//prototype
int furthestRear(int seats[], int size);//prototype
bool getSeatNo(int& value);//prototype
int x=0; // I needed a counter outside the main loop so x is not always 0 because I initilaze all array contents to be 0 only when the program is initlly ran
		//I couldn't think of another way than a  global variable
int newArray [25];// initializes a new array. I do this because at the end of the main, I re -run it. This re-creates the initial array and erases
				// all contents that the user reserved. I initialized this array outside the main() so It will not be overwritten
				// all of the contents of the initial array is coppied to newArray so when Array is re-initialized its contents remains intact
int main(){
	string response;
	string CF = "CF";//initializes responses the Computer is looking for
	string CE = "CE";
	string R = "R";
	string RF = "RF";
	string RB = "RB";
	string P = "P";
	string E = "E";
	string C = "C";
	const int size = 25; //size number of seats on plane I chose not to use CAPSLK for simplicity when typing
	int seatNo;
	int seats[size]; //an array with size number of seats (elements)
	if (x==0){ //during the first run of the program...
			for(int i =0; i<size; i++){ //initializes array elements to be zero. No spots on plane are used
					seats[i]= 0;
			}
	x++;
	}
	else //take newArray and copy its conetents to seat to be up to date
		for(int i =0; i<size; i++){
			seats[i] = newArray[i];
		}
	cout<<"Seats numbered from 1-25. \n What would you like to do? \n Check if full (CF) \n Check if empty (CE) \n Reserve a specific seat (R) \n Reserve seat closest to front (RF)";
	cout<<"\n Reserve seat closest to back (RB) \n (C)ancel a reservation \n (P)rint out information on all seats \n or (E)xit: "; //prompt
	cin>> response; //gets user response

	//all the conditions
	if(response.compare(CF)==0) //check if full
	{
		if (isFull(seats, size) == false) { //if seats are not full...
			cout << "\n The plane is not full \n \n";//..tell the user
		}
		else //seats must be full
			cout << "\n The plane is full \n \n"; //tell the user

	}
	if(response.compare(CE)==0) //Check if empty
	{
		if(isEmpty(seats, size)==false){ //if seats are not empty...
			cout<<"\n The plane is not empty \n \n"; //...tell the user
		}
		else //seats must be empty
			cout<<"\n The plane is empty \n \n";//tell the user
	}
	if(response.compare(R)==0)// Reserve a particular seat
	{
		int value = 0; //according to assignment pdf, int value must be passed to getSeatNo. I use this to store the seat number
		if(getSeatNo(value)==true){ //gets a seat number
			seatNo = value;//value becomes seatNo
			if(validSeatNum(size, seatNo)==true){ //if seatNo is a valid number on the plane..
				if(seatVacant(seats, seatNo)==true){// and if the seat is empty...
					reserveSeat(seats, seatNo); //reserve the seat
				}
				else //if seat is not empty
				cout<<"\n Sorry the seat is already reserved \n"; //tell user the seat is already reserved.
			}
		}
		else //if the user entered an invalid seat....
		cout<<"\n Invalid seat number. Please try again. "<<endl; //...tell the user
		
		
	}
	if(response.compare(RF)==0) //Reserve Front
	{
		if( isFull(seats, size)== true){ //if the plane is full...
			cout <<"\n Sorry no more seats left anywhere on the plane\n \n";//...tell the user
		}
		else//if the seat is not full, reserve the furthest front seat
			cout<<"\n Seat number "<< furthestFront(seats, size) <<" is reserved for you! \n \n";//tell the user
	}
	if(response.compare(RB)==0)// Reserve Back seat
	{
		if( isFull(seats, size)== true){ //if the plane is full...
			cout <<"\n Sorry no more seats left anywhere on the plane\n \n";//...tell the user
		}
		else// reserve the seat farthest to the back
			cout<<"Seat number "<< furthestRear(seats, size) <<" is reserved for you!"<<endl<<endl;//tell the user
		
	}
	if(response.compare(C)==0)// Cancel seat
	{
		int value = 0; // creates value
		if(getSeatNo(value)==true){// gets a seat number from the user
			seatNo = value;//value is the seat number
			if(validSeatNum(size, seatNo)==true){// if the seat number is valid for the plane...
				if(seatVacant(seats, seatNo)==false){ //..and if the seat is not empty...
					cancelSeat(seats, seatNo);//...cancel the seat and make it available
				}
				else // If seat is already empty...
				cout<<"\n Sorry the seat is already cancelled"<<endl;// Tell user to the seat is already cancelled

			}
		}
		else //user must have typed in a wrong seat number
		cout<<"Invalid seat number. Please try again. "<<endl<<endl; //tell the user
		
	}
	if(response.compare(P)==0)// print activity on all seats
	{
		for(int i =0; i<size; i++) {//runs through array
			if( seats[i]==0){ //if the array at this seat is 0 or empty
				cout<<"Seat "<< i+1 <<" is empty \n \n"; //tell the user. (i+1 is to keep the UI for the user consistant. 1-25)
			}
			else// the seat must be occupied
				cout<<"Seat "<< i+1<< " is reserved \n \n"; //tell the user
		}
		cout<<"There are "<<seatsLeft(seats,size)<<" seats left."<<endl; //tells user how many seats are left I had no use for this funcion anywhere else in my code
	}
		if(response.compare(E)==0) //Exit
			exit(1); //exit program
		for(int i =0; i<size; i++){ //increments through array
				
				newArray [i] = seats[i] ;//stores seats to newArray before program re-runs main function and re-initilizes seats[], erasing its data
			}
		main(); //re-run main()
	return 0;
}

bool isFull(int seats[], int size) { //Determines if all plane seats are full. If occupied the seat is a 1, and 0 if not occupied
	for (int i = 0; i < size; i++) { //initializes array elements to be zero. No spots on plane are used
		if (seats[i] == 0) {
			
			return false; //returns false if at least one seat on the plane is open or 0
		}
	}
	return true; //returns true if all the contents are 1 (or full)
} //returns true if plane is full, false if not

bool isEmpty(int seats[], int size){ //determines if all plane seats are empty. If occupied the seat is a 1, and 0 if not occupied
	for (int i = 0; i < size; i++) { //initializes array elements to be zero. No spots on plane are used
		if (seats[i] == 1) {
			return false; //returns false if at least one seat on the plane is open or 0
		}
	}
	return true; //returns true if all the contents are 0 (or empty)
} 


void reserveSeat(int seats[], int seatNo){ //reserves a seat numbered seatNO. Based on the main(), this function is only ran if seatNo is a valid seat Number	
				seats[seatNo-1] =1;// ...reserve the seat
				cout<<"Your seat is reserved \n \n";//...and print "your seat is reserved"

	}

int furthestFront(int seats[], int size){ //reserves the seat closes to the front. This function only runs if the plane is not full
	for (int i =0; i<size; i++){ //increments through array starting at the beginning
		if(seats[i]==0) //searches for the open seat. Thiss will be the clossest to front since Incrmenting through array is starting at the front
		{
			seats[i] =1;
			return i+1; //returns the seat number +1 to get the number in the range of 1-size for the user to easily understand
			            // I prefer to wrire my programs this way because it has a better user experience rather than seats being from 0 to numberOfSeats-1
		}
	}
	return 0;
}

int furthestRear(int seats[], int size){//This function finds the rear most available seat and reserves it
	for(int i = size-1; i !=0; i--){//increment from size-1 to 0. This cycles through aray in reverse order
		if(seats[i]==0)//finds the first seat that is empty
		{
			seats[i]=1; //reserves the seat
			return i+1; // returns seat number +1 to get the seat number in the range of 1-size
						// I prefer to wrire my programs this way because it has a better user experience rather than seats being from 0 to numberOfSeats-1
		}
	}
	return 0;
}

void cancelSeat(int seats[], int seatNo){ //unreserves the seat numbered seatNo I check if the seat is already empty in this function
	
				seats[seatNo-1] =0; //un reserve the seat seatNo
				cout<<"Your seat is cancelled \n \n"; //Gives user confirmation
			
}

bool seatVacant(int seats[], int seatNo){// determines if seatNo is an available seat. This function is only ran within other functions. This function
										//will only run if seatNo is a valid seat number
	if(seats[seatNo-1]==0) //if the seat the user enters is vacant..
		return true;//...return true
	else
		return false; //otherwise return false;
	return false;
}

int seatsLeft(int seats[], int size){ //determines the numbr of empty seats remaining
	int counter=0; //a counter keeps track of the number of empty seats
	for (int i =0; i< size; i++){ //increments through the entire array
		if(seats[i]==0) //if a particular seat is empty...
			counter++;  //counter increments
	}
	return counter; //the number of seats left is returned
}


bool getSeatNo(int &value){//gets the seat number, gets number by itself (doesn't contain characters)
	char str[50];//initilize a C-string
	int t =0; //initilize an array position for a second array... more on this a few lines down
	cout<< "Seats range from 1 to number of seats. Please enter a seat number you want to reserve/cancel: "; //prompt
		cin>>str; //saves user input to the C-string
	char newstr[50];// initialize a second array used to take numbers from first array and put it in this one
	for( int i =0; i< strlen(str); i++) //cycles through array. strlen(str) gets the length, for the bounds of the first array
		{
			if(isdigit(str[i])){ //if the character is a digit
				newstr[t] = str[i]; //place the character into the second array I found this beasier than removing characters from the existing array
				t++; //increments location in new array when a digit is placed in it
			}
				
		}
	value = atoi(newstr); //converts this new array into a int since it now contains only digits
//	value -=1; // subtract 1 to get it within the 0 to size-1 interval to work with arrays
	return true; //returns true if the digit can be created
}

bool validSeatNum(int size, int seatNo){ //determines if seatNo is a valid seat on the plane. 
		if(seatNo>size ||seatNo<1) // checks to see if the seat number entered is not offered on this plane
		{
			cout<<"Invalid Seat"<<endl <<endl; //if the seat is outside appropriate bounds then Invalid seat is outputted
			return false;
			}
		else
			return true; //if seat number is good
}