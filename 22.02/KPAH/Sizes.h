#if !defined(SIZES_H)
#define SIZES_H
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/////////////////////////////////////////////////////////////////////////////
class Sizes : public CView
{
public:
	Sizes();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(Sizes)
	CPalette    m_cPalette;
	CPalette    *m_pOldPalette;
	CRect       m_oldRect;
	float       m_fRadius;
	CClientDC   *m_pDC;
    float	L;
	float	L1;
	float	L2;
	float	W1;
	float	W;
	float	WG;
	float	WK;
	int	n;
	CString Student;
	CString Numstu;
	double Xshiftl;
	double Yshiftl;
	double oldMoveXl;
	double oldMoveYl;
	double Xshift;
	double Yshift;
	double m_Scale;
	double mouseX;
	double mouseY;
	double LDOWX;
	double LDOWY;
	BOOL ShiftSta;
	BOOL Lbutt;
	double  wAngleY;
    double  wAngleX;
	double  wAngleZ;
	double Rx;
	double Ry;
	double Rz;
	double R_x;
	double R_y;
	int winWidth;
	int winHeight;
	CPoint PMouse;
	int zhan;
	double oldwAngleY;
	double oldwAngleZ;
	double oldMoveY;
	double oldMoveX;
	double Ro;
	double scale_factor;
	int    viewport[4];		// параметры viewport-a.
	double projection[16];	// матрица проекции.
	double modelview[16];		// видовая матриц. 
	BOOL bSetupPixelFormat(void);
	void Init();
//{{AFX_VIRTUAL(Sizes)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
//}}AFX_VIRTUAL
public:
	void Calculate();
	void DrawScene();
	void SetCameraStart();
	void SetCamera();
	virtual ~Sizes();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
//{{AFX_MSG(Sizes)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
#endif // !defined(SIZES_H)
