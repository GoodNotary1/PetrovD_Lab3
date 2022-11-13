#pragma once


#include "Book.h"
#include "Classified.h"




class PetrovContainer
{
public:
	PetrovContainer();
	~PetrovContainer();

	vector<shared_ptr<PetrovBook>> PetrovBooks;

	void clear();

	void display(CDC* pDC, int& h, int& w);

	void SaveFile(CArchive& g);

	void LoadFile(CArchive& g);
};