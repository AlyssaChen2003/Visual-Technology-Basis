
// SmallBallView.cpp : CSmallBallView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SmallBall.h"
#endif

#include "SmallBallDoc.h"
#include "SmallBallView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSmallBallView

IMPLEMENT_DYNCREATE(CSmallBallView, CView)

BEGIN_MESSAGE_MAP(CSmallBallView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_COMMAND(ID_1, &CSmallBallView::On1)
	ON_COMMAND(ID_2, &CSmallBallView::On2)
	//ON_COMMAND(ID_3, &CSmallBallView::On3)
	//ON_COMMAND(ID_4, &CSmallBallView::On4)
	ON_COMMAND(ID_BUTTONSTART, &CSmallBallView::OnButtonstart)
	ON_COMMAND(ID_BUTTONSTOP, &CSmallBallView::OnButtonstop)
END_MESSAGE_MAP()

// CSmallBallView 构造/析构

CSmallBallView::CSmallBallView()
	: x(0)
	, y(0)
	, movex(0)
	, movey(0)
	, t(500)
{
	// TODO: 在此处添加构造代码
	movex=movey=10;
}

CSmallBallView::~CSmallBallView()
{
}

BOOL CSmallBallView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSmallBallView 绘制

void CSmallBallView::OnDraw(CDC* pDC)
{
	CSmallBallDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//pDC->SelectStockObject(BLACK_BRUSH);
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+15,y+15);
	//TODO: 在此处为本机数据添加绘制代码
}


// CSmallBallView 打印

BOOL CSmallBallView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSmallBallView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSmallBallView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CSmallBallView 诊断

#ifdef _DEBUG
void CSmallBallView::AssertValid() const
{
	CView::AssertValid();
}

void CSmallBallView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSmallBallDoc* CSmallBallView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSmallBallDoc)));
	return (CSmallBallDoc*)m_pDocument;
}
#endif //_DEBUG


// CSmallBallView 消息处理程序


int CSmallBallView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(1,t,NULL);
	return 0;
}


void CSmallBallView::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);

	// TODO: 在此处添加消息处理程序代码
}


void CSmallBallView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1){
		CDC* pDC=GetDC();
		pDC->SetROP2(R2_XORPEN);
		pDC->Ellipse(x,y,x+15,y+15);
		CRect rect;
		GetClientRect(&rect);
		if(x<0||x>rect.right-15)
			movex=-movex;
		if(y<0||y>rect.bottom-15)
			movey=-movey;
		x+=movex;
		y+=movey;
		pDC->Ellipse(x,y,x+15,y+15);
	}
	CView::OnTimer(nIDEvent);
}


void CSmallBallView::On1()
{
	// TODO: 在此添加命令处理程序代码
	t=t/2;
	SetTimer(1,t,NULL);//加速则将时间间隔调小
}


void CSmallBallView::On2()
{
	// TODO: 在此添加命令处理程序代码
	t=t*2;
	SetTimer(1,t,NULL);//减速则将时间间隔调大
}


//void CSmallBallView::On3()
//{
//	//KillTimer(1);//停止计时，小球暂停
//
//	// TODO: 在此添加命令处理程序代码
//}
//
//
//void CSmallBallView::On4()
//{
//	//SetTimer(1,t,NULL);//重新计时，小球启动
//
//	// TODO: 在此添加命令处理程序代码
//}


void CSmallBallView::OnButtonstart()
{
	SetTimer(1,t,NULL);// TODO: 在此添加命令处理程序代码
}


void CSmallBallView::OnButtonstop()
{
	KillTimer(1);// TODO: 在此添加命令处理程序代码
}
