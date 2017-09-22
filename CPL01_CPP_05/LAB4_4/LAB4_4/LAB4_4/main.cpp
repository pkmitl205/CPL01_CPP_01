#include <windows.h>
#include <cstdlib>
#include <iostream>
#include "button.h"

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);

int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	WNDCLASS wc;
	HWND hwnd;
	MSG msg;
	/***************** 1. Define Windows class ****************************/
	wc.style = NULL; // Class style
	wc.lpfnWndProc = (WNDPROC)WndProc; // Window procedure address
	wc.cbClsExtra = 0; // Class extra bytes
	wc.cbWndExtra = 0; // Window extra bytes
	wc.hInstance = hInstance; // Instance handle
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO); // Icon handle
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Cursor handle
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2); // Background color
	wc.lpszMenuName = NULL; // Menu name
	wc.lpszClassName = "MyWndClass"; // WNDCLASS name

									 /***************** 2. Register the Windows class **********************/

	RegisterClass(&wc);

	/***************** 3. Create window **********************/
	hwnd = CreateWindow(
		"MyWndClass", // WNDCLASS name
		"EasyWin32_Calculator", // Window title
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, // Window style
		100, // Horizontal position
		100, // Vertical position
		310, // Initial width
		310, // Initial height
		HWND_DESKTOP, // Handle of parent window
		NULL, // Menu handle
		hInstance, // Application's instance handle
		NULL// Window-creation data
	);

	/***************** 4. Display the window **********************/
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	/***************** 5. Message loop **********************/
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

HWND bt00, bt11, bt22, bt33, bt44, bt55, bt66, bt77, bt88, bt99,
btPlu, btMin, btMul, btDiv, btTotal, btDot,
edit11, edit22, edit33;

PAINTSTRUCT ps;
HDC hdc;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam,
	LPARAM lParam)
{

	switch (message) {

	case WM_CREATE:
	{
		bt77 = CreateWindow(TEXT("button"), TEXT("7"),
			WS_VISIBLE | WS_CHILD,
			20, 80, 60, 40,
			hwnd, (HMENU)bt7, NULL, NULL
		);
		bt88 = CreateWindow(TEXT("button"), TEXT("8"),
			WS_VISIBLE | WS_CHILD,
			85, 80, 60, 40,
			hwnd, (HMENU)bt8, NULL, NULL
		);
		bt99 = CreateWindow(TEXT("button"), TEXT("9"),
			WS_VISIBLE | WS_CHILD,
			150, 80, 60, 40,
			hwnd, (HMENU)bt9, NULL, NULL
		);
		btDiv = CreateWindow(TEXT("button"), TEXT("/"),
			WS_VISIBLE | WS_CHILD,
			215, 80, 60, 40,
			hwnd, (HMENU)Div, NULL, NULL
		);
		// ================================================
		bt44 = CreateWindow(TEXT("button"), TEXT("4"),
			WS_VISIBLE | WS_CHILD,
			20, 125, 60, 40,
			hwnd, (HMENU)bt4, NULL, NULL
		);
		bt55 = CreateWindow(TEXT("button"), TEXT("5"),
			WS_VISIBLE | WS_CHILD,
			85, 125, 60, 40,
			hwnd, (HMENU)bt5, NULL, NULL
		);
		bt66 = CreateWindow(TEXT("button"), TEXT("6"),
			WS_VISIBLE | WS_CHILD,
			150, 125, 60, 40,
			hwnd, (HMENU)bt6, NULL, NULL
		);
		btMul = CreateWindow(TEXT("button"), TEXT("*"),
			WS_VISIBLE | WS_CHILD,
			215, 125, 60, 40,
			hwnd, (HMENU)Mul, NULL, NULL
		);
		// ================================================
		bt11 = CreateWindow(TEXT("button"), TEXT("1"),
			WS_VISIBLE | WS_CHILD,
			20, 170, 60, 40,
			hwnd, (HMENU)bt1, NULL, NULL
		);
		bt22 = CreateWindow(TEXT("button"), TEXT("2"),
			WS_VISIBLE | WS_CHILD,
			85, 170, 60, 40,
			hwnd, (HMENU)bt2, NULL, NULL
		);
		bt33 = CreateWindow(TEXT("button"), TEXT("3"),
			WS_VISIBLE | WS_CHILD,
			150, 170, 60, 40,
			hwnd, (HMENU)bt3, NULL, NULL
		);
		btMin = CreateWindow(TEXT("button"), TEXT("-"),
			WS_VISIBLE | WS_CHILD,
			215, 170, 60, 40,
			hwnd, (HMENU)Min, NULL, NULL
		);
		// ================================================
		bt00 = CreateWindow(TEXT("button"), TEXT("0"),
			WS_VISIBLE | WS_CHILD,
			20, 215, 60, 40,
			hwnd, (HMENU)bt0, NULL, NULL,
			);

		btDot = CreateWindow(TEXT("button"), TEXT("."),
			WS_VISIBLE | WS_CHILD,
			85, 215, 60, 40,
			hwnd, (HMENU)dot, NULL, NULL
		);
		btPlu = CreateWindow(TEXT("button"), TEXT("+"),
			WS_VISIBLE | WS_CHILD,
			150, 215, 60, 40,
			hwnd, (HMENU)Plu, NULL, NULL
		);
		btTotal = CreateWindow(TEXT("button"), TEXT("="),
			WS_VISIBLE | WS_CHILD,
			215, 215, 60, 40,
			hwnd, (HMENU)Total, NULL, NULL
		);
		// ================================================

		//edit11 = CreateWindow(TEXT("edit"), TEXT(""),
		//	WS_VISIBLE | WS_CHILD,
		//	0, 50, 80, 25,
		//	hwnd, (HMENU)edit1, NULL, NULL
		//);
		/*edit22 = CreateWindow(TEXT("edit"), TEXT(""),
		WS_VISIBLE | WS_CHILD,
		0, 100, 80, 25,
		hwnd, (HMENU)edit2, NULL, NULL
		);*/

		edit33 = CreateWindow(TEXT("edit"), TEXT(""),
			WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_RIGHT | ES_READONLY,
			20, 10, 255, 50,
			hwnd, (HMENU)edit3, NULL, NULL
		);

		break;

	case WM_COMMAND: {
		//char variable1[50] = "0", variable2[50] = "0", stotal[50] = "0";
		//int v1, v2, total;

		//v1 = atoi(variable1);
		//v2 = atoi(variable2);

		//if (LOWORD(wParam) == bt0)
		//{
		//	_itoa(total, stotal, 10);
		//	SendMessage((HWND)edit33, (UINT)EM_GETLINE, (WPARAM)1, (LPARAM)&stotal);
		//}



		//	if (LOWORD(wParam) == bt1) {
		//		total = v1 + v2;
		//		_itoa(total, stotal, 10);
		//		SendMessage((HWND)edit33, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&stotal);
		//	}
		//	if (LOWORD(wParam) == bt2) {
		//		total = v1 - v2;
		//		_itoa(total, stotal, 10);
		//		SendMessage((HWND)edit33, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&stotal);
		//	}
		//	if (LOWORD(wParam) == bt3) {
		//		total = v1 * v2;
		//		_itoa(total, stotal, 10);
		//		SendMessage((HWND)edit33, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&stotal);
		//	}
		//	if (LOWORD(wParam) == bt4) {
		//		total = v1 / v2;
		//		_itoa(total, stotal, 10);
		//		SendMessage((HWND)edit33, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&stotal);
	}
					 break;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
