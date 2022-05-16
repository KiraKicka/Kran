; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCGwork
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "kohc.h"
LastPage=0

ClassCount=8
Class1=CCGwork
Class2=CCSection
Class3=CCStress
Class4=KOHCApp
Class5=CAboutDlg
Class6=KOHCDoc
Class7=KOHCView
Class8=CMainFrame

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDD_FORCES
Resource3=IDD_VARIANTS
Resource4=IDD_SECTIONS
Resource5=IDR_MAINFRAME
Resource6=IDD_MAIN
Resource7=IDR_MAINFRAME (English (U.S.))

[CLS:CCGwork]
Type=0
BaseClass=CFormView
HeaderFile=CGwork.h
ImplementationFile=CGwork.cpp
Filter=D
VirtualFilter=VWC
LastObject=IDC_STUDENTS

[CLS:CCSection]
Type=0
BaseClass=CFormView
HeaderFile=CSection.h
ImplementationFile=CSection.cpp

[CLS:CCStress]
Type=0
BaseClass=CFormView
HeaderFile=CStress.h
ImplementationFile=CStress.cpp

[CLS:KOHCApp]
Type=0
BaseClass=CWinApp
HeaderFile=KOHC.h
ImplementationFile=KOHC.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=KOHC.cpp
ImplementationFile=KOHC.cpp
LastObject=CAboutDlg

[CLS:KOHCDoc]
Type=0
BaseClass=CDocument
HeaderFile=KOHCDoc.h
ImplementationFile=KOHCDoc.cpp

[CLS:KOHCView]
Type=0
BaseClass=CFormView
HeaderFile=KOHCView.h
ImplementationFile=KOHCView.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_APP_EXIT
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_VIEW_TOOLBAR
Command11=ID_VIEW_STATUS_BAR
Command12=ID_APP_ABOUT
CommandCount=12

[ACL:IDR_MAINFRAME (English (U.S.))]
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

[DLG:IDD_MAIN]
Type=1
Class=KOHCView
ControlCount=4
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,static,1342308353
Control3=IDC_EDIT1,edit,1350631553
Control4=IDC_BUTTON1,button,1342242816

[DLG:IDD_VARIANTS]
Type=1
Class=CCGwork
ControlCount=43
Control1=IDC_NUMBER,edit,1350631425
Control2=IDC_SPIN1,msctls_updown32,1342177335
Control3=IDC_STUDENTS,combobox,1344340226
Control4=IDC_STATIC,static,1342308353
Control5=IDC_STATIC,static,1342308353
Control6=IDC_STATIC,static,1342308353
Control7=IDC_VARIANT,edit,1350633601
Control8=IDC_INCLUDE,button,1342382080
Control9=IDC_ERASE,button,1342242816
Control10=IDC_CLEAN,button,1342251008
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC,static,1342308354
Control15=IDC_STATIC,static,1342308354
Control16=IDC_STATIC,static,1342308354
Control17=IDC_STATIC,static,1342308354
Control18=IDC_STATIC,static,1342308354
Control19=IDC_STATIC,static,1342308354
Control20=IDC_STATIC,static,1342308354
Control21=IDC_STATIC,static,1342308354
Control22=IDC_SPAN,edit,1350633601
Control23=IDC_LENGTH_EDGE,edit,1350633601
Control24=IDC_LENGTH_REST,edit,1350633601
Control25=IDC_LENGTH_TRAILER,edit,1350633601
Control26=IDC_HIGH_EDGE,edit,1350633601
Control27=IDC_HIGH_REST,edit,1350633601
Control28=IDC_DISTANCE_MAIN,edit,1350633601
Control29=IDC_WIDTH_HORIZ,edit,1350633601
Control30=IDC_STATIC,static,1342308354
Control31=IDC_STATIC,static,1342308354
Control32=IDC_STATIC,static,1342308354
Control33=IDC_FORCE_LOAD,edit,1350633601
Control34=IDC_FORCE_VERTIC,edit,1350633601
Control35=IDC_FORCE_HORIZ,edit,1350633601
Control36=IDC_STATIC,static,1342308354
Control37=IDC_STATIC,static,1342308354
Control38=IDC_STATIC,static,1342308354
Control39=IDC_LOAD_MAIN,edit,1350633601
Control40=IDC_LOAD_ASSIS,edit,1350633601
Control41=IDC_LOAD_HORIZ,edit,1350633601
Control42=IDC_QUANTITY,edit,1350633601
Control43=IDC_STATIC,static,1342308354

[DLG:IDD_SECTIONS]
Type=1
Class=CCSection
ControlCount=36
Control1=IDC_STUDENTS,combobox,1344340226
Control2=IDC_NUMSTU,edit,1350631552
Control3=IDC_SPIN2,msctls_updown32,1342177335
Control4=IDC_CTEP,combobox,1344340226
Control5=IDC_NUMCTEP,edit,1350631552
Control6=IDC_SPIN1,msctls_updown32,1342177335
Control7=IDC_TYPEPLAF,combobox,1344340226
Control8=IDC_NUMPLAF,combobox,1344340226
Control9=IDC_Ry,combobox,1344340226
Control10=IDC_Rv,combobox,1344340226
Control11=IDC_CHECK,button,1342242816
Control12=IDC_STATIC,static,1342308353
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308353
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,button,1342177287
Control17=IDC_STATIC,static,1342308354
Control18=IDC_STATIC,static,1342308354
Control19=IDC_STATIC,static,1342308353
Control20=IDC_STATIC1,static,1342308354
Control21=IDC_STATIC2,static,1342308354
Control22=IDC_STATIC3,static,1342308354
Control23=IDC_STATIC4,static,1342308354
Control24=IDC_STATIC5,static,1342308354
Control25=IDC_STATIC6,static,1342308354
Control26=IDC_STATIC7,static,1342308354
Control27=IDC_STATIC8,static,1342308354
Control28=IDC_EDIT1,edit,1350631552
Control29=IDC_EDIT2,edit,1350631552
Control30=IDC_EDIT3,edit,1350631552
Control31=IDC_EDIT4,edit,1350631552
Control32=IDC_EDIT5,edit,1350631552
Control33=IDC_EDIT6,edit,1350631552
Control34=IDC_EDIT7,edit,1350631552
Control35=IDC_EDIT8,edit,1350631552
Control36=IDC_STATIC,static,1342308353

[DLG:IDD_FORCES]
Type=1
Class=CCStress
ControlCount=36
Control1=IDC_STUDENTS,combobox,1344340226
Control2=IDC_NUMSTU,edit,1350631553
Control3=IDC_SPIN2,msctls_updown32,1342177335
Control4=IDC_CTEP,combobox,1344340226
Control5=IDC_STATIC,static,1342308353
Control6=IDC_STATIC,static,1342308353
Control7=IDC_NUMCTEP,edit,1350631553
Control8=IDC_SPIN1,msctls_updown32,1342177335
Control9=IDC_STATIC,static,1342308353
Control10=IDC_STATIC,static,1342308353
Control11=IDC_STATIC,static,1342308353
Control12=IDC_STATIC,static,1342308353
Control13=IDC_STATIC,button,1342177287
Control14=IDC_NQ,edit,1350631553
Control15=IDC_NDMAX,edit,1350631553
Control16=IDC_NDMIN,edit,1350631553
Control17=IDC_STATIC,button,1342177287
Control18=IDC_STATIC,button,1342177287
Control19=IDC_STATIC,static,1342308353
Control20=IDC_STATIC,static,1342308353
Control21=IDC_NQG,edit,1350631553
Control22=IDC_NDG,edit,1350631553
Control23=IDC_STATIC,button,1342177287
Control24=IDC_STATIC,button,1342177287
Control25=IDC_STATIC,button,1342177287
Control26=IDC_STATIC,static,1342308353
Control27=IDC_STATIC,static,1342308353
Control28=IDC_NMAX,edit,1350631553
Control29=IDC_NMIN,edit,1350631553
Control30=IDC_STATIC,static,1342308353
Control31=IDC_STATIC,static,1342308353
Control32=IDC_NGMAX,edit,1350631553
Control33=IDC_NGMIN,edit,1350631553
Control34=IDC_STATIC,button,1342177287
Control35=IDC_STATIC,static,1342308353
Control36=IDC_SHOW,button,1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_MAIN
Command2=ID_VARIANTS
Command3=ID_FORCES
Command4=ID_SECTIONS
Command5=ID_SORTAMENT
Command6=ID_SNIP
Command7=ID_ABOUT
CommandCount=7

