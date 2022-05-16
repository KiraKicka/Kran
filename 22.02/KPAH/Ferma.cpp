#include "stdafx.h"
#include <math.h>
#include "KPAH.h"
#include "Ferma.h"
#include "gl\gl.h"
#include "gl\glu.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(Ferma, CView)
Ferma::Ferma()
{
	m_pDC = NULL;
	m_pOldPalette = NULL;
	L=0;
    L1=0;
    L2=0;
	W1=0;
    W=0;
	WG=0;
	WK=0;
	n=0;
	Xshift=0.0;
	Yshift=0.0;
	Xshiftl=0.0;
	Yshiftl=0.0;
	m_Scale=1.0f;
    Lbutt=false;
	ShiftSta=false;
    mouseX=0;
	mouseY=0;
    wAngleY=0;
    wAngleX=0;
	wAngleZ=0;
	LDOWX=0;
	LDOWY=0;
	scale_factor=0;
	oldMoveX=0;
	oldMoveY=0;
	oldMoveXl=0;
	oldMoveYl=0;
	oldwAngleY=0;
	oldwAngleZ=0;
	zhan=0;
}

Ferma::~Ferma()
{
}

BEGIN_MESSAGE_MAP(Ferma, CView)
//{{AFX_MSG_MAP(Ferma)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
void Ferma::OnDraw(CDC* pDC)
{
	 glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	 Calculate();
	 SetCamera();
	 DrawScene();
}

/////////////////////////////////////////////////////////////////////////////
// Ferma diagnostics

#ifdef _DEBUG
void Ferma::AssertValid() const
{
	CView::AssertValid();
}

void Ferma::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Ferma message handlers

void Ferma::Calculate()
{
	UpdateData(TRUE);
	if (Student=="")
	{
		MessageBox("no name");
		return;
	}
	else
	{
 	UINT let;
    int  n1, n2, n3;
    int nb, nh;
    int nx;
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
 	W  = int(l[n2] / 2.f + 7.f) / 10.f;
 	W1 = int(W * 4.5f) / 10.f;
 	WG = int(W * 7.f) / 10.f;
 	WK = int(W * 16.f) / 10.f;
 	nb = int(n / 2);
 	nh = int((n + 2) / 4);
 	L=float (l[n2]);
 	L2=float (l2[n3]);
}
}
 void Ferma::OnInitialUpdate() 
 {
 	CView::OnInitialUpdate();
 	
/* 	CStdioFile RFile;
 	CFileException fileException;
 	if(RFile.Open("user.txt",CFile::typeText|CFile::modeReadWrite),&fileException)
 
 	{
 		RFile.SeekToBegin();
		CString Stu,Num,str;
 		RFile.ReadString(str);
 			AfxExtractSubString(Stu, str, 0, ' ');
 			AfxExtractSubString(Num, str, 1, ' ');*/
 		Student="ABC";
 		Numstu="1";
		Calculate();
		SetCamera();
		DrawScene();
// 	}
 }
void Ferma::Init()
 {
 	HGLRC       hrc;
 	m_pDC = new CClientDC(this);

 	ASSERT(m_pDC != NULL);
 
if (!bSetupPixelFormat())
 		return;
 	hrc = wglCreateContext(m_pDC->GetSafeHdc());
 	wglMakeCurrent(m_pDC->GetSafeHdc(), hrc);
 
 	GetClientRect(&m_oldRect);
 	glClearDepth(1.0f);
 	glEnable(GL_DEPTH_TEST);

 }
BOOL Ferma::bSetupPixelFormat()
{
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),  // size of this pfd
		1,                              // version number
		PFD_DRAW_TO_WINDOW |            // support window
		  PFD_SUPPORT_OPENGL |          // support OpenGL
		  PFD_DOUBLEBUFFER,             // double buffered
		PFD_TYPE_RGBA,                  // RGBA type
		32,                             // 24-bit color depth
		0, 0, 0, 0, 0, 0,               // color bits ignored
		0,                              // no alpha buffer
		0,                              // shift bit ignored
		0,                              // no accumulation buffer
		0, 0, 0, 0,                     // accum bits ignored
		32,                             // 32-bit z-buffer
		0,                              // no stencil buffer
		0,                              // no auxiliary buffer
		PFD_MAIN_PLANE,                 // main layer
		0,                              // reserved
		0, 0, 0                         // layer masks ignored
	};
	int pixelformat;

	if ( (pixelformat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd)) == 0 )
	{
		MessageBox("ChoosePixelFormat failed");
		return FALSE;
	}

	if (SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat, &pfd) == FALSE)
	{
		MessageBox("SetPixelFormat failed");
		return FALSE;
	}

	return TRUE;
}
void Ferma::DrawScene()
{
	int re=(n-4)/2-1;
	glClearColor(1.0f,1.0f,1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2,0.0f, WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2, -W1, WK/2);

			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2, -W, WK/2);

			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+(n-3)*L2, -W,  WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L, -W1, WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L, 0.0f,  WK/2);
		glEnd();
	
		glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2, -W1, WK/2);	
			glColor3f(0.0f, 0.0f, 0.0);
			glVertex3f(-L/2+L1, 0.0f, WK/2);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2, -W, WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2, 0.0f, WK/2);

		glEnd();
	
		glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L, -W1,  WK/2);	
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L-L1, 0.0f,  WK/2);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L-L1-L2, -W,  WK/2);
		glEnd();
		glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2, 0.0f,  WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2, 0.0f,  WG+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L1, 0.0f,  WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L1+L2, 0.0f,  WG+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L1+L2, 0.0f,  WK/2);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L, 0.0f,  0.0f+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L, 0.0f,  WG+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L-L1, 0.0f,  0.0f+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L-L1-L2, 0.0f,  WG+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L-L1-L2, 0.0f,  0.0f+WK/2);

		glEnd();	
		for(int i=0;i<=re;i++)
		{
			glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2+2*L2*i, -W, 0.0f+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+2*L2+2*L2*i, 0.0f, 0.0f+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*i, -W, 0.0f+WK/2);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*i, 0.0f, 0.0f+WK/2);
			glEnd();
			/////////////////////////
			glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2+2*L2*i, 0.0f, WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+2*L2+2*L2*i, 0.0f, 0.0f+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*i, 0.0f, WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*i, 0.0f, 0.0f+WK/2);
			glEnd();
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////
		    
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2,0.0f, WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2, -W1, WG+WK/2);

			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2, -W, WG+WK/2);

			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+(n-3)*L2, -W,  WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L, -W1,  WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L, 0.0f,  WG+WK/2);
		glEnd();
	
		glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2, -W1, WG+WK/2);	
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1, 0.0f, WG+WK/2);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2, -W, WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2, 0.0f, WG+WK/2);

		glEnd();
	
		glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L, -W1,  WG+WK/2);	
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L-L1, 0.0f,  WG+WK/2);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L-L1-L2, -W,  WG+WK/2);
		glEnd();
			
		for(int j=0;j<=re;j++)
		{
			glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2+2*L2*j, -W, WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+2*L2+2*L2*j, 0.0f, WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*j, -W, WG+WK/2);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*j, 0.0f, WG+WK/2);
			glEnd();
			glBegin(GL_LINE_STRIP);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2+2*L2*j, -W, WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+2*L2+2*L2*j, -W, 0.0f+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*j, -W, WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*j, -W, 0.0f+WK/2);
			glEnd();
		}

			glBegin(GL_LINE_LOOP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2,0.0f, -WK+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2, -W1, -WK+WK/2);

			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2, -W, -WK+WK/2);

			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+(n-3)*L2, -W,  -WK+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L, -W1,  -WK+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L, 0.0f,  -WK+WK/2);
		glEnd();
	
		glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2, -W1, -WK+WK/2);	
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1, 0.0f, -WK+WK/2);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2, -W, -WK+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2, 0.0f, -WK+WK/2);

		glEnd();
	
		glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L, -W1,  -WK+WK/2);	
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L-L1, 0.0f,  -WK+WK/2);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L-L1-L2, -W,  -WK+WK/2);
		glEnd();
		glBegin(GL_LINE_STRIP);	
        glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2, 0.0f,  -WK+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2, 0.0f,  -WK-WG+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
	    glVertex3f(-L/2+L1, 0.0f,  -WK+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
	    glVertex3f(-L/2+L1+L2, 0.0f,  -WK-WG+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
	    glVertex3f(-L/2+L1+L2, 0.0f,  -WK+WK/2);
		glEnd();
		glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L, 0.0f,  -WK+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L, 0.0f,  -WK-WG+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L-L1, 0.0f,  -WK+WK/2);
        glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L-L1-L2, 0.0f,  -WK-WG+WK/2);
		glEnd();
		for(int i1=0;i1<=re;i1++)
		{
			glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2+2*L2*i1, -W, -WK+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+2*L2+2*L2*i1, 0.0f, -WK+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*i1, -W, -WK+WK/2);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*i1, 0.0f, -WK+WK/2);
			glEnd();
			glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2+2*L2*i1, 0.0f, -WK-WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+2*L2+2*L2*i1, 0.0f, -WK+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*i1, 0.0f, -WK-WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*i1, 0.0f, -WK+WK/2);
            glEnd();
		}
			
		   glBegin(GL_LINE_LOOP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2,0.0f, -WK-WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2, -W1, -WK-WG+WK/2);

			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2, -W, -WK-WG+WK/2);

			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+(n-3)*L2, -W,  -WK-WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L, -W1,  -WK-WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L, 0.0f,  -WK-WG+WK/2);
		glEnd();
	
		glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2, -W1, -WK-WG+WK/2);	
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1, 0.0f, -WK-WG+WK/2);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2, -W, -WK-WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2, 0.0f, -WK-WG+WK/2);

		glEnd();
	
		glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L, -W1,  -WK-WG+WK/2);	
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L-L1, 0.0f,  -WK-WG+WK/2);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L-L1-L2, -W,  -WK-WG+WK/2);
		glEnd();
			
		for(int j1=0;j1<=re;j1++)
		{
			glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2+2*L2*j1, -W, -WK-WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+2*L2+2*L2*j1, 0.0f, -WK-WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*j1, -W, -WK-WG+WK/2);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*j1, 0.0f, -WK-WG+WK/2);
			glEnd();
			glBegin(GL_LINE_STRIP);
            glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+L2+2*L2*j1, -W, -WK-WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+2*L2+2*L2*j1, -W, -WK+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*j1, -W, -WK-WG+WK/2);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-L/2+L1+3*L2+2*L2*j1, -W, -WK+WK/2);
			glEnd();
		}
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2, -W1, WG+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2, -W1, 0.0f+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L1+L2, -W, WG+WK/2);
        glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L1+L2, -W, 0.0f+WK/2);
		glEnd();
        glBegin(GL_LINES);
	    glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2, -W1, WG+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L1+L2, -W, 0.0f+WK/2);
        glEnd(); 
		
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2, -W1, -WK-WG+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2, -W1, -WK+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L1+L2, -W, -WK-WG+WK/2);
        glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L1+L2, -W, -WK+WK/2);
		glEnd();
        glBegin(GL_LINES);
	    glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2, -W1, -WK-WG+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L1+L2, -W, -WK+WK/2);
        glEnd();   

		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L, -W1, -WK+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L, -W1, -WK-WG+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L-L1-L2, -W, -WK+WK/2);
		glEnd();
        glBegin(GL_LINES);
	    glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L, -W1, -WK+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L-L1-L2, -W, -WK-WG+WK/2);
        glEnd();  
		
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L, -W1, 0.0f+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L, -W1, WG+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L-L1-L2, -W, 0.0f+WK/2);
		glEnd();
        glBegin(GL_LINES);
	    glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L, -W1, 0.0f+WK/2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-L/2+L-L1-L2, -W, WG+WK/2);
        glEnd();  

	glFinish();
	SwapBuffers(wglGetCurrentDC());	
}

void Ferma::SetCameraStart()
{
    Xshift=0;
	Yshift=0;
	m_fRadius=0;
	scale_factor=winWidth/L;
	Rx = winWidth/(2.*scale_factor);
	Ry = winHeight/(2.*scale_factor);
	Ro=sqrt(Rx*Rx+Ry*Ry+(WG+WK/2)*(WG+WK/2));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-Rx,Rx,-Ry,Ry,-Ro,Ro);

}
void Ferma::SetCamera()
{	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glPushMatrix();
    Rx = winWidth/(2.*scale_factor);
	Ry = winHeight/(2.*scale_factor);
	
	Ro=sqrt(L*L+(2*WG+WK)*(2*WG+WK)+W*W)/2;
	glOrtho(-Rx,Rx,-Ry,Ry,-Ro,Ro);
	glTranslated(Xshift,Yshift,0.0f);
	glTranslated(Xshiftl,Yshiftl,0.0f);
	glRotatef((float)wAngleY, 0.0f, 1.0f, 0.0f);
	glRotatef((float)wAngleZ, 0.0f, 0.0f, 1.0f);
}
int Ferma::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	Init(); // initialize OpenGL
	return 0;
}

void Ferma::OnDestroy() 
{
	HGLRC   hrc;
	hrc = ::wglGetCurrentContext();
	::wglMakeCurrent(NULL,  NULL);
	if (hrc)
		::wglDeleteContext(hrc);
	if (m_pOldPalette)
		m_pDC->SelectPalette(m_pOldPalette, FALSE);
	if (m_pDC)
		delete m_pDC;
	CView::OnDestroy();
}

void Ferma::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
		/*if(winWidth&&winHeight&&cx&&cy) {
		float dw,dh;
		dw = (float)cx/winWidth;	
		dh = (float)cy/winHeight;
		if (dw<dh) scale_factor*=dw;
		else scale_factor*=dh;
	}*/

	winWidth  = (GLint)cx;	
	winHeight = (GLint)cy;

	glViewport(0,0,winWidth,winHeight);
	glGetIntegerv(GL_VIEWPORT, viewport);	//получение матрицы камеры
	SetCameraStart();
	DrawScene();
}

BOOL Ferma::OnEraseBkgnd(CDC* pDC) 
{
	return CView::OnEraseBkgnd(pDC);
}

BOOL Ferma::PreCreateWindow(CREATESTRUCT& cs) 
{
	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	return CView::PreCreateWindow(cs);
}

void Ferma::OnLButtonDown(UINT nFlags, CPoint point) 
{
	SetCapture();
	Lbutt=TRUE;
    LDOWX=point.x;
	LDOWY=point.y;
	oldwAngleY=wAngleY;
	oldwAngleZ=wAngleZ;
	CView::OnLButtonDown(nFlags, point);
}

void Ferma::OnLButtonUp(UINT nFlags, CPoint point) 
{
	Lbutt=FALSE;
	
	ReleaseCapture();
    //glTranslated((LDOWX-winWidth/2)/scale_factor,(winHeight/2-LDOWY)/scale_factor,0) ; 
	//SetCamera();
	//DrawScene();
	CView::OnLButtonUp(nFlags, point);
}

void Ferma::OnMouseMove(UINT nFlags, CPoint point) 
{
	PMouse=point;

	if (ShiftSta==TRUE)
	{
		
		Xshift=oldMoveX-(mouseX-point.x)/scale_factor;
		Yshift=oldMoveY+(mouseY-point.y)/scale_factor;
		SetCamera();
		DrawScene();
	}
	if (Lbutt==TRUE)
	{
       wAngleY=oldwAngleY+(360*(LDOWX-point.x)/winWidth);
	   wAngleZ=oldwAngleZ-(360*(LDOWY-point.y)/winHeight);
       
       SetCamera();
	   //glTranslated((-LDOWX+winWidth/2)/scale_factor,(-winHeight/2+LDOWY)/scale_factor,0) ;
	   DrawScene();
	}	   
	PMouse=point;
	CView::OnMouseMove(nFlags, point);
}

BOOL Ferma::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	double oldscale=scale_factor;
	if(ShiftSta==FALSE)
	{
      	
		//SetCamera();
		if (zDelta>0)
		{ 	
			scale_factor*=(zDelta*0.01);
     	}
		if (zDelta<0)
		{
		
			scale_factor/=(-zDelta*0.01);
		}    
	}
		Xshiftl =oldMoveXl+(-winWidth/2+PMouse.x)*(1/scale_factor-1/oldscale);
        Yshiftl =oldMoveYl+(winHeight/2-PMouse.y)*(1/scale_factor-1/oldscale);
		oldMoveXl=Xshiftl;
	    oldMoveYl=Yshiftl;	
	     
	SetCamera();
	DrawScene();
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}
void Ferma::OnMButtonDown(UINT nFlags, CPoint point) 
{
	SetCapture();
	ShiftSta=TRUE;
	mouseX=point.x;
	mouseY=point.y;
    oldMoveX=Xshift;
    oldMoveY=Yshift;
	CView::OnMButtonDown(nFlags, point);
}

void Ferma::OnMButtonUp(UINT nFlags, CPoint point) 
{
	ReleaseCapture();
	ShiftSta=FALSE;
CView::OnMButtonUp(nFlags, point);
}


