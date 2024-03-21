// ElevatorDemo.h : main header file for the ELEVATORDEMO application
//

#if !defined(AFX_ELEVATORDEMO_H__305AE25D_B170_48A9_BA27_546376D4CACF__INCLUDED_)
#define AFX_ELEVATORDEMO_H__305AE25D_B170_48A9_BA27_546376D4CACF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CElevatorDemoApp:
// See ElevatorDemo.cpp for the implementation of this class
//

class CElevatorDemoApp : public CWinApp
{
public:
	CElevatorDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CElevatorDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CElevatorDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELEVATORDEMO_H__305AE25D_B170_48A9_BA27_546376D4CACF__INCLUDED_)
