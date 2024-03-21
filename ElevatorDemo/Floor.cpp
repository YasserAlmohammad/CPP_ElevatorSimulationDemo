// Floor.cpp: implementation of the Floor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ElevatorDemo.h"
#include "Reporter.h"
#include "Person.h"
#include "Floor.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


int Floor::count=0;
int Floor::MAX_FLOOR_PERSONS=4;
int Floor::TOTAL_FLOOR_NUM=5;


Floor::Floor(Reporter* r){
	ID=++count;
	reporter=r;
	reporter->send_message("new floor was created");
	reset();
	

}

void Floor::reset(){
	persons_num=0;
	//if(waiting_persons!=NULL)
	//	delete [] waiting_persons;
	waiting_persons=new Person*[MAX_FLOOR_PERSONS];
	for(int i=0;i<MAX_FLOOR_PERSONS;i++)
		waiting_persons[i]=NULL;

	light_on=false;
	button_pressed=false;
	reporter->send_message("floor was reset");
}

bool Floor::add_person(Person* p){
	CString message;
	if(persons_num<MAX_FLOOR_PERSONS){
		for(int i=0; i<MAX_FLOOR_PERSONS;i++)
			if(waiting_persons[i]==NULL){
				waiting_persons[i]=p;
				break;
			}
		++persons_num;
		button_pressed=true;
		message.Format("new person was added to floor %d",this->ID);
		reporter->send_message(message);
		return true;
	}
	message.Format("person couldn't be added to floor %d",this->ID);
	reporter->send_message(message);
	return false;

}

Person* Floor::remove_person(){

	Person* temp=NULL;
	for(int i=0; i<MAX_FLOOR_PERSONS; i++)
		if(waiting_persons[i]!=NULL){
			temp=waiting_persons[i];
			temp->setLocation(0);
			--persons_num;
			reporter->send_message("person leaved floor");
			waiting_persons[i]=NULL;
			break;
		}

	if(persons_num==0)
		button_pressed=false;
	return temp;
}

bool Floor::button_is_pressed(){
	return button_pressed;
}

int Floor::get_id(){
	return ID;
}

int Floor::get_persons_num(){
	return persons_num;
}

bool Floor::light_is_on(){
	return light_on;
}

void Floor::switch_light(){
	light_on=!light_on;
}

void Floor::set_button_pressed(bool state){
	button_pressed=state;
}

CString Floor::toString(){
	CString report;
	CString temp;
	report.Format("Floor %d contains %d persons,",ID,persons_num);
	for(int i=0;i<MAX_FLOOR_PERSONS;i++){
		if(waiting_persons[i]!=NULL){
			temp.Format("a person wants to go to floor%d, ",waiting_persons[i]->getDestination());
			report+=temp;
		}
	}
	if(button_pressed)
		temp.Format("button is pressed");
	else
		temp.Format("button is not pressed");
	report+=temp;

	if(light_on)
		temp.Format(",light is on");
	else
		temp.Format(",light is off");
	report+=temp;

	return report;
}

Floor::~Floor(){
	delete [] waiting_persons;
}

