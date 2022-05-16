#include "stdafx.h"
#include <math.h>
#include "KPAH.h"
#include "Sortament.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
void Sortament::AssertValid() const
{
	CFormView::AssertValid();
}
void Sortament::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
/////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(Sortament, CFormView)
Sortament::Sortament()
	: CFormView(Sortament::IDD)
{
//{{AFX_DATA_INIT(Sortament)
//}}AFX_DATA_INIT
}
Sortament::~Sortament()
{
}
void Sortament::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
//{{AFX_DATA_MAP(Sortament)
//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(Sortament, CFormView)
//{{AFX_MSG_MAP(Sortament)
//	ON_BN_CLICKED(IDC_ADD, OnAdd)
//	ON_BN_CLICKED(IDC_DEL, OnDel)
//	ON_BN_CLICKED(IDC_CUT, OnCut)
//	ON_NOTIFY(NM_CLICK, IDC_TAB, OnTab)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
void Sortament::OnInitialUpdate() 
{
/*	NmAdd.LoadBitmap(IDB_INS);
	HBITMAP hBitmap = (HBITMAP) NmAdd.GetSafeHandle();
	((CButton*)GetDlgItem(IDC_LISTADD))->SetBitmap(hBitmap);
	NmDel.LoadBitmap(IDB_DEL);
	hBitmap = (HBITMAP) NmDel.GetSafeHandle();
	((CButton*)GetDlgItem(IDC_COND_DEL))->SetBitmap(hBitmap);
	((CButton*)GetDlgItem(IDC_TAB_DEL))->SetBitmap(hBitmap);
	((CButton*)GetDlgItem(IDC_LISTDEL))->SetBitmap(hBitmap);
	TBcut.LoadBitmap(IDB_CUT);
	hBitmap = (HBITMAP) TBcut.GetSafeHandle();
	((CButton*) GetDlgItem(IDC_COND_CUT))->SetBitmap(hBitmap);
	((CButton*) GetDlgItem(IDC_TAB_CUT))->SetBitmap(hBitmap);
	TBadd.LoadBitmap(IDB_ADD);
	hBitmap = (HBITMAP) TBadd.GetSafeHandle();
	((CButton*)GetDlgItem(IDC_COND_ADD))->SetBitmap(hBitmap);
	((CButton*)GetDlgItem(IDC_TAB_ADD))->SetBitmap(hBitmap);
	TBcopy.LoadBitmap(IDB_COPY);
	hBitmap = (HBITMAP) TBcopy.GetSafeHandle();
	((CButton*) GetDlgItem(IDC_TAB_COPY))->SetBitmap(hBitmap);
	TBpaste.LoadBitmap(IDB_PASTE);
	hBitmap = (HBITMAP) TBpaste.GetSafeHandle();
	((CButton*)GetDlgItem(IDC_TAB_PASTE))->SetBitmap(hBitmap);
	CondList.SetExtendedStyle(CondList.GetExtendedStyle()|LVS_EX_GRIDLINES);
	CondList.SetExtendedStyle(CondList.GetExtendedStyle()|LVS_EX_FULLROWSELECT);
	SetWindowLong(CondList.m_hWnd, GWL_STYLE, 
				  GetWindowLong(CondList.m_hWnd, GWL_STYLE)|LVS_SHOWSELALWAYS);
	LV_COLUMN lvColumn;
	lvColumn.mask = LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|LVCF_SUBITEM;
	lvColumn.fmt  = LVCFMT_LEFT;
	CRect client;
	CondList.GetClientRect(client);	//������� ��������� �������
	lvColumn.pszText = "������";
	lvColumn.cx = client.Width()/9;
	CondList.InsertColumn(0,&lvColumn);
	lvColumn.pszText = "��� ���������� �������";
	lvColumn.cx = client.Width()-client.Width()/9
		-(client.Width()/9)*2-client.Width()/5;
	CondList.InsertColumn(1,&lvColumn);
	lvColumn.pszText = "�����";
	lvColumn.cx = client.Width()/9;
	CondList.InsertColumn(2,&lvColumn);
	lvColumn.pszText = "�����";
	lvColumn.cx = client.Width()/9;
	CondList.InsertColumn(3,&lvColumn);
	lvColumn.pszText = "���� ��������";
	lvColumn.cx = client.Width()/5;
	CondList.InsertColumn(4,&lvColumn);
	BoundBox.SetColumnWidth(50);
	CHANGE = FALSE;
	ChangeStage.SetRange(1, 10000);
	ChangeStage.SetPos(1);
	iStage = 1;
	iMedia = -1;
	iRegim = -1;
	nwBound = 0;
	iTypCond = 0;
	iList = -1;
	iBound = -1;
	iAxis = 0;
	curTypCond = -1;	// ��� �� ������
	curCond = -1;		// ������� �� �������
	curStage = 0;		// ������ �� �������
	taun = 1.;
	dtau = 1.;
	Prog[0].taun = 1.;
	Prog[0].dtauT = 1.;
	UpdateData(FALSE);
	CFormView::OnInitialUpdate();*/
}
void Sortament::OnAdd()	//����������  
{
/*	UpdateData(TRUE);
	int i,j;
	for (i=0; i<kCond; i++) {	// �������� ����������
		if (Cond[i].Proc!=curProc) continue;
		if (Cond[i].CondTyp!=curTypCond) continue;
		if (Cond[i].Axis!=iAxis) continue;
		if (Cond[i].Regim!=Funs[iRegim]) continue;
		if (Cond[i].Media!=med) continue;
		if (Cond[i].Stage!=iStage) continue;
		if (Cond[i].Bound==Lst[iList]) return;
	};
	if (kCond >= 1000) {
		AfxMessageBox(
"����� ��������� ������� ��������� ���������� 1000");
		return;
	};
	for (i=0; i<kCond; i++) {	// ����� ����� ��� ������� 
		if (Cond[i].Stage<=iStage) continue;
		break;
	}
	kCond++;
	for (j=kCond; j>i; j--)		// ������������ ����� � ������� 
		Cond[j]=Cond[j-1];
	if (i<0) i=0;
	Cond[i].Proc=curProc;
	Cond[i].CondTyp=curTypCond;
	Cond[i].Axis=iAxis;
	Cond[i].Regim=Funs[iRegim];
	Cond[i].Media=med;
	Cond[i].Stage=iStage;
	Cond[i].Bound=Lst[iList];
	for (j=kStage; j<=iStage; j++) {	// �������� � ���������� ��������� 
		Prog[j] = Prog[j-1];
		Prog[j].taun = -1.f;
	}
	if (kStage<=iStage) kStage=iStage+1;
	UpdateData(FALSE);
	CHANGE=TRUE; //������� ��������
	RefreshCond();
	CondList.EnsureVisible(i,FALSE);*/
}
void Sortament::OnDel()	//�������� 
{
/*	curCond = CondList.GetNextItem(-1,LVNI_SELECTED);
	if (curCond<0) return; 
	if (kCond<1) return; 
	kCond--;
	int i, mStage=0;
	for (i=curCond; i<kCond; i++) 
		Cond[i]=Cond[i+1];
	for (i=0; i<kCond; i++)
		if (Cond[i].Stage>mStage) mStage=Cond[i].Stage;
	kStage=mStage+1;
	CHANGE=TRUE; //������� ��������
	RefreshCond();
	if (kCond<1) {
		GetDlgItem(IDE_ST_END)->EnableWindow(FALSE);
		GetDlgItem(IDE_ST_STEP)->EnableWindow(FALSE);
		GetDlgItem(IDC_STGPAR)->EnableWindow(FALSE);
		return;
	}
	if (curCond==kCond) curCond--; 
	if (curCond<0) {	// ������ �� ������� 
		OnProg(FALSE,FALSE);	// ������ ���� ���������
		return;
	}
	CondList.EnsureVisible(curCond,FALSE);
	CondList.SetItemState(curCond,LVIS_SELECTED,LVIS_SELECTED);*/
}
void Sortament::OnCut()	//�������� ���� 
{
/*	CondList.DeleteAllItems();	// ������� ���� �������
	kCond=0;
	CHANGE=TRUE; //������� ��������
	curCond = -1;*/
}
void Sortament::OnTab(NMHDR* pNMHDR, LRESULT* pResult) 
{ //����� ��� �������������� ������ � �������
/*	curCond = CondList.GetNextItem(-1,LVNI_SELECTED);
	if (curCond<0) {	// ������ �� ������� 
		return;
	}
	if (Cond[curCond].Proc!=curProc) {	// ������������� ������ ��������� �������
		return;
	}
	RefreshEdit();	// ���������� ���� �������������� ���������� �������
	*pResult = 0;*/ 
}
void Sortament::RefreshEdit()	//���������� ���� ��������������
{
/*	iTypCond=Cond[curCond].CondTyp;
	iAxis=Cond[curCond].Axis;
	UpdateData(FALSE);	// ���������� ������ ������� ���� ������� � ���
	OnChangeTypCond();	// ���������� ������� ������� � ����
	int reg=Cond[curCond].Regim;
	iStage=Cond[curCond].Stage;
	if (iStage!=curStage) {
		UpdateData(FALSE);	// ���������� ������ ������� ������ � �����
		if (curStage>0) 
			SaveProg();	// ���������� ������� ������ � ���� �����������
		curStage=iStage;
	}*/
}
void Sortament::RefreshTab()	// ���������� ���� �������
{
/*	int i,reg,proc,typ,bnd;
	char s[100];
	LV_ITEM lvItem;
	lvItem.mask = LVIF_TEXT;
	CondList.DeleteAllItems();	// ������� ���� �������
	for (i=0; i<kCond; i++) {	// ���������� ���� �������
		lvItem.iSubItem = 0;
		lvItem.iItem = i;
		sprintf_s(s,sizeof(s),"%9.d",Cond[i].Stage);
		lvItem.pszText = s;
		CondList.InsertItem(&lvItem);
		proc=Cond[i].Proc;
		typ=Cond[i].CondTyp;
		reg=Cond[i].Regim;
		bnd=Cond[i].Bound;
		if ((proc==1) && (typ>2)) {	// ��������� ��������
			sprintf_s(s,sizeof(s),"%s",(LPCTSTR)(CondTyp[cCond[proc]+typ]));
  			CondList.SetItemText(i,1,s);
			sprintf_s(s,sizeof(s),"%s",Weld[reg].Name);
  			CondList.SetItemText(i,2,s);
			sprintf_s(s,sizeof(s),"%s",Zone[bnd].Name);
  			CondList.SetItemText(i,4,s);
		} else {	// ������� ��������� ������� 1,2 ��� 3 ����
			if (Cond[i].Axis>-1)
				sprintf_s(s,sizeof(s),"%s %s", (LPCTSTR)(CondTyp[cCond[proc]+typ])
						,(LPCTSTR)(ax[Cond[i].Axis]));
			else
				sprintf_s(s,sizeof(s),"%s", (LPCTSTR)(CondTyp[cCond[proc]+typ]));
  			CondList.SetItemText(i,1,s);
			sprintf_s(s,sizeof(s),"%s",Tab[reg].Name);
  			CondList.SetItemText(i,2,s);
			if (Cond[i].Media>-1) {
				sprintf_s(s,sizeof(s),"%s",Tab[Cond[i].Media].Name);
  				CondList.SetItemText(i,3,s);
			}
			sprintf_s(s,sizeof(s),"%s",List[bnd].Name);
  			CondList.SetItemText(i,4,s);
		}
	}*/
}
