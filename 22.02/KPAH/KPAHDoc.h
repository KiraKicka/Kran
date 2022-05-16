#if !defined(KPAHDOC_H)
#define KPAHDOC_H
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/////////////////////////////////////////////////////////////////////////////
class KPAHDoc : public CDocument
{
protected: // create from serialization only
	KPAHDoc();
	DECLARE_DYNCREATE(KPAHDoc)
//{{AFX_VIRTUAL(KPAHDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
//}}AFX_VIRTUAL
public:
	virtual ~KPAHDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
//{{AFX_MSG(KPAHDoc)
//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
#endif // !defined(KPAHDOC_H)
