#include <windows.h>
#include <stdio.h>
#include <thread>
#include <chrono>
#include <iostream>

#define UBound(n)	sizeof(n) / sizeof(n[0]);

int main(int argc, wchar_t* argv[])
{

	//Build Array Of Hyper Keys To Unregister
	//These map to W, T, Y, O, P, D, L, X, N, and Space, respectively.
	UINT offendingHyperKeys[10] = { 0x57, 0x54, 0x59, 0x4F, 0x50, 0x44, 0x4C, 0x58, 0x4E, 0x20 };

	//Kill Explorer
	system("taskkill /IM explorer.exe /F");

	//Register hotkey
	for (int i = 0; i < 10; i++) {
		RegisterHotKey(NULL, i, 0x1 + 0x2 + 0x4 + 0x8 | MOD_NOREPEAT, offendingHyperKeys[i]);
	}

	//Build Array Of Windows Keys To Unregister
	//These map to F, respectively.
	int iCnt = UBound(offendingHyperKeys);

	UINT offendingKeysWin[1] = { 0x46 };
	for (int i = 0; i < 1; i++) {
		RegisterHotKey(NULL, i + iCnt, 0x8 | MOD_NOREPEAT, offendingKeysWin[i]);
	}
	
	iCnt = iCnt + UBound(offendingKeysWin);

	//Restart Explorer
	system("start C:/Windows/explorer.exe");

	/* Sleep for a few seconds to make sure Explorer has time to
	   attempt to register the Office hotkeys, and get blocked by 
	   our hotkeys */
	std::this_thread::sleep_for(std::chrono::milliseconds(4000));
	 
	//deregister hotkeys by ID
	for (int i = 0; i < iCnt; i++) {
		UnregisterHotKey(NULL, i);
	}

	return 1;
}
