#include<windows.h>

constexpr int DISPLAY = 1 ;
constexpr int SUM = 2 ;
constexpr int DIFF = 3 ;
constexpr int MULT = 4 ;
constexpr int QUOTIENT = 5 ;
HWND textView, op1, op2;

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void addControls(HWND);

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE, LPSTR args, int nCmdShow) {
	WNDCLASSW wc{};
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = L"Window Class";
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpfnWndProc = WindowProcedure;
	wc.hInstance = hinstance;

	if (!RegisterClassW(&wc)) {
		return -1;
	}

	CreateWindowW(
		L"Window Class",
		L"GUI Calculator",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		NULL,
		NULL);

	MSG msg{};
	while (GetMessageW(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	return EXIT_SUCCESS;
}

LRESULT CALLBACK WindowProcedure(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_COMMAND:
		switch (wParam) {
			int result;
			WCHAR operand1[100], operand2[100];
			WCHAR buffer[100];
		case SUM:
			GetWindowTextW(op1, operand1, 100);
			GetWindowTextW(op2, operand2, 100);
			
			result = _wtoi(operand1) + _wtoi(operand2);

			wsprintf(buffer, L"%d", result);

			SetWindowTextW(textView,buffer);
			break;
		case DIFF:
			GetWindowTextW(op1, operand1, 100);
			GetWindowTextW(op2, operand2, 100);

			result = _wtoi(operand1) - _wtoi(operand2);

			wsprintf(buffer, L"%d", result);

			SetWindowTextW(textView, buffer);
			break;
		case MULT:
			GetWindowTextW(op1, operand1, 100);
			GetWindowTextW(op2, operand2, 100);

			result = _wtoi(operand1) * _wtoi(operand2);

			wsprintf(buffer, L"%d", result);

			SetWindowTextW(textView, buffer);
			break;
		case QUOTIENT:
			GetWindowTextW(op1, operand1, 100);
			GetWindowTextW(op2, operand2, 100);

			result = _wtoi(operand1) / _wtoi(operand2);

			wsprintf(buffer, L"%d", result);

			SetWindowTextW(textView, buffer);
			break;
		}
		break;
	case WM_CREATE:
		addControls(handle);
		break;
	case WM_DESTROY:
		PostQuitMessage(EXIT_SUCCESS);
		break;
	default:
		return DefWindowProcW(handle, msg, wParam, lParam);
	}
}

void addControls(HWND handle) {
	textView=CreateWindowW(L"Edit", L"", WS_CHILD | WS_VISIBLE|WS_BORDER|ES_CENTER, 100, 50, 1000, 100, handle, NULL, NULL, NULL);
	op1=CreateWindowW(L"Edit", L"", WS_CHILD | WS_VISIBLE|WS_BORDER|ES_CENTER, 100, 200,90, 100, handle, NULL, NULL, NULL);
	op2=CreateWindowW(L"Edit", L"", WS_CHILD | WS_VISIBLE|WS_BORDER|ES_CENTER, 500, 200,90, 100, handle, NULL, NULL, NULL);
	CreateWindowW(L"Button", L"Calculate", WS_VISIBLE | WS_CHILD, 650, 200, 70, 30, handle, (HMENU)DISPLAY, NULL, NULL);

	//operator buttons
	CreateWindowW(L"Button", L"+", WS_VISIBLE | WS_CHILD, 650, 240, 30, 30, handle, (HMENU)SUM, NULL, NULL);
	CreateWindowW(L"Button", L"-", WS_VISIBLE | WS_CHILD, 650, 280, 30, 30, handle, (HMENU)DIFF, NULL, NULL);
	CreateWindowW(L"Button", L"*", WS_VISIBLE | WS_CHILD, 650, 320, 30, 30, handle, (HMENU)MULT, NULL, NULL);
	CreateWindowW(L"Button", L"/", WS_VISIBLE | WS_CHILD, 650, 360, 30, 30, handle, (HMENU)QUOTIENT, NULL, NULL);
}
