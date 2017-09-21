#include <windows.h>
#include <tchar.h>
#include "static.h"


// Global Variables:
HINSTANCE hInst;					// current instance
TCHAR szTitle[] = "20170920_L6";				// The title bar text
TCHAR szWindowClass[] = "WinApp";				// the class name
BOOL	_bDrawOn = FALSE;
int		_nXSize, _nYSize;
HWND hWnd;

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
void 				DrawBall(HWND, int, int);



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
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return msg.wParam;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		/*else
		{
			if (_bDrawOn)
			{
				DrawBall(hWnd, _nXSize, _nYSize);
			}
		}*/
	}
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
	static	HWND	hStaticText, hStaticIcon, hStaticRect;
	switch (message)
	{
	case	WM_CREATE:
		if (bFirstTime)
		{
			bFirstTime = FALSE;
			hStaticText = CreateWindow("Static", "This is a static text(LABEL)", WS_CHILD | SS_CENTER, 10, 10, 130, 60, hWnd, NULL, hInst, NULL);
			hStaticIcon = CreateWindow("Static", "MyIcon", WS_CHILD | SS_ICON, 150, 10, 0, 0, hWnd, NULL, hInst, NULL);
			hStaticRect = CreateWindow("Static", "", WS_CHILD | SS_GRAYRECT, 10, 80, 200, 30, hWnd, NULL, hInst, NULL);
			ShowWindow(hStaticText, SW_SHOWNORMAL);
			ShowWindow(hStaticIcon, SW_SHOWNORMAL);

			ShowWindow(hStaticRect, SW_SHOWNORMAL);
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
	
	case	WM_COMMAND:
		switch (wParam)
		{
		case 	IDM_CHANGE:
			SetWindowText(hStaticText, "New text from SetWindowText()");
			break;
		case	IDM_SEND:
			SendMessage(hStaticText, WM_SETTEXT, 0, (LONG)(LPSTR)"New Text Via SendMessage()");
			break;
		case	IDM_QUIT:
			DestroyWindow(hWnd);
			break;
		}
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

