#pragma once
#include "stdafx.h"
#include "resource.h"

using namespace std;

extern HINSTANCE hInst;
extern bool isAbord;

void moveToCenter(HWND target);
LRESULT CALLBACK AccountDialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK MainDialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK LoginDialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);