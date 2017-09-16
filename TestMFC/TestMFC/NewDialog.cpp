// NewDialog.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFC.h"
#include "NewDialog.h"
#include "afxdialogex.h"


// CNewDialog dialog

IMPLEMENT_DYNAMIC(CNewDialog, CDialogEx)

CNewDialog::CNewDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NEWDIALOG, pParent)
{

}

CNewDialog::~CNewDialog()
{
}

void CNewDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNewDialog, CDialogEx)
END_MESSAGE_MAP()


// CNewDialog message handlers
