
// PetrovD_Lab3View.h : interface of the CPetrovDLab3View class
//

#pragma once


class CPetrovDLab3View : public CScrollView
{
protected: // create from serialization only
	CPetrovDLab3View() noexcept;
	DECLARE_DYNCREATE(CPetrovDLab3View)

// Attributes
public:
	CPetrovDLab3Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CPetrovDLab3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PetrovD_Lab3View.cpp
inline CPetrovDLab3Doc* CPetrovDLab3View::GetDocument() const
   { return reinterpret_cast<CPetrovDLab3Doc*>(m_pDocument); }
#endif

