#include "PlaneFlight.h"

/*
Ramzey Ghanaim

This file defines a PlaneFlight's functions. part of this file is copied from the provided
PlaneFlight.cpp includded in the project

*/

PlaneFlight::PlaneFlight() { //default constructor
     seats = new int[SIZE];
	 count = 0;
	                  // initialize all seats to empty
	 for (int num = 0; num < SIZE; num++)
		 seats[num] = 0;
}

PlaneFlight::PlaneFlight(int c) { //constructer that creates a PlaneFlight object with c number of seats
	seats = new int[c];
	count = 0;
	capacity = c;

	for (int num=0; num<c; num++) //sets all elements in array to 0
		seats[num] = 0;
}

PlaneFlight::PlaneFlight(const PlaneFlight& obj) { //copy constructor initializes a new PlaneFlight object's data to be the same as the data
	                                               //in the paramater. obj remains unchanged

	count = obj.count;
	capacity = obj.capacity;
	seats = new int[obj.capacity];
	for (int i=0; i<count; i++){ //cycles through array
		seats[i] = obj.seats[i];
	}
}

PlaneFlight::~PlaneFlight() { // deallocates any dynamic memory that has been allocated
	delete [] seats; //seasts are deallocated
}

PlaneFlight& PlaneFlight::operator=(const PlaneFlight& rightside) { //left obj becomes identical to the obj on the right side. rightside remains unchanged
 
	if (capacity != rightside.capacity) {
		delete [] seats;
		seats = new int[rightside.capacity];
	}

	count = rightside.count;
	capacity = rightside.capacity;
	for (int i=0; i<count; i++)
		seats[i] = rightside.seats[i];

	return *this; //returns the this variable (pointer to the object)
}


bool PlaneFlight::isFull() const{
     //Effect:  determines if all plane seats are full
     //Postcondition:  this PlaneFlight objects is unchanged
     //Returns: true if all seats are full, false otherwise

     return count == SIZE;
}

bool PlaneFlight::isEmpty () const{
     //Effect:  determines if all plane seats are empty
     //Postcondition:  this PlaneFlight objects is unchanged
     //Returns: true if all seats are empty, false otherwise
       
     return count == 0;
}


bool PlaneFlight::seatVacant(int seatNo) const{
     // Effect:  determines if seatNo is an available seat
     // Precondition:   seatNo is a valid seat number
     // Postcondition:  this PlaneFlight object is unchanged 

	  return seats[seatNo] == 0;
					  
}


void PlaneFlight::reserveSeat(int seatNo)  {
     // Effect: reserves the seat numbered ‘seatNo’
     // Precondition:  seat number is valid and seat is vacant
     // Postcondition:  seat #seatNo is now filled

	  seats[seatNo] = 1;
	  count++;
}

void PlaneFlight::cancelSeat(int seatNo){
      //Effect: unreserves the seat numbered ‘seatNo’
     // Precondition:  seat number is valid and  had been reserved
     // Postcondition:  seat #seatNo is now available 
					    
	  seats[seatNo] = 0;
	  count--;
}

bool PlaneFlight::validSeatNum(int seatNo)  const  {
     // Effect:  determines if seatNo is a valid number for this plane
     // Postcondition:  this PlaneFlight object is unchanged
     // Returns: true if seatNo is a seat on this plane, false otherwise
   
	  return seatNo >= 0 && seatNo < capacity;
}
  
//output
ostream& operator<<(ostream& out, const PlaneFlight& obj) { //Seat information for the plane is printed. the planeflight remains unmodified
	for (int i=0; i<obj.capacity; i++) {
		out << "Seat number " << i << " is ";
		if (obj.seats[i] == 0)
			out << "vacant." << endl;
		else
			out << "reserved." << endl;
	}
	return out; //returns the ostream obj that was passed into the parameter
}
