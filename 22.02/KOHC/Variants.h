#if !defined(VARIANTS_H)
#define VARIANTS_H
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
/////////////////////////////////////////////////////////////////////////////
class Variants : public CFormView
{
public:
	Variants();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(Variants)
	KOHCDoc* GetDocument();
public:
//{{AFX_DATA(Variants)
	enum { IDD = IDD_VARIANTS };
	CSpinButtonCtrl	NUM;
	CComboBox	CBStudent;
	double	L;
	CString	Student;
	int		Variant;
	double	L1;
	double	L2;
	double	W1;
	double	LT;
	double	W;
	double	WG;
	double	WK;
	double	P;
	double	D;
	double	DG;
	double	Q;
	double	QV;
	double	QG;
	int		Num;
	int		n;
//}}AFX_DATA
//{{AFX_VIRTUAL(Variants)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
//}}AFX_VIRTUAL
	void Calculate();
	virtual ~Variants();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
//{{AFX_MSG(Variants)
	afx_msg void OnInclude();
	afx_msg void OnErase();
	afx_msg void OnClean();
	afx_msg void OnSelStudent();
//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#ifndef _DEBUG  // debug version in KOHCView.cpp
inline KOHCDoc* Variants::GetDocument()
   { return (KOHCDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
#endif // !defined(VARIANTS_H)
