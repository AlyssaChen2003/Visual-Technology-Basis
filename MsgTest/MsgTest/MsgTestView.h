
// MsgTestView.h : CMsgTestView ��Ľӿ�
//

#pragma once
#include "atltypes.h"
#define WM_MYMESSAGE WM_USER+1

class CMsgTestView : public CView
{
protected: // �������л�����
	CMsgTestView();
	DECLARE_DYNCREATE(CMsgTestView)

// ����
public:
	CMsgTestDoc* GetDocument() const;

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
	virtual ~CMsgTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CPoint m_pos;
	CString m_str;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
private:
	int m_flag;
};

#ifndef _DEBUG  // MsgTestView.cpp �еĵ��԰汾
inline CMsgTestDoc* CMsgTestView::GetDocument() const
   { return reinterpret_cast<CMsgTestDoc*>(m_pDocument); }
#endif

