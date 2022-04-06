#include "graphic_console.h"
#include "Lib_game.h"

void nameLevel1(int x, int y, int h, int w, int color)
{
	SetColor(6);
	gotoxy(x + 28, y + 34);
	cout << " __                              _      ___";
	gotoxy(x + 28, y + 35);
	cout << "|  |      ___      _ _    ___   | |    |_  |";
	gotoxy(x + 28, y + 36);
	cout << "|  |__   | -_|    | | |  | -_|  | |     _| |_";
	gotoxy(x + 28, y + 37);
	cout << "|_____|  |___|     \\_/   |___|  |_|    |_____|";
	SetColor(15);
}

void nameLevel2(int x, int y, int h, int w, int color)
{
	SetColor(6);
	gotoxy(x + 28, y + 34);
	cout << "  _      ___  __   __  ___   _      ___";
	gotoxy(x + 28, y + 35);
	cout << " | |    | __| \\ \\ / / | __| | |    |_  )";
	gotoxy(x + 28, y + 36);
	cout << " | |__  | _|   \\ V /  | _|  | |__   / /";
	gotoxy(x + 28, y + 37);
	cout << " |____| |___|   \\_/   |___| |____| /___|";
	SetColor(15);
}

void nameLevel3(int x, int y, int h, int w, int color)
{
	SetColor(6);
	gotoxy(x + 28, y + 34);
	cout << "  _      ___  __   __  ___   _      ____";
	gotoxy(x + 28, y + 35);
	cout << " | |    | __| \\ \\ / / | __| | |    |__ /";
	gotoxy(x + 28, y + 36);
	cout << " | |__  | _|   \\ V /  | _|  | |__   |_ \\";
	gotoxy(x + 28, y + 37);
	cout << " |____| |___|   \\_/   |___| |____| |___/";
	SetColor(15);
}