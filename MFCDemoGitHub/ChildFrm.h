
// ChildFrm.h : interface of the CChildFrame class
//

#pragma once

#include "GstSplitterWnd.h"

class CChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// Attributes
public:
	CGstSplitterWnd m_wndMainSplitter;
	BOOL m_bInitSplitter;

// Operations
public:

// Overrides
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);

// Generated message map functions
protected:
	afx_msg void OnSize(UINT, int, int);

	DECLARE_MESSAGE_MAP()
};
