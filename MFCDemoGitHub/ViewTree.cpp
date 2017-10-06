
#include "stdafx.h"
#include "ViewTree.h"
#include "MemDC.h"
#include "afxControlbarUtil.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewTree

CViewTree::CViewTree()
{
}

CViewTree::~CViewTree()
{
}

BEGIN_MESSAGE_MAP(CViewTree, CTreeCtrl)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewTree message handlers

BOOL CViewTree::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	BOOL bRes = CTreeCtrl::OnNotify(wParam, lParam, pResult);

	NMHDR* pNMHDR = (NMHDR*)lParam;
	ASSERT(pNMHDR != NULL);

	if (pNMHDR && pNMHDR->code == TTN_SHOW && GetToolTips() != NULL)
	{
		GetToolTips()->SetWindowPos(&wndTop, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOSIZE);
	}

	return bRes;
}

BOOL CViewTree::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	UNUSED_ALWAYS(pDC);
	return TRUE;

	//return CTreeCtrl::OnEraseBkgnd(pDC);
}

void CViewTree::OnSize(UINT nType, int cx, int cy)
{
	CTreeCtrl::OnSize(nType, cx, cy);
}

void CViewTree::OnPaint()
{
	CRect rectClient;
	GetClientRect(rectClient);

	CPaintDC dc(this);

	// Paint to a memory device context to reduce screen flicker.
	CGstMemDC memDC(&dc, &rectClient);

	// Let the window do its default painting...
	CTreeCtrl::DefWindowProc(WM_PAINT, (WPARAM)memDC.m_hDC, 0);
}
