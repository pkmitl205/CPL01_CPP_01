//***************************************************//
//********* Pakon Ruchirekserikun 58030205 **********//
//***************************************************//

#include <windows.h>
#include <cstdlib>
#include <iostream>

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
		400, // Initial width
		400, // Initial height
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


#define bt1 1
#define bt2 2
#define bt3 3
#define bt4 4
#define edit1 5
#define edit2 6
#define edit3 7

HWND bt11, bt22, bt33, bt44, edit11, edit22, edit33;

PAINTSTRUCT ps;
HDC hdc;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam,
	LPARAM lParam)
{

	switch (message) {

	case WM_CREATE:
	{
		bt11 = CreateWindow(TEXT("button"), TEXT("plus( + )"),
			WS_VISIBLE | WS_CHILD,
			0, 10, 80, 25,
			hwnd, (HMENU)bt1, NULL, NULL
		);
		bt22 = CreateWindow(TEXT("button"), TEXT("minus( - )"),
			WS_VISIBLE | WS_CHILD,
			100, 10, 80, 25,
			hwnd, (HMENU)bt2, NULL, NULL
		);
		bt33 = CreateWindow(TEXT("button"), TEXT("multiple( * )"),
			WS_VISIBLE | WS_CHILD,
			200, 10, 80, 25,
			hwnd, (HMENU)bt3, NULL, NULL
		);
		bt44 = CreateWindow(TEXT("button"), TEXT("divided( / )"),
			WS_VISIBLE | WS_CHILD,
			300, 10, 80, 25,
			hwnd, (HMENU)bt4, NULL, NULL
		);
		edit11 = CreateWindow(TEXT("edit"), TEXT(""),
			WS_VISIBLE | WS_CHILD,
			0, 50, 80, 25,
			hwnd, (HMENU)edit1, NULL, NULL
		);
		edit22 = CreateWindow(TEXT("edit"), TEXT(""),
			WS_VISIBLE | WS_CHILD,
			0, 100, 80, 25,
			hwnd, (HMENU)edit2, NULL, NULL
		);
		edit33 = CreateWindow(TEXT("edit"), TEXT(""),
			WS_VISIBLE | WS_CHILD,
			0, 150, 80, 25,
			hwnd, (HMENU)edit3, NULL, NULL
		);
		break;
	}
	case WM_COMMAND: {
		char variable1[50] = "0", variable2[50] = "0", stotal[50] = "0";
		int v1, v2, total;

		SendMessage((HWND)edit11, (UINT)EM_GETLINE, (WPARAM)1, (LPARAM)&variable1);
		SendMessage((HWND)edit22, (UINT)EM_GETLINE, (WPARAM)1, (LPARAM)&variable2);

		v1 = atoi(variable1);
		v2 = atoi(variable2);

		if (LOWORD(wParam) == bt1) {
			total = v1 + v2;
			_itoa(total, stotal, 10);
			SendMessage((HWND)edit33, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&stotal);
		}
		if (LOWORD(wParam) == bt2) {
			total = v1 - v2;
			_itoa(total, stotal, 10);
			SendMessage((HWND)edit33, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&stotal);
		}
		if (LOWORD(wParam) == bt3) {
			total = v1 * v2;
			_itoa(total, stotal, 10);
			SendMessage((HWND)edit33, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&stotal);
		}
		if (LOWORD(wParam) == bt4) {
			total = v1 / v2;
			_itoa(total, stotal, 10);
			SendMessage((HWND)edit33, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&stotal);
		}
		break;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
