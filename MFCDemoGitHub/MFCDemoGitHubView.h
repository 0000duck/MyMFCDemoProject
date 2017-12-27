
// MFCDemoGitHubView.h : interface of the CMFCDemoGitHubView class
//

#pragma once

class CMFCDemoGitHubDoc;

class CMFCDemoGitHubView : public CView
{
protected: // create from serialization only
	CMFCDemoGitHubView();
	DECLARE_DYNCREATE(CMFCDemoGitHubView)

// Attributes
public:
	CMFCDemoGitHubDoc* GetDocument() const;
	CToolTipCtrl	m_ToolTipCtrl;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL PreTranslateMessage(MSG* pMsg);

// Implementation
public:
	virtual ~CMFCDemoGitHubView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCDemoGitHubView.cpp
inline CMFCDemoGitHubDoc* CMFCDemoGitHubView::GetDocument() const
   { return reinterpret_cast<CMFCDemoGitHubDoc*>(m_pDocument); }
#endif

