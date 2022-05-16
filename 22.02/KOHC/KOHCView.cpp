// KOHCView.cpp : implementation of the KOHCView class
#include "stdafx.h"
#include "KOHC.h"
#include "MainFrm.h"

#include "KOHCDoc.h"
#include "KOHCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
void KOHCView::AssertValid() const
{
	CFormView::AssertValid();
}
void KOHCView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
KOHCDoc* KOHCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(KOHCDoc)));
	return (KOHCDoc*)m_pDocument;
}
#endif
/////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(KOHCView, CFormView)
BEGIN_MESSAGE_MAP(KOHCView, CFormView)
//{{AFX_MSG_MAP(KOHCView)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
KOHCView::KOHCView()
	: CFormView(KOHCView::IDD)
{
	//{{AFX_DATA_INIT(KOHCView)
	//}}AFX_DATA_INIT
}
KOHCView::~KOHCView()
{
}
void KOHCView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}
BOOL KOHCView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CFormView::PreCreateWindow(cs);
}
void KOHCView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
}
/////////////////////////////////////////////////////////////////////////////
