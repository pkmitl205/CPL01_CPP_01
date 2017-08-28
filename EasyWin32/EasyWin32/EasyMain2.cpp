//================================================================================//
//==================== Pakon Ruchirekserikun 58030205 ============================//
//================================================================================//

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
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // Background color
	wc.lpszMenuName = NULL; // Menu name
	wc.lpszClassName = "MyWndClass"; // WNDCLASS name

	/***************** 2. Register the Windows class **********************/

	RegisterClass(&wc);

	/***************** 3. Create window **********************/
	hwnd = CreateWindow(
		"MyWndClass", // WNDCLASS name
		"SDK Application", // Window title
		WS_OVERLAPPEDWINDOW, // Window style
		CW_USEDEFAULT, // Horizontal position
		CW_USEDEFAULT, // Vertical position
		CW_USEDEFAULT, // Initial width
		CW_USEDEFAULT, // Initial height
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

		//******************** Doraemon Laboratory ********************//

		SelectObject(hdc, CreatePen(PS_SOLID, 2, RGB(0, 0, 0)));

		//**************** BODY ****************//


		SelectObject(hdc, CreateSolidBrush(RGB(53, 46, 255))); //Blue

		RoundRect(hdc, 70, 285, 230, 370, 42, 38);

		SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255))); // White
		RoundRect(hdc, 70, 360, 230, 380, 43, 40);

		SelectObject(hdc, CreateSolidBrush(RGB(53, 46, 255))); //Blue
		RoundRect(hdc, 85, 280, 215, 450, 42, 38);

		SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255))); // White

		Ellipse(hdc, 90, 260, 210, 420);

		Ellipse(hdc, 100, 350, 200, 380); //bag

		MoveToEx(hdc, 150, 425, NULL); //leg
		LineTo(hdc, 150, 450);

		//**************** HEAD ****************//
		SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
		Ellipse(hdc, 70, 150, 230, 310);
		SelectObject(hdc, CreateSolidBrush(RGB(53, 46, 255))); //Blue
		Ellipse(hdc, 50, 100, 250, 300);
		SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255))); // White
		Ellipse(hdc, 60, 140, 240, 300);

		SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255))); // White
		Ellipse(hdc, 100, 107, 150, 180); //Left Eye
		Ellipse(hdc, 150, 107, 200, 180); //Right Eye

		SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0))); // Black
		Ellipse(hdc, 128, 130, 143, 150); //Eye1
		Ellipse(hdc, 158, 130, 173, 150); //Eye2

		SelectObject(hdc, CreateSolidBrush(RGB(255, 2, 5))); //Red
		Ellipse(hdc, 135, 155, 165, 185); //Nose

		SelectObject(hdc, CreateSolidBrush(RGB(255, 2, 5))); //Red
		MoveToEx(hdc, 150, 185, NULL);
		LineTo(hdc, 150, 240);
		Ellipse(hdc, 140, 240, 160, 270); //Mouth

		MoveToEx(hdc, 130, 195, NULL);
		LineTo(hdc, 80, 180);
		MoveToEx(hdc, 130, 200, NULL);
		LineTo(hdc, 80, 200);
		MoveToEx(hdc, 130, 205, NULL);
		LineTo(hdc, 80, 220);

		MoveToEx(hdc, 170, 195, NULL);
		LineTo(hdc, 220, 180);
		MoveToEx(hdc, 170, 200, NULL);
		LineTo(hdc, 220, 200);
		MoveToEx(hdc, 170, 205, NULL);
		LineTo(hdc, 220, 220);

		SelectObject(hdc, CreateSolidBrush(RGB(204, 245, 39))); //Yellow
		Ellipse(hdc, 135, 300, 165, 330); //bell

		SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255))); // White
		Ellipse(hdc, 80, 460, 150, 440); // Left Foot
		Ellipse(hdc, 150, 460, 220, 440); // Right Foot


		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
