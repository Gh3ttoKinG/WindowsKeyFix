#include <windows.h>
#include <stdio.h>
#include <thread>
#include <chrono>
#include <iostream>

#define UBound(n)	sizeof(n) / sizeof(n[0]);

int main(int argc, wchar_t* argv[])
{

	// https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-registerhotkey
	// https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-unregisterhotkey

	int iCnt = 0;

	//Build Array Of Hyper Keys To Unregister
	//These map respectively to            W,   T,    Y,    O,    P,    D,    L,    X,    N,   Space
	UINT offendingHyperKeys[11] = { 0x0, 0x57, 0x54, 0x59, 0x4F, 0x50, 0x44, 0x4C, 0x58, 0x4E, 0x20 };
	int iHyperKeys = UBound(offendingHyperKeys);

	//Kill Explorer
	system("taskkill /IM explorer.exe /F");

	//Register hotkey
	for (int i = 0; i < iHyperKeys; i++) {
		//                      0x1       0x2           0x4         0x8       0x4000
		RegisterHotKey(NULL, i, MOD_ALT + MOD_CONTROL + MOD_SHIFT + MOD_WIN | MOD_NOREPEAT, offendingHyperKeys[i]);
	}
	iCnt = iCnt + UBound(offendingHyperKeys);

	//Build Array Of Windows Keys To Unregister
	//These map respectively to   C,    F,    Q,    S,    U,    W,   Space
	UINT offendingKeysWin[7] = { 0x43, 0x46, 0x51, 0x53, 0x55, 0x57, 0x20 };
	int iWinKeys = UBound(offendingKeysWin);
	for (int i = 0; i < iWinKeys; i++) {
		//                                   0x8       0x4000
		RegisterHotKey(NULL, i + iHyperKeys, MOD_WIN | MOD_NOREPEAT, offendingKeysWin[i]);
	}

	iCnt = iCnt + UBound(offendingKeysWin);

	//Restart Explorer
	system("start C:/Windows/explorer.exe");

	/* Sleep for a few seconds to make sure Explorer has time to
	   attempt to register the Office hotkeys, and get blocked by
	   our hotkeys */
	std::this_thread::sleep_for(std::chrono::milliseconds(10000));

	//deregister hotkeys by ID
	/*
	for (int i = 0; i < iCnt; i++) {
		UnregisterHotKey(NULL, i);
	}f
	*/
	return 1;
}
