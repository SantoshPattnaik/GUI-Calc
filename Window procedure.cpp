#include"Window procedure.h"
#include"functions.h"
#include<stdio.h>
#include<algorithm>
/*
* This file contains the window procedure of the main application window
*
* wsprintf() function is used to convert integer to LPCWSTR form
* _wtoi() function is used to convert wchar_t type text recieved as input from edit box
*
* Exception handling is intentional left
*/
LRESULT CALLBACK WindowProcedure(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam) {
	int result{};
	WCHAR string[100]{};
	WCHAR operand1[100]{}, operand2[100]{};
	WCHAR buffer[100]{};
	WCHAR temp1[100]{};
	WCHAR temp2[100]{};
	WCHAR symbol[5]{};
	WCHAR _symbol[5]{};
	switch (msg) {
	case WM_COMMAND:
		Beep(100, 100);
		GetWindowTextW(op_symb, symbol, 5);
		//checking if symbol is empty
		if (wcscmp(symbol, L"") == 0) {
			if (wParam == 0 || wParam == 1 || wParam == 2 || wParam == 3 || wParam == 4 || wParam == 5 || wParam == 6 || wParam == 7 || wParam == 8 || wParam == 9) {
				GetWindowTextW(input1, operand1, 100);
				if (wcscmp(operand1, L"") == 0) {
					wsprintf(buffer, L"%d", (int)wParam);
					SetWindowTextW(input1, buffer);
				}
				else {
					//GetWindowTextW(input1, operand1, 100);
					wsprintf(temp1, L"%d", (int)wParam);
					wcscat_s(operand1, 100, temp1);
					SetWindowTextW(input1, operand1);
				}
			}
			if (wParam == SUM || wParam == DIFF || wParam == MULT || wParam == QUOTIENT) {
				if (wParam == SUM) {
					wcscat_s(symbol, 5, L"+");
				}
				else if (wParam == DIFF) {
					wcscat_s(symbol, 5, L"-");
				}
				else if (wParam == MULT) {
					wcscat_s(symbol, 5, L"X");
				}
				else if (wParam == QUOTIENT) {
					wcscat_s(symbol, 5, L"/");
				}
				SetWindowTextW(op_symb, symbol);
			}
		}
		else {
			if (wParam == SUM || wParam == DIFF || wParam == MULT || wParam == QUOTIENT) {
				//resetting symbol variable
				std::fill(std::begin(symbol), std::end(symbol), 0);

				if (wParam == SUM) {
					wcscat_s(symbol, 5, L"+");
				}
				else if (wParam == DIFF) {
					wcscat_s(symbol, 5, L"-");
				}
				else if (wParam == MULT) {
					wcscat_s(symbol, 5, L"X");
				}
				else if (wParam == QUOTIENT) {
					wcscat_s(symbol, 5, L"/");
				}
				SetWindowTextW(op_symb, symbol);
			}
			if (wParam == 0 || wParam == 1 || wParam == 2 || wParam == 3 || wParam == 4 || wParam == 5 || wParam == 6 || wParam == 7 || wParam == 8 || wParam == 9) {
				GetWindowTextW(input2, operand2, 100);
				if (wcscmp(operand2, L"") == 0) {
					wsprintf(buffer, L"%d", (int)wParam);
					SetWindowTextW(input2, buffer);
				}
				else {
					wsprintf(temp2, L"%d", (int)wParam);
					wcscat_s(operand2, 100, temp2);
					SetWindowTextW(input2, operand2);
				}
			}
			//calculate the values using the operator
			if (wParam == DISPLAY) {
				calculate(handle);
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
}