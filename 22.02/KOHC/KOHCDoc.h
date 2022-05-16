// KOHCDoc.h : interface of the KOHCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KOHCDOC_H__14A6D23C_E63D_42CD_BC66_1F08E5BD7212__INCLUDED_)
#define AFX_KOHCDOC_H__14A6D23C_E63D_42CD_BC66_1F08E5BD7212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class KOHCDoc : public CDocument
{
protected: // create from serialization only
	KOHCDoc();
	DECLARE_DYNCREATE(KOHCDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(KOHCDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~KOHCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(KOHCDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KOHCDOC_H__14A6D23C_E63D_42CD_BC66_1F08E5BD7212__INCLUDED_)
