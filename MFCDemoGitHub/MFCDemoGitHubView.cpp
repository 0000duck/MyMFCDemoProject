
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
