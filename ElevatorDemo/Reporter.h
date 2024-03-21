// Reporter.h: interface for the Reporter class.
//
//////////////////////////////////////////////////////////////////////

#include "ElevatorDemoDlg.h"
#include <fstream.h>

#if !defined(AFX_REPORTER_H__BB06E04D_C786_41A1_B2A0_6592A474836B__INCLUDED_)
#define AFX_REPORTER_H__BB06E04D_C786_41A1_B2A0_6592A474836B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Reporter{
public:
	Reporter(CElevatorDemoDlg*);
	virtual ~Reporter();

	void report(CString);

	void send_message(CString);
	ofstream output;
private:
	CElevatorDemoDlg* ui;
};

#endif // !defined(AFX_REPORTER_H__BB06E04D_C786_41A1_B2A0_6592A474836B__INCLUDED_)
