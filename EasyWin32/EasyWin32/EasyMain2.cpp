#include <windows.h>

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);

int     	WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	WNDCLASS wc;
	HWND hwnd;
	MSG msg;
	/***************** 1. Define Windows class ****************************/
	wc.style = 0; // Class style
	wc.lpfnWndProc = (WNDPROC)WndProc; // Window procedure address
	wc.cbClsExtra = 0; // Class extra bytes
	wc.cbWndExtra = 0; // Window extra bytes
	wc.hInstance = hInstance; // Instance handle
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO); // Icon handle
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Cursor handle
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 0); // Background color
	wc.lpszMenuName = NULL; // Menu name
	wc.lpszClassName = "MyWndClass"; // WNDCLASS name

	/***************** 2. Register the Windows class **********************/

	RegisterClass(&wc);

	/***************** 3. Create window **********************/
	hwnd = CreateWindow(
		"MyWndClass", // WNDCLASS name
		"CPL01_CPP_02", // Window title
		WS_OVERLAPPEDWINDOW, // Window style
		600, // Horizontal position
		600, // Vertical position
		600, // Initial width
		600, // Initial height
		HWND_DESKTOP, // Handle of parent window
		NULL, // Menu handle
		hInstance, // Application's instance handle
		NULL // Window-creation data
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


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam,
	LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) {

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Ellipse(hdc, 10, 10, 200, 100);
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
