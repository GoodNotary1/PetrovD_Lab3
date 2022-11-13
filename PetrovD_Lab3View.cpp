
// PetrovD_Lab3View.cpp : implementation of the CPetrovDLab3View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PetrovD_Lab3.h"
#endif

#include "PetrovD_Lab3Doc.h"
#include "PetrovD_Lab3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPetrovDLab3View

IMPLEMENT_DYNCREATE(CPetrovDLab3View, CScrollView)

BEGIN_MESSAGE_MAP(CPetrovDLab3View, CScrollView)
END_MESSAGE_MAP()

// CPetrovDLab3View construction/destruction

CPetrovDLab3View::CPetrovDLab3View() noexcept
{
	// TODO: add construction code here

}

CPetrovDLab3View::~CPetrovDLab3View()
{
}

BOOL CPetrovDLab3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CPetrovDLab3View drawing

void CPetrovDLab3View::OnDraw(CDC* pDC)
{
	CPetrovDLab3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int h = 0;
	int w = 0;
	pDoc->library.display(pDC, h, w);

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	CSize sizeTotal;
	sizeTotal.cx = w * tm.tmAveCharWidth;
	sizeTotal.cy = h;
	SetScrollSizes(MM_TEXT, sizeTotal);
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}

void CPetrovDLab3View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CPetrovDLab3View diagnostics

#ifdef _DEBUG
void CPetrovDLab3View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPetrovDLab3View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CPetrovDLab3Doc* CPetrovDLab3View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPetrovDLab3Doc)));
	return (CPetrovDLab3Doc*)m_pDocument;
}
#endif //_DEBUG


// CPetrovDLab3View message handlers
