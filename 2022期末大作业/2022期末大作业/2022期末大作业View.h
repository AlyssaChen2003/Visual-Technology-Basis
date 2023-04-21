
// 2022期末大作业View.h : CMy2022期末大作业View 类的接口
//

#pragma once
#include "mydlg.h"
#include "atltypes.h"


class CMy2022期末大作业View : public CView
{
protected: // 仅从序列化创建
	CMy2022期末大作业View();
	DECLARE_DYNCREATE(CMy2022期末大作业View)

// 特性
public:
	CMy2022期末大作业Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy2022期末大作业View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	MyDlg mydlg;
	afx_msg void OnTest();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int offset;
	CRect bmp_rect;
	CPoint bmp_pos;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPopup1();
	afx_msg void OnPopup2();
	int type;
};

#ifndef _DEBUG  // 2022期末大作业View.cpp 中的调试版本
inline CMy2022期末大作业Doc* CMy2022期末大作业View::GetDocument() const
   { return reinterpret_cast<CMy2022期末大作业Doc*>(m_pDocument); }
#endif

