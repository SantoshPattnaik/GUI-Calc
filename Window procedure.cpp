#include"Window procedure.h"

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

			SetWindowTextW(textView, buffer);
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