
// 2022��ĩ����ҵView.h : CMy2022��ĩ����ҵView ��Ľӿ�
//

#pragma once
#include "mydlg.h"
#include "atltypes.h"


class CMy2022��ĩ����ҵView : public CView
{
protected: // �������л�����
	CMy2022��ĩ����ҵView();
	DECLARE_DYNCREATE(CMy2022��ĩ����ҵView)

// ����
public:
	CMy2022��ĩ����ҵDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy2022��ĩ����ҵView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // 2022��ĩ����ҵView.cpp �еĵ��԰汾
inline CMy2022��ĩ����ҵDoc* CMy2022��ĩ����ҵView::GetDocument() const
   { return reinterpret_cast<CMy2022��ĩ����ҵDoc*>(m_pDocument); }
#endif

