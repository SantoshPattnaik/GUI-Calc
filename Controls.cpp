#include"Controls.h"

/// <summary>
/// This function contains all the controls as child windows which are used in the main window
/// </summary>
/// <param name="handle"></param>

void addControls(HWND handle) {
	textView = CreateWindowW(L"Static", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 50, 150, 100, handle, NULL, NULL, NULL);

	input1 = CreateWindowW(L"Static", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 100, 200, 90, 100, handle, NULL, NULL, NULL);
	op_symb = CreateWindowW(L"Static", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 280, 200, 80, 100, handle, NULL, NULL, NULL);
	input2 = CreateWindowW(L"Static", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 500, 200, 90, 100, handle, NULL, NULL, NULL);
	CreateWindowW(L"Button", L"Calculate", WS_VISIBLE | WS_CHILD, 650, 200, 70, 30, handle, (HMENU)DISPLAY, NULL, NULL);

	//operator buttons
	CreateWindowW(L"Button", L"+", WS_VISIBLE | WS_CHILD, 650, 240, 30, 30, handle, (HMENU)SUM, NULL, NULL);
	CreateWindowW(L"Button", L"-", WS_VISIBLE | WS_CHILD, 650, 280, 30, 30, handle, (HMENU)DIFF, NULL, NULL);
	CreateWindowW(L"Button", L"*", WS_VISIBLE | WS_CHILD, 650, 320, 30, 30, handle, (HMENU)MULT, NULL, NULL);
	CreateWindowW(L"Button", L"/", WS_VISIBLE | WS_CHILD, 650, 360, 30, 30, handle, (HMENU)QUOTIENT, NULL, NULL);

	//digit buttons
	btn1 = CreateWindowW(L"Button", L"1", WS_VISIBLE | WS_CHILD, 690, 240, 30, 30, handle, (HMENU)1, NULL, NULL);
	btn2 = CreateWindowW(L"Button", L"2", WS_VISIBLE | WS_CHILD, 730, 240, 30, 30, handle, (HMENU)2, NULL, NULL);
	btn3 = CreateWindowW(L"Button", L"3", WS_VISIBLE | WS_CHILD, 770, 240, 30, 30, handle, (HMENU)3, NULL, NULL);
	btn4 = CreateWindowW(L"Button", L"4", WS_VISIBLE | WS_CHILD, 690, 280, 30, 30, handle, (HMENU)4, NULL, NULL);
	btn5 = CreateWindowW(L"Button", L"5", WS_VISIBLE | WS_CHILD, 730, 280, 30, 30, handle, (HMENU)5, NULL, NULL);
	btn6 = CreateWindowW(L"Button", L"6", WS_VISIBLE | WS_CHILD, 770, 280, 30, 30, handle, (HMENU)6, NULL, NULL);
	btn7 = CreateWindowW(L"Button", L"7", WS_VISIBLE | WS_CHILD, 690, 320, 30, 30, handle, (HMENU)7, NULL, NULL);
	btn8 = CreateWindowW(L"Button", L"8", WS_VISIBLE | WS_CHILD, 730, 320, 30, 30, handle, (HMENU)8, NULL, NULL);
	btn9 = CreateWindowW(L"Button", L"9", WS_VISIBLE | WS_CHILD, 770, 320, 30, 30, handle, (HMENU)9, NULL, NULL);
	btn0 = CreateWindowW(L"Button", L"0", WS_VISIBLE | WS_CHILD, 730, 360, 30, 30, handle, (HMENU)0, NULL, NULL);

	testing = CreateWindowW(L"Button", L"0", WS_VISIBLE | WS_CHILD, 730, 460, 30, 30, handle, (HMENU)TESTING, NULL, NULL);
}
