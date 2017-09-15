
// TestMFCDlg.h : header file
//

#pragma once


// CTestMFCDlg dialog
class CTestMFCDlg : public CDialogEx
{
// Construction
public:
	CTestMFCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnEnChangeEdit1();
//	CString m_name;
//	CString m_email;
	afx_msg void OnEnChangeName();
//	CString m_num1;
//	CString m_num2;
//	CString m_num3;
//	CString m_total;
	afx_msg void OnClickPlus();
	afx_msg void OnEnChangeEdit2();
	int m_numb1;
	int m_numb2;
	int m_totalb;
};
