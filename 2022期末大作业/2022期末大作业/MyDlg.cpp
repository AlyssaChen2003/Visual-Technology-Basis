// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "2022��ĩ����ҵ.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg �Ի���

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
	mycb.InsertString(0,L"ˮƽ��");
	mycb.InsertString(1,L"ˮƽ��");
	mycb.InsertString(2,L"бʮ����");
	mycb.SetCurSel(2);
	DDX_Control(pDX, IDC_EDIT_NAME, myname);
	DDX_Control(pDX, IDC_EDIT_ID, myid);
	myname.SetWindowTextW(L"���ӱ");
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


// MyDlg ��Ϣ�������





void MyDlg::OnClickedButtonColor()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CColorDialog dlg;
	dlg.DoModal();
}


void MyDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	
	if(type==0)
		str1.Format(L"�߿�ͼ�Σ���Բ");
	if(type==1)
		str1.Format(L"�߿�ͼ�Σ�����");


	str2.Format(L"�߿���ɫ��%s",);
	str3.Format(L"�߿��ȣ�%s",);
	str4.Format(L"�����%s",);

	if (((CButton *)GetDlgItem(IDC_CHECK_RED))->GetCheck())
	str5+="�����ɫ����ɫ";
	if (((CButton *)GetDlgItem(IDC_CHECK_BLUE))->GetCheck())
	str5+="�����ɫ����ɫ";
	if (((CButton *)GetDlgItem(IDC_CHECK_GREEN))->GetCheck())
	str5+="�����ɫ����ɫ";

}
