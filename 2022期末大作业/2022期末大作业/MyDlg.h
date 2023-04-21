#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// MyDlg 对话框

class MyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg)

public:
	MyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
