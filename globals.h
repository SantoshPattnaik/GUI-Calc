#ifndef GLOBALS_H
#define GLOBALS_H

#include<windows.h>

constexpr auto DISPLAY = 20;
constexpr auto SUM = 21;
constexpr auto DIFF = 22;
constexpr auto MULT = 23;
constexpr auto QUOTIENT = 24;

_declspec(selectany) HWND textView, op1, op2;

#endif
