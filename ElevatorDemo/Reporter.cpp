// Reporter.cpp: implementation of the Reporter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ElevatorDemo.h"

#include <fstream.h>
#include "ElevatorDemoDlg.h"
#include "Reporter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Reporter::Reporter(CElevatorDemoDlg* u )
{
	ui=u;
	output.open("c:\messages.txt",ios::out);
}

Reporter::~Reporter()
{
	output.close();
}

void Reporter::report(CString report){
	ui->m_sReport=report;
	ui->UpdateData(false);
	output<<"***report:"<<report<<endl;
}

void Reporter::send_message(CString message){
	ui->m_sMessages=message;
	ui->UpdateData(false);
	output<<message<<endl;
	

}
