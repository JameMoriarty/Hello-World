// 考勤管理系统Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "考勤管理系统.h"
#include "考勤管理系统Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
#include<iostream>
#include<iomanip>
#include <string.h>
using namespace std;

class Student{
private:
	char name[10];              //姓名
	char date[20];              //考勤记录日期
	char course[20];            //考勤课程
	char type[10];              //考勤类型
	char num[20];               //学号
public:
	Student()
	{
//	    cout<<"请输入学生姓名、学号、缺课日期、缺课课程、缺课类型"<<endl;
//		cin>>name>>num>>date>>course>>type;
	}
	void input()
	{
	    cin>>name>>num>>date>>course>>type;
	}
	void print()
	{
	    cout<<name<<setw(12)<<num<<setw(12)<<date<<setw(12)<<course<<setw(12)<<type<<endl;
	}
	char outnum(char nu[])
	{
	    strcpy(nu,num);
	}
	friend void change(Student s[],int n);
	friend int sreach(Student s[],char nu[],int n);

};

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON6_TC, OnButton6Tc)
	ON_BN_CLICKED(IDC_BUTTON3_TJ, OnButton3Tj)
	ON_BN_CLICKED(IDC_BUTTON1_SYG, OnButton1Syg)
	ON_BN_CLICKED(IDC_BUTTON4_XG, OnButton4Xg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnEditchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	
}

void CMyDlg::OnButton6Tc() 
{
	// TODO: Add your control notification handler code here
	EndDialod(NULL);
}

void CMyDlg::OnButton3Tj() 
{
	// TODO: Add your control notification handler code here
	CButton *cBtnSyg=(CButton *)GetDlgItem();
}

void CMyDlg::OnButton1Syg() 
{
	// TODO: Add your control notification handler code here
	/*
	CButton *cBtnSyg=(CButton *)GetDlgItem(IDC_BUTTON_SYG);
	CButton *cBtnXyg=(CButton *)GetDlgItem(IDC_BUTTON_XYG);
	CButton *cBtnTj=(CButton *)GetDlgItem(IDC_BUTTON_TJ);
	CButton *cBtnCx=(CButton *)GetDlgItem(IDC_BUTTON_CX);
	CButton *cBtnXg=(CButton *)GetDlgItem(IDC_BUTTON_XG);
	CButton *cBtnOk=(CButton *)GetDlgItem(IDCOK);
	CButton *cBtnCa=(CButton *)GetDlgItem(IDCANCEL);
	CButton *cBtnTc=(CButton *)GetDlgItem(IDC_BUTTON_TC);
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);
	CEdit * cEdtRq=(CEdit *)GetDlgItem(IDC_EDIT_RQ);
	CEdit * cEdtKc=(CEdit *)GetDlgItem(IDC_EDIT_KC);
	CEdit * cEdtLx=(CEdit *)GetDlgItem(IDC_EDIT_LX);
	cBtnSyg->EnableWindow(FALSE);
	cBtnXyg->EnableWindow(FALSE);
	cBtnTj->EnableWindow(FALSE);
	cBtnCx->EnableWindow(FALSE);
	cBtnXg->EnableWindow(FALSE);
	cBtnOk->EnableWindow(TRUE);
	cBtnCa->EnableWindow(TRUE);
	cBtnTc->EnableWindow(FALSE);

	cEdtXh->EnableWindow(TRUE);
	cEdtXm->EnableWindow(TRUE);
	cEdtRq->EnableWindow(TRUE);
	cEdtKc->EnableWindow(TRUE);
	cEdtLx->EnableWindow(TRUE);

	cEdtXh->SetFocus();
	boolXgOrTi=FALSE;
	*/
}



void CMyDlg::OnButton4Xg() 
{
	// TODO: Add your control notification handler code here
	
}
