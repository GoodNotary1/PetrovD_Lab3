#pragma once

#include "Header.h"

using namespace std;

class PetrovBook :
	public CObject
{
public:
	DECLARE_SERIAL(PetrovBook);
	CString title;
	int year;
	CString author;

	PetrovBook();
	virtual ~PetrovBook();

	virtual void output(CDC* pDC, int& h, int& w);

	virtual void create();

	virtual void Serialize(CArchive& f);
};