#include"Window procedure.h"
#include<windows.h>

INT WINAPI WinMain(_In_ HINSTANCE hinstance,_In_opt_ HINSTANCE,_In_ LPSTR args,_In_ int nCmdShow) {
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
