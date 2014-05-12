#include "Common.hpp"

int fps;
int tps;
_mouse mouse;

void clearConsole()
{
	HANDLE hStdout; // handle to console screen 
	COORD coordScreen = { 0, 0 }; // home for the cursor 
	DWORD cCharsWritten; // 
	CONSOLE_SCREEN_BUFFER_INFO csbi; // 
	DWORD dwConSize; // Used to store size of screen 

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE); // Get handle to output screen. 

	// Get the number of character cells in the current buffer. 
	if (!GetConsoleScreenBufferInfo(hStdout, &csbi))
	{
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks. 
	if (!FillConsoleOutputCharacter(hStdout, // Handle to console screen buffer 
		(TCHAR) ' ', // Space Character to write to the buffer 
		dwConSize, // Number of cells to write 
		coordScreen, // Coordinates of first cell 
		&cCharsWritten)) // Receive number of characters written 
	{
		return;
	}

	// Get the current text attribute. 
	if (!GetConsoleScreenBufferInfo(hStdout, &csbi))
	{
		return;
	}


	// Set the buffer's attributes accordingly. 
	if (!FillConsoleOutputAttribute(hStdout, // Handle to console screen buffer 
		csbi.wAttributes, // Character attributes to use 
		dwConSize, // Number of cells to set attribute 
		coordScreen, // Coordinates of first cell 
		&cCharsWritten)) // Receive number of characters written 
	{
		return;
	}

	// Put the cursor at its home coordinates. 
	SetConsoleCursorPosition(hStdout, coordScreen);

}
