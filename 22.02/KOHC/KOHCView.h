#if !defined(KOHCVIEW_H)
#define KOHCVIEW_H
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/////////////////////////////////////////////////////////////////////////////
class KOHCView : public CFormView
{
protected: // create from serialization only
	DECLARE_DYNCREATE(KOHCView)
public:
//{{AFX_DATA(KOHCView)
	enum{ IDD = IDD_MAIN };
//}}AFX_DATA
	KOHCView();
	KOHCDoc* GetDocument();
//{{AFX_VIRTUAL(KOHCView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
//}}AFX_VIRTUAL
public:
	virtual ~KOHCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
//{{AFX_MSG(KOHCView)
//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#ifndef _DEBUG  // debug version in KOHCView.cpp
inline KOHCDoc* KOHCView::GetDocument()
   { return (KOHCDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
#endif // !defined(KOHCVIEW_H)
