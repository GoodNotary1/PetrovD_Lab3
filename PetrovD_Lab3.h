
// PetrovD_Lab3.h : main header file for the PetrovD_Lab3 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
#include "Container.h"


// CPetrovDLab3App:
// See PetrovD_Lab3.cpp for the implementation of this class
//

class CPetrovDLab3App : public CWinApp
{
public:
	CPetrovDLab3App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPetrovDLab3App theApp;
