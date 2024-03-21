// Schedule.cpp: implementation of the Schedule class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ElevatorDemo.h"

#include <time.h>
#include <assert.h>
#include "Elevator.h"
#include "Floor.h"
#include "Reporter.h"
#include "Schedule.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


Schedule::Schedule(Floor** f,Elevator* e,Reporter* r){
	floors=f;
	elevator=e;
	reporter=r;

}

void Schedule::floor_generate_person(){
	srand(time(NULL));
	int floor_id=1+rand()%Floor.TOTAL_FLOOR_NUM;
	int dest_floor=1+rand()%Floor.TOTAL_FLOOR_NUM;

	if(dest_floor==floor_id){
		if(dest_floor==1)
			dest_floor=2;
		else
			if(dest_floor==Floor.TOTAL_FLOOR_NUM)
				dest_floor=1;
			else
				dest_floor=dest_floor-1;
	}

	if(floors[floor_id -1]->get_persons_num()<Floor::MAX_FLOOR_PERSONS){

		Person* newPerson=new Person();
		assert(newPerson!=0);
		//_ASSERTE(newPerson!=0);
		newPerson->setDestination(dest_floor);
		newPerson->setLocation(floor_id);

		floors[floor_id - 1]->add_person(newPerson);
	}
//	if(!(floors[floor_id - 1]->add_person(newPerson)))
//		delete newPerson;
		
}

void Schedule::notify_reporter(){
	reporter->output<<"\n";
	reporter->report(elevator->toString());
	for(int i=0;i<Floor.TOTAL_FLOOR_NUM;i++)
		reporter->report(floors[i]->toString());
	reporter->output<<"\n";

}

void Schedule::elevator_pooling(){
	elevator->query_floors();
}

void Schedule::elevator_increment_time(){
	elevator->increment_time();
}

Schedule::~Schedule()
{

}
