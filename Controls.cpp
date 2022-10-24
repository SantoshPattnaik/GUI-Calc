#include"Controls.h"

//HWND textView{}, op1{}, op2{};
void addControls(HWND handle) {
	textView = CreateWindowW(L"Static", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 100, 50, 1000, 100, handle, NULL, NULL, NULL);
	op1 = CreateWindowW(L"Static", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 100, 200, 90, 100, handle, NULL, NULL, NULL);
	op2 = CreateWindowW(L"Static", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 500, 200, 90, 100, handle, NULL, NULL, NULL);
	CreateWindowW(L"Button", L"Calculate", WS_VISIBLE | WS_CHILD, 650, 200, 70, 30, handle, (HMENU)DISPLAY, NULL, NULL);

	//operator buttons
	CreateWindowW(L"Button", L"+", WS_VISIBLE | WS_CHILD, 650, 240, 30, 30, handle, (HMENU)SUM, NULL, NULL);
	CreateWindowW(L"Button", L"-", WS_VISIBLE | WS_CHILD, 650, 280, 30, 30, handle, (HMENU)DIFF, NULL, NULL);
	CreateWindowW(L"Button", L"*", WS_VISIBLE | WS_CHILD, 650, 320, 30, 30, handle, (HMENU)MULT, NULL, NULL);
	CreateWindowW(L"Button", L"/", WS_VISIBLE | WS_CHILD, 650, 360, 30, 30, handle, (HMENU)QUOTIENT, NULL, NULL);

	//digit buttons
	CreateWindowW(L"Button", L"1", WS_VISIBLE | WS_CHILD, 690, 240, 30, 30, handle, (HMENU)1, NULL, NULL);
	CreateWindowW(L"Button", L"2", WS_VISIBLE | WS_CHILD, 730, 240, 30, 30, handle, (HMENU)2, NULL, NULL);
	CreateWindowW(L"Button", L"3", WS_VISIBLE | WS_CHILD, 770, 240, 30, 30, handle, (HMENU)3, NULL, NULL);
	CreateWindowW(L"Button", L"4", WS_VISIBLE | WS_CHILD, 690, 280, 30, 30, handle, (HMENU)4, NULL, NULL);
	CreateWindowW(L"Button", L"5", WS_VISIBLE | WS_CHILD, 730, 280, 30, 30, handle, (HMENU)5, NULL, NULL);
	CreateWindowW(L"Button", L"6", WS_VISIBLE | WS_CHILD, 770, 280, 30, 30, handle, (HMENU)6, NULL, NULL);
	CreateWindowW(L"Button", L"7", WS_VISIBLE | WS_CHILD, 690, 320, 30, 30, handle, (HMENU)7, NULL, NULL);
	CreateWindowW(L"Button", L"8", WS_VISIBLE | WS_CHILD, 730, 320, 30, 30, handle, (HMENU)8, NULL, NULL);
	CreateWindowW(L"Button", L"9", WS_VISIBLE | WS_CHILD, 770, 320, 30, 30, handle, (HMENU)9, NULL, NULL);
	CreateWindowW(L"Button", L"0", WS_VISIBLE | WS_CHILD, 730, 360, 30, 30, handle, (HMENU)0, NULL, NULL);
}
