#if !defined(FORCES_H)
#define FORCES_H
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
/////////////////////////////////////////////////////////////////////////////
class Forces : public CFormView
{
public:
	Forces();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(Forces)
	KOHCDoc* GetDocument();
public:
//{{AFX_DATA(Forces)
	enum { IDD = IDD_FORCES };
	CSpinButtonCtrl	NUMCTEP;
	CSpinButtonCtrl	NUMSTU;
	CComboBox	CBStu;
	CComboBox	CBCtep;
	double	NDG;
	double	NDMAX;
	double	NGMAX;
	double	NGMIN;
	double	NMAX;
	double	NMIN;
	double	NQ;
	double	NQG;
	int		Numctep;
	int		Numstu;
	CString	Student;
	double	L;
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
	double	NDMIN;
//}}AFX_DATA
public:
	double C[3][7];
	double PP[100][7];
	double H[100][7];
	double B[100][7];
//{{AFX_VIRTUAL(Forces)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//}}AFX_VIRTUAL
public:
	void Calculate();
	virtual ~Forces();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
//{{AFX_MSG(Forces)
	afx_msg void OnShow();
//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#ifndef _DEBUG  // debug version in KOHCView.cpp
inline KOHCDoc* Forces::GetDocument()
   { return (KOHCDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
#endif // !defined(FORCES_H)
