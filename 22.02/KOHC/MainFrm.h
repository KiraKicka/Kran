/////////////////////////////////////////////////////////////////////////////
#if !defined(MAINFRM_H)
	#define MAINFRM_H
	#if _MSC_VER > 1000
		#pragma once
	#endif // _MSC_VER > 1000
class CMainFrame : public CFrameWnd
{
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)
	UINT curForm;
//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
//}}AFX_VIRTUAL
public:
	void SwitchToForm(UINT nForm, CView* pView);
	virtual ~CMainFrame();
	#ifdef _DEBUG
		virtual void AssertValid() const;
		virtual void Dump(CDumpContext& dc) const;
	#endif
protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMain();
	afx_msg void OnVariants();
	afx_msg void OnForces();
	afx_msg void OnSections();
	afx_msg void OnSortament();
	afx_msg void OnSNiP();
//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
#endif // !defined(MAINFRM_H)
