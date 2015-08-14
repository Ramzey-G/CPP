#include "JetBlue.h"
/*
 Ramzey Ghanaim
 this class defines function of the JetBlue class. This class inherits all
 functions of a planeflight
*/
JetBlue::JetBlue():PlaneFlight() { //inherited from PlaneFlight class
}
 
JetBlue::JetBlue(int c): PlaneFlight(c) {//inherited from PlaneFlight class
}

int JetBlue::seatsLeft() const { //returns number of seats that are not reserved
	int i;
	int seats=0; //reserved seats
	for (i=0; validSeatNum(i); i++){ //increments through array of valid seats
		if (!seatVacant(i)){ //if a seat at i is vacant...
			seats++; //...increment number of seats left
		}
	}
	return i-seats;
}

int JetBlue::furthestFront() const { //retruns the avaliable seat furthest front
	int i;
	for (i=0; validSeatNum(i); i++){ //increments through array
		if (seatVacant(i))//If seat is vacant...
			break;//loop is done,
	}
	return i; //return that seat number
}

int JetBlue::furthestRear() const {//returns the available seat furthest back
	int seat=0;
	for (int i=0; validSeatNum(i); i++){ //increments through array
		if (seatVacant(i))
			seat = i;
	}
	return seat; //returns the available seat
}