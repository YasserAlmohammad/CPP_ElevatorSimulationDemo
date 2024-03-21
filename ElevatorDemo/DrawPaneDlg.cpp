// DrawPaneDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ElevatorDemo.h"
#include "DrawPaneDlg.h"

#include "Floor.h"
#include "Elevator.h"
#include "PersonUI.h"
#include "ElevatorUI.h"
#include "FloorUI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DrawPaneDlg dialog

bool DrawPaneDlg::initialized=false;

DrawPaneDlg::DrawPaneDlg(CWnd* pParent /*=NULL*/)
	: CDialog(DrawPaneDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(DrawPaneDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DrawPaneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DrawPaneDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DrawPaneDlg, CDialog)
	//{{AFX_MSG_MAP(DrawPaneDlg)
	ON_WM_PAINT()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DrawPaneDlg message handlers

void DrawPaneDlg::callOnPaint()
{
	OnPaint();
}

void DrawPaneDlg::initializeUI(Elevator *e, Floor **f)
{
	CRect clientRect;
	GetClientRect(&clientRect);
	elevator=e;
	floors=f;

	//check for updating: so reallocate memory if neccessary

	if(floorsUI!=NULL){
		delete [] floorsUI;
	}


	startX=0;
	startY=0;
	elevatorX=0;
	elevatorY=0;
	floorsNum=Floor.TOTAL_FLOOR_NUM;
	int clientHeight=clientRect.Height();
	FloorUI::setHeight(clientHeight/floorsNum);
	int buildingHeight=FloorUI::getHeight()*floorsNum;
	
	//draw floors
	floorsUI=new FloorUI[floorsNum];

	for(int i=0;i<floorsNum;i++){
		floorsUI[i].setFloor(f[i]); //first building is down
		floorsUI[i].setPos(startX,startY+buildingHeight-(i+1)*FloorUI::getHeight());
	}
	
	elevatorUI.setElevator(e);
	initialized=true;

}

void DrawPaneDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	for(int i=0;i<floorsNum;i++){
		floorsUI[i].draw(&dc);
	}

	
	calculateElevatorPos();
	
	elevatorUI.setPos(elevatorX,elevatorY);
	elevatorUI.draw(&dc);
	
	// Do not call CDialog::OnPaint() for painting messages
}

void DrawPaneDlg::calculateElevatorPos()
{
	elevatorX=floorsUI[floorsNum-1].getHolePos().x+1;
	int down=elevator->get_location().down_floor_id;
	
	if(down!=0){ //it's between
		float Y=floorsUI[down-1].getPos().y; //the cieling
		float percent=(float)elevator->get_location().floor_percent/elevator->TIME_FROM_FLOOR_TO_ANOTHER;
		percent=1-percent;
		Y=Y+percent*FloorUI::getHeight()-elevatorUI.getHeight(); 
		elevatorY=(int)Y; 
	}
	else{
		int in=elevator->get_location().in_floor_id;
		int Y=floorsUI[in-1].getPos().y;
		Y=Y+FloorUI::getHeight()-elevatorUI.getHeight();
		elevatorY=Y;
		
	}
	
	
}

void DrawPaneDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	if(initialized){
		CRect clientRect;
		GetClientRect(&clientRect);

		int startX=0;
		int startY=0;

		int clientHeight=clientRect.Height();
		FloorUI::setHeight(clientHeight/floorsNum);
		int buildingHeight=FloorUI::getHeight()*floorsNum;
	
		for(int i=0;i<floorsNum;i++)
			floorsUI[i].setPos(startX,startY+buildingHeight-(i+1)*FloorUI::getHeight());
	
		Invalidate();
	}
	
}
