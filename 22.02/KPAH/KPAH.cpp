// KPAH.cpp : Defines the class behaviors for the application.
#include "stdafx.h"
#include "KPAH.h"
#include "MainFrm.h"
#include "KPAHDoc.h"
#include "KPAHView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(KPAHApp, CWinApp)
//{{AFX_MSG_MAP(KPAHApp)
	ON_COMMAND(ID_ABOUT, OnAppAbout)
//}}AFX_MSG_MAP
//	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
//	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
KPAHApp::KPAHApp()
{
}
/////////////////////////////////////////////////////////////////////////////
// The one and only KPAHApp object
KPAHApp theApp;
/////////////////////////////////////////////////////////////////////////////
BOOL KPAHApp::InitInstance()
{
	SetRegistryKey("Local AppWizard-Generated Applications");
	LoadStdProfileSettings(0);  // Load standard INI file options (including MRU)
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(KPAHDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(KPAHView));
	AddDocTemplate(pDocTemplate);
	EnableShellOpen();	// Enable DDE Execute open
	RegisterShellFileTypes(TRUE);
	CCommandLineInfo cmdInfo;	// Parse command line
	ParseCommandLine(cmdInfo);
	if (!ProcessShellCommand(cmdInfo))// Dispatch command line
		return FALSE;
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();
	m_pMainWnd->DragAcceptFiles();	// Enable drag/drop open
	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
//}}AFX_DATA
//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//}}AFX_VIRTUAL
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
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
void KPAHApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}
/////////////////////////////////////////////////////////////////////////////

