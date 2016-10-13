#include "stdafx.h"
#include "DialogProcs.h"
#include "Database.h"

void moveToCenter(HWND target) {
	RECT windowRect;
	int screenWidth, screenHeight;
	int windowWidth, windowHeight;

	GetWindowRect(target, &windowRect);
	windowWidth = windowRect.right - windowRect.left;
	windowHeight = windowRect.bottom - windowRect.top;

	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	MoveWindow(target, (screenWidth - windowWidth) / 2, (screenHeight - windowHeight) / 2, windowWidth, windowHeight, TRUE);
}

LRESULT CALLBACK AccountDialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_INITDIALOG:
		ComboBox_AddString(GetDlgItem(hwnd, IDC_COMBO1), L"Add");
		ComboBox_AddString(GetDlgItem(hwnd, IDC_COMBO1), L"Delete");
		return true;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hwnd, 0);
			return TRUE;
		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK MainDialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_INITDIALOG:
		moveToCenter(hwnd);
		return true;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDC_BUTTON1:
			cout << "add/delete account button clicked" << endl;
			DialogBoxA(hInst, MAKEINTRESOURCEA(IDD_ACCOUNT), hwnd, (DLGPROC)AccountDialogProc);
			break;
		case IDC_BUTTON2:
			cout << "modify authority button clicked" << endl;
			break;
		case IDCANCEL:
			EndDialog(hwnd, 0);
			return TRUE;
		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK LoginDialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	char login_user_name[20];
	char login_password[20];

	switch (message) {
	case WM_INITDIALOG:
		moveToCenter(hwnd);
		return true;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK:
			GetDlgItemTextA(hwnd, IDC_USERNAME, login_user_name, 20);
			GetDlgItemTextA(hwnd, IDC_PASSWORD, login_password, 20);
			if (login(login_user_name, login_password)) {
				cout << "login succeeds!" << endl;
				EndDialog(hwnd, 0);
			}
			else {
				//MessageBoxA(hwnd, "Fail to login", "Error", MB_OK | MB_ICONINFORMATION);
				cout << "login failed" << endl;
			}
			return TRUE;

		case IDCANCEL:
			isAbord = true;
			EndDialog(hwnd, 0);
			return TRUE;
		}
		break;
	}
	return FALSE;
}
