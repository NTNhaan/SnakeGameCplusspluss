#include "thuviencuatui.h"

int whereX()
{
	HANDLE handleoutput;
	handleoutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(handleoutput, &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int whereY()
{
	HANDLE handleoutput;
	handleoutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(handleoutput, &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
void gotoXY(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetColor(WORD color)
{
	HANDLE hconsoleoutput;
	hconsoleoutput = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_SCREEN_BUFFER_INFO screen;
	GetConsoleScreenBufferInfo(hconsoleoutput, &screen);
	
	WORD wAttributes = screen.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	
	SetConsoleTextAttribute(hconsoleoutput, wAttributes);
}

int inputKey()
{
	if(kbhit())
	{
		int key = getch();
		
		if(key = 224)
		{
			key = getch();
			return key + 1000;
		}
		return key;
	}
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility};
	SetConsoleCursorInfo(handle, &cursor);
}
