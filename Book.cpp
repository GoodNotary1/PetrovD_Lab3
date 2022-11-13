#include "pch.h"
#include "Book.h"
#include "targetver.h"


using namespace std;

PetrovBook::PetrovBook()
{
}

PetrovBook::~PetrovBook()
{
}

IMPLEMENT_SERIAL(PetrovBook, CObject, 0)

void PetrovBook::create()
{
	string buff;
	cout << "Input title:" << endl;
	getline(cin >> ws, buff);
	title = buff.c_str();
	cout << "Input publishing year:" << endl;
	cin >> year;
	cout << "Input author name:" << endl;
	getline(cin >> ws, buff);
	author = buff.c_str();
	cout << endl;
}

void PetrovBook::output(CDC* pDC, int& h, int& w)
{
	CString utext1 = _T("Book:");
	pDC->TextOutW(0, h, utext1);
	if (utext1.GetLength() > w)
		w = utext1.GetLength();
	h += 40;
	CString utext2 = _T("Title: ") + title + _T("; Year: ") + to_string(year).c_str() + _T("; Author: ") + author;
	pDC->TextOutW(0, h, utext2);
	if (utext2.GetLength() > w)
		w = utext1.GetLength();
	h += 40;
}

void PetrovBook::Serialize(CArchive& f)
{
	CObject::Serialize(f);
	if (f.IsStoring())
	{
		f << title << year << author;
	}
	else
	{
		f >> title >> year >> author;
	}
}


