
// 2022��ĩ����ҵ.h : 2022��ĩ����ҵ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy2022��ĩ����ҵApp:
// �йش����ʵ�֣������ 2022��ĩ����ҵ.cpp
//

class CMy2022��ĩ����ҵApp : public CWinApp
{
public:
	CMy2022��ĩ����ҵApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2022��ĩ����ҵApp theApp;
