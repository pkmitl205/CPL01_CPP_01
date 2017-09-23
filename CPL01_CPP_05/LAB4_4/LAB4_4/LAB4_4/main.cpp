// =================================================
// =================================================
// ===	### PHAKON RUCHIREKSERIKUN 58030205 ###  ===
// =================================================
// =================================================

#include <windows.h>
#include <cstdio>
#include <cmath>
#include <string>

#define SPACE  " "

// ====================================
// ### Global Variables ###
// ====================================

static HINSTANCE L4_hInstance;
static HWND    Form1, Edit1;

static char    L4_ClassName[2048];

static int     L4_ScaleX, L4_ScaleY;
static double  Op1, Op2;
static long    OpFlag, EqFlag, Code;


// ======================================
// ### Macros used###
// ======================================

#define Show(Window) RedrawWindow(Window,0,0,0);ShowWindow(Window,SW_SHOW);
#define VAL(a) (double)atof(a)

int     str_cmp(char*, char*);
HWND    L4_Form(char*, int = 0, int = 0, int = 250, int = 150, int = 0, int = 0);
HWND    L4_Edit(char*, HWND, int, int, int, int, int, int = 0, int = -1);
HWND    L4_Button(char*, HWND, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = -1);
char*   L4_Get_Text(HWND);
int     L4_Set_Text(HWND, char*);
HFONT   L4_Set_Font(char *, int, int = 0, int = 0, int = 0, int = 0);
LRESULT Set_Color(int, int, int, int);
char*   L4_TmpStr(size_t);
char*   trim(char*);
char*   str(double);
int     instr(char*, char*, int = 0, int = 0);
char    *_stristr_(char*, char*);

void    FormLoad(void);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void    ProcessNumber(int);
void    ProcessOperator(int);

// ======================================
// ### Standard main form Windows GUI ###
// ======================================

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR CmdLine, int CmdShow)
{
	WNDCLASS wc;
	MSG      Msg;
	// ====================================
	strcpy(L4_ClassName, "LAB4_CAL");

	// ====================================
	// Scale Dialog Units To Screen Units
	// ====================================

	RECT rc = { 0,0,4,8 };
	MapDialogRect(NULL, &rc);
	L4_ScaleX = rc.right / 2;
	L4_ScaleY = rc.bottom / 4;
	L4_hInstance = hInst;
	// ====================================
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = L4_ClassName;
	RegisterClass(&wc);

	FormLoad();

	// ========================================================
	// ### Message Loop, Windows GUI Functions Via Messages ###
	// ========================================================

	while (GetMessage(&Msg, NULL, 0, 0))
	{
		HWND hActiveWindow = GetActiveWindow();
		if (!IsWindow(hActiveWindow) || !IsDialogMessage(hActiveWindow, &Msg))
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
	}
	return Msg.wParam;
}

// ================================================
// ### Circular Storage To Prevent Memory Leaks ###
// ================================================

char *L4_TmpStr(size_t Bites)
{
	static int   StrCnt;
	static char *StrFunc[2048];
	StrCnt = (StrCnt + 1) & 2047;
	if (StrFunc[StrCnt]) free(StrFunc[StrCnt]);
	return StrFunc[StrCnt] = (char*)calloc(Bites + 128, sizeof(char));
}

// ============================
// ### fancy string compare ###
// ============================
int str_cmp(char *a, char *b)
{
	register int counter;
	counter = counter^counter;
	while (1)
	{
		if ((a[counter] ^ b[counter]))
		{
			if ((UINT)a[counter] >= (UINT)b[counter])
			{
				return  1;
			}
			return -1;
		}
		if (!a[counter]) return 0;
		counter++;
	}
	return 0;
}


// ======================================================
// ### remove certain leading and trailing characters ###
// ======================================================

char *trim(char *S)
{
	register int i = strlen(S);
	char *strtmp = L4_TmpStr(i);
	strcpy(strtmp, S);
	while (i--)
	{
		if (S[i] != 0 &&
			S[i] != 9 &&
			S[i] != 10 &&
			S[i] != 11 &&
			S[i] != 13 &&
			S[i] != 32) break;
	}
	strtmp[++i] = 0;
	if (strtmp)
	{
		while (*(strtmp + 1) &&
			*strtmp == '\x00' ||
			*strtmp == '\x09' ||
			*strtmp == '\x0A' ||
			*strtmp == '\x0B' ||
			*strtmp == '\x0D' ||
			(*strtmp == '\x20'))
			strtmp++;
	}
	return strtmp;
}

// =====================
// ### sets accuracy ###
// =====================

char *str(double d)
{
	register char *strtmp = L4_TmpStr(16);
	sprintf(strtmp, "% .15G", d);
	return strtmp;
}

// =====================================================================
// ### returns the position where a substring is located in a string ###
// =====================================================================

int instr(char* mane, char* match, int offset, int sensflag)
{
	register char *s;
	if (!mane || !match || !*match || offset>(int)strlen(mane)) return 0;
	if (sensflag)
		s = _stristr_(offset>0 ? mane + offset - 1 : mane, match);
	else
		s = strstr(offset>0 ? mane + offset - 1 : mane, match);
	return s ? (int)(s - mane) + 1 : 0;
}

// ========================
// ### supports instr() ###
// ========================

char *_stristr_(char *String, char *Pattern)
{
	register char *pptr, *sptr, *start;
	register UINT  slen, plen;
	for (start = (char *)String,
		pptr = (char *)Pattern,
		slen = strlen(String),
		plen = strlen(Pattern);
		slen >= plen;
		start++, slen--)
	{
		while (toupper(*start) != toupper(*Pattern))
		{
			start++;
			slen--;
			if (slen < plen) return(0);
		}
		sptr = start;
		pptr = (char *)Pattern;
		while (toupper(*sptr) == toupper(*pptr))
		{
			sptr++;
			pptr++;
			if (!*pptr) return (start);
		}
	}
	return(0);
}

// ========================
// ### created the form ##
// ========================

HWND L4_Form(char *Caption, int X, int Y, int W, int H, int Style, int Exstyle)
{
	HWND  A;
	// assign default style
	if (!Style)
	{
		Style = WS_MINIMIZEBOX |
			WS_SIZEBOX |
			WS_CAPTION |
			WS_MAXIMIZEBOX |
			WS_POPUP |
			WS_SYSMENU;
	}
	A = CreateWindowEx(Exstyle, L4_ClassName, Caption,
		Style,
		X*L4_ScaleX,
		Y*L4_ScaleY,
		(4 + W)*L4_ScaleX,
		(12 + H)*L4_ScaleY,
		NULL, (HMENU)NULL, L4_hInstance, NULL);
	SendMessage(A, (UINT)WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT),
		(LPARAM)MAKELPARAM(FALSE, 0));
	return A;
}


// create the various calculator buttons
HWND L4_Button
(char* Text, HWND hWnd, int id, int X, int Y, int W, int H, int Style, int Exstyle)
{
	HWND  A;
	// assign default style
	if (!Style)
	{
		Style = WS_CHILD | WS_VISIBLE | BS_MULTILINE | BS_PUSHBUTTON | WS_TABSTOP;
	}
	if (Exstyle == -1)
	{
		Exstyle = WS_EX_STATICEDGE;
	}
	A = CreateWindowEx(Exstyle, "button", Text, Style,
		X*L4_ScaleX, Y*L4_ScaleY, W*L4_ScaleX, H*L4_ScaleY,
		hWnd, (HMENU)id, L4_hInstance, NULL);
	SendMessage(A, (UINT)WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), //Font Button
		(LPARAM)MAKELPARAM(FALSE, 0));
	if (W == 0)
	{
		HDC  hdc = GetDC(A);
		SIZE  size;
		GetTextExtentPoint32(hdc, Text, strlen(Text), &size);
		ReleaseDC(A, hdc);
		MoveWindow(A, X*L4_ScaleX, Y*L4_ScaleY, (int)(size.cx + (size.cx*0.5)), (int)(size.cy + (size.cy*0.32
			)), TRUE);
	}
	return A;
}


// create the edit box to display entry and result
HWND L4_Edit
(char* Text, HWND hWnd, int id, int X, int Y, int W, int H, int Style, int Exstyle)
{
	HWND  A;
	// assign default style
	if (!Style)
	{
		Style = WS_CHILD | WS_VISIBLE | ES_WANTRETURN | ES_MULTILINE | ES_RIGHT;
	}
	if (Exstyle == -1)
	{
		Exstyle = WS_EX_CLIENTEDGE;
	}
	A = CreateWindowEx(Exstyle, "edit", Text, Style,
		X*L4_ScaleX, Y*L4_ScaleY, W*L4_ScaleX, H*L4_ScaleY,
		hWnd, (HMENU)id, L4_hInstance, NULL);

	SendMessage(A, (UINT)WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT),
		(LPARAM)MAKELPARAM(FALSE, 0));
	return A;
}


char *L4_Get_Text(HWND hWnd)
{
	int tmpint;
	tmpint = 1 + GetWindowTextLength(hWnd);
	char *strtmp = L4_TmpStr(tmpint);
	GetWindowText(hWnd, strtmp, tmpint);
	return strtmp;
}


int L4_Set_Text(HWND hWnd, char *Text)
{
	return SetWindowText(hWnd, Text);
}


LRESULT Set_Color(int TxtColr, int BkColr, int wParam, int lParam)
{
	static HBRUSH  ReUsableBrush;
	DeleteObject(ReUsableBrush);
	ReUsableBrush = CreateSolidBrush(BkColr);
	SetTextColor((HDC)wParam, TxtColr);
	SetBkColor((HDC)wParam, BkColr);
	return (LRESULT)ReUsableBrush;
}


HFONT L4_Set_Font(char *Font, int Size, int Bold, int Italic, int Underline, int StrikeThru)
{
	HDC hDC = GetDC(HWND_DESKTOP);
	int CyPixels = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(HWND_DESKTOP, hDC);
	return CreateFont(0 - (Size*CyPixels) / 72, 0, 0, 0, Bold, Italic, Underline, StrikeThru,
		0, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, Font);
}


// details like corner coordinates,width,length,text,font

void FormLoad(void)
{
	Form1 = L4_Form("LAB4_Calculator", 67, 0, 165, 200);
	Edit1 = L4_Edit(SPACE, Form1, 99, 5, 7, 150, 30);
	SendMessage(Edit1, (UINT)WM_SETFONT, (WPARAM)L4_Set_Font("Verdana", 20), 1);

	L4_Button("0", Form1, 100, 5, 165, 25, 25);
	L4_Button("1", Form1, 101, 5, 135, 25, 25);
	L4_Button("2", Form1, 102, 35, 135, 25, 25);
	L4_Button("3", Form1, 103, 65, 135, 25, 25);
	L4_Button("4", Form1, 104, 5, 105, 25, 25);
	L4_Button("5", Form1, 105, 35, 105, 25, 25);
	L4_Button("6", Form1, 106, 65, 105, 25, 25);
	L4_Button("7", Form1, 107, 5, 75, 25, 25);
	L4_Button("8", Form1, 108, 35, 75, 25, 25);
	L4_Button("9", Form1, 109, 65, 75, 25, 25);
	L4_Button(".", Form1, 110, 35, 165, 25, 25);
	L4_Button("CE", Form1, 112, 5, 45, 25, 25);
	L4_Button("-", Form1, 113, 95, 105, 25, 25);
	L4_Button("/", Form1, 114, 95, 45, 25, 25);
	L4_Button("%", Form1, 115, 130, 75, 25, 25);
	L4_Button("C", Form1, 116, 35, 45, 25, 25);
	L4_Button("+", Form1, 117, 95, 135, 25, 55);
	L4_Button("X", Form1, 118, 95, 75, 25, 25);
	L4_Button("=", Form1, 119, 65, 165, 25, 25);
	L4_Button("1/X", Form1, 120, 130, 105, 25, 25);
	L4_Button("X^2", Form1, 121, 130, 135, 25, 25);
	L4_Button("Sqr", Form1, 122, 130, 165, 25, 25);
	L4_Button("+/-", Form1, 123, 65, 45, 25, 25
	);

	Show(Form1);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	while (1)
	{
		if (LOWORD(wParam)>99 && LOWORD(wParam)<110)
		{
			ProcessNumber(LOWORD(wParam) - 100);
			break;
		}
		if (LOWORD(wParam)>109)
		{
			ProcessOperator(LOWORD(wParam));
		}
		break;
	}
	if ((HWND)lParam == Edit1 && Msg == WM_CTLCOLOREDIT)
		return Set_Color(RGB(0, 250, 0), RGB(0, 0, 0), wParam, lParam); //Color EditText
																		// tidy up and exit program
	if (Msg == WM_DESTROY)
	{
		UnregisterClass(L4_ClassName, L4_hInstance);
		PostQuitMessage(0);
	}
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}


void ProcessNumber(int Digit)
{
	char A[2048];
	strcpy(A, (char*)L4_Get_Text(Edit1));
	if (str_cmp(A, SPACE) == 0)
	{
		*A = 0;
	}
	if (EqFlag)
	{
		*A = 0;
		EqFlag = FALSE;
	}
	if (OpFlag)
	{
		*A = 0;
		L4_Set_Text(Edit1, "");
		OpFlag = FALSE;
	}
	sprintf(A, "%s%s", A, trim(str(Digit)));
	L4_Set_Text(Edit1, A);
}


void ProcessOperator(int Operator)
{
	char A[2048];
	strcpy(A, (char*)L4_Get_Text(Edit1));
	if (str_cmp(A, SPACE) == 0)
	{
		*A = 0;
	}
	while (1)
	{
		if (Operator == 110)   //  .   period
		{
			if (EqFlag)
			{
				*A = 0;
				EqFlag = FALSE;
			}
			if (OpFlag)
			{
				*A = 0;
				L4_Set_Text(Edit1, "");
				OpFlag = FALSE;
			}
			if (instr(A, ".") == 0)
			{
				sprintf(A, "%s%s", A, ".");
			}
			L4_Set_Text(Edit1, A);
			break;
		}
		if (Operator == 112)     // CE   clear last entry
		{
			L4_Set_Text(Edit1, SPACE);
			EqFlag = FALSE;
			break;
		}
		if (Operator == 113)     // -   subtract
		{
			Op1 = VAL(L4_Get_Text(Edit1));
			Code = 4;
			OpFlag = TRUE;
			EqFlag = FALSE;
			break;
		}
		if (Operator == 114)      //  /   divide
		{
			Op1 = VAL(L4_Get_Text(Edit1));
			Code = 2;
			OpFlag = TRUE;
			EqFlag = FALSE;
			break;
		}
		if (Operator == 115)     //  %  percent to decimal
		{
			Op2 = VAL(L4_Get_Text(Edit1)) / 100;
			L4_Set_Text(Edit1, trim(str(Op2)));
			EqFlag = FALSE;
			break;
		}
		if (Operator == 116)      //  C   clear all
		{
			L4_Set_Text(Edit1, SPACE);
			Op1 = 0;
			Op2 = 0;
			Code = 0;
			EqFlag = FALSE;
			break;
		}
		if (Operator == 117)      //  +   add
		{
			Op1 = VAL(L4_Get_Text(Edit1));
			Code = 3;
			OpFlag = TRUE;
			EqFlag = FALSE;
			break;
		}
		if (Operator == 118)     //  x    multiply
		{
			Op1 = VAL(L4_Get_Text(Edit1));
			Code = 1;
			OpFlag = TRUE;
			EqFlag = FALSE;
			break;
		}
		if (Operator == 119)       //  =  equals
		{
			Op2 = VAL(L4_Get_Text(Edit1));
			OpFlag = FALSE;
			EqFlag = TRUE;
			while (1)
			{
				if (Code == 1)
				{
					Op1 *= Op2;
					break;
				}
				if (Code == 2)
				{
					Op1 /= Op2;
					break;
				}
				if (Code == 3)
				{
					Op1 += Op2;
					break;
				}
				if (Code == 4)
				{
					Op1 -= Op2;
				}
				break;
			}
			strcpy(A, (char*)trim(str(Op1)));
			if (instr(A, "INFINITY"))
			{
				strcpy(A, "ERROR: DIVISON BY ZERO");
			}
			L4_Set_Text(Edit1, A);
			Op2 = 0;
			break;
		}
		if (Operator == 120)     //  1/x   invert
		{
			L4_Set_Text(Edit1, str(1 / VAL(L4_Get_Text(Edit1))));
			OpFlag = TRUE;
			EqFlag = FALSE;
			break;
		}
		if (Operator == 121)     //   x^2    square
		{
			L4_Set_Text(Edit1, str(VAL(L4_Get_Text(Edit1))*VAL(L4_Get_Text(Edit1))));
			OpFlag = TRUE;
			EqFlag = FALSE;
			break;
		}
		if (Operator == 122)     //  sqrt   square-root
		{
			L4_Set_Text(Edit1, str(sqrt(VAL(L4_Get_Text(Edit1)))));
			OpFlag = TRUE;
			EqFlag = FALSE;
			break;
		}
		if (Operator == 123)     //  neg = negate
		{
			L4_Set_Text(Edit1, str(-1 * VAL(L4_Get_Text(Edit1))));
			OpFlag = TRUE;
			EqFlag = FALSE;
		}
		break;
	}
}
