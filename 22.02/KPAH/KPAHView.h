// KPAHView.h : interface of the KPAHView class
/////////////////////////////////////////////////////////////////////////////
#if !defined(KPAHVIEW_H)
	#define KPAHVIEW_H
	#if _MSC_VER > 1000
		#pragma once
	#endif // _MSC_VER > 1000
class KPAHView : public CFormView
{
public:
	KPAHView();
	DECLARE_DYNCREATE(KPAHView)
//{{AFX_DATA(KPAHView)
	enum{ IDD = IDD_MAIN };
	CString	Student;
	CString	Numstu;
//}}AFX_DATA
	KPAHDoc* GetDocument();
//{{AFX_VIRTUAL(KPAHView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
//}}AFX_VIRTUAL
	virtual ~KPAHView();
	#ifdef _DEBUG
		virtual void AssertValid() const;
		virtual void Dump(CDumpContext& dc) const;
	#endif
protected:
//{{AFX_MSG(KPAHView)
	afx_msg void OnRegister();
//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
	#ifndef _DEBUG  // debug version in KPAHView.cpp
		inline KPAHDoc* KPAHView::GetDocument()
		   { return (KPAHDoc*)m_pDocument; }
	#endif
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
#endif // !defined(KPAHVIEW_H)
