
// GraphDrawing.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CGraphDrawingApp:
// Сведения о реализации этого класса: GraphDrawing.cpp
//

class CGraphDrawingApp : public CWinApp
{
public:
	CGraphDrawingApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CGraphDrawingApp theApp;
