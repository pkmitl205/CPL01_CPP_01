#include <windows.h>
#include <tchar.h>
#include "button.h"

// Global Variables:
HINSTANCE hInst;					// current instance
TCHAR szTitle[] = "20170921_L2";				// The title bar text
TCHAR szWindowClass[] = "WinApp";				// the class name

												// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);


int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	// TODO: Place code here.
	MSG msg;

	// Register Class 
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. 
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(MyMenu);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
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
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rt;
	char szHello[] = "Hello, C-Free!";
	static 	BOOL 	bFirstTime = TRUE;
	static	HWND	hGroup, hRad1, hRad2, hCheck, hBut1, hBut2;

	switch (message)
	{
	case	WM_CREATE:
		if (bFirstTime)
		{
			bFirstTime = FALSE;
			hGroup = CreateWindow("BUTTON", "Group Box", WS_CHILD | BS_GROUPBOX, 10, 10, 120, 100, hWnd, NULL, hInst, NULL);
			hRad1 = CreateWindow("BUTTON", "Radio &1", WS_CHILD | BS_RADIOBUTTON, 20, 40, 80, 20, hWnd, (HMENU)RAD01, hInst, NULL);
			hRad2 = CreateWindow("BUTTON", "Radio &2", WS_CHILD | BS_RADIOBUTTON, 20, 70, 80, 20, hWnd, (HMENU)RAD02, hInst, NULL);

			hCheck = CreateWindow("BUTTON", "&Check Box", WS_CHILD | BS_AUTO3STATE, 20, 120, 100, 20, hWnd, (HMENU)CHECK_BOX, hInst, NULL);
			hBut1 = CreateWindow("BUTTON", "&Show Status", WS_CHILD | BS_PUSHBUTTON, 140, 20, 100, 40, hWnd, (HMENU)RAD01, hInst, NULL);
			hBut2 = CreateWindow("BUTTON", "&Done", WS_CHILD | BS_PUSHBUTTON, 140, 110, 100, 40, hWnd, (HMENU)RAD02, hInst, NULL);

			ShowWindow(hGroup, SW_SHOWNORMAL);
			ShowWindow(hRad1, SW_SHOWNORMAL);
			ShowWindow(hRad2, SW_SHOWNORMAL);
			ShowWindow(hCheck, SW_SHOWNORMAL);
			ShowWindow(hBut1, SW_SHOWNORMAL);
			ShowWindow(hBut2, SW_SHOWNORMAL);
		}
		break;
	case	WM_COMMAND:
		switch (wParam)
		{
		case 	RAD01:
			SendMessage(hRad1, BM_SETCHECK, TRUE, 0L);
			SendMessage(hRad2, BM_SETCHECK, FALSE, 0L);
			break;
		case	RAD02:
			SendMessage(hRad1, BM_SETCHECK, FALSE, 0L);
			SendMessage(hRad2, BM_SETCHECK, TRUE, 0L);
			break;
		case	CHECK_BOX:
			break;
		case	IDM_QUIT:
			DestroyWindow(hWnd);
			break;
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...

		GetClientRect(hWnd, &rt);
		DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
		EndPaint(hWnd, &ps);
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
