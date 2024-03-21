// ElevatorDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ElevatorDemo.h"
#include "Reporter.h"
#include "Floor.h"
#include "Elevator.h"
#include "Schedule.h"

#include "PersonUI.h"
#include "FloorUI.h"
#include "ElevatorUI.h"

#include "DrawPaneDlg.h"
#include "ElevatorDemoDlg.h"

#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



Schedule* schedule;
Reporter* reporter;
Floor** floors;
Elevator* elevator;
DrawPaneDlg drawPane;


/////////////////////////////////////////////////////////////////////////////
// CElevatorDemoDlg dialog

CElevatorDemoDlg::CElevatorDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CElevatorDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CElevatorDemoDlg)
	m_sMessages = _T("");
	m_sReport = _T("");
	m_iPersonI = 0;
	m_iReportI = 0;
	m_iSpeed = 0;
	m_iFloorNum = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}




void CElevatorDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CElevatorDemoDlg)
	DDX_Control(pDX, IDC_MESSAGES, m_cMessages);
	DDX_Control(pDX, IDC_REPORT, m_cReport);
	DDX_Control(pDX, IDC_VALIDATE, m_cValid);
	DDX_Control(pDX, ID_STOPTIMER, m_cStop);
	DDX_Control(pDX, ID_STARTTIMER, m_cStart);
	DDX_Text(pDX, IDC_MESSAGES, m_sMessages);
	DDX_Text(pDX, IDC_REPORT, m_sReport);
	DDX_Text(pDX, IDC_PERSON, m_iPersonI);
	DDX_Text(pDX, IDC_REPORTI, m_iReportI);
	DDX_Text(pDX, IDC_SPEED, m_iSpeed);
	DDX_Text(pDX, IDC_FLOORNUM, m_iFloorNum);
	DDV_MinMaxInt(pDX, m_iFloorNum, 2, 10);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CElevatorDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CElevatorDemoDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_STARTTIMER, OnStarttimer)
	ON_BN_CLICKED(ID_STOPTIMER, OnStoptimer)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_VALIDATE, OnValidate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CElevatorDemoDlg message handlers

BOOL CElevatorDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_iElevatorInterval=1000;
	m_iPoolingInterval=1000;
	m_iPersonInterval=5000;
	m_iReportInterval=1000;
	
	on=FALSE;
	
	reporter=new Reporter(this);
	floors=new Floor*[Floor.TOTAL_FLOOR_NUM];
	for(int i=0;i<Floor.TOTAL_FLOOR_NUM;i++)
		floors[i]=new Floor(reporter);
	elevator=new Elevator(floors,reporter);	
	schedule=new Schedule(floors,elevator,reporter);


	drawPane.Create(IDD_DRAWPANE,this);
	drawPane.ShowWindow(SW_SHOW);
	drawPane.initializeUI(elevator,floors);
	drawPane.Invalidate();


	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CElevatorDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CElevatorDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CElevatorDemoDlg::OnStarttimer() 
{
	on=TRUE;
	
//	SetTimer(ID_REPORTER_TIMER,m_iReportInterval,NULL);
//	SetTimer(ID_POOLING_TIMER,m_iPoolingInterval,NULL);
	SetTimer(ID_PERSONS_TIMER,m_iPersonInterval,NULL);
	SetTimer(ID_ELEVATOR_TIME_TIMER,m_iElevatorInterval,NULL);
	
	m_cStop.EnableWindow(TRUE);
	m_cStart.EnableWindow(FALSE);
	m_cValid.EnableWindow(FALSE);
}

void CElevatorDemoDlg::OnStoptimer() 
{
	on=FALSE;
//	KillTimer(ID_REPORTER_TIMER);
//	KillTimer(ID_POOLING_TIMER);
	KillTimer(ID_PERSONS_TIMER);
	KillTimer(ID_ELEVATOR_TIME_TIMER);

/*
	ofstream output("output.txt",ios::out);
	CTime time=CTime::GetCurrentTime();
	output<<time.GetHour()<<":"<<time.GetMinute()<<":"<<time.GetSecond()<<":"<<endl;
	output<<fileOutPut<<endl;
	output.close();
*/	
	m_cStop.EnableWindow(FALSE);
	m_cStart.EnableWindow(TRUE);
	m_cValid.EnableWindow(TRUE);
}

void CElevatorDemoDlg::OnTimer(UINT nIDEvent) 
{
	switch(nIDEvent){
	case ID_ELEVATOR_TIME_TIMER:
			 schedule->notify_reporter();
			 schedule->elevator_increment_time();
			 schedule->elevator_pooling();
			 drawPane.Invalidate();
		break;
/*	case ID_POOLING_TIMER:
			 schedule->elevator_pooling();
		break;

	case ID_REPORTER_TIMER:
			 schedule->notify_reporter();
		break;
*/
  case ID_PERSONS_TIMER:
			 schedule->floor_generate_person();

		break;
	}

	UpdateData(FALSE);	
	CDialog::OnTimer(nIDEvent);
}


void CElevatorDemoDlg::OnValidate() 
{

	bool go=false;
	bool outOfRange=false;
	if(on)
		OnStoptimer();

	UpdateData(TRUE);
	if((m_iPersonI>0)&&(m_iPersonI<25)){
		go=true;
		m_iPersonInterval=m_iPersonI*1000;
	}
	else
		outOfRange=true;

	if((m_iReportI<10)&&(m_iReportI>0)){
		go=true;
		m_iReportInterval=m_iReportI*1000;
	}
	else
		outOfRange=true;

	if((m_iSpeed>0)&&(m_iSpeed<=20)){
		go=true;
		elevator->TIME_FROM_FLOOR_TO_ANOTHER=m_iSpeed;
	}
	else
		outOfRange=true;

	//initialize again
	if((m_iFloorNum>1)&&(m_iFloorNum<10)){
		go=true;
		int oldNum=floors[0]->TOTAL_FLOOR_NUM;
		Floor::count=0;
		floors[0]->TOTAL_FLOOR_NUM=m_iFloorNum;
		
		//free old memory
		delete schedule;
		delete elevator;
		for(int i=0;i<oldNum;i++)
			delete floors[i];
		delete [] floors;

		//reaLlocate memory
		floors=new Floor*[Floor.TOTAL_FLOOR_NUM];
		for(i=0;i<Floor.TOTAL_FLOOR_NUM;i++)
			floors[i]=new Floor(reporter);
		elevator=new Elevator(floors,reporter);	
		schedule=new Schedule(floors,elevator,reporter);

		drawPane.initializeUI(elevator,floors);
		drawPane.Invalidate();
	}
	else
		outOfRange=true;
	if(outOfRange)
		MessageBox("one or more values not set properly");
	
	
}
