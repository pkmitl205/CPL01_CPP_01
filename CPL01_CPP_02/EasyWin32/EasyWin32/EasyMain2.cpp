//***************************************************//
//********* Pakon Ruchirekserikun 58030205 **********//
//***************************************************//

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
		SelectObject(hdc, CreateSolidBrush(RGB(204, 245, 39))); //Yellow
		RoundRect(hdc, 300, 285, 460, 370, 42, 38);
		SelectObject(hdc, CreateSolidBrush(RGB(113, 230, 89))); //Green
		RoundRect(hdc, 530, 285, 690, 370, 42, 38);
		SelectObject(hdc, CreateSolidBrush(RGB(250, 111, 92))); //Red
		RoundRect(hdc, 760, 285, 920, 370, 42, 38);
		SelectObject(hdc, CreateSolidBrush(RGB(250, 92, 245))); //Pink
		RoundRect(hdc, 990, 285, 1150, 370, 42, 38);

		SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255))); // White
		RoundRect(hdc, 70, 360, 230, 380, 43, 40);
		RoundRect(hdc, 300, 360, 460, 380, 43, 40);
		RoundRect(hdc, 530, 360, 690, 380, 43, 40);
		RoundRect(hdc, 760, 360, 920, 380, 43, 40);
		RoundRect(hdc, 990, 360, 1150, 380, 43, 40);

		SelectObject(hdc, CreateSolidBrush(RGB(53, 46, 255))); //Sky Blue
		RoundRect(hdc, 85, 280, 215, 450, 42, 38);
		SelectObject(hdc, CreateSolidBrush(RGB(204, 245, 39))); //Yellow
		RoundRect(hdc, 315, 280, 445, 450, 42, 38);
		SelectObject(hdc, CreateSolidBrush(RGB(113, 230, 89))); //Green
		RoundRect(hdc, 545, 280, 675, 450, 42, 38);
		SelectObject(hdc, CreateSolidBrush(RGB(250, 111, 92))); //Red
		RoundRect(hdc, 775, 280, 905, 450, 42, 38);
		SelectObject(hdc, CreateSolidBrush(RGB(250, 92, 245))); //Pink
		RoundRect(hdc, 1005, 280, 1135, 450, 42, 38);

		SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255))); // White
		Ellipse(hdc, 90, 260, 210, 420);
		Ellipse(hdc, 320, 260, 440, 420);
		Ellipse(hdc, 550, 260, 670, 420);
		Ellipse(hdc, 780, 260, 900, 420);
		Ellipse(hdc, 1010, 260, 1130, 420);

		//bag
		Ellipse(hdc, 100, 350, 200, 380);
		Ellipse(hdc, 330, 350, 430, 380);
		Ellipse(hdc, 560, 350, 660, 380);
		Ellipse(hdc, 790, 350, 890, 380);
		Ellipse(hdc, 1020, 350, 1120, 380);

		//leg
		MoveToEx(hdc, 150, 425, NULL); 
		LineTo(hdc, 150, 450);
		MoveToEx(hdc, 380, 425, NULL); 
		LineTo(hdc, 380, 450);
		MoveToEx(hdc, 610, 425, NULL); 
		LineTo(hdc, 610, 450);
		MoveToEx(hdc, 840, 425, NULL); 
		LineTo(hdc, 840, 450);
		MoveToEx(hdc, 1070, 425, NULL); 
		LineTo(hdc, 1070, 450);

		//**************** HEAD ****************//
		SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
		Ellipse(hdc, 70, 150, 230, 310);
		Ellipse(hdc, 300, 150, 460, 310);
		Ellipse(hdc, 530, 150, 690, 310);
		Ellipse(hdc, 760, 150, 920, 310);
		Ellipse(hdc, 990, 150, 1150, 310);
		
		
		SelectObject(hdc, CreateSolidBrush(RGB(53, 46, 255))); //Sky Blue
		Ellipse(hdc, 50, 100, 250, 300);
		SelectObject(hdc, CreateSolidBrush(RGB(204, 245, 39))); //Yellow
		Ellipse(hdc, 280, 100, 480, 300);
		SelectObject(hdc, CreateSolidBrush(RGB(113, 230, 89))); //Green
		Ellipse(hdc, 510, 100, 710, 300);
		SelectObject(hdc, CreateSolidBrush(RGB(250, 111, 92))); //Red
		Ellipse(hdc, 740, 100, 940, 300);
		SelectObject(hdc, CreateSolidBrush(RGB(250, 92, 245))); //Pink
		Ellipse(hdc, 970, 100, 1170, 300);

		SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255))); // White
		Ellipse(hdc, 60, 140, 240, 300);
		Ellipse(hdc, 290, 140, 470, 300);
		Ellipse(hdc, 520, 140, 700, 300);
		Ellipse(hdc, 750, 140, 930, 300);
		Ellipse(hdc, 980, 140, 1160, 300);

		SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255))); // White
		//Left Eye
		Ellipse(hdc, 100, 107, 150, 180);
		Ellipse(hdc, 330, 107, 380, 180);
		Ellipse(hdc, 560, 107, 610, 180);
		Ellipse(hdc, 790, 107, 840, 180);
		Ellipse(hdc, 1020, 107, 1070, 180);

		//Right Eye
		Ellipse(hdc, 150, 107, 200, 180);
		Ellipse(hdc, 380, 107, 430, 180);
		Ellipse(hdc, 610, 107, 660, 180);
		Ellipse(hdc, 840, 107, 890, 180);
		Ellipse(hdc, 1070, 107, 1120, 180);

		SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0))); // Black
		//Eye1
		Ellipse(hdc, 128, 130, 143, 150);
		Ellipse(hdc, 358, 130, 373, 150);
		Ellipse(hdc, 588, 130, 603, 150);
		Ellipse(hdc, 818, 130, 833, 150);
		Ellipse(hdc, 1048, 130, 1063, 150);
		//Eye2
		Ellipse(hdc, 158, 130, 173, 150); 
		Ellipse(hdc, 388, 130, 403, 150);
		Ellipse(hdc, 618, 130, 633, 150);
		Ellipse(hdc, 848, 130, 863, 150);
		Ellipse(hdc, 1078, 130, 1093, 150);

		//Nose
		SelectObject(hdc, CreateSolidBrush(RGB(255, 2, 5))); //Red
		Ellipse(hdc, 135, 155, 165, 185);
		Ellipse(hdc, 365, 155, 395, 185);
		Ellipse(hdc, 595, 155, 625, 185);
		Ellipse(hdc, 825, 155, 855, 185);
		Ellipse(hdc, 1055, 155, 1085, 185);

		SelectObject(hdc, CreateSolidBrush(RGB(255, 2, 5))); //Red
		MoveToEx(hdc, 150, 185, NULL);
		LineTo(hdc, 150, 240);
		MoveToEx(hdc, 380, 185, NULL);
		LineTo(hdc, 380, 240);
		MoveToEx(hdc, 610, 185, NULL);
		LineTo(hdc, 610, 240);
		MoveToEx(hdc, 840, 185, NULL);
		LineTo(hdc, 840, 240);
		MoveToEx(hdc, 1070, 185, NULL);
		LineTo(hdc, 1070, 240);

		//Mouth
		Ellipse(hdc, 140, 240, 160, 270);
		Ellipse(hdc, 370, 240, 390, 270);
		Ellipse(hdc, 600, 240, 620, 270);
		Ellipse(hdc, 830, 240, 850, 270);
		Ellipse(hdc, 1060, 240, 1080, 270);

		MoveToEx(hdc, 130, 195, NULL);
		LineTo(hdc, 80, 180);
		MoveToEx(hdc, 130, 200, NULL);
		LineTo(hdc, 80, 200);
		MoveToEx(hdc, 130, 205, NULL);
		LineTo(hdc, 80, 220);

		MoveToEx(hdc, 360, 195, NULL);
		LineTo(hdc, 310, 180);
		MoveToEx(hdc, 360, 200, NULL);
		LineTo(hdc, 310, 200);
		MoveToEx(hdc, 360, 205, NULL);
		LineTo(hdc, 310, 220);

		MoveToEx(hdc, 590, 195, NULL);
		LineTo(hdc, 540, 180);
		MoveToEx(hdc, 590, 200, NULL);
		LineTo(hdc, 540, 200);
		MoveToEx(hdc, 590, 205, NULL);
		LineTo(hdc, 540, 220);

		MoveToEx(hdc, 820, 195, NULL);
		LineTo(hdc, 770, 180);
		MoveToEx(hdc, 820, 200, NULL);
		LineTo(hdc, 770, 200);
		MoveToEx(hdc, 820, 205, NULL);
		LineTo(hdc, 770, 220);

		MoveToEx(hdc, 820, 195, NULL);
		LineTo(hdc, 770, 180);
		MoveToEx(hdc, 820, 200, NULL);
		LineTo(hdc, 770, 200);
		MoveToEx(hdc, 820, 205, NULL);
		LineTo(hdc, 770, 220);

		MoveToEx(hdc, 1050, 195, NULL);
		LineTo(hdc, 1000, 180);
		MoveToEx(hdc, 1050, 200, NULL);
		LineTo(hdc, 1000, 200);
		MoveToEx(hdc, 1050, 205, NULL);
		LineTo(hdc, 1000, 220);



		MoveToEx(hdc, 170, 195, NULL);
		LineTo(hdc, 220, 180);
		MoveToEx(hdc, 170, 200, NULL);
		LineTo(hdc, 220, 200);
		MoveToEx(hdc, 170, 205, NULL);
		LineTo(hdc, 220, 220);

		MoveToEx(hdc, 400, 195, NULL);
		LineTo(hdc, 450, 180);
		MoveToEx(hdc, 400, 200, NULL);
		LineTo(hdc, 450, 200);
		MoveToEx(hdc, 400, 205, NULL);
		LineTo(hdc, 450, 220);

		MoveToEx(hdc, 630, 195, NULL);
		LineTo(hdc, 680, 180);
		MoveToEx(hdc, 630, 200, NULL);
		LineTo(hdc, 680, 200);
		MoveToEx(hdc, 630, 205, NULL);
		LineTo(hdc, 680, 220);

		MoveToEx(hdc, 860, 195, NULL);
		LineTo(hdc, 910, 180);
		MoveToEx(hdc, 860, 200, NULL);
		LineTo(hdc, 910, 200);
		MoveToEx(hdc, 860, 205, NULL);
		LineTo(hdc, 910, 220);

		MoveToEx(hdc, 1090, 195, NULL);
		LineTo(hdc, 1140, 180);
		MoveToEx(hdc, 1090, 200, NULL);
		LineTo(hdc, 1140, 200);
		MoveToEx(hdc, 1090, 205, NULL);
		LineTo(hdc, 1140, 220);

		SelectObject(hdc, CreateSolidBrush(RGB(204, 245, 39))); //Yellow
		Ellipse(hdc, 135, 300, 165, 330); //bell
		Ellipse(hdc, 365, 300, 395, 330);
		Ellipse(hdc, 595, 300, 625, 330);
		Ellipse(hdc, 825, 300, 855, 330);
		Ellipse(hdc, 1055, 300, 1085, 330);

		SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255))); // White
		// Left Foot
		Ellipse(hdc, 80, 460, 150, 440); 
		Ellipse(hdc, 310, 460, 380, 440);
		Ellipse(hdc, 540, 460, 610, 440);
		Ellipse(hdc, 770, 460, 840, 440);
		Ellipse(hdc, 1000, 460, 1070, 440);
		// Right Foot
		Ellipse(hdc, 150, 460, 220, 440); 
		Ellipse(hdc, 380, 460, 450, 440);
		Ellipse(hdc, 610, 460, 680, 440);
		Ellipse(hdc, 840, 460, 910, 440);
		Ellipse(hdc, 1070, 460, 1140, 440);

		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
