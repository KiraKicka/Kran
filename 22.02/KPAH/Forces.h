#if !defined(FORCES_H)
#define FORCES_H
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/////////////////////////////////////////////////////////////////////////////
#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
class Forces : public CFormView
{
public:
	Forces();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(Forces)
public:
//{{AFX_DATA(Forces)
	enum { IDD = IDD_FORCES };
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
	double	NBDG;
	double	NBDMAX;
	double	NBQ;
	double	NBQG;
	double	NC1DG;
	double	NC1DMAX;
	double	NC1Q;
	double	NC1QG;
	double	NC2DG;
	double	NC2DMAX;
	double	NC2Q;
	double	NC2QG;
	double	NHDG;
	double	NHDMAX;
	double	NHQ;
	double	NHQG;
	double	NPDG;
	double	NPDMAX;
	double	NPDMIN;
	double	NPQ;
	double	NPQG;
//}}AFX_DATA
	double C[3][7];
	double PP[100][7];
	double H[100][7];
	double B[100][7];
	COLORREF m_colorEditBK;
	CBrush* m_pEditBkBrush;
	CString Student;
	CString Numstu;
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
	afx_msg void OnNext();
	afx_msg void OnResult();
	afx_msg void OnDestroy();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
#endif // !defined(FORCES_H)
