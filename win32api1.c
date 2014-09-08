#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

/**

hInstance is a handle to the program's exe module and to get any other resources to memory

hPrevInstance, which is a handle to the previously run instance of the program, is always NULL for win32 programs
It was used as a handler in win16 but not applicable for win32 and beyond.

lpCmdLine are the command-line arguments, passed as a string, NOT including the program name
LPSTR is a data type specification and is analogous to char* in C...
LP stands for LONG POINTER
You can use char* if you wish
LPCSTR is a pointer to a constant string

nCmdShow is an integer value
*/

{
	MessageBox(NULL, "Goodbye, cruel world!", "DeathNote", MB_OK);
	return 0;
}