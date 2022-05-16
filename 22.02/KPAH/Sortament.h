#if !defined(SORTAMENT_H)
#define SORTAMENT_H
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/////////////////////////////////////////////////////////////////////////////
#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
class Sortament : public CFormView
{
public:
	Sortament();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(Sortament)
	void RefreshTab();	// Обновление окна таблицы
	void RefreshEdit();	//Заполнение окон редактирования
//{{AFX_DATA(Sortament)
	enum {IDD = IDD_SORTAMENT };
//}}AFX_DATA
//{{AFX_VIRTUAL(Sortament)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//}}AFX_VIRTUAL
public:
	virtual ~Sortament();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
//{{AFX_MSG(Sortament)
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnCut();
	afx_msg void OnTab(NMHDR* pNMHDR, LRESULT* pResult);
//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
#endif // !defined(SORTAMENT_H)
