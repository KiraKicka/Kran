#include "stdafx.h"
#include "KPAH.h"
#include "KPAHDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
void KPAHDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void KPAHDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
/////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(KPAHDoc, CDocument)

BEGIN_MESSAGE_MAP(KPAHDoc, CDocument)
//{{AFX_MSG_MAP(KPAHDoc)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
KPAHDoc::KPAHDoc()
{
}
KPAHDoc::~KPAHDoc()
{
}
BOOL KPAHDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
void KPAHDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}
/////////////////////////////////////////////////////////////////////////////
