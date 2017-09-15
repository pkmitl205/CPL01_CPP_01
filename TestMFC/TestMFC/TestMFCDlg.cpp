
// TestMFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFC.h"
#include "TestMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMFCDlg dialog


CTestMFCDlg::CTestMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTMFC_DIALOG, pParent)

	, m_numb1(0)
	, m_numb2(0)
	, m_totalb(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUM1, m_numb1);
	DDX_Text(pDX, IDC_NUM2, m_numb2);
	DDX_Text(pDX, IDC_TOTALB, m_totalb);
}

BEGIN_MESSAGE_MAP(CTestMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CTestMFCDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_Plus, &CTestMFCDlg::OnClickPlus)
END_MESSAGE_MAP()


// CTestMFCDlg message handlers

BOOL CTestMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTestMFCDlg::OnBnClickedOk()
{
	
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	{

	}
		
}


void CTestMFCDlg::OnClickPlus()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_totalb = m_numb1 + m_numb2;
	UpdateData(FALSE);
}


void CTestMFCDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
