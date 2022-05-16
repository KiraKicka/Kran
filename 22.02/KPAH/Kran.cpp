#include "stdafx.h"
#include <math.h>
#include "KPAH.h"
#include "Kran.h"
#include "gl\gl.h"
#include "gl\glu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
void Kran::AssertValid() const
{
	CView::AssertValid();
};
void Kran::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
};
#endif
/////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(Kran, CView)
Kran::Kran()
{
	m_pDC = NULL;
	x = 0;
	y = 0;
	z = 0;
};
Kran::~Kran()
{
};
BEGIN_MESSAGE_MAP(Kran, CView)
//{{AFX_MSG_MAP(Kran)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEWHEEL()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
void Kran::OnDraw(CDC* pDC)
{
	DrawScene();
};
/////////////////////////////////////////////////////////////////////////////
BOOL Kran::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	return CView::PreCreateWindow(cs);
};
int Kran::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	Init(); // initialize OpenGL
	return 0;
};
void Kran::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	if(cy > 0) {
		glViewport(0, 0, cx, cy);
		if((m_oldRect.right > cx) || (m_oldRect.bottom > cy))
			RedrawWindow();
		m_oldRect.right = cx;
		m_oldRect.bottom = cy;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0f, (GLdouble)cx/cy, m_fNearPlane, m_fNearPlane + m_fMaxObjSize);
		glMatrixMode(GL_MODELVIEW);
	};
};
/////////////////////////////////////////////////////////////////////////////
void Kran::Init()
{
	m_pDC = new CClientDC(this);
	ASSERT(m_pDC != NULL);
	if (!bSetupPixelFormat())
		return;
	HGLRC hrc = wglCreateContext(m_pDC->GetSafeHdc());
	wglMakeCurrent(m_pDC->GetSafeHdc(), hrc);
	GetClientRect(&m_oldRect);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	m_fNearPlane = 1.0f;
	m_fMaxObjSize = 10.0f;
	m_fRadius = m_fNearPlane + m_fMaxObjSize / 2.0f;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(-1.0f, 0.5f, -m_fRadius);
	glRotatef(25.f, 1.0f, 0.0f, 0.0f);
	glRotatef(0.f, 0.0f, 1.0f, 0.0f);
	glRotatef(0.f, 0.0f, 0.0f, 1.0f);
};
BOOL Kran::bSetupPixelFormat()
{
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),  // size of this pfd
		1,                              // version number
		PFD_DRAW_TO_WINDOW |            // support window
		PFD_SUPPORT_OPENGL |			// support OpenGL
		PFD_DOUBLEBUFFER,				// double buffered
		PFD_TYPE_RGBA,                  // RGBA type
		24,                             // 24-bit color depth
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

void Kran::DrawScene(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(-1.0f, 0.5f, -m_fRadius);
	glRotatef(25.f, 1.0f, 0.0f, 0.0f);
	glRotatef(0.f, 0.0f, 1.0f, 0.0f);
	glRotatef(0.f, 0.0f, 0.0f, 1.0f);
		glLineWidth(10);
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0f, 1.0f, 0.0f+z);
			glVertex3f(-3.5f, 1.0f, 0.5f+z);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(2.5f, 1.0f, 0.5f+z);
			glVertex3f(2.5f, 0.7f, 0.5f+z);
			glVertex3f(1.95f, 0.5f, 0.5f+z);
			glVertex3f(-2.95f, 0.5f, 0.5f+z);
			glVertex3f(-3.5f, 0.7f, 0.5f+z);
		glEnd();
		for (int i=0;i<8;i++) {
			glBegin(GL_LINES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex3f(-3.3f+0.7f*i, 1.0f, 0.5f+z);
				glVertex3f(-2.95f+0.7f*i, 0.5f, 0.5f+z);
			glEnd();
			
			glBegin(GL_LINES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex3f(-2.6f+0.7f*i, 1.0f, 0.5f+z);
				glVertex3f(-2.95f+0.7f*i, 0.5f, 0.5f+z);
			glEnd();
			
			glBegin(GL_LINES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex3f(-2.95f+0.7f*i, 1.0f, 0.5f+z);
				glVertex3f(-2.95f+0.7f*i, 0.5f, 0.5f+z);
			glEnd();
		}
		glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(-3.5f, 0.7f, 0.5f+z);
			glVertex3f(-3.3f, 1.0f, 0.5f+z);
		glEnd();
		glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(2.5f, 0.7f, 0.5f+z);
			glVertex3f(2.3f, 1.0f, 0.5f+z);
		glEnd();

		glBegin(GL_LINE_LOOP);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-3.5f, 1.0f, 0.2f+z);
			glVertex3f(2.5f, 1.0f, 0.2f+z);
			glVertex3f(2.5f, 0.7f, 0.2f+z);
			glVertex3f(1.95f, 0.5f, 0.2f+z);
			glVertex3f(-2.95f, 0.5f, 0.2f+z);
			glVertex3f(-3.5f, 0.7f, 0.2f+z);
		glEnd();
		for (int k=0;k<8;k++) {
			glBegin(GL_LINES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex3f(-3.3f+0.7f*k, 1.0f, 0.2f+z);
				glVertex3f(-2.95f+0.7f*k, 1.0f, 0.5f+z);
			glEnd();
			
			glBegin(GL_LINES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex3f(-2.95f+0.7f*k, 1.0f, 0.5f+z);
				glVertex3f(-2.6f+0.7f*k, 1.0f, 0.2f+z);
			glEnd();
					
		};
		glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(-3.5f, 1.0f, 0.5f+z);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(-3.3f, 1.0f, 0.2f+z);
		glEnd();
		glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(2.5f, 1.0f, 0.5f+z);
			glVertex3f(2.3f, 1.0f, 0.2f+z);
		glEnd();
///////////////////////////////////////////////////////////////////////////
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-3.5f, 1.0f, -0.5f+z);
			glVertex3f(2.5f, 1.0f, -0.5f+z);
			glVertex3f(2.5f, 0.7f, -0.5f+z);
			glVertex3f(1.95f, 0.5f, -0.5f+z);
			glVertex3f(-2.95f, 0.5f, -0.5f+z);
			glVertex3f(-3.5f, 0.7f, -0.5f+z);
		glEnd();
		for (int ii=0;ii<8;ii++) {
			glBegin(GL_LINES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex3f(-3.3f+0.7f*ii, 1.0f, -0.5f+z);
				glVertex3f(-2.95f+0.7f*ii, 0.5f, -0.5f+z);
			glEnd();
			
			glBegin(GL_LINES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex3f(-2.6f+0.7f*ii, 1.0f, -0.5f+z);
				glVertex3f(-2.95f+0.7f*ii, 0.5f, -0.5f+z);
			glEnd();
			
			glBegin(GL_LINES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex3f(-2.95f+0.7f*ii, 1.0f, -0.5f+z);
				glVertex3f(-2.95f+0.7f*ii, 0.5f, -0.5f+z);
			glEnd();
		}
		glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(-3.5f, 0.7f, -0.5f+z);
			glVertex3f(-3.3f, 1.0f, -0.5f+z);
		glEnd();
		glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(2.5f, 0.7f, -0.5f+z);
			glVertex3f(2.3f, 1.0f, -0.5f+z);
		glEnd();

		glBegin(GL_LINE_LOOP);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-3.5f, 1.0f, -0.8f+z);
			glVertex3f(2.5f, 1.0f, -0.8f+z);
			glVertex3f(2.5f, 0.7f, -0.8f+z);
			glVertex3f(1.95f, 0.5f, -0.8f+z);
			glVertex3f(-2.95f, 0.5f, -0.8f+z);
			glVertex3f(-3.5f, 0.7f, -0.8f+z);
		glEnd();		
		for (int kk=0;kk<8;kk++) {
			glBegin(GL_LINES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex3f(-3.3f+0.7f*kk, 1.0f, -0.8f+z);
				glVertex3f(-2.95f+0.7f*kk, 1.0f, -0.5f+z);
			glEnd();
			
			glBegin(GL_LINES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex3f(-2.95f+0.7f*kk, 1.0f, -0.5f+z);
				glVertex3f(-2.6f+0.7f*kk, 1.0f, -0.8f+z);
			glEnd();
					
		}
		glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(-3.5f, 1.0f, -0.5f+z);
			glVertex3f(-3.3f, 1.0f, -0.8f+z);
		glEnd();
		glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(2.5f, 1.0f, -0.5f+z);
			glVertex3f(2.3f, 1.0f, -0.8f+z);
		glEnd();
///////////////////////////////////////////////////////////////////////////////////
		glColor3f(1.0f, 1.0f, 0.0f);
		drawCircle(-3.0f + x,1.1f,0.2f+z,0.1f,50);
		drawCircle(-2.5f + x,1.1f,0.2f+z,0.1f,50);
		drawCircle(-2.5f + x,1.1f,-0.5f+z,0.1f,50);
		drawCircle(-3.0f + x,1.1f,-0.5f+z,0.1f,50);
		glBegin(GL_QUADS);
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(-3.2f + x, 1.1f, 0.4f + z);
			glVertex3f(-2.3f + x, 1.1f, -0.7f + z);
			glVertex3f(-2.3f + x, 1.1f, -0.7f + z);
			glVertex3f(-3.2f + x, 1.1f, 0.4f + z);
		glEnd();
///////////////////////////////////////////////////////////////////////////////
/*	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslatef(-2.5f+xx,1.2f,0.0f+z);
	glScalef(1.0f,0.2f,0.8f);
	glTranslatef(2.5f-xx,-1.2f,0.0f-z);
	glScalef(1.0f,5,1.25f);
	glColor3f(1.0f, 0.0f, 1.0f);
	glTranslatef(-3.8f,-0.1f,-0.2f+z);
	glScalef(0.4f,0.4f,1.6f);
	glTranslatef(0.0f,0.0f,0.0f);
	glTranslatef(16.2f,0,0);*/
	glPopMatrix();
	glFinish();
	SwapBuffers(wglGetCurrentDC());
}

void Kran::drawCircle(float x, float y, float z, float r, int amountSegments)
{
	glBegin(GL_LINE_LOOP);
	double dfi = 2.0*3.1415926/amountSegments, angle;
	float dx, dy;
	int i;
	for (i = 0; i < amountSegments; i++) {
		angle = dfi*i;
		dx = r*(float)cos(angle);
		dy = r*(float)sin(angle);
		glVertex3f(x + dx, y + dy, z);
	}
	glEnd();
};

BOOL Kran::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}
//--------------------------------------------------------------------
BOOL Kran::OnMouseWheel(UINT nFlags, short zDelta, CPoint point) 
{
	if (Ctrl > 0)  	// перемещение крана по цеху
		z += 0.001f*zDelta;
	else  			// перемещение тележки по крану
		x += 0.001f*zDelta;
	Invalidate(FALSE);	//все перерисовать
	return TRUE;
}
//-------------------------------------------------------------
void Kran::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	switch (nChar) {	//нажатые клавиши
	case 16:	//Shift
		Shift = 1;	//подъем крюка включен
		Ctrl = 0;  	//перемещение крана выключено
		break;
	case 17:	//Ctrl
		Ctrl = 1;  	//перемещение крана включено
	}
	Invalidate(FALSE);	// Все перерисовать
}
//-------------------------------------------------------------
void Kran::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	switch (nChar) {
	case 16:	//Shift
		Shift = 0;	//подъем крюка выключен
		break;
	case 17:	//Ctrl
		Ctrl = 0;  	//перемещение крана выключено
	}
	Invalidate(FALSE);	//все перерисовать
}

