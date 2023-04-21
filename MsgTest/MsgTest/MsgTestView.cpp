
// MsgTestView.cpp : CMsgTestView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MsgTest.h"
#endif

#include "MsgTestDoc.h"
#include "MsgTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMsgTestView

IMPLEMENT_DYNCREATE(CMsgTestView, CView)

BEGIN_MESSAGE_MAP(CMsgTestView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_HOTKEY()
	ON_MESSAGE(WM_MYMESSAGE,OnMyMessage)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMsgTestView ����/����

CMsgTestView::CMsgTestView()
	: m_pos(0)
	, m_str(_T(""))
	, m_flag(0)
{
	// TODO: �ڴ˴���ӹ������

}

CMsgTestView::~CMsgTestView()
{
}

BOOL CMsgTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMsgTestView ����

void CMsgTestView::OnDraw(CDC* /*pDC*/)
{
	CMsgTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//pDC->TextOutW(m_pos.x,m_pos.y,m_str);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//PostMessage(WM_MYMESSAGE,10,50);
}


// CMsgTestView ��ӡ

BOOL CMsgTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMsgTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMsgTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMsgTestView ���

#ifdef _DEBUG
void CMsgTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMsgTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMsgTestDoc* CMsgTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMsgTestDoc)));
	return (CMsgTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMsgTestView ��Ϣ�������


int CMsgTestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	//SetTimer(1,50,NULL);
	/*RegisterHotKey(m_hWnd,1001,MOD_CONTROL|MOD_ALT,'z');
	RegisterHotKey(m_hWnd,1002,MOD_CONTROL|MOD_ALT,'Z');*/
	
	return 0;
}


void CMsgTestView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//KillTimer(1);
	/*UnregisterHotKey(m_hWnd,1001);
	UnregisterHotKey(m_hWnd,1002);*/
}


void CMsgTestView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent==1){

	}
	CView::OnTimer(nIDEvent);
}


void CMsgTestView::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*if(nHotKeyId==1001||nHotKeyId==1002)
		MessageBox(L"Hot Key z or Z Clicked!");
	CView::OnHotKey(nHotKeyId, nKey1, nKey2);*/
}


LRESULT CMsgTestView::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	CString str;
	CDC *pDC=GetDC();
	str.Format(L"Activated by '@',Message Param is %d and %d!",wParam,lParam);
	Invalidate(1);
	UpdateWindow();
	pDC->TextOutW(0,0,str);
	return LRESULT();//�Զ�����Ϣ
}


void CMsgTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	if(m_flag==1){
		CString str_2;
		str_2.Format(L"Ctrl+Mouse Clicked At ( %d , %d ) !",point.x,point.y);
		MessageBox(str_2);
		m_flag=0;
	}
	else{
		CString str;
	str.Format(L"Mouse Clicked At ( %d , %d ) !",point.x,point.y);
	MessageBox(str);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMsgTestView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	str.Format(L"%c",nChar);
	
	if(str=='@')//�ж�������ַ�������ǡ�@���򼤻���Ϣ
		PostMessage(WM_MYMESSAGE,10,50);
	else
		MessageBox(str);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


BOOL CMsgTestView::PreTranslateMessage(MSG* pMsg)
{
//�ж��Ƿ�Ϊ������Ϣ
	if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST)
{     CDC *pDC=GetDC();
//�ж��Ƿ��¼���control��
		if(pMsg->wParam==VK_CONTROL)
			m_flag=1;//��Ϊ1���������������¼��и���m_flag��ֵ���Ƿ�����Control�������ͬ��Ϣ
		if(pMsg->wParam==VK_F1){
			Invalidate(1);
			UpdateWindow();
			pDC->TextOutW(0,0,L"F1 Key!");
		}
		if(pMsg->wParam==VK_F2){
			Invalidate(1);
			UpdateWindow();
			pDC->TextOutW(0,0,L"F2 Key!");
		}
		if(pMsg->wParam==VK_F3){
			Invalidate(1);
			UpdateWindow();
			pDC->TextOutW(0,0,L"F3 Key!");
		}


}
return CView::PreTranslateMessage(pMsg);
}
