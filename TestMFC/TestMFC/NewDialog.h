#pragma once


// CNewDialog dialog

class CNewDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CNewDialog)

public:
	CNewDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNewDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEWDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
