// KOHCDoc.cpp : implementation of the KOHCDoc class
//

#include "stdafx.h"
#include "KOHC.h"

#include "KOHCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// KOHCDoc

IMPLEMENT_DYNCREATE(KOHCDoc, CDocument)

BEGIN_MESSAGE_MAP(KOHCDoc, CDocument)
	//{{AFX_MSG_MAP(KOHCDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// KOHCDoc construction/destruction

KOHCDoc::KOHCDoc()
{
}

KOHCDoc::~KOHCDoc()
{
}

BOOL KOHCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// KOHCDoc serialization

void KOHCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// KOHCDoc diagnostics

#ifdef _DEBUG
void KOHCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void KOHCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// KOHCDoc commands
