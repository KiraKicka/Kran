// KPAHView.cpp : implementation of the KPAHView class
//

#include "stdafx.h"
#include "KPAH.h"

#include "KPAHDoc.h"
#include "KPAHView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// KPAHView

IMPLEMENT_DYNCREATE(KPAHView, CFormView)

BEGIN_MESSAGE_MAP(KPAHView, CFormView)
//{{AFX_MSG_MAP(KPAHView)
	ON_BN_CLICKED(IDC_REGISTER, OnRegister)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
KPAHView::KPAHView()
	: CFormView(KPAHView::IDD)
{
//{{AFX_DATA_INIT(KPAHView)
	Student = "";
	Numstu = "";
//}}AFX_DATA_INIT
}
KPAHView::~KPAHView()
{
}
//---------------------------------------------------------------
void KPAHView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
//{{AFX_DATA_MAP(KPAHView)
	DDX_Text(pDX, IDC_STUDENT, Student);
	DDX_Text(pDX, IDC_NUMSTU, Numstu);
//}}AFX_DATA_MAP
}
//---------------------------------------------------------------
BOOL KPAHView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CFormView::PreCreateWindow(cs);
}

void KPAHView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	GetDlgItem(IDC_STUDENT)->SetWindowText(Student);
	GetDlgItem(IDC_NUMSTU)->SetWindowText(Numstu);
}
/////////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
void KPAHView::AssertValid() const
{
	CFormView::AssertValid();
}
void KPAHView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
//---------------------------------------------------------------
KPAHDoc* KPAHView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(KPAHDoc)));
	return (KPAHDoc*)m_pDocument;
}
#endif //_DEBUG
/////////////////////////////////////////////////////////////////////////////
void KPAHView::OnRegister() 
{
	CString Stu,Num;
	GetDlgItem(IDC_STUDENT)->GetWindowText(Stu);
	GetDlgItem(IDC_NUMSTU)->GetWindowText(Num);
	int num =atoi(Num);
 	int i = num/1000000;
	int j = num%1000000;
	int let,n1,n2,n3;
 	let = abs(Stu.GetAt(0));
 	n1 = (let+ i) % 9;
 	let = abs(Stu.GetAt(1));
 	n2 = (let+ i) % 10;
 	let = abs(Stu.GetAt(2));
 	n3 = (let+ i) % 7;
/*	if (n1*10000+n2*100+n3==j)
	{
		ofstream fout;
		fout.open("user.txt");
		fout<<Stu<<" "<<Num;
		fout<<flush;
		fout.close();
	}
	else
	{
		MessageBox("name or number wrong!!!!!");
		ofstream fout;
		fout.open("user.txt");
		fout<<"";
		fout<<flush;
		fout.close();
	}
		
*/
}

