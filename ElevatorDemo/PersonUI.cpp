// PersonUI.cpp: implementation of the PersonUI class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ElevatorDemo.h"

#include "Person.h"
#include "PersonUI.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int PersonUI::width=10;
int PersonUI::height=20;

PersonUI::PersonUI(int x,int y)
{
	setPos(x,y);
}

PersonUI::~PersonUI()
{

}

void PersonUI::setPos(int x,int y){
	pos.x=x;
	pos.y=y;
}

void PersonUI::setHeight(int h){
	height=h;
	width=h/3;
}

void PersonUI::draw(CDC* dc,Person* p){
	CBrush brush(RGB(255, 0, 0));
	CRect rect(pos.x,pos.y,pos.x+width,pos.y+height);
	dc->FillRect(rect,NULL);
	CString str="";
	str.Format("%d",p->getDestination());
	dc->DrawText(str,rect,DT_CENTER);
	dc->FrameRect(rect,&brush);

}
