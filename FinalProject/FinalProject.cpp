// FinalProject.cpp : Defines the entry point for the application.
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "FinalProject.h"
#include "Note.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_FINALPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_FINALPROJECT));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_FINALPROJECT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_FINALPROJECT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, _T("Quick Note"), WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME,
	   400, 30, 640, 500, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
		HANDLE_MSG(hWnd, WM_CREATE, OnCreate);
		HANDLE_MSG(hWnd, WM_COMMAND, OnCommand);
		HANDLE_MSG(hWnd, WM_DESTROY, OnDestroy);
		HANDLE_MSG(hWnd, WM_PAINT, OnPaint);
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

BOOL OnCreate(HWND hWnd, LPCREATESTRUCT lpCreateStruct)
{
	INITCOMMONCONTROLSEX icc;
	icc.dwSize = sizeof(icc);
	icc.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&icc);

	// Lấy font hệ thống
	LOGFONT lf;
	GetObject(GetStockObject(DEFAULT_GUI_FONT), sizeof(LOGFONT), &lf);
	HFONT hFont = CreateFont(lf.lfHeight, lf.lfWidth,
		lf.lfEscapement, lf.lfOrientation, lf.lfWeight,
		lf.lfItalic, lf.lfUnderline, lf.lfStrikeOut, lf.lfCharSet,
		lf.lfOutPrecision, lf.lfClipPrecision, lf.lfQuality,
		lf.lfPitchAndFamily, lf.lfFaceName);

	UI = CreateWindowEx(0, L"STATIC", L"Note:", WS_CHILD | WS_VISIBLE, 10, 7, 100, 200, hWnd, NULL, hInst, NULL);
	SendMessage(UI, WM_SETFONT, WPARAM(hFont), TRUE);

	UI = CreateWindowEx(0, L"STATIC", L"Tag:", WS_CHILD | WS_VISIBLE, 250, 7, 100, 200, hWnd, NULL, hInst, NULL);
	SendMessage(UI, WM_SETFONT, WPARAM(hFont), TRUE);

	UI = CreateWindowEx(0, L"STATIC", L"Suggest Tag:", WS_CHILD | WS_VISIBLE, 400, 7, 100, 200, hWnd, NULL, hInst, NULL);
	SendMessage(UI, WM_SETFONT, WPARAM(hFont), TRUE);

	UI=CreateWindowEx(0, L"BUTTON", L"Thêm Note Mới", WS_CHILD | WS_VISIBLE | BS_CENTER | WS_BORDER | BS_PUSHBUTTON, 250, 55, 100, 70, hWnd, (HMENU)IDC_BUTTON_ADD, hInst, NULL);
	SendMessage(UI, WM_SETFONT, WPARAM(hFont), TRUE);

	g_txtNoteData = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT , 10, 30, 200, 100, hWnd, NULL, hInst, NULL);
	SendMessage(g_txtNoteData, WM_SETFONT, WPARAM(hFont), TRUE);

	g_txtNoteTag= CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT | ES_AUTOHSCROLL, 250, 30, 100, 22, hWnd, NULL, hInst, NULL);
	SendMessage(g_txtNoteTag, WM_SETFONT, WPARAM(hFont), TRUE);

	list<WCHAR*> ListColumnNoteTagName;
	ListColumnNoteTagName.push_back(L"Số lượng");
	ListColumnNoteTagName.push_back(L"Tên Tag");
	g_NoteTagListView = CreateListView(hWnd, 400, 30, 200, 100);
	InitListViewColumns(g_NoteTagListView, ListColumnNoteTagName);

	list<WCHAR*> ListColumnNote;
	ListColumnNote.push_back(L"Thời gian");
	ListColumnNote.push_back(L"Tag");
	ListColumnNote.push_back(L"Note");
	g_NoteListView = CreateListView(hWnd, 10, 150, 600, 100);
	InitListViewColumns(g_NoteListView, ListColumnNote);

	ListColumnNote.clear();
	ListColumnNoteTagName.clear();
	
	return true;
}

void OnDestroy(HWND hwnd)
{
	PostQuitMessage(0);
}

void OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	// TODO: Add any drawing code here...
	EndPaint(hWnd, &ps);
}

void OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify)
{
	int size1 = 0; 
	int size2 = 0; 
	
	switch (id)
	{
	case IDC_BUTTON_ADD:
	{
		
		size1 = GetWindowTextLength(g_txtNoteData);
		size2 = GetWindowTextLength(g_txtNoteTag);
		
		if (size1 == 0 || size2 == 0)
		{
			MessageBox(0, L"Bạn chưa nhập đủ thông tin", L"ERROR", MB_ICONINFORMATION | MB_OK);
			break;
		}

		Note buffer;
		buffer.data = new WCHAR[size1 + 1];

		GetWindowText(g_txtNoteData, &buffer.data[0], size1 + 1);
		GetWindowText(g_txtNoteTag, &buffer.tag[0], size2 + 1);

		
	}
	break;
	}
}

HWND CreateListView(HWND hwndParent, int x, int y,  int witdh, int height)
{
	INITCOMMONCONTROLSEX icex;           // Structure for control initialization.
	icex.dwICC = ICC_LISTVIEW_CLASSES;
	InitCommonControlsEx(&icex);

	RECT rcClient;                       // The parent window's client area.

	GetClientRect(hwndParent, &rcClient);

	// Create the list-view window in report view with label editing enabled.
	HWND hWndListView = CreateWindow(WC_LISTVIEW,
		L"",
		WS_CHILD | WS_BORDER | LVS_REPORT | LVS_EDITLABELS | WS_VISIBLE | LVS_REPORT | LVS_EDITLABELS,
		x, y, witdh, height,
		hwndParent,
		NULL,
		hInst,
		NULL);

	return (hWndListView);
}
BOOL InitListViewColumns(HWND hWndListView, list<WCHAR*> szText)
{
	RECT rect;
	GetWindowRect(hWndListView, &rect);
	
	//WCHAR szText[2][256] = { L"Tag", L"Số lượng" };     // Temporary buffer.
	LVCOLUMN lvc;
	int iCol;

	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	
	// Add the columns.
	int pos = 0;
	for (list<WCHAR*>::iterator iCol = szText.begin(); iCol != szText.end(); iCol++)
	{
		lvc.iSubItem = pos;
		lvc.pszText = *iCol;
		lvc.cx = (rect.right - rect.left - 100) / (szText.size() - 1);            // Width of column in pixels.

		if (iCol == szText.begin())
		{
			lvc.cx = 100;
			lvc.fmt = LVCFMT_CENTER;
		}
		// Load the names of the column headings from the string resources.
		//LoadString(hInst, NULL, szText[iCol], sizeof(szText) / sizeof(szText[0]));

		// Insert the columns into the list view.
		if (ListView_InsertColumn(hWndListView, pos, &lvc) == -1)
			return FALSE;
	}
	pos++;
	return TRUE;
}
BOOL InsertListViewItems(HWND hWndListView, list<CNote> g_data)
{
	LVITEM lvI;
	int pos = 0;
	for (list<CNote>::iterator index = g_data.begin(); index != g_data.end(); index++)
	{
		Note Buffer;
	
		Buffer.data = index->getData();
		Buffer.tag = index->getTag();
		Buffer.time = currentDateToString();

		// nạp cột đầu - Loại chi tiêu:
		lvI.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
		lvI.iItem = pos;

		lvI.iSubItem = 0;
		lvI.pszText = &Buffer.data[0];
		lvI.state = 0;
		ListView_InsertItem(hWndListView, &lvI);
		//Nạp các cột còn lại (Content, Cost)
		lvI.mask = LVIF_TEXT;

		//Cột đầu tiên là Content
		lvI.iSubItem = 1;
		lvI.pszText = &Buffer.tag[0];
		ListView_SetItem(hWndListView, &lvI);

		//Cột tiếp theo là Cost
		lvI.iSubItem = 2;
		lvI.pszText = &convertStringToWstring(Buffer.time)[0];
		ListView_SetItem(hWndListView, &lvI);
		
		pos++;
	}

	return TRUE;
}
BOOL InsertListViewItems(HWND hWndListView, CNote g_data, int startPos)
{
	//LVITEM lvI;
	//for (int index = startPos; index < g_data.getSize(); index++)
	//{
	//	DataStruct Buffer;

	//	//TCHAR* Buffer1 = new TCHAR[g_data.getData(index).PaymentType.size()+1];
	//	//Buffer1[g_data.getData(index).PaymentType.size() + 1] = 0;
	//	//std::copy(g_data.getData(index).PaymentType.begin(), g_data.getData(index).PaymentType.end(), Buffer1);
	//	Buffer.PaymentType = g_data.getData(index).PaymentType;
	//	Buffer.Content = g_data.getData(index).Content;
	//	Buffer.Cost = g_data.getData(index).Cost;

	//	// nạp cột đầu - Loại chi tiêu:
	//	lvI.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
	//	lvI.iItem = index;

	//	lvI.iSubItem = 0;
	//	lvI.pszText = &Buffer.PaymentType[0];
	//	lvI.state = 0;
	//	ListView_InsertItem(hWndListView, &lvI);
	//	//Nạp các cột còn lại (Content, Cost)
	//	lvI.mask = LVIF_TEXT;

	//	//Cột đầu tiên là Content
	//	lvI.iSubItem = 1;
	//	lvI.pszText = &Buffer.Content[0];
	//	ListView_SetItem(hWndListView, &lvI);

	//	//Cột tiếp theo là Cost
	//	lvI.iSubItem = 2;
	//	lvI.pszText = &Buffer.Cost[0];
	//	ListView_SetItem(hWndListView, &lvI);

	//}

	return TRUE;
}

string currentDateToString()
{
	SYSTEMTIME time;
	GetLocalTime(&time);

	string str;
	str += (time.wHour + ':' + time.wMinute + ':' + time.wSecond + " " + time.wDay + '-' + time.wMonth + '-' + time.wYear);

	return str;
}

wstring convertStringToWstring(string tmp)
{
	wstring s(tmp.begin(), tmp.end());
	return s;
}
