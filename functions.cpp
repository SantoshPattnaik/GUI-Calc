#include"functions.h"

void calculate(HWND handle) {
	WCHAR input_field1[100]{}, input_field2[100]{}, _operator[5]{}, buffer[100]{};
	int result{};

	GetWindowTextW(input1, input_field1, 100);
	GetWindowTextW(input2, input_field2, 100);
	GetWindowTextW(op_symb, _operator, 5);

	if (wcscmp(input_field1, L"") != 0 && wcscmp(input_field2, L"") != 0 && wcscmp(_operator, L"") != 0) {
		if (wcscmp(_operator, L"+") == 0) {
			result = _wtoi(input_field1) + _wtoi(input_field2);
		}
		if (wcscmp(_operator, L"-") == 0) {
			result = _wtoi(input_field1) - _wtoi(input_field2);
		}
		if (wcscmp(_operator, L"X") == 0) {
			result = _wtoi(input_field1) * _wtoi(input_field2);
		}
		if (wcscmp(_operator, L"/") == 0) {
			if (_wtoi(input_field2) != 0) {
				result = _wtoi(input_field1) / _wtoi(input_field2);
			}
			else {
				MessageBox(handle, L"Divide By zero", L"Error", MB_OK);
			}
		}
	}
	wsprintf(buffer, L"%d", result);
	SetWindowTextW(textView, buffer);
}