
#include "pch.h"
#include "Container.h"

using namespace std;

vector<shared_ptr<PetrovBook>> PetrovBooks;

PetrovContainer::PetrovContainer()
{
}

PetrovContainer::~PetrovContainer()
{
	PetrovBooks.clear();
}

void PetrovContainer::clear()
{
	PetrovBooks.clear();
}

void PetrovContainer::display(CDC* pDC, int& h, int& w)
{
	CString str = _T("Library:");
	w = str.GetLength();
	pDC->TextOutW(0, h, str);
	h += 40;
	if (PetrovBooks.empty())
	{
		pDC->TextOutW(0, h, _T("No books\n"));
		if (string("No books").length() > w)
			w = str.GetLength();
	}
	else
		for_each(PetrovBooks.begin(), PetrovBooks.end(), bind(&PetrovBook::output, placeholders::_1, pDC, ref(h), ref(w)));
}

void PetrovContainer::SaveFile(CArchive& g)
{
	g << PetrovBooks.size();
	
	for (auto it : PetrovBooks)
	{
		g << it.get();
	}
}

void PetrovContainer::LoadFile(CArchive& g)
{
	int count;

	g >> count;

	for (int i = 0; i < count; i++)
	{
		PetrovBook* temp = new PetrovBook;
		g >> temp;
		shared_ptr<PetrovBook> t(temp);
		PetrovBooks.push_back(t);
	}
}

