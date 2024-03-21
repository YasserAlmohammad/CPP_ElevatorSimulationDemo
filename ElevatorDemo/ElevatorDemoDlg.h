// ElevatorDemoDlg.h : header file
//


#if !defined(AFX_ELEVATORDEMODLG_H__7B8AF379_E97A_4578_BE9B_9806AB403F09__INCLUDED_)
#define AFX_ELEVATORDEMODLG_H__7B8AF379_E97A_4578_BE9B_9806AB403F09__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CElevatorDemoDlg dialog

class CElevatorDemoDlg : public CDialog
{
// Construction
public:
	void drawScene();
	BOOL on;
	CString fileOutPut;
	int m_iReportInterval;
	int m_iPersonInterval;
	int m_iPoolingInterval;
	int m_iElevatorInterval;
	CElevatorDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CElevatorDemoDlg)
	enum { IDD = IDD_ELEVATORDEMO_DIALOG };
	CEdit	m_cMessages;
	CEdit	m_cReport;
	CButton	m_cValid;
	CButton	m_cStop;
	CButton	m_cStart;
	CString	m_sMessages;
	CString	m_sReport;
	int		m_iPersonI;
	int		m_iReportI;
	int		m_iSpeed;
	int		m_iFloorNum;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CElevatorDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CElevatorDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStarttimer();
	afx_msg void OnStoptimer();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnValidate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELEVATORDEMODLG_H__7B8AF379_E97A_4578_BE9B_9806AB403F09__INCLUDED_)
