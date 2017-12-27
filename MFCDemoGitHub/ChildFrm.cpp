
// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "MFCDemoGitHub.h"

#include "ChildFrm.h"
#include "MFCDemoGitHubView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	m_bInitSplitter = FALSE;
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying the CREATESTRUCT cs
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	//return CMDIChildWnd::OnCreateClient(lpcs, pContext);

	CRect cr;
	GetClientRect(&cr);

	if (!m_wndMainSplitter.CreateStatic(this, 1, 2)) //1 row, 2 columns 
	{
		MessageBox(_T("Error setting up splitter frames!"), _T("Init Error!"), MB_OK | MB_ICONERROR);
		return FALSE;
	}

	if (!m_wndMainSplitter.CreateView(0, 0, RUNTIME_CLASS(CMFCDemoGitHubView),
		CSize(cr.Width() / 2, cr.Height()), pContext))
	{
		MessageBox(_T("Error setting up splitter frames!"),
			_T("Init Error!"), MB_OK | MB_ICONERROR);
		return FALSE;
	}

	if (!m_wndMainSplitter.CreateView(0, 1, RUNTIME_CLASS(CMFCDemoGitHubView),
		CSize(cr.Width() / 2, cr.Height()), pContext))
	{
		MessageBox(_T("Error setting up splitter frames!"),
			_T("Init Error!"), MB_OK | MB_ICONERROR);
		return FALSE;
	}

	m_bInitSplitter = TRUE;

	return TRUE;
}

// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CChildFrame message handlers
void CChildFrame::OnSize(UINT nType, int cx, int cy)
{
	CMDIChildWndEx::OnSize(nType, cx, cy);
	CRect cr;
	GetWindowRect(&cr);

	if (m_bInitSplitter && nType != SIZE_MINIMIZED)
	{
		m_wndMainSplitter.SetRowInfo(0, cy, 0);
		m_wndMainSplitter.SetColumnInfo(0, cr.Width() / 2, 50);
		m_wndMainSplitter.SetColumnInfo(1, cr.Width() / 2, 50);

		m_wndMainSplitter.RecalcLayout();
	}
}