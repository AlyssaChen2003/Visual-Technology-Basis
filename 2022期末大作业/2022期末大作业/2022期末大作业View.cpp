
// 2022期末大作业View.cpp : CMy2022期末大作业View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2022期末大作业.h"
#endif
#include "MyDlg.h"
#include "2022期末大作业Doc.h"
#include "2022期末大作业View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2022期末大作业View

IMPLEMENT_DYNCREATE(CMy2022期末大作业View, CView)

BEGIN_MESSAGE_MAP(CMy2022期末大作业View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TEST, &CMy2022期末大作业View::OnTest)
	ON_WM_CHAR()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_POPUP_1, &CMy2022期末大作业View::OnPopup1)
	ON_COMMAND(ID_POPUP_2, &CMy2022期末大作业View::OnPopup2)
END_MESSAGE_MAP()

// CMy2022期末大作业View 构造/析构

CMy2022期末大作业View::CMy2022期末大作业View()
	: offset(20)
	, bmp_pos(0)
	, type(0)
{
	// TODO: 在此处添加构造代码

}

CMy2022期末大作业View::~CMy2022期末大作业View()
{
}

BOOL CMy2022期末大作业View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	
	
	return CView::PreCreateWindow(cs);
}

// CMy2022期末大作业View 绘制

void CMy2022期末大作业View::OnDraw(CDC* /*pDC*/)
{
	CMy2022期末大作业Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	AfxGetMainWnd()->SetWindowText(L"2022期末大作业-陈睿颖");
	CRect rect;
	GetClientRect(&rect);
	CBitmap bm; 
	bm.LoadBitmap(IDB_BITMAP1);
	CDC *pDC=GetDC();
	CDC memDC; 
	memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(&bm);
	BITMAP info; 
	bm.GetBitmap(&info);
	

	pDC->StretchBlt(rect.Width()-info.bmWidth,0,info.bmWidth, info.bmHeight,&memDC,0,0,info.bmWidth,info.bmHeight,SRCCOPY);
	bm.DeleteObject();
	SetTextColor(*pDC, RGB(220,20,60));
	pDC->TextOutW(0,rect.Height()-20,L"姓名：陈睿颖 学号：2013544");

	CPen pen(PS_SOLID,1,RGB(255,0,255));
	pDC->SelectObject(&pen);
	CBrush brush, *oldBrush;
	brush.CreateHatchBrush(HS_DIAGCROSS,RGB(0,0,255));
	oldBrush=pDC->SelectObject(&brush);
	pDC->Ellipse(rect.Width()/2-50,rect.Height()/2-50,rect.Width()/2+50,rect.Height()/2+50);
	
	mydlg.X=rect.Width()/2;
	mydlg.Y=rect.Height()/2;
}


// CMy2022期末大作业View 打印

BOOL CMy2022期末大作业View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2022期末大作业View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2022期末大作业View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2022期末大作业View 诊断

#ifdef _DEBUG
void CMy2022期末大作业View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2022期末大作业View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2022期末大作业Doc* CMy2022期末大作业View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2022期末大作业Doc)));
	return (CMy2022期末大作业Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2022期末大作业View 消息处理程序


void CMy2022期末大作业View::OnTest()
{
	mydlg.DoModal();
	// TODO: 在此添加命令处理程序代码
}


void CMy2022期末大作业View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nChar=='n'||nChar=='N'){
		SetTimer(1,100,NULL);
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMy2022期末大作业View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1){
		CDC* pDC = GetDC();
		CRect Rect;
		GetClientRect(&Rect);
		bmp_pos.x=Rect.Width()-52;
		bmp_pos.y=0;
		bmp_rect.right=bmp_pos.x+52;
		bmp_rect.left=bmp_pos.x;
		bmp_rect.top=bmp_pos.y;
		bmp_rect.bottom=bmp_pos.y+41;
			CBitmap bm;
			bm.LoadBitmapW(IDB_BITMAP1);
			CBrush newBrush;
			newBrush.CreatePatternBrush(&bm);
			pDC->SelectObject(newBrush);
			CRect rect, newRect;
			GetClientRect(&rect);//获取客户区数据
			newRect = bmp_rect;
			if(bmp_pos.x>0){
					newRect.right -= offset;
					newRect.left -= offset;
					InvalidateRect(bmp_rect, true);
					// 绘制位图
					bmp_pos.x -= offset;
					pDC->PatBlt(newRect.left, newRect.top, 52, 41, PATCOPY);
					bmp_rect=newRect;
					
			}
	}
	CView::OnTimer(nIDEvent);
}


void CMy2022期末大作业View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnRButtonDown(nFlags, point);
	CMenu menu;
	menu.CreatePopupMenu();
	menu.AppendMenuW(MF_ENABLED,ID_POPUP_1,L"矩形");
	menu.AppendMenuW(MF_ENABLED,ID_POPUP_2,L"椭圆");
	CPoint pt;
	GetCursorPos(&pt);
	
	menu.TrackPopupMenu(TPM_LEFTALIGN,pt.x,pt.y,this);
	CView::OnRButtonDown(nFlags, point);
}


void CMy2022期末大作业View::OnPopup1()
{CDC *pDC=GetDC();
	CRect rect;
	// TODO: 在此添加命令处理程序代码
	RedrawWindow(CRect(rect.Width()/2-50,rect.Height()/2-50,rect.Width()/2+50,rect.Height()/2+50));
	mydlg.type=1;
	GetClientRect(rect);
	CPen pen(PS_SOLID,1,RGB(255,0,255));
	pDC->SelectObject(&pen);
	CBrush brush, *oldBrush;
	brush.CreateHatchBrush(HS_DIAGCROSS,RGB(0,0,255));
	oldBrush=pDC->SelectObject(&brush);
	pDC->Rectangle(rect.Width()/2-50,rect.Height()/2-50,rect.Width()/2+50,rect.Height()/2+50);
}


void CMy2022期末大作业View::OnPopup2()
{	mydlg.type=0;
	// TODO: 在此添加命令处理程序代码
	CDC *pDC=GetDC();
	CRect rect;
	GetClientRect(rect);
	RedrawWindow(CRect(rect.Width()/2-50,rect.Height()/2-50,rect.Width()/2+50,rect.Height()/2+50));
	CPen pen(PS_SOLID,1,RGB(255,0,255));
	pDC->SelectObject(&pen);
	CBrush brush, *oldBrush;
	brush.CreateHatchBrush(HS_DIAGCROSS,RGB(0,0,255));
	oldBrush=pDC->SelectObject(&brush);
	pDC->Ellipse(rect.Width()/2-50,rect.Height()/2-50,rect.Width()/2+50,rect.Height()/2+50);
}
