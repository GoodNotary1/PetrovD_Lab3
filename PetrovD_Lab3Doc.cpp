
// PetrovD_Lab3Doc.cpp : implementation of the CPetrovDLab3Doc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PetrovD_Lab3.h"
#endif

#include "PetrovD_Lab3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPetrovDLab3Doc

IMPLEMENT_DYNCREATE(CPetrovDLab3Doc, CDocument)

BEGIN_MESSAGE_MAP(CPetrovDLab3Doc, CDocument)
END_MESSAGE_MAP()


// CPetrovDLab3Doc construction/destruction

CPetrovDLab3Doc::CPetrovDLab3Doc() noexcept
{
	// TODO: add one-time construction code here

}

CPetrovDLab3Doc::~CPetrovDLab3Doc()
{
}

BOOL CPetrovDLab3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	library.clear();

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CPetrovDLab3Doc serialization

void CPetrovDLab3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		library.SaveFile(ar);
	}
	else
	{
		library.clear();
		library.LoadFile(ar);
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CPetrovDLab3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CPetrovDLab3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CPetrovDLab3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CPetrovDLab3Doc diagnostics

#ifdef _DEBUG
void CPetrovDLab3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPetrovDLab3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPetrovDLab3Doc commands
