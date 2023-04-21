// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "2022期末大作业.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDlg::IDD, pParent)
	, rec(0)
	, ell(0)
	, type(0)
	, X(0)
	, Y(0)
	, str1(_T(""))
	, str2(_T(""))
	, str3(_T(""))
	, str4(_T(""))
	, str5(_T(""))
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, myslc);
	myslc.SetRange(1,6,true);
	myslc.SetTicFreq(1);
	DDX_Control(pDX, IDC_COMBO1, mycb);
	mycb.InsertString(0,L"水平线");
	mycb.InsertString(1,L"水平线");
	mycb.InsertString(2,L"斜十字线");
	mycb.SetCurSel(2);
	DDX_Control(pDX, IDC_EDIT_NAME, myname);
	DDX_Control(pDX, IDC_EDIT_ID, myid);
	myname.SetWindowTextW(L"陈睿颖");
	myid.SetWindowTextW(L"2013544");
	
	DDX_Control(pDX, IDC_EDIT_X, myx);
	DDX_Control(pDX, IDC_EDIT_Y, myy);
	CRect rect;
	GetClientRect(&rect);
	CString x;
	x.Format(L"%d",X);
	myx.SetWindowTextW(x);
	CString y;
	y.Format(L"%d",Y);
	myy.SetWindowTextW(y);
	CButton* radio1=(CButton*)GetDlgItem(IDC_RADIO_RECT);
	CButton* radio0=(CButton*)GetDlgItem(IDC_RADIO_ELLIPSE);
	if(type==0)
		radio0->SetCheck(1);
	if(type==1)
		radio1->SetCheck(1);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	//ON_BN_CLICKED(IDC_CHECK3, &MyDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_BUTTON_COLOR, &MyDlg::OnClickedButtonColor)
	ON_BN_CLICKED(IDOK, &MyDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// MyDlg 消息处理程序





void MyDlg::OnClickedButtonColor()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog dlg;
	dlg.DoModal();
}


void MyDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	
	if(type==0)
		str1.Format(L"边框图形：椭圆");
	if(type==1)
		str1.Format(L"边框图形：矩形");


	str2.Format(L"边框颜色：%s",);
	str3.Format(L"边框宽度：%s",);
	str4.Format(L"填充风格：%s",);

	if (((CButton *)GetDlgItem(IDC_CHECK_RED))->GetCheck())
	str5+="填充颜色：红色";
	if (((CButton *)GetDlgItem(IDC_CHECK_BLUE))->GetCheck())
	str5+="填充颜色：蓝色";
	if (((CButton *)GetDlgItem(IDC_CHECK_GREEN))->GetCheck())
	str5+="填充颜色：绿色";

}
