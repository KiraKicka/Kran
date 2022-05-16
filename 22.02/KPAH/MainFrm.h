// MainFrm.h : interface of the CMainFrame class
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
	CWnd* pKran;
	CWnd* pFerma;
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
	afx_msg void OnKran();
	afx_msg void OnUpdateKran(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFerma(CCmdUI* pCmdUI);
	afx_msg void OnSizes();
	afx_msg void OnUpdateSizes(CCmdUI* pCmdUI);
	afx_msg void OnForces();
	afx_msg void OnUpdateForces(CCmdUI* pCmdUI);
	afx_msg void OnSections();
	afx_msg void OnUpdateSections(CCmdUI* pCmdUI);
	afx_msg void OnSortament();
	afx_msg void OnSNiP();
	afx_msg void OnFerma();
//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
#endif // !defined(MAINFRM_H)
