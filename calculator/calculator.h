
// calculator.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CcalculatorApp: 
// �аѾ\��@�����O�� calculator.cpp
//

class CcalculatorApp : public CWinApp
{
public:
	CcalculatorApp();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CcalculatorApp theApp;