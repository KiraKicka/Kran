#include "stdafx.h"
#include "KPAH.h"
#include "KPAHDoc.h"
#include "KPAHView.h"
#include "Kran.h"
#include "Ferma.h"
#include "Sizes.h"
#include "Forces.h"
#include "Sections.h"
#include "Sortament.h"
//#include "SNiP.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}
void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif
/////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_MAIN, OnMain)
	ON_COMMAND(ID_KRAN, OnKran)
	ON_COMMAND(ID_FERMA, OnFerma)
	ON_COMMAND(ID_SIZES, OnSizes)
	ON_COMMAND(ID_FORCES, OnForces)
	ON_COMMAND(ID_SECTIONS, OnSections)
	ON_COMMAND(ID_SORTAMENT, OnSortament)
	ON_COMMAND(ID_SNIP, OnSNiP)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};
/////////////////////////////////////////////////////////////////////////////
CMainFrame::CMainFrame()
{
	curForm = IDD_MAIN;
}
CMainFrame::~CMainFrame()
{
}
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		| WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE;

	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
void CMainFrame::SwitchToForm(UINT nForm, CView* pView)	//������������ ����
{
	if (nForm == curForm) return;	//����� �������� �������
	curForm = nForm;				//������� �������� �����
	CView* pOldView = GetActiveView();		//������� ����
	CDocument* pDoc = GetActiveDocument();	//�������� ��������
	pView->Create(NULL, NULL, 0L, CFrameWnd::rectDefault, 
				  this, nForm, NULL);	//�������� ������ ����
	pView->ShowWindow(SW_SHOW);		//����� ��������
	pOldView->ShowWindow(SW_HIDE);	//������� ������
	pDoc->AddView(pView);		//����� ������������ � ���������
	pDoc->RemoveView(pOldView);	//������� ��������
	SetActiveView(pView);		//����� ������� ��������
	pView->OnInitialUpdate();	//����� ����������� � ������	  
	pView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	RecalcLayout();		//�������� ���������� � �����
	delete pOldView;	//������� �������
}
/////////////////////////////////////////////////////////////////////////////
void CMainFrame::OnMain()	//������������� �� ������� ���� 
{
	SwitchToForm(IDD_MAIN, (CView*)new KPAHView);
}
void CMainFrame::OnKran()	//������������� �� ������ �����  
{
	SwitchToForm(IDD_KRAN, (CView*)new Kran);
}
void CMainFrame::OnFerma()	//������������� �� ������ ����� 
{
    SwitchToForm(IDD_FERMA, (CView*)new Ferma);	
}
void CMainFrame::OnSizes()	//������������� �� ���������� ����� 
{
	SwitchToForm(IDD_SIZES, (CView*)new Sizes);
}
void CMainFrame::OnForces()	//������������� �� �������� ������ 
{
	SwitchToForm(IDD_FORCES, (CView*)new Forces);
}
void CMainFrame::OnSections()	//������������� �� �������� ������� 
{
	SwitchToForm(IDD_SECTIONS, (CView*)new Sections);
}
void CMainFrame::OnSortament()	//������������� �� ��������� 
{
	SwitchToForm(IDD_SORTAMENT, (CView*)new Sortament);
}
void CMainFrame::OnSNiP()	//������������� �� ���� 
{
//	SwitchToForm(IDD_SNIP, (CView*)new SNiP);
}
