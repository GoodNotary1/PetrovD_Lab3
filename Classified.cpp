#include "pch.h"
#include "Classified.h"


using namespace std;

classified_book::classified_book()
{
}

classified_book::~classified_book()
{
}

IMPLEMENT_SERIAL(classified_book, PetrovBook, VERSIONABLE_SCHEMA | 1)

void classified_book::create()
{
	PetrovBook::create();

	cout << "Input security level:" << endl;
	cin >> sec_level;
	cout << "Input number of approved users:" << endl;
	cin >> appr_user_num;
}

void classified_book::output(CDC* pDC, int& h, int& w)
{
	CString utext1 = _T("Classified book:");
	pDC->TextOutW(0, h, utext1);
	if (utext1.GetLength() > w)
		w = utext1.GetLength();
	h += 40;
	CString utext2 = _T("Title: ") + title + _T("; Year: ") + to_string(year).c_str() + _T("; Author: ") + author + _T("; Security level: ") + to_string(sec_level).c_str() + _T("; Number of approved users: ") + to_string(appr_user_num).c_str();
	pDC->TextOutW(0, h, utext2);
	if (utext2.GetLength() > w)
		w = utext1.GetLength();
	h += 40;
}

void classified_book::Serialize(CArchive& f)
{
	PetrovBook::Serialize(f);
	if (f.IsStoring())
	{
		f << sec_level << appr_user_num;
	}
	else
	{
		f >> sec_level >> appr_user_num;
	}
}