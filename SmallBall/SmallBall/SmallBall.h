
// SmallBall.h : SmallBall Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSmallBallApp:
// �йش����ʵ�֣������ SmallBall.cpp
//

class CSmallBallApp : public CWinApp
{
public:
	CSmallBallApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSmallBallApp theApp;
