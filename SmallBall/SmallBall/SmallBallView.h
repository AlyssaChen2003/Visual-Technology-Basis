
// SmallBallView.h : CSmallBallView ��Ľӿ�
//

#pragma once


class CSmallBallView : public CView
{
protected: // �������л�����
	CSmallBallView();
	DECLARE_DYNCREATE(CSmallBallView)

// ����
public:
	CSmallBallDoc* GetDocument() const;

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
	virtual ~CSmallBallView();
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
private:
	int x;
	int y;
	int movex;
	int movey;
public:
	afx_msg void On1();
public:
	int t;
public:
	afx_msg void On2();
	//afx_msg void On3();
	//afx_msg void On4();
	afx_msg void OnButtonstart();
	afx_msg void OnButtonstop();
};

#ifndef _DEBUG  // SmallBallView.cpp �еĵ��԰汾
inline CSmallBallDoc* CSmallBallView::GetDocument() const
   { return reinterpret_cast<CSmallBallDoc*>(m_pDocument); }
#endif

