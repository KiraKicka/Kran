#if !defined(KRAN_H)
	#define KRAN_H
	#if _MSC_VER > 1000
		#pragma once
	#endif // _MSC_VER > 1000
/////////////////////////////////////////////////////////////////////////////
class Kran : public CView
{
public:
	Kran();    // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(Kran)
	CCreateContext context;
	CRect       m_oldRect;
	float       m_fNearPlane, m_fMaxObjSize, m_fRadius;
	CClientDC   *m_pDC;
	float x,y,z;
	int Shift, Ctrl;
	void Init();
	BOOL bSetupPixelFormat(void);
	void DrawScene(void);
	void drawCircle(float x, float y, float z, float r, int amountSegments);
//{{AFX_VIRTUAL(Kran)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
//}}AFX_VIRTUAL
public:
	virtual ~Kran();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	#ifdef _DEBUG
		virtual void AssertValid() const;
		virtual void Dump(CDumpContext& dc) const;
	#endif
protected:
	BOOL    m_play1,m_play2,m_play3,mouseup,mousedowne;
public:
//{{AFX_MSG(Kran)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg BOOL Proverka(int virtualcode);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
#endif // !defined(KRAN_H)
