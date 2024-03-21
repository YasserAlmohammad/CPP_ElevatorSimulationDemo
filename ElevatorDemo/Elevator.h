// Elevator.h: interface for the Elevator class.
//
//////////////////////////////////////////////////////////////////////

#include "Floor.h"
#include "Person.h"
#include "Reporter.h"

#if !defined(AFX_ELEVATOR_H__5EA90C14_A372_424B_BA26_12D5B9142657__INCLUDED_)
#define AFX_ELEVATOR_H__5EA90C14_A372_424B_BA26_12D5B9142657__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct Elevator_Location{
	int up_floor_id;    //equals 0 if elevator in a foor
	int in_floor_id;    //equals 0 if the elevator between two floors
	int down_floor_id;	//equals 0 if elevator in a foor
	int floor_percent;
};

enum Elevator_Status{
	GOING_UP,
	GOING_DOWN,
	STOPPED,
};

class Elevator{
public:
	Elevator(Floor**,Reporter*);
	virtual ~Elevator();

	void reset();  //initialize elevator to first floor, closed and empty

	bool add_person(Person *); //adding this preson to ones in the elevator
	void remove_person(int); //removes the person from the simulation

	int load_persons(Floor*); //when stopping in a floor, we load as we can
	int unload_persons(Floor*);// when stopping and people get out the elevator 

	Elevator_Status get_status();
	Elevator_Location get_location();
	
	void stopped_next_move(); 
	void moving_next_move(); 
	void query_floors();
	/*check calls from floors to determine the next move
	this method can be called by inside timer or outside one, " pooling "  
	it calles stopped_next_move() and moving_next_move() for execution
	*/
	CString toString(); //gives a report of the current state
	void ring(); //rings when reaching a floor
	void increment_time();
	int getLoadNum(){ return load_num;}
	static int MAX_ELEVATOR_LOAD;
	static int TIME_FROM_FLOOR_TO_ANOTHER;
	
	Person** persons;
private:
	int load_num; //how many people inside

	Elevator_Status status;
	Elevator_Location location;
	int last_floor_time;
	int time;   //when time - last_floor_time = TIME_FROM_FLOOR_TO_ANOTHER 
	//then the elevator reached a floor: the location and direction may change

	Floor** floors; //we'll refrence floors for query
	//char* description;
	Reporter* reporter;
	
};


#endif // !defined(AFX_ELEVATOR_H__5EA90C14_A372_424B_BA26_12D5B9142657__INCLUDED_)
