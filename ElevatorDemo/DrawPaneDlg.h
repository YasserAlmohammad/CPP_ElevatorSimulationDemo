#if !defined(AFX_DRAWPANEDLG_H__FBCC493B_AF7D_4204_BF00_304D4E1BC411__INCLUDED_)
#define AFX_DRAWPANEDLG_H__FBCC493B_AF7D_4204_BF00_304D4E1BC411__INCLUDED_

#include "ElevatorUI.h"	// Added by ClassView
#include "FloorUI.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DrawPaneDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DrawPaneDlg dialog

class DrawPaneDlg : public CDialog
{
// Construction
public:
	static bool initialized;
	Floor** floors;
	Elevator* elevator;
	void calculateElevatorPos();
	void initializeUI(Elevator* e,Floor** f);
	ElevatorUI elevatorUI;
	FloorUI* floorsUI;
	int floorsNum;
	int elevatorY;
	int elevatorX;
	int startY;
	int startX;
	void callOnPaint();
	DrawPaneDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DrawPaneDlg)
	enum { IDD = IDD_DRAWPANE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DrawPaneDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DrawPaneDlg)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWPANEDLG_H__FBCC493B_AF7D_4204_BF00_304D4E1BC411__INCLUDED_)
