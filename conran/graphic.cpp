#include <iostream>
#include "Lib_game.h"
#include <Windows.h>
#include <ctime>
#include <conio.h>
#include <stdio.h>
#include "graphic_console.h"
#include <fstream>
#include <string>

using  namespace std;

// User Interface
void graphicConsole()
{
	setConsole();
	draw_SnakeTxt();
	drawSnakeShape();
	menuBoard();
}

void setConsole()
{
	FixConsoleWindow();
	resizeConsole(WIDTH, HEIGHT);
}

// draw Snake letter
void draw_SnakeTxt()
{
	fstream fIn;
	string s[8];
	fIn.open("SnakeText.txt", ios::in);
	int i = 0;
	textcolor(12);
	while (!fIn.eof())
	{
		getline(fIn, s[i], '\n');
		gotoxy(X_CENTER - 10, i);
		cout << s[i] << endl;
		i++;
	}
	textcolor(7);
	fIn.close();
	return;
}

// draw Snake shape
void drawSnakeShape()
{
	fstream fIn;
	string s[7];
	fIn.open("Snake_shape.txt", ios::in);
	int i = 0;
	textcolor(10);
	while (!fIn.eof())
	{
		getline(fIn, s[i], '\n');
		gotoxy(X_CENTER - 20, i + 9);
		cout << s[i] << endl;
		i++;
	}
	fIn.close();

	fstream In;
	In.open("Snake_shape2.txt", ios::in);
	int j = 0;
	string str[20];
	textcolor(13);
	while (!In.eof())
	{
		getline(In, str[j], '\n');
		gotoxy(10, 18 + j);
		cout << str[j] << endl;
		gotoxy(X_CENTER + 55, 18 + j);
		cout << str[j] << endl;
		j++;
	}
	In.close();
	textcolor(7);
	return;
}

void menuBoard()
{
	// x: toa do bat dau ve board menu
	// y: toa do chieu cao
	// w: toa do be rong cua board menu
	// h: toa do chieu sau cua board menu
	int x = X_CENTER - 3, y = 18, w = X_CENTER + 35, h = y + 17;
	for (int i = x; i <= w; i++)
	{
		gotoxy(i, y);
		cout << char(219);
		gotoxy(i, 2 * y);
		cout << char(219);
	}

	for (int i = y + 1; i <= h; i++)
	{
		gotoxy(x, i);
		cout << char(219);
		gotoxy(w, i);
		cout << char(219);
	}
	cout << endl << endl;
	return;
}

// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
	
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x , y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm tự viết
void ToMau(int x, int y, string& a, int color) // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}

//============= đặt màu cho chữ =========
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

#define KEY_NONE -1
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;;
}

//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

int inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}