#include "stdafx.h"
#include "resource.h"
#include "DialogProcs.h"

using namespace std;

HINSTANCE hInst = NULL;
bool isAbord = false;

#ifdef _DEBUG
int main()
#else
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdline, int iCmdShow)
#endif
{
	hInst = GetModuleHandle(NULL);
	DialogBoxA(hInst, MAKEINTRESOURCEA(IDD_LOGIN), NULL, (DLGPROC)LoginDialogProc);
	if (isAbord)
		return 0;

	//get the authority of current user
	//set the states of buttons according to the authority(in the dialog initiation)
	DialogBoxA(hInst, MAKEINTRESOURCEA(IDD_MAIN), NULL, (DLGPROC)MainDialogProc);

    return 0;
}

