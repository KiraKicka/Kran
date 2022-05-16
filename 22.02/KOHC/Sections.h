#if !defined(SECTIONS_H)
#define SECTIONS_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
/////////////////////////////////////////////////////////////////////////////
class Sections : public CFormView
{
public:
	Sections();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(Sections)
	KOHCDoc* GetDocument();
//{{AFX_DATA(Sections)
	enum { IDD = IDD_SECTIONS };
	CSpinButtonCtrl	NUMSTU;
	CSpinButtonCtrl	NUMCTEP;
	CComboBox	CBStudent;
	CComboBox	CBType;
	CComboBox	CBRy;
	CComboBox	CBRv;
	CComboBox	CBCtep;
	double	bap1;
	double	bap2;
	double	bap3;
	double	bap4;
	double	bap5;
	double	bap6;
	double	bap7;
	double	bap8;
	int		Numctep;
	int		Numstu;
	CString	Student;
//}}AFX_DATA
	double C[3][7];
	double PP[100][7];
	double H[100][7];
	double B[100][7];
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
	double	NDG;
	double	NDMAX;
	double	NGMAX;
	double	NGMIN;
	double	NMAX;
	double	NMIN;
	double	NQ;
	double	NQG;
//{{AFX_VIRTUAL(Sections)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//}}AFX_VIRTUAL
public:
	void Calculate();
	virtual ~Sections();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
//{{AFX_MSG(Sections)
	afx_msg void OnSelchangeCtep();
	afx_msg void OnSelchangeTypeplaf();
	afx_msg void OnCheck();
//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#ifndef _DEBUG  // debug version in KOHCView.cpp
inline KOHCDoc* Sections::GetDocument()
   { return (KOHCDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
#endif // !defined(SECTIONS_H)
