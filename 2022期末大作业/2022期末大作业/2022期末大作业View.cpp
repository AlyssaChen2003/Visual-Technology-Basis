
// 2022��ĩ����ҵView.cpp : CMy2022��ĩ����ҵView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2022��ĩ����ҵ.h"
#endif
#include "MyDlg.h"
#include "2022��ĩ����ҵDoc.h"
#include "2022��ĩ����ҵView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2022��ĩ����ҵView

IMPLEMENT_DYNCREATE(CMy2022��ĩ����ҵView, CView)

BEGIN_MESSAGE_MAP(CMy2022��ĩ����ҵView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TEST, &CMy2022��ĩ����ҵView::OnTest)
	ON_WM_CHAR()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_POPUP_1, &CMy2022��ĩ����ҵView::OnPopup1)
	ON_COMMAND(ID_POPUP_2, &CMy2022��ĩ����ҵView::OnPopup2)
END_MESSAGE_MAP()

// CMy2022��ĩ����ҵView ����/����

CMy2022��ĩ����ҵView::CMy2022��ĩ����ҵView()
	: offset(20)
	, bmp_pos(0)
	, type(0)
{
	// TODO: �ڴ˴���ӹ������

}

CMy2022��ĩ����ҵView::~CMy2022��ĩ����ҵView()
{
}

BOOL CMy2022��ĩ����ҵView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	
	
	return CView::PreCreateWindow(cs);
}

// CMy2022��ĩ����ҵView ����

void CMy2022��ĩ����ҵView::OnDraw(CDC* /*pDC*/)
{
	CMy2022��ĩ����ҵDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	AfxGetMainWnd()->SetWindowText(L"2022��ĩ����ҵ-���ӱ");
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
	pDC->TextOutW(0,rect.Height()-20,L"���������ӱ ѧ�ţ�2013544");

	CPen pen(PS_SOLID,1,RGB(255,0,255));
	pDC->SelectObject(&pen);
	CBrush brush, *oldBrush;
	brush.CreateHatchBrush(HS_DIAGCROSS,RGB(0,0,255));
	oldBrush=pDC->SelectObject(&brush);
	pDC->Ellipse(rect.Width()/2-50,rect.Height()/2-50,rect.Width()/2+50,rect.Height()/2+50);
	
	mydlg.X=rect.Width()/2;
	mydlg.Y=rect.Height()/2;
}


// CMy2022��ĩ����ҵView ��ӡ

BOOL CMy2022��ĩ����ҵView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2022��ĩ����ҵView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2022��ĩ����ҵView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2022��ĩ����ҵView ���

#ifdef _DEBUG
void CMy2022��ĩ����ҵView::AssertValid() const
{
	CView::AssertValid();
}

void CMy2022��ĩ����ҵView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2022��ĩ����ҵDoc* CMy2022��ĩ����ҵView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2022��ĩ����ҵDoc)));
	return (CMy2022��ĩ����ҵDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy2022��ĩ����ҵView ��Ϣ�������


void CMy2022��ĩ����ҵView::OnTest()
{
	mydlg.DoModal();
	// TODO: �ڴ���������������
}


void CMy2022��ĩ����ҵView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nChar=='n'||nChar=='N'){
		SetTimer(1,100,NULL);
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMy2022��ĩ����ҵView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
			GetClientRect(&rect);//��ȡ�ͻ�������
			newRect = bmp_rect;
			if(bmp_pos.x>0){
					newRect.right -= offset;
					newRect.left -= offset;
					InvalidateRect(bmp_rect, true);
					// ����λͼ
					bmp_pos.x -= offset;
					pDC->PatBlt(newRect.left, newRect.top, 52, 41, PATCOPY);
					bmp_rect=newRect;
					
			}
	}
	CView::OnTimer(nIDEvent);
}


void CMy2022��ĩ����ҵView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnRButtonDown(nFlags, point);
	CMenu menu;
	menu.CreatePopupMenu();
	menu.AppendMenuW(MF_ENABLED,ID_POPUP_1,L"����");
	menu.AppendMenuW(MF_ENABLED,ID_POPUP_2,L"��Բ");
	CPoint pt;
	GetCursorPos(&pt);
	
	menu.TrackPopupMenu(TPM_LEFTALIGN,pt.x,pt.y,this);
	CView::OnRButtonDown(nFlags, point);
}


void CMy2022��ĩ����ҵView::OnPopup1()
{CDC *pDC=GetDC();
	CRect rect;
	// TODO: �ڴ���������������
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


void CMy2022��ĩ����ҵView::OnPopup2()
{	mydlg.type=0;
	// TODO: �ڴ���������������
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
