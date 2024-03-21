// ElevatorUI.cpp: implementation of the ElevatorUI class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ElevatorDemo.h"

#include "Elevator.h"
#include "PersonUI.h"
#include "ElevatorUI.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int ElevatorUI::width=38;
int ElevatorUI::height=40;


ElevatorUI::ElevatorUI()
{
	setPos(0,0);
	elevator=NULL;

}

ElevatorUI::~ElevatorUI()
{

}

void ElevatorUI::setPos(int x,int y){
	pos.x=x;
	pos.y=y;
}

void ElevatorUI::draw(CDC* dc){
	persons_num=elevator->getLoadNum();
	CBrush brush(RGB(100, 0, 0));
	CRect elevatorRect(pos.x,pos.y,pos.x+width,pos.y+height);

	dc->FillRect(elevatorRect,NULL);
	dc->FrameRect(elevatorRect,&brush);

	PersonUI* person=new PersonUI(pos.x,pos.y+height-PersonUI::getHeight());
	int personXPos=pos.x+1;
	for(int i=0;i<elevator->MAX_ELEVATOR_LOAD;i++){
		if(elevator->persons[i]!=NULL){
			person->setPos(personXPos,pos.y+height-PersonUI::getHeight());
			person->draw(dc,elevator->persons[i]);
			personXPos+=2+PersonUI::getWidth();
		}
	}
	delete person;
}

void ElevatorUI::setHeight(int h){
	height=h;
	width=h-2;
}