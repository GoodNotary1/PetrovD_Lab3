#pragma once
#include <stdio.h>
#include "resource.h"
#include <tchar.h>
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      
#define _AFX_NO_MFC_CONTROLS_IN_DIALOGS         

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            
#endif

#include <afx.h>
#include <afxwin.h>         
#include <afxext.h>         
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>          
#endif

#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                    
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <memory>
#include <algorithm>

using namespace std;