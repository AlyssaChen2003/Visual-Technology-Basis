
// MsgTestView.cpp : CMsgTestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CMsgTestView 构造/析构

CMsgTestView::CMsgTestView()
	: m_pos(0)
	, m_str(_T(""))
	, m_flag(0)
{
	// TODO: 在此处添加构造代码

}

CMsgTestView::~CMsgTestView()
{
}

BOOL CMsgTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMsgTestView 绘制

void CMsgTestView::OnDraw(CDC* /*pDC*/)
{
	CMsgTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//pDC->TextOutW(m_pos.x,m_pos.y,m_str);
	// TODO: 在此处为本机数据添加绘制代码
	//PostMessage(WM_MYMESSAGE,10,50);
}


// CMsgTestView 打印

BOOL CMsgTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMsgTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMsgTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMsgTestView 诊断

#ifdef _DEBUG
void CMsgTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMsgTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMsgTestDoc* CMsgTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMsgTestDoc)));
	return (CMsgTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMsgTestView 消息处理程序


int CMsgTestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	//SetTimer(1,50,NULL);
	/*RegisterHotKey(m_hWnd,1001,MOD_CONTROL|MOD_ALT,'z');
	RegisterHotKey(m_hWnd,1002,MOD_CONTROL|MOD_ALT,'Z');*/
	
	return 0;
}


void CMsgTestView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//KillTimer(1);
	/*UnregisterHotKey(m_hWnd,1001);
	UnregisterHotKey(m_hWnd,1002);*/
}


void CMsgTestView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1){

	}
	CView::OnTimer(nIDEvent);
}


void CMsgTestView::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	return LRESULT();//自定义消息
}


void CMsgTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	str.Format(L"%c",nChar);
	
	if(str=='@')//判断输入的字符，如果是“@”则激活消息
		PostMessage(WM_MYMESSAGE,10,50);
	else
		MessageBox(str);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


BOOL CMsgTestView::PreTranslateMessage(MSG* pMsg)
{
//判断是否为键盘消息
	if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST)
{     CDC *pDC=GetDC();
//判断是否按下键盘control键
		if(pMsg->wParam==VK_CONTROL)
			m_flag=1;//置为1，在鼠标左键单击事件中根据m_flag的值即是否摁下Control键输出不同消息
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
