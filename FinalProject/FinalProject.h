#pragma once
#ifndef FINALPROJECT_H
#define FINALPROJECT_H



#include "resource.h"
#include "Note.h"

#include "stdafx.h"
#include <windowsX.h>
#include <winuser.h>
#include <commctrl.h>

//time library
#include <minwinbase.h>

//convert string to wstring
#include <locale>
#include <codecvt>

#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment(lib, "ComCtl32.lib")

void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void OnPaint(HWND hwnd);
void OnDestroy(HWND hwnd);
BOOL OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);

HWND CreateListView(HWND hwndParent, int x, int y, int witdh, int height);
BOOL InitListViewColumns(HWND hWndListView, list<WCHAR*> szText);
BOOL InsertListViewItems(HWND hWndListView, CNote g_data);
BOOL InsertListViewItems(HWND hWndListView, CNote g_data, int startPos);

string currentDateToString();
wstring convertStringToWstring(string tmp);
//Global variable
HWND hWnd;
HWND g_txtNoteData;
HWND g_txtNoteTag;
HWND UI;
HWND g_NoteTagListView;
HWND g_NoteListView;

list<CNote> m_NoteList;

#endif