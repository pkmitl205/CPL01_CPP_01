#include<windows.h>
#include"DrawBall.h"
void DrawBall(HWND hWnd, int nXSize, int nYSize)
{
	HDC hDC;
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	static int nX = 2 * BALLRAD, nY = 2 * BALLRAD, nVelX = VELOCITY, nVelY = VELOCITY;

	nXSize = GetSystemMetrics(SM_CXSCREEN);
	nYSize = GetSystemMetrics(SM_CYSCREEN);

	nX = nX + nVelX;
	nY = nY + nVelY;

	if (nY>nYSize) nY = 2 * BALLRAD;
	if (nX>nXSize) nX = 2 * BALLRAD;
	if ((nY<MINRAD) || (nYSize - nY<MINRAD))
	{
		nVelY = -1 * nVelY;
	}
	else
	{
		if ((nX<MINRAD) || (nXSize - nX<MINRAD))
		{
			nVelX = -1 * nVelX;
		}
	}

	hDC = GetDC(hWnd);
	hPen = CreatePen(PS_SOLID, VELOCITY + VELOCITY / 2, RGB(255, 255, 255));
	hBrush = CreateSolidBrush(RGB(255, 0, 0));
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	Ellipse(hDC, nX - BALLRAD, nY - BALLRAD, nX + BALLRAD, nY + BALLRAD);

	SelectObject(hDC, hOldPen);
	DeleteObject(hPen);
	hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	hOldPen = (HPEN)SelectObject(hDC, hPen);

	Rectangle(hDC, nX + BALLRAD / 3, nY - BALLRAD / 3, nX + 2 + BALLRAD / 3, nY - 2 - BALLRAD / 3);

	SelectObject(hDC, hOldPen);
	DeleteObject(hPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hBrush);
	ReleaseDC(hWnd, hDC);
}
