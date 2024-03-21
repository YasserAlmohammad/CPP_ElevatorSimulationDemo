// Elevator.cpp: implementation of the Elevator class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ElevatorDemo.h"

#include "Floor.h"
#include "Person.h"
#include "Reporter.h"

#include "Elevator.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


int Elevator::MAX_ELEVATOR_LOAD=4;
int Elevator::TIME_FROM_FLOOR_TO_ANOTHER=5;



Elevator::Elevator(Floor** f,Reporter* r){
	floors=f;
	reporter=r;
	reporter->send_message("elevator was created");
	reset();

}

Elevator::~Elevator(){
	delete [] persons;
	reporter->send_message("elevator was destroied");

}

void Elevator::reset(){
	load_num=0;
	persons=new Person*[MAX_ELEVATOR_LOAD];
	for(int i=0; i<MAX_ELEVATOR_LOAD;i++)
		persons[i]=NULL;
	status=STOPPED;
	location.down_floor_id=0;
	location.in_floor_id=1; //first floor
	location.up_floor_id=0;
	location.floor_percent=0;
	last_floor_time=0;
	time=0;
	//description="";
	reporter->send_message("elevator was rest");

}

enum Elevator_Status Elevator::get_status(){
	return status;
}

Elevator_Location Elevator::get_location(){
	return location;
}

void Elevator::increment_time(){
	++time;
}

bool Elevator::add_person(Person* person){
	if(load_num<MAX_ELEVATOR_LOAD){
		++load_num;
		for(int i=0;i<MAX_ELEVATOR_LOAD;i++)
			if(persons[i]==NULL){
				persons[i]=person;
				person[i].setLocation(0);
				reporter->send_message("person entered the elevator");
				return true;
			}
	}
	reporter->send_message("person can't enter elevator: too much people");
	return false;
}

void Elevator::remove_person(int i){
	if(persons[i]!=NULL){
		delete persons[i];
		persons[i]=NULL;
		--load_num;
	}
	reporter->send_message("person got out from elevator");

}


//this method is called when elevator stops on a floor
int Elevator::load_persons(Floor* floor){
	int loaded=0;
	if(load_num<MAX_ELEVATOR_LOAD){
		int max_num_to_load=MAX_ELEVATOR_LOAD - load_num;
		while((floor->get_persons_num()>0)&&(loaded<max_num_to_load)){ //we can load few
			add_person(floor->remove_person());
			++loaded;
		}
		if(floor->get_persons_num()==0)
			floor->set_button_pressed(false);
	}

	return loaded;
	
}

//we unload all persons whom destination is the current floor
int Elevator::unload_persons(Floor* floor){
	int unloaded=0;
	if(load_num>0){  
		for(int i=0; i<MAX_ELEVATOR_LOAD; i++){
			if(persons[i]!=NULL){
				if(persons[i]->getDestination()==floor->get_id()){
					remove_person(i);
					++unloaded;
				}
			}
		}


	}
	return unloaded;

}


/*  this method is called during pooling to check floors and decide 
	what it must do : loading, unloading, stopping or continue movement
	to another floor
	this query happens when elevator reaches a floor
	when loading or unloading happens it' better to notify the reporter
*/

void Elevator::stopped_next_move(){ 
	//first check the current floor
	last_floor_time=time;
	Floor* floor=floors[location.in_floor_id-1];
	if(floor->button_is_pressed()){ //people waiting in this floor
		load_persons(floor);
		/*we make a strategy for next direction here, but for now
		  if any of the persons inside the elevator wants to decend
		  down, the elevator goes down first
		  the first floor always go up
		  the last floor always go down
		*/
		for(int i=0;i<MAX_ELEVATOR_LOAD;i++)
			if((persons[i]!=NULL)&&(persons[i]->getDestination()<location.in_floor_id))
				status=GOING_DOWN;
			if(status!=GOING_DOWN)
				status=GOING_UP;				
	}
	else{ 
		/*check other floors, the strategey:
		  if any down level floor asks for the elevator, it directly
		  goe's down, else it goes up if people asks it in upper floors
		*/
		for(int i=1;i<location.in_floor_id;i++)
			if(floors[i-1]->button_is_pressed())
				status=GOING_DOWN;
		if(status!=GOING_DOWN)
			for(int i=location.in_floor_id;i<Floor.TOTAL_FLOOR_NUM;i++)
				if(floors[i]->button_is_pressed())
					status=GOING_UP;
	}

	if(status==GOING_DOWN){
		location.up_floor_id=location.in_floor_id;
		location.down_floor_id=location.up_floor_id-1;
		location.in_floor_id=0;
		location.floor_percent=TIME_FROM_FLOOR_TO_ANOTHER-1;
		
	}
	else
		if(status==GOING_UP){
			location.down_floor_id=location.in_floor_id;
			location.up_floor_id=location.down_floor_id+1;
			location.in_floor_id=0;
			++location.floor_percent;
			
		}

}

void Elevator::moving_next_move(){
	/*elevator in move
	   reached a floor:
	   we reach a floor when elevator is in moving state and he reached
	   the time required to travel between two floors
     */
	if((time-last_floor_time)>=TIME_FROM_FLOOR_TO_ANOTHER){ //>= is more trusted
		//set the location
		if(status==GOING_UP){
			if(location.up_floor_id==0) //error
				location.up_floor_id=1; //error
			location.in_floor_id=location.up_floor_id;
		}
		else{ 
			if(location.down_floor_id==0) //error
				location.down_floor_id=1;   // error
			location.in_floor_id=location.down_floor_id;
		}
		location.up_floor_id=location.down_floor_id=0;
		CString message;
		message.Format("elevator now reached floor%d",location.in_floor_id);
		reporter->send_message(message);

		int loaded=0,unloaded=0;
		//test if anyone wants to get out
		for(int i=0;i<MAX_ELEVATOR_LOAD;i++)
			if((persons[i]!=NULL)&&(persons[i]->getDestination()==location.in_floor_id)){
				unloaded=unload_persons(floors[location.in_floor_id-1]);
				break;
			}
		bool up=false;
		/*if someone already exists in elevator and wants to go up
		elevator must go up even if one's who newly entered wants to
		get in and goes down
		*/
		for(i=0;i<MAX_ELEVATOR_LOAD;i++)				
			if((persons[i]!=NULL)&&(persons[i]->getDestination()>location.in_floor_id))
				up=true;
		
		//test if any wants to get in if room available( button pressed)
		if(floors[location.in_floor_id-1]->button_is_pressed())
			if(load_num<MAX_ELEVATOR_LOAD)
				loaded=load_persons(floors[location.in_floor_id-1]);
		
		//decide next direction
		if(load_num==0){
			if(unloaded>0){ 
				bool called=false;
				for(int i=1;i<location.in_floor_id;i++)
					if(floors[i-1]->button_is_pressed()){
						status=GOING_DOWN;
						called=true;
						break;
					}
				if(!called){//if no one called it from bellow, look up  
					for(int i=location.in_floor_id;i<Floor.TOTAL_FLOOR_NUM;i++)
						if(floors[i]->button_is_pressed()){
							status=GOING_UP;
							called=true;
							break;
						}
				}
				if(!called){ //no one calls it at all
					status=STOPPED;
					reporter->send_message("elevator stopped");
				}

			}
			//else:it's empty and floor as well so continue it's direction 
			//it's been requested
		}
		else{ //it contains people
			status=GOING_UP;
			if(!up){ //if an old passenger is going up: continue 
				for(int i=0;i<MAX_ELEVATOR_LOAD;i++)
					if((persons[i]!=NULL)&&(persons[i]->getDestination()<location.in_floor_id)){
						status=GOING_DOWN;
						break;
					}
			}
		}
		if(status==GOING_DOWN){
			location.floor_percent=TIME_FROM_FLOOR_TO_ANOTHER;
			location.up_floor_id=location.in_floor_id;
			location.down_floor_id=location.up_floor_id-1;
			location.in_floor_id=0;
		}
		else
			if(status==GOING_UP){
				location.floor_percent=0;
				location.down_floor_id=location.in_floor_id;
				location.up_floor_id=location.down_floor_id+1;
				location.in_floor_id=0;
			}
		last_floor_time=time;
		
	}
	else{
		if(status==GOING_DOWN){
			if(location.floor_percent==0)
				location.floor_percent=TIME_FROM_FLOOR_TO_ANOTHER-1;
			else
				location.floor_percent=location.floor_percent-1;
		}
		else{
			if(status==GOING_UP){
				
				if(location.floor_percent==TIME_FROM_FLOOR_TO_ANOTHER)
					location.floor_percent=0;
				else
					++location.floor_percent;

			}
			else
				location.floor_percent=0;
		}
	}
		
}

//this method was divided into two just for clearness
void Elevator::query_floors(){
	if(status==STOPPED) //1
		stopped_next_move();		
	else //2
		moving_next_move();	

	//3 between two floors, do nothing



}

CString Elevator::toString(){
	CString report,temp;

	report.Format("elevator time=%d ,it contains %d persons ",time,load_num);
	for(int i=0;i<MAX_ELEVATOR_LOAD;i++){
		if(persons[i]!=NULL){
			temp.Format("person wants to go to floor%d",persons[i]->getDestination());
			report+=temp;
		}
	}
	
	if(status==STOPPED)
		temp.Format("it's stopped now in floor:%d",location.in_floor_id);
	else{
		if(location.in_floor_id==0)
			temp.Format("it's between floor%d and floor%d",location.down_floor_id,location.up_floor_id); 
		else
			temp.Format("it reached floor%d",location.in_floor_id);
		if(status==GOING_UP)
			temp+=",it's moving up";
		else
			temp+=",it's moving down";
	}
	
	report+=temp;
	return report;
	/*
	if(location.in_floor_id==0)
		return "elevator: contains "+load_num+" persons, it's between floor"+location.down_floor_id+" and floor"+location.up_floor_id+"";
	else
		return "elevator: contains "+load_num+" persons, it's in floor"+location.in_floor_id+"";

	*/
 }

