
// MFCDemoGitHubView.cpp : implementation of the CMFCDemoGitHubView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCDemoGitHub.h"
#endif

#include "MFCDemoGitHubDoc.h"
#include "MFCDemoGitHubView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDemoGitHubView

IMPLEMENT_DYNCREATE(CMFCDemoGitHubView, CView)

BEGIN_MESSAGE_MAP(CMFCDemoGitHubView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCDemoGitHubView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCDemoGitHubView construction/destruction

CMFCDemoGitHubView::CMFCDemoGitHubView()
{
	// TODO: add construction code here

}

CMFCDemoGitHubView::~CMFCDemoGitHubView()
{
}

BOOL CMFCDemoGitHubView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

void CMFCDemoGitHubView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	if (m_ToolTipCtrl.Create(this, TTS_ALWAYSTIP) && m_ToolTipCtrl.AddTool(this))
	{
		m_ToolTipCtrl.SendMessage(TTM_SETMAXTIPWIDTH, 0, SHRT_MAX);
		//m_ToolTipCtrl.SendMessage(TTM_SETDELAYTIME, TTDT_AUTOPOP, SHRT_MAX);
		//m_ToolTipCtrl.SendMessage(TTM_SETDELAYTIME, TTDT_INITIAL, (int)(0.01 * 1000));
		//m_ToolTipCtrl.SendMessage(TTM_SETDELAYTIME, TTDT_RESHOW, 100);
	}
}

BOOL CMFCDemoGitHubView::PreTranslateMessage(MSG * pMsg)
{
	if (::IsWindow(m_ToolTipCtrl.m_hWnd) && pMsg->hwnd == m_hWnd)
	{
		switch (pMsg->message)
		{
		case WM_LBUTTONDOWN:
		case WM_MOUSEMOVE:
		case WM_LBUTTONUP:
		case WM_RBUTTONDOWN:
		case WM_MBUTTONDOWN:
		case WM_RBUTTONUP:
		case WM_MBUTTONUP:
			m_ToolTipCtrl.RelayEvent(pMsg);
			break;
		}
	}

	return __super ::PreTranslateMessage(pMsg);
}

// CMFCDemoGitHubView drawing

void CMFCDemoGitHubView::OnDraw(CDC* /*pDC*/)
{
	CMFCDemoGitHubDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCDemoGitHubView printing


void CMFCDemoGitHubView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCDemoGitHubView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCDemoGitHubView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCDemoGitHubView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCDemoGitHubView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCDemoGitHubView::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_ToolTipCtrl.Activate(FALSE);
}

void CMFCDemoGitHubView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_ToolTipCtrl.Activate(TRUE);
	m_ToolTipCtrl.UpdateTipText(_T("Tooltip Show Up and Start Tracking"), this);
}

void CMFCDemoGitHubView::OnMouseMove(UINT nFlags, CPoint point)
{
	CString strText;
	strText.Format(_T("Position: X %d, Y %d"), point.x, point.y);
	m_ToolTipCtrl.UpdateTipText(strText, this);
}

void CMFCDemoGitHubView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCDemoGitHubView diagnostics

#ifdef _DEBUG
void CMFCDemoGitHubView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDemoGitHubView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDemoGitHubDoc* CMFCDemoGitHubView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDemoGitHubDoc)));
	return (CMFCDemoGitHubDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDemoGitHubView message handlers
