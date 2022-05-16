#include "stdafx.h"
#include <math.h>
#include "KOHC.h"
#include "KOHCDoc.h"
#include "Forces.h"
#include <string>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
void Forces::AssertValid() const
{
	CFormView::AssertValid();
}

void Forces::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
KOHCDoc* Forces::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(KOHCDoc)));
	return (KOHCDoc*)m_pDocument;
}
#endif
/////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(Forces, CFormView)
Forces::Forces()
	: CFormView(Forces::IDD)
{
//{{AFX_DATA_INIT(Forces)
	NDG = 0.0;
	NDMAX = 0.0;
	NGMAX = 0.0;
	NGMIN = 0.0;
	NMAX = 0.0;
	NMIN = 0.0;
	NQ = 0.0;
	NQG = 0.0;
	Numctep = 0;
	Numstu = 0;
	Student = _T("");
	NDMIN = 0.0;
//}}AFX_DATA_INIT
}
Forces::~Forces()
{
}
void Forces::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
//{{AFX_DATA_MAP(Forces)
	DDX_Control(pDX, IDC_SPIN1, NUMCTEP);
	DDX_Control(pDX, IDC_SPIN2, NUMSTU);
	DDX_Control(pDX, IDC_STUDENTS, CBStu);
	DDX_Control(pDX, IDC_CTEP, CBCtep);
	DDX_Text(pDX, IDC_NDG, NDG);
	DDX_Text(pDX, IDC_NDMAX, NDMAX);
	DDX_Text(pDX, IDC_NGMAX, NGMAX);
	DDX_Text(pDX, IDC_NGMIN, NGMIN);
	DDX_Text(pDX, IDC_NMAX, NMAX);
	DDX_Text(pDX, IDC_NMIN, NMIN);
	DDX_Text(pDX, IDC_NQ, NQ);
	DDX_Text(pDX, IDC_NQG, NQG);
	DDX_Text(pDX, IDC_NUMCTEP, Numctep);
	DDX_Text(pDX, IDC_NUMSTU, Numstu);
	DDX_CBString(pDX, IDC_STUDENTS, Student);
	DDX_Text(pDX, IDC_NDMIN, NDMIN);
//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(Forces, CFormView)
//{{AFX_MSG_MAP(Forces)
	ON_BN_CLICKED(IDC_SHOW, OnShow)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
void Forces::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	CEdit *prow1=(CEdit *)GetDlgItem(IDC_NUMSTU);
    NUMSTU.SetBuddy(prow1);
	NUMSTU.SetRange(1,40);
	NUMSTU.SetBase(1);
	NUMSTU.SetPos(1);
	CEdit *prow2=(CEdit *)GetDlgItem(IDC_NUMCTEP);
	NUMCTEP.SetBuddy(prow2);
	NUMCTEP.SetRange(1,20);
	NUMCTEP.SetBase(1);
	NUMCTEP.SetPos(1);
	CBCtep.SetCurSel(0);
}
void Forces::Calculate()
{
	UpdateData(TRUE);
	if (Student=="")
	{
		MessageBox("no name");
		return;
	}
	else
	{
	double  e;
	double	e1;
	double	e2;
	double	e3;
	double  a;
	double	a1;
	double	a2;
	double	a3;
	double	a4;
	double	a5;
	double	a6;
	double	a7;
	double	a8;
	double	a9;
	double	a10;
	double	a11;
	double	a12;
 	UINT let;
    int  n1, n2, n3;
    int nb, nh;
    int nx;
    double l[]= {22., 31., 19., 27., 33., 21., 28., 16., 25., 13.};
    double l2[] ={1.5, 1.8, 1.4, 1.7, 1.3, 1.6, 1.2};
    double p[]= {200.,400.,150.,350.,125.,300.,100.,250.,450.};
 	UpdateData();
 	int i = NUMSTU.GetPos();
 	let = abs(Student.GetAt(0));
 	n1 = (let+ i) % 9;
 	let = abs(Student.GetAt(1));
 	n2 = (let+ i) % 10;
 	let = abs(Student.GetAt(2));
 	n3 = (let+ i) % 7;
 	for (; ;) 
 	{
 		if (n3 == 8) n3 = 1;
 		nx = int(l[n2] / l2[n3]);
 		n = nx / 2 *2 + 2;
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
 	P=float (p[n1]);
 	L=float (l[n2]);
 	L2=float (l2[n3]);
	///////////////////////////////
	e=QV/Q;
	e1=QG/Q;
	e2=DG/D;
	e3=WG/W;
	B[1][1]=B[1][2]=B[1][3]=B[1][4]=B[1][5]=B[1][6]=PP[1][3]=PP[2][3]=0;
	for (int it=2;it<=nb;it++)
	{
		a1=L1+(((it/2)*2)-1)*L2;
		B[it][1]=a1*(a1-L)*Q/W/2;
		B[it][2]=D*a1*(LT+a1*2-L*2)/W/L;
		B[it][4]=B[it][1]*e;
        B[it][5]=B[it][1]*e1/e3;
		B[it][6]=B[it][2]*e2/e3;
	}
	a=L1+L2;
	a2=cos(atan(L2/W)+atan((W-W1)/a));
	a3=cos(atan(L2/WG));
	a4=a2*sqrt(pow(L2,2)+pow(W,2));
	a5=a3*sqrt(pow(L2,2)+pow(WG,2));
	H[1][1]=(L-L1)*L1*Q/a4/2;
	H[1][2]=(L*2-L1*2-LT)*L1*D/a4/L;
	H[1][4]=H[1][1]*e;
	H[1][5]=H[1][1]*e1*a4/a5;
	H[1][6]=H[1][2]*e2*a4/a5;
	for (int is=2;is<=nh;is++)
		{
			a6=L1+(is-1)*L2*2;
			H[is][1]=a6*(L-a6)/W/2*Q;
			H[is][2]=a6*(L*2-a6*2-LT)*D/W/L;
			H[is][4]=H[is][1]*e;
			H[is][5]=H[is][1]*e1/e3;
			H[is][6]=H[is][2]*e2/e3;

		}
	  a7=a*sqrt(W1*W1+L1*L1)/(W1*L2+W*L1);
      a8=sqrt(WG*WG+L1*L1)/WG;
      PP[1][1]=a7*(L1-L)*Q/2;
      PP[1][2]=a7*(L1*2+LT-L*2)*D/L;
      PP[1][4]=PP[1][1]*e;
      PP[1][5]=a8*(L1-L)*QG/2;
      PP[1][6]=PP[1][2]*a8/a7*e2;
      a9=a2*L*W*sqrt(a*a+(W-W1)*(W-W1));
      a10=a3*L*WG*a;
      PP[2][1]=a*L*(W1*(L-a)-L1*W)*Q/a9/2;
      PP[2][2]=(2*(L-a)-LT)*W1*a*D/a9;
      PP[2][4]=PP[2][1]*e;
      PP[2][5]=a*L*WG*(L-L2)*QG/a10/2;
      PP[2][6]=PP[2][2]*WG/W1*e2*a9/a10;
      a11=L*cos(atan(L2/W));
      a12=L*cos(atan(L2/WG));
	  for (int il=3;il<=nb;il++)
	  {
		  PP[il][1]=pow((-1.),il)*((1.5-il)*L2-L1+L/2)/a11*Q*L;
		  PP[il][2]=pow((-1.),il)*(L-L1-(il-1)*L2-LT/2)*D*2/a11;
		  PP[il][3]=pow((-1.),il)*(LT/2-L1-(il-2)*L2)*2/a11*D;
		  PP[il][4]=PP[il][1]*e;
		  PP[il][5]=PP[il][1]*a11/a12*e1;
	      PP[il][6]=PP[il][2]*a11/a12*e2;


	  }
	  C[1][1]=-L1*Q/2;
      C[1][2]=-D;
      C[1][4]=C[1][1]*e;
      C[1][5]=C[1][1]*e1;
      C[1][6]=-DG;
      C[2][1]=-L2*Q;
      C[2][2]=-D;
      C[2][4]=-L2*QV;
      C[2][5]=-L2*QG;
      C[2][6]=-DG;
      for (int ip=1;ip<=6;ip++)
		  C[3][ip]=C[2][ip];
	  if(CBCtep.GetCurSel()==0)
	  {
		  NQ=B[Numctep][1];
		  NDMAX=B[Numctep][2];
		  NDMIN=0;
		  NQG=B[Numctep][5];
		  NDG=B[Numctep][6];
		  NMAX=NQ+NDMAX+NQG+NDG;
		  NMIN=NQ+NDMIN+NQG;
		  NGMAX=0;
		  NGMIN=0;
	  }
	  else if(CBCtep.GetCurSel()==1)
	  {
		  NQ=H[Numctep][1];
		  NDMAX=H[Numctep][2];
		  NDMIN=0;
		  NQG=H[Numctep][5];
		  NDG=H[Numctep][6];
		  NMAX=NQ+NDMAX+NQG;
		  NMIN=NQ+NDMIN+NQG;
		  NGMAX=0;
		  NGMIN=0;
	  }
	  else if(CBCtep.GetCurSel()==2)
	  {
		  NQ=PP[Numctep][1];
		  NDMAX=PP[Numctep][2];
		  NDMIN=PP[Numctep][3];
		  NQG=PP[Numctep][5];
		  NDG=PP[Numctep][6];
		  NMAX=NQ+NDMAX;
		  NMIN=NQ+NDMIN;
		  NGMAX=NQG+NDG;
		  NGMIN=-NQG-NDG;
	  }
	  else if(CBCtep.GetCurSel()==3)
	  {
		  NQ=C[Numctep][1];
		  NDMAX=C[Numctep][2];
		  NDMIN=C[Numctep][3];
		  NQG=C[Numctep][5];
		  NDG=C[Numctep][6];
		  NMAX=NQ+NDMAX;
		  NMIN=NQ;
		  NGMAX=NQG+NDG;
		  NGMIN=-NQG-NDG;
	  }
 	UpdateData(FALSE);
	}
}
void Forces::OnShow() 
{
	Calculate();
}
