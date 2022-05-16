#include "stdafx.h"
#include <math.h>
#include "KOHC.h"
#include "KOHCDoc.h"
#include "Sections.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
void Sections::AssertValid() const
{
	CFormView::AssertValid();
}

void Sections::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
KOHCDoc* Sections::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(KOHCDoc)));
	return (KOHCDoc*)m_pDocument;
}
#endif
/////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(Sections, CFormView)
Sections::Sections()
	: CFormView(Sections::IDD)
{
//{{AFX_DATA_INIT(Sections)
	bap1 = 0.0;
	bap2 = 0.0;
	bap3 = 0.0;
	bap4 = 0.0;
	bap5 = 0.0;
	bap6 = 0.0;
	bap7 = 0.0;
	bap8 = 0.0;
	Numctep = 0;
	Numstu = 0;
	Student = _T("");
//}}AFX_DATA_INIT
}
Sections::~Sections()
{
}
void Sections::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
//{{AFX_DATA_MAP(Sections)
	DDX_Control(pDX, IDC_SPIN2, NUMSTU);
	DDX_Control(pDX, IDC_SPIN1, NUMCTEP);
	DDX_Control(pDX, IDC_STUDENTS, CBStudent);
	DDX_Control(pDX, IDC_TYPEPLAF, CBType);
	DDX_Control(pDX, IDC_Ry, CBRy);
	DDX_Control(pDX, IDC_Rv, CBRv);
	DDX_Control(pDX, IDC_CTEP, CBCtep);
	DDX_Text(pDX, IDC_EDIT1, bap1);
	DDX_Text(pDX, IDC_EDIT2, bap2);
	DDX_Text(pDX, IDC_EDIT3, bap3);
	DDX_Text(pDX, IDC_EDIT4, bap4);
	DDX_Text(pDX, IDC_EDIT5, bap5);
	DDX_Text(pDX, IDC_EDIT6, bap6);
	DDX_Text(pDX, IDC_EDIT7, bap7);
	DDX_Text(pDX, IDC_EDIT8, bap8);
	DDX_Text(pDX, IDC_NUMCTEP, Numctep);
	DDX_Text(pDX, IDC_NUMSTU, Numstu);
	DDX_CBString(pDX, IDC_STUDENTS, Student);
//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(Sections, CFormView)
//{{AFX_MSG_MAP(Sections)
	ON_CBN_SELCHANGE(IDC_CTEP, OnSelchangeCtep)
	ON_CBN_SELCHANGE(IDC_TYPEPLAF, OnSelchangeTypeplaf)
	ON_BN_CLICKED(IDC_CHECK, OnCheck)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
void Sections::OnInitialUpdate() 
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
	CBType.SetCurSel(0);
	CBRv.SetCurSel(0);
	CBRy.SetCurSel(0);
	GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
}
void Sections::OnSelchangeCtep() 
{
	if (CBCtep.GetCurSel()==1)
	{
		CBType.ResetContent();
		CBType.InsertString(0,"T");
		CBType.SetCurSel(0);
		GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT2)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT3)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT4)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT5)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC4)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC5)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC6)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->SetWindowText("A");
	}
	else if (CBCtep.GetCurSel()==2)
	{
		CBType.ResetContent();
		CBType.InsertString(0,"DYHP");
		CBType.InsertString(1,"DYP");
		CBType.InsertString(2,"DS");
		CBType.InsertString(3,"t");
		CBType.SetCurSel(0);
		GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT2)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT3)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT4)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT5)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC4)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC5)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC6)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->SetWindowText("A");
		GetDlgItem(IDC_STATIC2)->SetWindowText("JX");
		GetDlgItem(IDC_STATIC3)->SetWindowText("JY");
		GetDlgItem(IDC_STATIC4)->SetWindowText("X0");
		GetDlgItem(IDC_STATIC5)->SetWindowText("XZ");
	}
	else if (CBCtep.GetCurSel()==3)
	{
		
		CBType.ResetContent();
		CBType.InsertString(0,"DYHP");
		CBType.InsertString(1,"DYP");
		CBType.InsertString(2,"DS");
		CBType.InsertString(3,"t");
		CBType.SetCurSel(0);
		GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT2)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT3)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT4)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT5)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC4)->ShowWindow(TRUE);	
		GetDlgItem(IDC_STATIC5)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC6)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->SetWindowText("A");
		GetDlgItem(IDC_STATIC2)->SetWindowText("JX");
		GetDlgItem(IDC_STATIC3)->SetWindowText("JY");
		GetDlgItem(IDC_STATIC4)->SetWindowText("X0");
		GetDlgItem(IDC_STATIC5)->SetWindowText("XZ");
	}
	else if(CBCtep.GetCurSel()==0)
	{
		CBType.ResetContent();
		CBType.InsertString(0,"DT");
		CBType.InsertString(1,"T");
		CBType.SetCurSel(0);
		GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT2)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT3)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT4)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT5)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT6)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT7)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC4)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC5)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC6)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC7)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->SetWindowText("A");
		GetDlgItem(IDC_STATIC2)->SetWindowText("JX");
		GetDlgItem(IDC_STATIC3)->SetWindowText("JY");
		GetDlgItem(IDC_STATIC4)->SetWindowText("S");
		GetDlgItem(IDC_STATIC5)->SetWindowText("B");
		GetDlgItem(IDC_STATIC6)->SetWindowText("H");
		GetDlgItem(IDC_STATIC7)->SetWindowText("T");
	}
}

void Sections::OnSelchangeTypeplaf() 
{
	if (CBCtep.GetCurSel()==0)
	{
		if (CBType.GetCurSel()==0)
		{
			GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT2)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT3)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT4)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT5)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT6)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT7)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC3)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC4)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC5)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC6)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC7)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
		    GetDlgItem(IDC_STATIC1)->SetWindowText("A");
		    GetDlgItem(IDC_STATIC2)->SetWindowText("JX");
		    GetDlgItem(IDC_STATIC3)->SetWindowText("JY");
		    GetDlgItem(IDC_STATIC4)->SetWindowText("S");
		    GetDlgItem(IDC_STATIC5)->SetWindowText("B");
			GetDlgItem(IDC_STATIC6)->SetWindowText("H");
			GetDlgItem(IDC_STATIC7)->SetWindowText("T");
		}
		else if (CBType.GetCurSel()==1)
		{
			GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT2)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT3)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT4)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT5)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT6)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT7)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT8)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC3)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC4)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC5)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC6)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC7)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC8)->ShowWindow(TRUE);
		    GetDlgItem(IDC_STATIC1)->SetWindowText("A");
		    GetDlgItem(IDC_STATIC2)->SetWindowText("JX");;
		    GetDlgItem(IDC_STATIC3)->SetWindowText("JY");
		    GetDlgItem(IDC_STATIC4)->SetWindowText("H");
		    GetDlgItem(IDC_STATIC5)->SetWindowText("B");
			GetDlgItem(IDC_STATIC6)->SetWindowText("S");
			GetDlgItem(IDC_STATIC7)->SetWindowText("T");
			GetDlgItem(IDC_STATIC8)->SetWindowText("X0");
		}
	}
	else if (CBCtep.GetCurSel()==1)
	{
		GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT2)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT3)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT4)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT5)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC4)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC5)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC6)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->SetWindowText("A");
	}
	else if (CBCtep.GetCurSel()==2||CBCtep.GetCurSel()==3)
	{
		if (CBType.GetCurSel()==0)
		{
			GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT2)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT3)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT4)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT5)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC3)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC4)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC5)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC6)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC1)->SetWindowText("A");
			GetDlgItem(IDC_STATIC2)->SetWindowText("JX");
			GetDlgItem(IDC_STATIC3)->SetWindowText("JY");
			GetDlgItem(IDC_STATIC4)->SetWindowText("X0");
			GetDlgItem(IDC_STATIC5)->SetWindowText("XZ");
			
		}
		else if (CBType.GetCurSel()==1)
		{
			GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT2)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT3)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT4)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT5)->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC3)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC4)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC5)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC6)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC1)->SetWindowText("A");
			GetDlgItem(IDC_STATIC2)->SetWindowText("JX");
			GetDlgItem(IDC_STATIC3)->SetWindowText("X0");
			GetDlgItem(IDC_STATIC4)->SetWindowText("XZ");
		}
		else if (CBType.GetCurSel()==2)
		{
			GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT2)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT3)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT4)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT5)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC3)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC4)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC5)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC6)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC1)->SetWindowText("A");
			GetDlgItem(IDC_STATIC2)->SetWindowText("JX");
			GetDlgItem(IDC_STATIC3)->SetWindowText("JY");
			GetDlgItem(IDC_STATIC4)->SetWindowText("X0");
			GetDlgItem(IDC_STATIC5)->SetWindowText("XZ");
		}
		else if (CBType.GetCurSel()==3)
		{
			GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT2)->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT3)->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT4)->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT5)->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC3)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC4)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC5)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC6)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC1)->SetWindowText("D");
			GetDlgItem(IDC_STATIC2)->SetWindowText("S");

		}
	}
}
void Sections::OnCheck() 
{
	int iB,jB;
	//UpdateData(TRUE);
	Calculate();
	int Rv,Ry;
	if (CBRv.GetCurSel()==0)
	{
		Rv=36;	
	}
	else if (CBRv.GetCurSel()==1)
	{
		Rv=75;
	}
	else if (CBRv.GetCurSel()==2)
	{
		Rv=90;
	}
	if (CBRy.GetCurSel()==0)
	{
		Ry=250;	
	}
	else if (CBRy.GetCurSel()==1)
	{
		Ry=350;
	}
	else if (CBRy.GetCurSel()==2)
	{
		Ry=450;
	}

	double rH,rvH,sigmavH,sigmaH,AH1,RyH,RvH,AH;
	CString ss;
	double rP1,rvP1,sigmavP1,sigmaP1,AP1,AP3,AP4,JxP1,JyP1,
		   JP,JP1,iP,iP1,lP1,lP2,lambdaP,lambdaP1,lambdaPw,lambdaP_,fiP
		 ,RyP,RvP,JxP,JyP,sP,AP,DP,x0P,xzP;
	 int n1;
	double yAB,xAB,yBB,xBB,MxB,MyB,sigmaAB,sigmaBB,rB,rvB,sigma1B,sigmavB,sigmaB,ixB,iyB,WxB,WyB,mxB,myB,
		lambdaxB,lambdayB,lambdaxB_,lambdayB_,fixB,fiyB,fiB,lambdaB_,mB,rateB,aitaB,m1B,cB,mefB1,mefB2,
		mefB3,mefB4,fieB,fiexy,RyB,RvB,AB,JxB,JyB,sB,bB,hB,tB,z0B,kz;
	double lambda[21]={0.5,1.0,1.5,2.0,2.5,3.0,3.5,4.0,4.5,5.0,5.5,6.0,6.5,7.0,8.0,9.0,10.0,11.0,12.0,13.0,14.0};
	double fie[13]={0.1,0.25,0.5,0.75,1.0,1.25,1.5,1.75,2.0,2.5,3.0,3.5,4.0};
	double mef[21][13]={0.967,0.922,0.850,0.782,0.722,0.669,0.620,0.577,0.538,0.469,0.417,0.370,0.337,
						0.925,0.854,0.778,0.711,0.653,0.600,0.563,0.520,0.484,0.427,0.382,0.341,0.307,
						0.875,0.804,0.716,0.647,0.593,0.548,0.507,0.470,0.439,0.388,0.347,0.312,0.283,
						0.813,0.742,0.653,0.587,0.536,0.496,0.457,0.425,0.397,0.352,0.315,0.286,0.260,
						0.742,0.672,0.587,0.526,0.480,0.442,0.410,0.383,0.357,0.317,0.287,0.262,0.238,
						0.667,0.597,0.520,0.465,0.425,0.395,0.365,0.342,0.320,0.287,0.260,0.238,0.217,
						0.587,0.522,0.455,0.408,0.375,0.350,0.325,0.303,0.287,0.258,0.233,0.216,0.198,
						0.505,0.447,0.394,0.356,0.330,0.309,0.289,0.270,0.256,0.232,0.212,0.197,0.181,
						0.418,0.382,0.342,0.310,0.288,0.272,0.257,0.242,0.229,0.208,0.192,0.178,0.165,
						0.354,0.326,0.295,0.273,0.253,0.239,0.225,0.215,0.205,0.188,0.175,0.162,0.150,
						0.302,0.280,0.256,0.240,0.224,0.212,0.200,0.192,0.184,0.170,0.158,0.148,0.138,
						0.258,0.244,0.223,0.210,0.198,0.190,0.178,0.172,0.166,0.153,0.145,0.137,0.128,
						0.223,0.213,0.196,0.185,0.176,0.170,0.160,0.155,0.149,0.140,0.132,0.125,0.117,
						0.194,0.186,0.173,0.163,0.157,0.152,0.145,0.141,0.136,0.127,0.121,0.115,0.108,
						0.152,0.146,0.138,0.133,0.128,0.121,0.117,0.115,0.113,0.106,0.100,0.095,0.091,
						0.122,0.117,0.112,0.107,0.103,0.100,0.098,0.096,0.093,0.088,0.085,0.082,0.079,
						0.100,0.097,0.093,0.091,0.090,0.085,0.081,0.080,0.079,0.075,0.072,0.070,0.069,
						0.083,0.079,0.077,0.076,0.075,0.073,0.071,0.069,0.068,0.063,0.062,0.061,0.060,
						0.069,0.067,0.064,0.063,0.062,0.060,0.059,0.059,0.058,0.055,0.054,0.053,0.052,
						0.062,0.061,0.054,0.053,0.052,0.051,0.051,0.050,0.049,0.049,0.048,0.048,0.047,
						0.052,0.049,0.049,0.048,0.048,0.047,0.047,0.046,0.045,0.044,0.043,0.043,0.042};
	double E=200000;
	if (CBCtep.GetCurSel()==1)
	{
		RyH=Ry;
		RvH=Rv;
		AH=bap1;
		rH=NMIN/NMAX;
		if (rH>-1&&rH<0)
		{
			rvH=2.5/(1.5-rH);
		}
		else if (rH>0&&rH<0.8)
		{
			rvH=2/(1.2-rH);
		}
		else if (rH>0.8&&rH<1)
		{
			rvH=1/(1-rH);
		}
		sigmavH=1.1*1.63*rvH*RvH;
		if (sigmavH>RyH)
			sigmaH=RyH;
		else
			sigmaH=sigmavH;
		AH1=fabs(1000*NMAX/sigmaH);
		kz=AH/AH1;
		if (AH>=AH1)
			ss="H right!!!";
		else
			ss="H wrong!!!";
	}
//////////////////////////////////////////////HHHHHHHHHHHHHHHHHHHHHHHHHHHH
	else if (CBCtep.GetCurSel()==2||CBCtep.GetCurSel()==3)
	{
		RvP=Rv;
		RyP=Ry;
		if (CBCtep.GetCurSel()==2)
		{
			lP1=sqrt(L2*L2+W*W);
			rP1=NMIN/NMAX;
			if (NMAX>0)
			{
				if (rP1>-1&&rP1<0)
				{
					rvP1=2.5/(1.5-rP1);
				}
				else if (rP1>0&&rP1<0.8)
				{
					rvP1=2/(1.2-rP1);
				}
				else if (rP1>0.8&&rP1<1)
				{
					rvP1=1/(1-rP1);
				}
				
			}
			else if (NMAX<0)
			{
				rvP1=2/(1-rP1);
			}
		}
		if (CBCtep.GetCurSel()==3)
		{
			lP1=W;
			rP1=NMIN/NMAX;
			if (NMAX>0)
			{
				if (rP1>-1&&rP1<0)
				{
					rvP1=2.5/(1.5-rP1);
				}
				else if (rP1>0&&rP1<0.8)
				{
					rvP1=2/(1.2-rP1);
				}
				else if (rP1>0.8&&rP1<1)
				{
					rvP1=1/(1-rP1);
				}
				
			}
			else if (NMAX<0)
			{
				rvP1=2/(1-rP1);
			}
		}
		sigmavP1=1.1*1.63*rvP1*RvP;
		if (sigmavP1>RyP)
			sigmaP1=RyP;
		else
			sigmaP1=sigmavP1;
		AP1=fabs(1000*NMAX/sigmaP1/2);
		
		if (CBType.GetCurSel()==0||CBType.GetCurSel()==2)
		{
			AP=bap1;
			JxP=bap2;
			JyP=bap3;
			x0P=bap4;
			xzP=bap5;
			JxP1=2*JxP;
			JyP1=2*(JyP+AP*(x0P+xzP/2));
			if (JxP1>JyP1)
			{
				JP=JyP1;
				JP1=JyP;
			}
			else
			{
				JP=JxP1;
				JP1=JxP;
			}
			iP=sqrt(JP/(2*AP));
			iP1=sqrt(JP1/AP);
			lambdaPw=lP1/iP;
			n1=int(lP1/40/iP1);
			lP2=lP1/(n1+1);
			lambdaP1=lP2/iP1;
			lambdaP=sqrt(lambdaPw*lambdaPw+lambdaP1*lambdaP1);
			lambdaP_=lambdaP*sqrt(RyP/E);
			if (lambdaP_<=2.5)
			{
				fiP=1-(0.073-5.53*RyP/E)*sqrt(lambdaP_*lambdaP_*lambdaP_);
			}
			else if (lambdaP_>2.5&&lambdaP_<=4.5)
			{
				fiP=1.47-13.0*RyP/E-(0.371-27.3*RyP/E)*lambdaP_+(0.0275-5.53*RyP/E)*(lambdaP_*lambdaP_);
			}
			else
				fiP=332/lambdaP_/lambdaP_/(51-lambdaP_);
			AP3=fabs(1000*NMAX/RyP/fiP/2);
			if (AP>=AP1&&AP>=AP3)
			{
				if(CBCtep.GetCurSel()==2)
					ss="P right!!!";
				else if (CBCtep.GetCurSel()==3)
					ss="C right!!!";
			}
			else
			{
				if(CBCtep.GetCurSel()==2)
					ss="P wrong!!!";
				else if(CBCtep.GetCurSel()==3)
					ss="C wrong!!!";
			}
			if (AP1>=AP3)
			{
				kz=AP/AP1;
			}
			else
				kz=AP/AP3;


		}
		else if (CBType.GetCurSel()==1)
		{
			RvP=Rv;
			RyP=Ry;
			AP=bap1;
			JxP=bap2;
			JyP=bap2;
			x0P=bap3;
			xzP=bap4;
			JxP1=2*JxP;
			JyP1=2*(JyP+AP*(x0P+xzP/2));
			if (JxP1>JyP1)
			{
				JP=JyP1;
				JP1=JyP;
			}
			else
			{
				JP=JxP1;
				JP1=JxP;
			}
			iP=sqrt(JP/(2*AP));
			iP1=sqrt(JP1/AP);
			lambdaPw=lP1/iP;
			n1=int(lP1/40/iP1);
			lP2=lP1/(n1+1);
			lambdaP1=lP2/iP1;
			lambdaP=sqrt(lambdaPw*lambdaPw+lambdaP1*lambdaP1);
			lambdaP_=lambdaP*sqrt(RyP/E);
			if (lambdaP_<=2.5)
			{
				fiP=1-(0.073-5.53*RyP/E)*sqrt(lambdaP_*lambdaP_*lambdaP_);
			}
			else if (lambdaP_>2.5&&lambdaP_<=4.5)
			{
				fiP=1.47-13.0*RyP/E-(0.371-27.3*RyP/E)*lambdaP_+(0.0275-5.53*RyP/E)*(lambdaP_*lambdaP_);
			}
			else
				fiP=332/lambdaP_/lambdaP_/(51-lambdaP_);
			AP3=fabs(1000*NMAX/RyP/fiP/2);
			if (AP>=AP1&&AP>=AP3)
			{
				if(CBCtep.GetCurSel()==2)
					ss="P right\r\n";
				else if(CBCtep.GetCurSel()==3)
					ss="C right\r\n";
			}
			else
			{
				if(CBCtep.GetCurSel()==2)
					ss="P wrong\r\n";
				else if(CBCtep.GetCurSel()==3)
					ss="C wrong\r\n";
			}
			if (AP1>=AP3)
			{
				kz=AP/AP1;
			}
			else
				kz=AP/AP3;

		}
		else if (CBType.GetCurSel()==3)
		{
			RvP=Rv;
			RyP=Ry;
			DP=bap1;
			sP=bap2;
			AP4=3.14*(DP*DP+(DP-2*sP)*(DP-2*sP))/4;
			JyP=3.14*(DP*DP*DP*DP+(DP-2*sP)*(DP-2*sP)*(DP-2*sP)*(DP-2*sP))/64;
			iP=sqrt(JyP/AP4);
			lambdaP=lP1/iP;
			lambdaP_=lambdaP*sqrt(RyP/E);
			if (lambdaP_<=2.5)
			{
				fiP=1-(0.073-5.53*RyP/E)*sqrt(lambdaP_*lambdaP_*lambdaP_);
			}
			else if (lambdaP_>2.5&&lambdaP_<=4.5)
			{
				fiP=1.47-13.0*RyP/E-(0.371-27.3*RyP/E)*lambdaP_+(0.0275-5.53*RyP/E)*(lambdaP_*lambdaP_);
			}
			else
				fiP=332/lambdaP_/lambdaP_/(51-lambdaP_);
			AP3=fabs(1000*NDMAX/RyP/fiP);
			if (AP4>=2*AP1&&AP4>=AP3)
			{
				if(CBCtep.GetCurSel()==2)
					ss="P right\r\n";
				else if(CBCtep.GetCurSel()==3)
					ss="C right\r\n";
			}
			else
			{
				if(CBCtep.GetCurSel()==2)
					ss="P wrong\r\n";
				else if(CBCtep.GetCurSel()==3)
					ss="C wrong\r\n";
			}
			if (2*AP1>=AP3)
			{
				kz=AP4/AP1/2;
			}
			else
				kz=AP4/AP3;
		}
	}
	/////////////////////////////////////////////////////////////////////////////PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
///////////////////////////////////////////////////////////////CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
	if (CBCtep.GetCurSel()==0)
	{
		if (CBType.GetCurSel()==0)
		{
			RvB=Rv;
			RyB=Ry;
			AB=bap1;
			JxB=bap2;
			JyB=bap3;
			sB=bap4;
			bB=bap5;
			hB=bap6;
			tB=bap7;
			yAB=-hB/2;
			xAB=-bB/2;
			yBB=hB/2;
			xBB=bB/2;
			MxB=1000000*D*L2/6;
			MyB=1000000*DG*L2/6;
			sigmaAB=fabs(MxB/JxB*yAB+MyB/JyB*xAB+1000*NMAX/AB);
			sigmaBB=fabs(MxB/JxB*yBB+MyB/JyB*xBB+1000*NMAX/AB);
			sigma1B=fabs(1000*NMAX/AB);
			rB=NMIN/NMAX;
			rvB=2/(1-rB);
			sigmavB=1.1*1.63*rvB*RvB;
			if (sigmavB>RyB)
			{
				sigmaB=RyB;
			}
			else
			{
				sigmaB=sigmavB;
			}
			ixB=sqrt(JxB/AB);
			iyB=sqrt(JyB/AB);
			WxB=2*JxB/hB;
			WyB=2*JyB/bB;
			mxB=fabs(MxB*AB/WxB/NMAX/1000);
			myB=fabs(MyB*AB/WyB/NMAX/1000);
			lambdaxB=1000*L2/ixB;
			lambdayB=1000*L2/iyB;
			lambdaxB_=lambdaxB*sqrt(RyB/E);
			lambdayB_=lambdayB*sqrt(RyB/E);
			if (lambdaxB_<=2.5)
			{
				fixB=1-(0.073-5.53*RyB/E)*sqrt(lambdaxB_*lambdaxB_*lambdaxB_);
			}
			else if (lambdaxB_>2.5&&lambdaxB_<=4.5)
			{
				fixB=1.47-13.0*RyB/E-(0.371-27.3*RyB/E)*lambdaxB_+(0.0275-5.53*RyB/E)*(lambdaxB_*lambdaxB_);
			}
			else
			{
				fixB=332/lambdaxB_/lambdaxB_/(51-lambdaxB_);
			}
			if (lambdayB_<=2.5)
			{
				fiyB=1-(0.073-5.53*RyB/E)*sqrt(lambdayB_*lambdayB_*lambdayB_);
			}
			else if (lambdayB_>2.5&&lambdayB_<=4.5)
			{
				fiyB=1.47-13.0*RyB/E-(0.371-27.3*RyB/E)*lambdayB_+(0.0275-5.53*RyB/E)*(lambdayB_*lambdayB_);
			}
			else
			{
				fiyB=332/lambdayB_/lambdayB_/(51-lambdayB_);
			}
			if (mxB>=myB)
			{
				fiB=fixB;
			}
			else
			{
				fiB=fiyB;
			}
			if (lambdaxB_>=lambdayB_)
			{
				lambdaB_=lambdaxB_;
				mB=mxB;
				m1B=myB;
			}
			else
			{
				lambdaB_=lambdayB_;
				mB=myB;
				m1B=mxB;
			}
			rateB=bB*tB/sB/(hB-2*tB);
			if (lambdaB_>=0&&lambdaB_<=5)
			{
				if (mB>=0.1&&mB<=5)
				{
					if (rateB>=0&&rateB<=0.4)
					{
						aitaB=1.45-0.05*mB-0.01*(5-mB)*lambdaB_;
					}
					else if (rateB>0.4&&rateB<1)
					{
						aitaB=1.75-0.1*mB-0.02*(5-mB)*lambdaB_;
					}
					else
					{
						aitaB=1.9-0.1*mB-0.02*(6-mB)*lambdaB_;
					}
				}
				else
				{
					if (rateB>=0&&rateB<=0.4)
					{
						aitaB=1.2;
					}
					else if (rateB>0.4&&rateB<1)
					{
						aitaB=1.25;
					}
					else
					{
						aitaB=1.4-0.02*lambdaB_;
					}
				}
				

			}
			else
			{
				if (rateB>=0&&rateB<=0.4)
				{
					aitaB=1.2;
				}
				else if (rateB>0.4&&rateB<1)
				{
					aitaB=1.25;
				}
				else
				{
					aitaB=1.3;
				}
			}
			for (iB=0;iB<21;iB++)
			{
				if (lambdaB_<lambda[iB])
				{
					iB=iB-1;
					break;
				}

			}
			for (jB=0;jB<13;jB++)
			{
				if ((aitaB*mB)<fie[jB])
				{
					jB=jB-1;
					break;
				}
			}
			mefB1=mef[iB][jB];
			mefB2=mef[iB][jB+1];
			mefB3=mef[iB+1][jB];
			mefB4=mef[iB+1][jB+1];
			fieB=mefB1-(mefB1-mefB3)*(lambdaB_-lambda[iB])/(lambda[iB+1]-lambda[iB])
				-((mefB1-(mefB1-mefB3)*(lambdaB_-lambda[iB])/(lambda[iB+1]-
				lambda[iB]))-(mefB2-(mefB2-mefB4)*(lambdaB_-lambda[iB])/
				(lambda[iB+1]-lambda[iB])))*(aitaB*mB-fie[jB])/(fie[jB+1]-fie[jB]);
			cB=1/(1+0.6*m1B);
			fiexy=fieB*(0.6*pow(cB,1.0/3)+0.4*pow(cB,1.0/4));
			if (sigmaAB<sigmaB&&sigmaBB<sigmaB&&sigma1B<(RyB*fiB)&&sigma1B<(RyB*fiexy))
			{
				ss="B right\r\n";
			}
			else
			{
				ss="B wrong\r\n";
			}	
		
	}////////////////////////////////////////////////////////////////////////////////gongxing
		else if (CBType.GetCurSel()==1)
		{
			RvB=Rv;
			RyB=Ry;
			AB=bap1;
			JxB=bap2;
			JyB=bap3;
			sB=bap4;
			bB=bap5;
			hB=bap6;
			tB=bap7;
			z0B=bap8;
			yAB=(z0B-hB)/2;
			xAB=-sB/2;
			yBB=z0B;
			xBB=bB/2;
			MxB=1000000*D*L2/6;
			MyB=1000000*DG*L2/6;
			sigmaAB=fabs(MxB/JxB*yAB+MyB/JyB*xAB+1000*NMAX/AB);
			sigmaBB=fabs(MxB/JxB*yBB+MyB/JyB*xBB+1000*NMAX/AB);
			sigma1B=fabs(1000*NMAX/AB);
			rB=NMIN/NMAX;
			rvB=2/(1-rB);
			sigmavB=1.1*1.63*rvB*RvB;
			if (sigmavB>RyB)
			{
				sigmaB=RyB;
			}
			else
			{
				sigmaB=sigmavB;
			}
			ixB=sqrt(JxB/AB);
			iyB=sqrt(JyB/AB);
			WxB=JxB/(hB-z0B);
			WyB=2*JyB/bB;
			mxB=fabs(MxB*AB/WxB/NMAX/1000);
			myB=fabs(MyB*AB/WyB/NMAX/1000);
			lambdaxB=1000*L2/ixB;
			lambdayB=1000*L2/iyB;
			lambdaxB_=lambdaxB*sqrt(RyB/E);
			lambdayB_=lambdayB*sqrt(RyB/E);
			if (lambdaxB_<=2.5)
		{
			fixB=1-(0.073-5.53*RyB/E)*sqrt(lambdaxB_*lambdaxB_*lambdaxB_);
		}
		else if (lambdaxB_>2.5&&lambdaxB_<=4.5)
		{
			fixB=1.47-13.0*RyB/E-(0.371-27.3*RyB/E)*lambdaxB_+(0.0275-5.53*RyB/E)*(lambdaxB_*lambdaxB_);
		}
		else
		{
			fixB=332/lambdaxB_/lambdaxB_/(51-lambdaxB_);
		}
		if (lambdayB_<=2.5)
		{
			fiyB=1-(0.073-5.53*RyB/E)*sqrt(lambdayB_*lambdayB_*lambdayB_);
		}
		else if (lambdayB_>2.5&&lambdayB_<=4.5)
		{
			fiyB=1.47-13.0*RyB/E-(0.371-27.3*RyB/E)*lambdayB_+(0.0275-5.53*RyB/E)*(lambdayB_*lambdayB_);
		}
		else
		{
			fiyB=332/lambdayB_/lambdayB_/(51-lambdayB_);
		}
		if (mxB>=myB)
		{
			fiB=fixB;
		}
		else
		{
			fiB=fiyB;
		}
		if (lambdaxB_>=lambdayB_)
		{
			lambdaB_=lambdaxB_;
			mB=mxB;
			m1B=myB;
		}
		else
		{
			lambdaB_=lambdayB_;
			mB=myB;
			m1B=mxB;
		}
		rateB=bB*tB/sB/(hB-tB);
		if (lambdaB_>=0&&lambdaB_<=5)
		{
			if (mB>=0.1&&mB<=5)
			{
				if (rateB>=0&&rateB<=0.6)
				{
					aitaB=1.45+0.04*mB;
				}
				else if (rateB>0.6&&rateB<1.2)
				{
					aitaB=1.8+0.12*mB;
				}
				else if (rateB>1.2&&rateB<1.8)
				{
					aitaB=2+0.25*mB+0.1*lambdaB_;
				}
				else
				{
					aitaB=3+0.25*mB+0.1*lambdaB_;

				}
			}
			else
			{
				if (rateB>=0&&rateB<=0.6)
				{
					aitaB=1.65;
				}
				else if (rateB>0.6&&rateB<1.2)
				{
					aitaB=2.4;
				}
				else if (rateB>1.2&&rateB<1.8)
				{
					aitaB=0;
				}
				else
				{
					aitaB=0;

				}
			}
			

		}
		else
		{
			if (rateB>=0&&rateB<=0.6)
				{
					aitaB=1.65;
				}
				else if (rateB>0.6&&rateB<1.2)
				{
					aitaB=2.4;
				}
				else if (rateB>1.2&&rateB<1.8)
				{
					aitaB=0;
				}
				else
				{
					aitaB=0;

				}
		}
		for (iB=0;iB<21;iB++)
		{
			if (lambdaB_<lambda[iB])
			{
				iB=iB-1;
				break;
			}

		}
		for (jB=0;jB<13;jB++)
		{
			if ((aitaB*mB)<fie[jB])
			{
				jB=jB-1;
				break;
			}
		}
		mefB1=mef[iB][jB];
		mefB2=mef[iB][jB+1];
		mefB3=mef[iB+1][jB];
		mefB4=mef[iB+1][jB+1];
		fieB=mefB1-(mefB1-mefB3)*(lambdaB_-lambda[iB])/(lambda[iB+1]-lambda[iB])
			-((mefB1-(mefB1-mefB3)*(lambdaB_-lambda[iB])/(lambda[iB+1]-
			lambda[iB]))-(mefB2-(mefB2-mefB4)*(lambdaB_-lambda[iB])/
			(lambda[iB+1]-lambda[iB])))*(aitaB*mB-fie[jB])/(fie[jB+1]-fie[jB]);
		cB=1/(1+0.6*m1B);
		fiexy=fieB*(0.6*pow(cB,1.0/3)+0.4*pow(cB,1.0/4));
		if (sigmaAB<sigmaB&&sigmaBB<sigmaB&&sigma1B<(RyB*fiB)&&sigma1B<(RyB*fiexy))
		{
			ss="B right\r\n";
		}
		else
		{
			ss="B wrong\r\n";
		}
		
		}
	if (sigmaB<(RyB*fiB)&&sigmaB<(RyB*fiexy))
			{
				if (sigmaAB>sigmaBB&&sigmaAB>sigma1B)
				{
					kz=sigmaB/sigmaAB;
				}
				else if (sigmaBB>sigmaAB&&sigmaBB>sigma1B)
				{
					kz=sigmaB/sigmaBB;
				}
				else if (sigma1B>sigmaAB&&sigma1B>sigmaBB)
				{
					kz=sigmaB/sigma1B;
				}
				
			}
			else if ((RyB*fiB)<sigmaB&&(RyB*fiB)<(RyB*fiexy))
			{
				if (sigmaAB>sigmaBB&&sigmaAB>sigma1B)
				{
					kz=(RyB*fiB)/sigmaAB;
				}
				else if (sigmaBB>sigmaAB&&sigmaBB>sigma1B)
				{
					kz=(RyB*fiB)/sigmaBB;
				}
				else if (sigma1B>sigmaAB&&sigma1B>sigmaBB)
				{
					kz=(RyB*fiB)/sigma1B;
				}
				
			}
			else if ((RyB*fiexy)<sigmaB&&(RyB*fiexy)<(RyB*fiB))
			{
				if (sigmaAB>sigmaBB&&sigmaAB>sigma1B)
				{
					kz=(RyB*fiexy)/sigmaAB;
				}
				else if (sigmaBB>sigmaAB&&sigmaBB>sigma1B)
				{
					kz=(RyB*fiexy)/sigmaBB;
				}
				else if (sigma1B>sigmaAB&&sigma1B>sigmaBB)
				{
					kz=(RyB*fiexy)/sigma1B;
				}
				
			}
	}
	CString kzs;
	kzs.Format("%s KZ = %g",ss,kz); 
	MessageBox(kzs);
 	UpdateData(FALSE);
}

void Sections::Calculate()
{
	UpdateData(TRUE);
	if (Student=="")
	{
		MessageBox("no name");
		return;
	}
	else{
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
	  }

}
