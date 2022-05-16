; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=KPAHDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "KPAH.h"
LastPage=0

ClassCount=5
Class1=KPAHApp
Class2=KPAHDoc
Class3=KPAHView
Class4=CMainFrame

ResourceCount=11
Resource1=IDD_KPAH_FORM (English (U.S.))
Resource2=IDD_FORCES
Resource7=IDD_FERMA
Resource8=IDD_MAIN
Resource9=IDD_KRAN
Resource10=IDD_ABOUTBOX
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX (English (U.S.))
Resource4=IDD_SECTIONS
Resource5=IDD_SORTAMENT
Resource6=IDD_SIZES
Resource11=IDR_MAINFRAME

[CLS:KPAHApp]
Type=0
HeaderFile=KPAH.h
ImplementationFile=KPAH.cpp
Filter=N

[CLS:KPAHDoc]
Type=0
HeaderFile=KPAHDoc.h
ImplementationFile=KPAHDoc.cpp
Filter=N
LastObject=ID_MAIN

[CLS:KPAHView]
Type=0
HeaderFile=KPAHView.h
ImplementationFile=KPAHView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=ID_ABOUT


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=KPAH.cpp
ImplementationFile=KPAH.cpp
Filter=D
LastObject=CAboutDlg

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_KPAH_FORM (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ABOUTBOX]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_MAIN
Command2=ID_KRAN
Command3=ID_FERMA
Command4=ID_SIZES
Command5=ID_FORCES
Command6=ID_SECTIONS
Command7=ID_SORTAMENT
Command8=ID_SNIP
Command9=ID_ABOUT
CommandCount=9

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_APP_EXIT
Command6=ID_KRAN
Command7=ID_FERMA
Command8=ID_VIEW_TOOLBAR
Command9=ID_ABOUT
CommandCount=9

[DLG:IDD_MAIN]
Type=1
Class=?
ControlCount=6
Control1=IDC_STATIC,static,1342308353
Control2=IDC_STATIC,static,1342308353
Control3=IDC_STUDENT,edit,1350631553
Control4=IDC_NUMSTU,edit,1350631553
Control5=IDC_REGISTER,button,1342242816
Control6=IDC_STATIC,static,1342177806

[DLG:IDD_KRAN]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_SIZES]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_SECTIONS]
Type=1
Class=?
ControlCount=31
Control1=IDC_CTEP,combobox,1344339970
Control2=IDC_NUMCTEP,edit,1350631552
Control3=IDC_SPIN1,msctls_updown32,1342177335
Control4=IDC_TYPEPLAF,combobox,1344340226
Control5=IDC_NUMPLAF,combobox,1344340226
Control6=IDC_Ry,combobox,1344340226
Control7=IDC_Rv,combobox,1344340226
Control8=IDC_CHECK,button,1342242816
Control9=IDC_STATIC,static,1342308353
Control10=IDC_STATIC,static,1342308353
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308354
Control14=IDC_STATIC,static,1342308354
Control15=IDC_STATIC,static,1342308353
Control16=IDC_STATIC1,static,1342308354
Control17=IDC_STATIC2,static,1342308354
Control18=IDC_STATIC3,static,1342308354
Control19=IDC_STATIC4,static,1342308354
Control20=IDC_STATIC5,static,1342308354
Control21=IDC_STATIC6,static,1342308354
Control22=IDC_STATIC7,static,1342308354
Control23=IDC_STATIC8,static,1342308354
Control24=IDC_EDIT1,edit,1350631553
Control25=IDC_EDIT2,edit,1350631553
Control26=IDC_EDIT3,edit,1350631553
Control27=IDC_EDIT4,edit,1350631553
Control28=IDC_EDIT5,edit,1350631553
Control29=IDC_EDIT6,edit,1350631553
Control30=IDC_EDIT7,edit,1350631553
Control31=IDC_EDIT8,edit,1350631553

[DLG:IDD_FORCES]
Type=1
Class=?
ControlCount=37
Control1=IDC_STATIC,static,1342308353
Control2=IDC_STATIC,static,1342308353
Control3=IDC_STATIC,static,1342308353
Control4=IDC_STATIC,button,1342177287
Control5=IDC_NBQ,edit,1350631553
Control6=IDC_NBDMAX,edit,1350631553
Control7=IDC_NC1Q,edit,1350631553
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308353
Control10=IDC_STATIC,static,1342308353
Control11=IDC_NBQG,edit,1350631553
Control12=IDC_NBDG,edit,1350631553
Control13=IDC_STATIC,button,1342177287
Control14=IDC_SHOW,button,1342242816
Control15=IDC_NEXT,button,1342242816
Control16=IDC_RESULT,button,1476460544
Control17=IDC_NHQ,edit,1350631553
Control18=IDC_NHDMAX,edit,1350631553
Control19=IDC_NPDMIN,edit,1350631553
Control20=IDC_NPQ,edit,1350631553
Control21=IDC_NPDMAX,edit,1350631553
Control22=IDC_NC1DMAX,edit,1350631553
Control23=IDC_NC2Q,edit,1350631553
Control24=IDC_NC2DMAX,edit,1350631553
Control25=IDC_NHQG,edit,1350631553
Control26=IDC_NHDG,edit,1350631553
Control27=IDC_NPQG,edit,1350631553
Control28=IDC_NPDG,edit,1350631553
Control29=IDC_NC1QG,edit,1350631553
Control30=IDC_NC1DG,edit,1350631553
Control31=IDC_NC2QG,edit,1350631553
Control32=IDC_NC2DG,edit,1350631553
Control33=IDC_STATIC,static,1342308354
Control34=IDC_STATIC,static,1342308354
Control35=IDC_STATIC,static,1342308354
Control36=IDC_STATIC,static,1342308354
Control37=IDC_STATIC,static,1342308354

[DLG:IDD_SORTAMENT]
Type=1
Class=?
ControlCount=1
Control1=IDC_SIZ,SysListView32,1350631424

[DLG:IDD_FERMA]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

