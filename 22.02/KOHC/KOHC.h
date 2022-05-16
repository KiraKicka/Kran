// KOHC.h : main header file for the KOHC application
//

#if !defined(AFX_KOHC_H__C426C217_EE75_4271_A76D_EE55D3A3AD91__INCLUDED_)
#define AFX_KOHC_H__C426C217_EE75_4271_A76D_EE55D3A3AD91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// KOHCApp:
// See KOHC.cpp for the implementation of this class
//

class KOHCApp : public CWinApp
{
public:
	KOHCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(KOHCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(KOHCApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KOHC_H__C426C217_EE75_4271_A76D_EE55D3A3AD91__INCLUDED_)
