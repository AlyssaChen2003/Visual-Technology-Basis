#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// MyDlg �Ի���

class MyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg)

public:
	MyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck3();
	CSliderCtrl myslc;
	CComboBox mycb;
	CEdit myname;
	CEdit myid;
	CEdit myx;
	CEdit myy;
	afx_msg void OnClickedButtonColor();
	int rec;
	int ell;
	int type;
	int X;
	int Y;
	afx_msg void OnBnClickedOk();
	CString str1;
	CString str2;
	CString str3;
	CString str4;
	CString str5;
};
