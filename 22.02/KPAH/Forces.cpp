#include "stdafx.h"
#include <math.h>
#include "KPAH.h"
#include "Forces.h"
#include "MainFrm.h"
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
#endif
/////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(Forces, CFormView)
Forces::Forces()
	: CFormView(Forces::IDD)
{
	//{{AFX_DATA_INIT(Forces)
	NBDG = 0.0;
	NBDMAX = 0.0;
	NBQ = 0.0;
	NBQG = 0.0;
	NC1DG = 0.0;
	NC1DMAX = 0.0;
	NC1Q = 0.0;
	NC1QG = 0.0;
	NC2DG = 0.0;
	NC2DMAX = 0.0;
	NC2Q = 0.0;
	NC2QG = 0.0;
	NHDG = 0.0;
	NHDMAX = 0.0;
	NHQ = 0.0;
	NHQG = 0.0;
	NPDG = 0.0;
	NPDMAX = 0.0;
	NPDMIN = 0.0;
	NPQ = 0.0;
	NPQG = 0.0;
	m_colorEditBK = RGB(255,255,255);
	m_pEditBkBrush = new CBrush(RGB(255,255,255));
	//}}AFX_DATA_INIT
}
Forces::~Forces()
{
}
void Forces::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Forces)
	DDX_Text(pDX, IDC_NBDG, NBDG);
	DDX_Text(pDX, IDC_NBDMAX, NBDMAX);
	DDX_Text(pDX, IDC_NBQ, NBQ);
	DDX_Text(pDX, IDC_NBQG, NBQG);
	DDX_Text(pDX, IDC_NC1DG, NC1DG);
	DDX_Text(pDX, IDC_NC1DMAX, NC1DMAX);
	DDX_Text(pDX, IDC_NC1Q, NC1Q);
	DDX_Text(pDX, IDC_NC1QG, NC1QG);
	DDX_Text(pDX, IDC_NC2DG, NC2DG);
	DDX_Text(pDX, IDC_NC2DMAX, NC2DMAX);
	DDX_Text(pDX, IDC_NC2Q, NC2Q);
	DDX_Text(pDX, IDC_NC2QG, NC2QG);
	DDX_Text(pDX, IDC_NHDG, NHDG);
	DDX_Text(pDX, IDC_NHDMAX, NHDMAX);
	DDX_Text(pDX, IDC_NHQ, NHQ);
	DDX_Text(pDX, IDC_NHQG, NHQG);
	DDX_Text(pDX, IDC_NPDG, NPDG);
	DDX_Text(pDX, IDC_NPDMAX, NPDMAX);
	DDX_Text(pDX, IDC_NPDMIN, NPDMIN);
	DDX_Text(pDX, IDC_NPQ, NPQ);
	DDX_Text(pDX, IDC_NPQG, NPQG);
	//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(Forces, CFormView)
//{{AFX_MSG_MAP(Forces)
	ON_BN_CLICKED(IDC_SHOW, OnShow)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_RESULT, OnResult)
	ON_WM_DESTROY()
	ON_WM_CTLCOLOR()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
void Forces::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
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
	int r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,r17,r18,r19,r20,r21;
    double l[]= {22., 31., 19., 27., 33., 21., 28., 16., 25., 13.};
    double l2[] ={1.5, 1.8, 1.4, 1.7, 1.3, 1.6, 1.2};
    double p[]= {200.,400.,150.,350.,125.,300.,100.,250.,450.};
 	UpdateData();
 	int num =atoi(Numstu);
 	int i = num/1000000;
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

	if (fabs((NBQ+0.000001)/(B[nb][1]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NBQ))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NBQ))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NBQ))->UpdateWindow();
		r1=1;
	}
	else if (fabs((NBQ+0.000001)/(B[nb][1]+0.000001)-1)>0.03&&fabs((NBQ+0.000001)/(B[nb][1]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NBQ))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NBQ))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NBQ))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NBQ))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NBQ))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NBQ))->UpdateWindow();
	}
	if (fabs((NBDMAX+0.000001)/(B[nb][2]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NBDMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NBDMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NBDMAX))->UpdateWindow();
		r2=1;
	}
	else if (fabs((NBDMAX+0.000001)/(B[nb][2]+0.000001)-1)>0.03&&fabs((NBDMAX+0.000001)/(B[nb][2]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NBDMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NBDMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NBDMAX))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NBDMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NBDMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NBDMAX))->UpdateWindow();
	}
	if (fabs((NHQ+0.000001)/(H[nh][1]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NHQ))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NHQ))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NHQ))->UpdateWindow();
		r3=1;
	}
	else if (fabs((NHQ+0.000001)/(H[nh][1]+0.000001)-1)>0.03&&fabs((NHQ+0.000001)/(H[nh][1]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NHQ))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NHQ))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NHQ))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NHQ))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NHQ))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NHQ))->UpdateWindow();
	}
	if (fabs((NHDMAX+0.000001)/(H[nh][2]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NHDMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NHDMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NHDMAX))->UpdateWindow();
		r4=1;
	}
	else if (fabs((NHDMAX+0.000001)/(H[nh][2]+0.000001)-1)>0.03&&fabs((NHDMAX+0.000001)/(H[nh][2]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NHDMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NHDMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NHDMAX))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NHDMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NHDMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NHDMAX))->UpdateWindow();
	}
	if (fabs((NPQ+0.000001)/(PP[nb][1]+0.000001)-1)<=0.1)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NPQ))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPQ))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPQ))->UpdateWindow();
		r5=1;
	}
	else if (fabs((NPQ+0.000001)/(PP[nb][1]+0.000001)-1)>0.1&&fabs((NPQ+0.000001)/(PP[nb][1]+0.000001)-1)<=0.5)
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NPQ))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPQ))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPQ))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NPQ))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPQ))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPQ))->UpdateWindow();
	}
	if (fabs((NPDMAX+0.000001)/(PP[nb][2]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NPDMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPDMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPDMAX))->UpdateWindow();
		r6=1;
	}
	else if (fabs((NPDMAX+0.000001)/(PP[nb][2]+0.000001)-1)>0.03&&fabs((NPDMAX+0.000001)/(PP[nb][2]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NPDMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPDMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPDMAX))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NPDMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPDMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPDMAX))->UpdateWindow();
	}
	if (fabs((NPDMIN+0.000001)/(PP[nb][3]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NPDMIN))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPDMIN))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPDMIN))->UpdateWindow();
		r7=1;
	}
	else if (fabs((NPDMIN+0.000001)/(PP[nb][3]+0.000001)-1)>0.03&&fabs((NPDMIN+0.000001)/(PP[nb][3]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NPDMIN))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPDMIN))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPDMIN))->UpdateWindow();		
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NPDMIN))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPDMIN))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPDMIN))->UpdateWindow();
	}
	if (fabs((NC1Q+0.000001)/(C[1][1]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,0,255);
		((CEdit *)GetDlgItem(IDC_NC1Q))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC1Q))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC1Q))->UpdateWindow();
		r8=1;
	}
	else if (fabs((NC1Q+0.000001)/(C[1][1]+0.000001)-1)>0.03&&fabs((NC1Q+0.000001)/(C[1][1]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NC1Q))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC1Q))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC1Q))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NC1Q))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC1Q))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC1Q))->UpdateWindow();
	}
	if (fabs((NC1DMAX+0.000001)/(C[1][2]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NC1DMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC1DMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC1DMAX))->UpdateWindow();
		r9=1;
	}
	else if (fabs((NC1DMAX+0.000001)/(C[1][2]+0.000001)-1)>0.03&&fabs((NC1DMAX+0.000001)/(C[1][2]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NC1DMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC1DMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC1DMAX))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NC1DMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC1DMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC1DMAX))->UpdateWindow();
	}
	if (fabs((NC2Q+0.000001)/(C[2][1]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NC2Q))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC2Q))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC2Q))->UpdateWindow();
		r10=1;
	}
	else if (fabs((NC2Q+0.000001)/(C[2][1]+0.000001)-1)>0.03&&fabs((NC2Q+0.000001)/(C[2][1]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NC2Q))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC2Q))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC2Q))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NC2Q))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC2Q))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC2Q))->UpdateWindow();
	}
	if (fabs((NC2DMAX+0.000001)/(C[2][2]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NC2DMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC2DMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC2DMAX))->UpdateWindow();
		r11=1;
	}
	else if (fabs((NC2DMAX+0.000001)/(C[2][2]+0.000001)-1)>0.03&&fabs((NC2DMAX+0.000001)/(C[2][2]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NC2DMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC2DMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC2DMAX))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NC2DMAX))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC2DMAX))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC2DMAX))->UpdateWindow();
	}

	if (fabs((NBQG+0.000001)/(B[nb][5]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NBQG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NBQG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NBQG))->UpdateWindow();
		r12=1;
	}
	else if (fabs((NBQG+0.000001)/(B[nb][5]+0.000001)-1)>0.03&&fabs((NBQG+0.000001)/(B[nb][5]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NBQG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NBQG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NBQG))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NBQG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NBQG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NBQG))->UpdateWindow();
	}
	if (fabs((NBDG+0.000001)/(B[nb][6]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NBDG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NBDG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NBDG))->UpdateWindow();
		r13=1;
	}
	else if (fabs((NBDG+0.000001)/(B[nb][6]+0.000001)-1)>0.03&&fabs((NBDMAX+0.000001)/(B[nb][6]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NBDG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NBDG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NBDG))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NBDG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NBDG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NBDG))->UpdateWindow();
	}
	if (fabs((NHQG+0.000001)/(H[nh][5]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NHQG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NHQG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NHQG))->UpdateWindow();
		r14=1;
	}
	else if (fabs((NHQG+0.000001)/(H[nh][5]+0.000001)-1)>0.03&&fabs((NHQG+0.000001)/(H[nh][5]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NHQG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NHQG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NHQG))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NHQG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NHQG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NHQG))->UpdateWindow();
	}
	if (fabs((NHDG+0.000001)/(H[nh][6]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NHDG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NHDG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NHDG))->UpdateWindow();
		r15=1;
	}
	else if (fabs((NHDG+0.000001)/(H[nh][6]+0.000001)-1)>0.03&&fabs((NHDG+0.000001)/(H[nh][6]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NHDG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NHDG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NHDG))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NHDG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NHDG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NHDG))->UpdateWindow();
	}
	if (fabs((NPQG+0.000001)/(PP[nb][5]+0.000001)-1)<=0.1)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NPQG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPQG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPQG))->UpdateWindow();
		r16=1;
	}
	else if (fabs((NPQG+0.000001)/(PP[nb][5]+0.000001)-1)>0.1&&fabs((NPQG+0.000001)/(PP[nb][5]+0.000001)-1)<=0.5)
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NPQG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPQG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPQG))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NPQG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPQG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPQG))->UpdateWindow();
	}
	if (fabs((NPDG+0.000001)/(PP[nb][6]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NPDG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPDG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPDG))->UpdateWindow();
		r17=1;
	}
	else if (fabs((NPDG+0.000001)/(PP[nb][6]+0.000001)-1)>0.03&&fabs((NPDG+0.000001)/(PP[nb][6]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NPDG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPDG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPDG))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NPDG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NPDG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NPDG))->UpdateWindow();
	}

	if (fabs((NC1QG+0.000001)/(C[1][5]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,0,255);
		((CEdit *)GetDlgItem(IDC_NC1QG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC1QG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC1QG))->UpdateWindow();
		r18=1;
	}
	else if (fabs((NC1QG+0.000001)/(C[1][5]+0.000001)-1)>0.03&&fabs((NC1QG+0.000001)/(C[1][5]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NC1QG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC1QG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC1QG))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NC1Q))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC1Q))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC1Q))->UpdateWindow();
	}
	if (fabs((NC1DG+0.000001)/(C[1][6]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NC1DG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC1DG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC1DG))->UpdateWindow();
		r19=1;
	}
	else if (fabs((NC1DG+0.000001)/(C[1][6]+0.000001)-1)>0.03&&fabs((NC1DG+0.000001)/(C[1][6]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NC1DG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC1DG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC1DG))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NC1DG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC1DG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC1DG))->UpdateWindow();
	}
	if (fabs((NC2QG+0.000001)/(C[2][5]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NC2QG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC2QG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC2QG))->UpdateWindow();
		r20=1;
	}
	else if (fabs((NC2QG+0.000001)/(C[2][5]+0.000001)-1)>0.03&&fabs((NC2QG+0.000001)/(C[2][5]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NC2QG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC2QG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC2QG))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NC2QG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC2QG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC2QG))->UpdateWindow();
	}
	if (fabs((NC2DG+0.000001)/(C[2][6]+0.000001)-1)<=0.03)
	{
		m_colorEditBK = RGB(0,255,0);
		((CEdit *)GetDlgItem(IDC_NC2DG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC2DG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC2DG))->UpdateWindow();
		r21=1;
	}
	else if (fabs((NC2DG+0.000001)/(C[2][6]+0.000001)-1)>0.03&&fabs((NC2DG+0.000001)/(C[2][6]+0.000001)-1)<=0.2)
	{
		m_colorEditBK = RGB(255,255,0);
		((CEdit *)GetDlgItem(IDC_NC2DG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC2DG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC2DG))->UpdateWindow();
	}
	else
	{
		m_colorEditBK = RGB(255,0,0);
		((CEdit *)GetDlgItem(IDC_NC2DG))->SetRedraw(TRUE);
		((CEdit *)GetDlgItem(IDC_NC2DG))->Invalidate();
		((CEdit *)GetDlgItem(IDC_NC2DG))->UpdateWindow();
	} 
	if(r1&&r2&&r3&&r4&&r5&&r6&&r7&&r8&&r9&&r10&&r11&&r12&&r13&&r14&&r15&&r16&&r17&&r18&&r19&&r20&&r21)
	{
		GetDlgItem(IDC_RESULT)->EnableWindow(TRUE);
	}
 	UpdateData(FALSE);
	}
}
void Forces::OnShow() 
{
	Calculate();
}

void Forces::OnNext() 
{
}

void Forces::OnResult() 
{
}

void Forces::OnDestroy() 
{
	CFormView::OnDestroy();
	
	delete m_pEditBkBrush;
}

HBRUSH Forces::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	switch (nCtlColor) {
  
 case CTLCOLOR_EDIT:
 case CTLCOLOR_MSGBOX:
  // Set color to green on black and return the background brush.
  pDC->SetBkColor(m_colorEditBK);
  return (HBRUSH)(m_pEditBkBrush->GetSafeHandle());
  
 default:
  
	// TODO: Return a different brush if the default is not desired
	return hbr;
	}
}


