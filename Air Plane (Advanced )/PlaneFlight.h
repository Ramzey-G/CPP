#ifndef PLANEFLIGHT_H //preprocessor comand
#define PLANEFLIGHT_H //preprocessor comand

#include <iostream>
using namespace std;

/*
Ramzey Ghanaim
Part of this file was coppied and pasted from the provided PlaneFlight.h file. 

Pre processor commands ensure the header file does not get included more than once to prevent 
multi-deffinition errors.
*/

const int SIZE = 10;

class PlaneFlight{

public:
	PlaneFlight();//defalt constructor
	PlaneFlight(int c);
	   //Effect: creates a PlaneFlight object with theCapacity number of seats
	   //Postcondition: PlaneFlight object exists and is ready for reservations

	PlaneFlight(const PlaneFlight& obj);
	   //Effect: this copy constructor initializes a new PlaneFlight object's data to be
	   //        identical with data in parameter obj (deep copy made)
	   //Postcondition: obj is unchanged

    ~PlaneFlight();
      //Effect: deallocates any dynamic memory that has been allocated
      //Postcondition: dynamic memory has been deallocated

	bool isFull() const;
    // Effect:  determines if all plane seats are full
    // Postcondition:  this PlaneFlight objects is unchanged
    // Returns: true if all seats are full, false otherwise

  bool isEmpty () const;
    // Effect:  determines if all plane seats are empty
    // Postcondition:  this PlaneFlight objects is unchanged
    // Returns: true if all seats are empty, false otherwise

  bool seatVacant(int seatNo) const;
     // Effect:  determines if seatNo is an available seat
     // Precondition:   seatNo is a valid seat number
     // Postcondition:  this PlaneFlight object is unchanged
       
    void reserveSeat(int seatNo);
     // Effect: reserves the seat numbered ‘seatNo’
     // Precondition:  seat is vacant
     // Postcondition:  seat #seatNo is now filled   

    void cancelSeat(int seatNo);
      //Effect: unreserves the seat numbered ‘seatNo’
      // Precondition:  seat had been reserved
     // Postcondition:  seat #seatNo is now available      

   bool validSeatNum(int seatNo)  const;
      //Effect:  determines if seatNo is a valid number for this plane
      // Postcondition:  this PlaneFlight object is unchanged
      //Returns: true if seatNo is a seat on this plane, false otherwise
  
   PlaneFlight& operator=(const PlaneFlight& rightside);
      //Effect: this object is now identical to rightside
	  //Postcondition: rightside is not changed
      //Returns: this object

   friend ostream& operator<<(ostream& out, const PlaneFlight& obj);
      //Effect: seat information for this plane
      //Postcondition: this PlaneFlight object is unchanged
      //Returns: the ostream object that was passed as parameter

private:
	  int* seats;    //plane seats (0- empty, 1 - full) seats is a pointer 
	  int count;     //number of reservations made
	  int capacity;  //plane capacity
};

#endif
