#include "stdafx.h"
#include <math.h>
#include "KOHC.h"
#include "KOHCDoc.h"
#include "Variants.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
void Variants::AssertValid() const
{
	CFormView::AssertValid();
}

void Variants::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
KOHCDoc* Variants::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(KOHCDoc)));
	return (KOHCDoc*)m_pDocument;
}
#endif
/////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(Variants, CFormView)
Variants::Variants()
	: CFormView(Variants::IDD)
{
//{{AFX_DATA_INIT(Variants)
	Student = "";
	Variant = 0;
	L = 0.0;
	L1 = 0.0;
	L2 = 0.0;
	LT = 0.0;
	W = 0.0;
	W1 = 0.0;
	WG = 0.0;
	WK = 0.0;
	P = 0.0;
	D = 0.0;
	DG = 0.0;
	Q = 0.0;
	QV = 0.0;
	QG = 0.0;
	Num = 0;
	n = 0;
//}}AFX_DATA_INIT
}
Variants::~Variants()
{
}
void Variants::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
//{{AFX_DATA_MAP(Variants)
	DDX_Control(pDX, IDC_SPIN1, NUM);
	DDX_Control(pDX, IDC_STUDENTS, CBStudent);
	DDX_CBString(pDX, IDC_STUDENTS, Student);
	DDX_Text(pDX, IDC_VARIANT, Variant);
	DDX_Text(pDX, IDC_SPAN, L);
	DDX_Text(pDX, IDC_LENGTH_EDGE, L1);
	DDX_Text(pDX, IDC_LENGTH_REST, L2);
	DDX_Text(pDX, IDC_LENGTH_TRAILER, LT);
	DDX_Text(pDX, IDC_HIGH_REST, W);
	DDX_Text(pDX, IDC_HIGH_EDGE, W1);
	DDX_Text(pDX, IDC_WIDTH_HORIZ, WG);
	DDX_Text(pDX, IDC_DISTANCE_MAIN, WK);
	DDX_Text(pDX, IDC_FORCE_LOAD, P);
	DDX_Text(pDX, IDC_FORCE_VERTIC, D);
	DDX_Text(pDX, IDC_FORCE_HORIZ, DG);
	DDX_Text(pDX, IDC_LOAD_MAIN, Q);
	DDX_Text(pDX, IDC_LOAD_ASSIS, QV);
	DDX_Text(pDX, IDC_LOAD_HORIZ, QG);
	DDX_Text(pDX, IDC_NUMBER, Num);
	DDX_Text(pDX, IDC_QUANTITY, n);
//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(Variants, CFormView)
//{{AFX_MSG_MAP(Variants)
	ON_BN_CLICKED(IDC_INCLUDE, OnInclude)
	ON_BN_CLICKED(IDC_ERASE, OnErase)
	ON_BN_CLICKED(IDC_CLEAN, OnClean)
	ON_CBN_SELENDOK(IDC_STUDENTS, OnSelStudent)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
void Variants::Calculate() //������ ������ �������� �������
{
	if (Student=="") {
		MessageBox("������� ������� � ��� ��������");
		return;
	}
 	UINT let;
	
	int nb, nh,np;
	int nx;
	double l[]= {22., 31., 19., 27., 33., 21., 28., 16., 25., 13.};
	double l2[] ={1.5, 1.8, 1.4, 1.7, 1.3, 1.6, 1.2};
	double p[]= {200.,400.,150.,350.,125.,300.,100.,250.,450.};
 	int i = NUM.GetPos();
    
 	let = abs(Student.GetAt(0));
 	 int n1 = (let+ i) % 9;
 	let = abs(Student.GetAt(1));
 	 int n2 = (let+ i) % 10;
 	let = abs(Student.GetAt(2));
 	int n3 = (let+ i) % 7;
 	
	for (; ;) 
 	{
	if (n3 == 8) n3 = 1;
 		nx = int(l[n2] / l2[n3]);
 		n =int (nx / 2 *2 + 2);
 		L1 = float((l[n2] - (n - 2) * l2[n3]) / 2.f);
	if ((L1 >= .3f) && (L1 <= 1.5f)) break;
 		n3++;
 	}

 	LT = (l[n2] > 20.f) ? 2.5f : 2.2f;
 	W  = int(l[n2] / 2.f + 7.f) / 10.f;
 	W1 = int(W * 4.5f) / 10.f;
 	WG = int(W * 7.f) / 10.f;
 	WK = int(W * 16.f) / 10.f;
 	D  = int(p[n1] * 3.75f) / 10.f;
 	DG = int(D * 1.2f) / 10.f;
 	Q  = int(sqrt(p[n1] * l[n2]) * .6f) / 100.f;
 	QV = int(Q * 31.f) / 100.f;
 	QG = int(Q * 15.f) / 100.f;
 	nb = int(n / 2);
 	nh = int((n + 2) / 4);
	np=nb;
 	P=float (p[n1]);
 	L=float (l[n2]);
 	L2=float (l2[n3]);
 	Variant=i*1000000+n1*10000+n2*100+n3;
 	UpdateData(FALSE);
 }
BOOL Variants::PreCreateWindow(CREATESTRUCT& cs) 
{
	return CFormView::PreCreateWindow(cs);
}
BOOL Variants::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, 
					 const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
void Variants::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	CEdit *prow=(CEdit *)GetDlgItem(IDC_NUMBER);
    NUM.SetBuddy(prow);
	NUM.SetRange(1,40);
	NUM.SetBase(1);
	NUM.SetPos(1);
}
void Variants::OnInclude()//��������� �������� � ������
{ 
    UpdateData(TRUE);
	Num++;
	Calculate();	//������ ������ �������� �������
	CBStudent.AddString(Student);
	CStdioFile work;
	if (!work.Open(Student+".txt", CFile::modeCreate | CFile::modeWrite | CFile::typeText)) {
		AfxMessageBox("������ �������� ����� " + Student + ".txt");
		return;
	};
	CString str;
	char Name[] = "            ";
	int i;
	for (i=0; i<Student.GetLength(); i++)
		Name[i]=Student[i];
	work.WriteString(" |-------------------------------------------------------------------|\n");
	work.WriteString(" |-------------------------------------------------------------------|\n");
	work.WriteString(" |    �������     |        ������� �� ������         |    �������    |\n");
    str.Format(" |   %s |      <<������� �����������>>     |    %d    |\n",Name,Variant);
	work.WriteString(str);
	work.WriteString(" |-------------------------------------------------------------------|\n");
    str.Format(" |������ �����   . . . . . . . . . . . . . . . . . L  =  %8.2f  � |\n",L);
    work.WriteString(str);
	str.Format(" |����� ������� �������� �������� �����  . . . . . L1 =   %8.2f � |\n",L1);
	work.WriteString(str);
    str.Format(" |����� ��������� �������� �������� �����  . . . . L2 =  %8.2f  � |\n",L2);
	work.WriteString(str);
    str.Format(" |���� �������   . . . . . . . . . . . . . . . . . LT =  %8.2f  � |\n",LT);
	work.WriteString(str);
    str.Format(" |������ �������� �����   . . . . . . . . . . . .  W1 =  %8.2f  � |\n",W1);
	work.WriteString(str);
    str.Format(" |������ ����� ������������ ����� . . . . . . . .  W  =  %8.2f  � |\n",W);
	work.WriteString(str);
    str.Format(" |���������� ����� �������� ������� . . . . . . .  WK =  %8.2f  � |\n",WK);
	work.WriteString(str);
    str.Format(" |������ �������������� ����� . . . . . . . . . .  WG =  %8.2f  � |\n",WG);
	work.WriteString(str);
    str.Format(" |���������������� ����� . . . . . . . . . . . . . P  = %8.2f  K� |\n",P);
	work.WriteString(str); 
    str.Format(" |������������ ���� �� �������� ������ �������. .   D =  %8.2f �� |\n",D);
	work.WriteString(str); 
    str.Format(" |�������������� ����������� ����  . . . . . . .   DG = %8.2f ��  |\n",DG);
	work.WriteString(str); 
    str.Format(" |�������������� ��������: �� ������� �����. . .    Q =%8.2f ��/� |\n",Q);
	work.WriteString(str);
    str.Format(" |      �� ������������ ��������������� �����. .   QV =%8.2f ��/� |\n",QV);
	work.WriteString(str);
    str.Format(" |�������������� �������������� �������� . . . .   QG = %8.2f ��/�|\n",QG);
	work.WriteString(str);
    str.Format(" |���������� �������� �������� �����   . . . . .    n = %d ����      |\n",n);
	work.WriteString(str);
    work.WriteString(" |-------------------------------------------------------------------|\n");
    work.WriteString(" | ������������ ��������� ������� ������������������    |    m       |\n");
    work.WriteString(" | ��� ������� ������� �����                            |   1.1      |\n");
    work.WriteString(" | ��� ������� �������� � ����� �������������� �����    |   1.0      |\n");
    work.WriteString(" | ��� ������� �������� ����� ����������� �������       |   0.5      |\n");
    work.WriteString(" |-------------------------------------------------------------------|\n");
    work.WriteString(" |             ������� ������ ��� ��������               |����/����� |\n");
    work.WriteString(" |-------------------------------------------------------------------|\n");
    work.WriteString(" | 1.��������� ����� ���� ��������� �����  (3 ��������). |           |\n");
       int nb, nh,np;
	nb = int(n / 2);
 	nh = int((n + 2) / 4);
	np=nb;
    str.Format(" | ��� �������� ������� �����: B-%2d , H-%d ,P-%2d,C-1, C-2 |  10 ����� |\n",nb,nh,np);
	work.WriteString(str);
	work.WriteString(" |   ��������� ����� ������� ������ �� ��������� ����  � |           |\n");
    work.WriteString(" |   ���������� ������:  �� �������������� �������� N(Q),|   20%     |\n");
    work.WriteString(" |     - �� ��������������� ��� : Nmax(D) � Nmin(D)      |           |\n");
    work.WriteString(" |-------------------------------------------------------------------|\n");
    work.WriteString(" |2.��������� ����������� ������� ��� ��������� �������� |           |\n");
    work.WriteString(" | ������� � ��������������� ����.                       |           |\n");
    work.WriteString(" | C�������� ������� ������������ � ����������� ������   | 10 ������ |\n");
    work.WriteString(" | � �������� ������� ����� � ������ ��������� ��������  |           |\n");
    work.WriteString(" | ������ �� �������� � ������������ � ��������������    |   40%     |\n");
    work.WriteString(" | ������ � ��������� �������� � ����������� �� �������� |           |\n");
    work.WriteString(" |-------------------------------------------------------------------|\n");
    work.WriteString(" | 3.����������� � ������������� ���� ������� �������    |           |\n");
    work.WriteString(" |  �������� ������� � �������������� ����, ���������    |           |\n");
    work.WriteString(" |  ������� ������� �� �������� �� ����������� ���������,| 30 ������ |\n");
    work.WriteString(" |  ������������ � ������������ ��� ������; ��������� �  |           |\n");
    work.WriteString(" |  �������������� �������� �����; �������������� �������|   60%     |\n");
    work.WriteString(" |  ����, ���������� ������� ���. ��������� 1-� ���� -   |           |\n");
    work.WriteString(" |  ���������������� ������� ���� ������� ����� �������  |           |\n");
    work.WriteString(" |  ��������. ���������� ����� ������� �����.            |           |\n");
    work.WriteString(" |-------------------------------------------------------------------|\n");
    work.WriteString(" |4.����������� ������� ��������� ��� ������� ����� ���- |           |\n");
    work.WriteString(" | ���� ��������. �������������� ������� ����, ��������� |           |\n");
    work.WriteString(" | ����������� ������� ������������ ����������. ���������| 15 ���    |\n");
    work.WriteString(" | 2-� ���� - ���������������� ������� ���� ������� �����|           |\n");
    work.WriteString(" | ������� ��������. ���������� ����� ������� �����.     |   80%     |\n");
    work.WriteString(" | ��������� 3-� ���� - ����� ��� ���� 1 � 2 ��������.   |           |\n");
    work.WriteString(" |-------------------------------------------------------------------|\n");
    work.WriteString(" |5.��������� 4-� ���� - ��������������� ������� �� ���- | 30 ���    |\n");
    work.WriteString(" | ����� ������������ � ��������-������������� �������.  |   100%    |\n");
    work.WriteString(" |-------------------------------------------------------------------|\n");
    work.WriteString(" |-------------------------------------------------------------------|\n");
	work.Close();
}
void Variants::OnErase() 
{    
	int iPos=CBStudent.GetCurSel();
	CBStudent.DeleteString(iPos);
	UpdateData(TRUE);
	Variant = 0;
	L = 0.0;
	L1 = 0.0;
	L2 = 0.0;
	LT = 0.0;
	W = 0.0;
	W1 = 0.0;
	WG = 0.0;
	WK = 0.0;
	P = 0.0;
	D = 0.0;
	DG = 0.0;
	Q = 0.0;
	QV = 0.0;
	QG = 0.0;
	Num = 0;
	n = 0;
	UpdateData(FALSE);
}
void Variants::OnClean() 
{
	CBStudent.ResetContent();
	UpdateData(TRUE);
	Variant = 0;
	L = 0.0;
	L1 = 0.0;
	L2 = 0.0;
	LT = 0.0;
	W = 0.0;
	W1 = 0.0;
	WG = 0.0;
	WK = 0.0;
	P = 0.0;
	D = 0.0;
	DG = 0.0;
	Q = 0.0;
	QV = 0.0;
	QG = 0.0;
	Num = 0;
	n = 0;
	UpdateData(FALSE);
}
void Variants::OnSelStudent() 
{
	int iPos=CBStudent.GetCurSel();
	CBStudent.GetLBText(iPos, Student);
	Calculate();	//������ ������ �������� �������
}

