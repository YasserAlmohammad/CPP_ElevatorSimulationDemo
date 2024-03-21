// FloorUI.cpp: implementation of the FloorUI class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ElevatorDemo.h"
#include "PersonUI.h"
#include "Floor.h"
#include "ElevatorUI.h"
#include "FloorUI.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int FloorUI::width=200;
int FloorUI::height=100;
int FloorUI::personSpaceWidth=15;
int FloorUI::elevatorHoleWidth=40;

FloorUI::FloorUI()
{
	setPos(0,0);
	floor=NULL;
}

FloorUI::~FloorUI()
{

}

void FloorUI::setPos(int x,int y){
	pos.x=x;
	pos.y=y;
    elevatorHolePos.x=x+10;
	elevatorHolePos.y=y;
	personsPos.x=pos.x+10+elevatorHoleWidth+10;
	personsPos.y=pos.y+height-PersonUI::getHeight();
}



void FloorUI::setHeight(int h){
	height=h;
	width=height*2;
	ElevatorUI::setHeight(h/2);
	PersonUI::setHeight(h/4);
	personSpaceWidth=PersonUI::getWidth()+5;
	elevatorHoleWidth=ElevatorUI::getWidth()+4;
}

void FloorUI::draw(CDC* dc){
	//if (floor!= NULL){
	persons_num=floor->get_persons_num();
	CBrush brush(RGB(100, 0, 0));
	CRect floorRect(pos.x,pos.y,pos.x+width,pos.y+height);
	CRect elevatorHoleRect(elevatorHolePos.x,elevatorHolePos.y,elevatorHolePos.x+elevatorHoleWidth,pos.y+height);
	PersonUI* person=new PersonUI(personsPos.x,personsPos.y);
	CBrush brushHole(RGB(200,200,200));
	dc->FrameRect(floorRect,&brush);
	dc->FillRect(elevatorHoleRect,&brushHole);
	dc->FrameRect(elevatorHoleRect,&brush);

	int personXPos=personsPos.x;
	for(int i=0;i<floor->MAX_FLOOR_PERSONS;i++){
		if(floor->waiting_persons[i]!=NULL){
			personXPos+=personSpaceWidth;
			person->setPos(personXPos,personsPos.y);
			person->draw(dc,floor->waiting_persons[i]);
		}
	}
	delete person;
	
	//}
}
