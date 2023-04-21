
// SmallBallView.cpp : CSmallBallView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CSmallBallView ����/����

CSmallBallView::CSmallBallView()
	: x(0)
	, y(0)
	, movex(0)
	, movey(0)
	, t(500)
{
	// TODO: �ڴ˴���ӹ������
	movex=movey=10;
}

CSmallBallView::~CSmallBallView()
{
}

BOOL CSmallBallView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSmallBallView ����

void CSmallBallView::OnDraw(CDC* pDC)
{
	CSmallBallDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//pDC->SelectStockObject(BLACK_BRUSH);
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+15,y+15);
	//TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSmallBallView ��ӡ

BOOL CSmallBallView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSmallBallView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSmallBallView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CSmallBallView ���

#ifdef _DEBUG
void CSmallBallView::AssertValid() const
{
	CView::AssertValid();
}

void CSmallBallView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSmallBallDoc* CSmallBallView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSmallBallDoc)));
	return (CSmallBallDoc*)m_pDocument;
}
#endif //_DEBUG


// CSmallBallView ��Ϣ�������


int CSmallBallView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	SetTimer(1,t,NULL);
	return 0;
}


void CSmallBallView::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);

	// TODO: �ڴ˴������Ϣ����������
}


void CSmallBallView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ���������������
	t=t/2;
	SetTimer(1,t,NULL);//������ʱ������С
}


void CSmallBallView::On2()
{
	// TODO: �ڴ���������������
	t=t*2;
	SetTimer(1,t,NULL);//������ʱ��������
}


//void CSmallBallView::On3()
//{
//	//KillTimer(1);//ֹͣ��ʱ��С����ͣ
//
//	// TODO: �ڴ���������������
//}
//
//
//void CSmallBallView::On4()
//{
//	//SetTimer(1,t,NULL);//���¼�ʱ��С������
//
//	// TODO: �ڴ���������������
//}


void CSmallBallView::OnButtonstart()
{
	SetTimer(1,t,NULL);// TODO: �ڴ���������������
}


void CSmallBallView::OnButtonstop()
{
	KillTimer(1);// TODO: �ڴ���������������
}
