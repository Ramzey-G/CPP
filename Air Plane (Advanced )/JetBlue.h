#ifndef JETBLUE_H //copied this fromat fromthe planeFlight.h file provided in the project. preprocessor command
#define JETBLUE_H //preprocessor comand

#include "PlaneFlight.h"

/*
 Ramzey Ghanaim
 this class states functions that belong to the JetBlue class. This class inherits all
 functions of a planeflight
*/
class JetBlue :public PlaneFlight {
public:
	JetBlue();// constructor which initializes the a plane with SIZE (defined in PlaneFlight.h) seats
	JetBlue(int theCapacity);// constructor which initializes a plane with ‘capacity’ seats

	int seatsLeft() const; //determines/returns number of empty seats (assuming  the PlaneFlight object is not changed)

	int furthestFront() const;//finds and returns the front-most available seat as long as the object is not full. obj is not changed

	int furthestRear() const;// finds and reterns the rear-most available seat, as long as obj is not full. obj is unchanged
};
#endif