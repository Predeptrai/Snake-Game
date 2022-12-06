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
	int x = X_CENTER - 3, y = 18;
	draw(x, y, 37, 18, 7);
	gotoxy(x + 7, y + 1);
	textcolor(11);
	cout << " _____ _____ _____ _____\n";
	gotoxy(x + 7, y + 2);
	textcolor(12);
	cout << "|     |   __|   | |  |  |\n";
	gotoxy(x + 7, y + 3);
	textcolor(13);
	cout << "| | | |   __| | | |  |  |\n";
	gotoxy(x + 7, y + 4);
	textcolor(14);
	cout << "|_|_|_|_____|_|___|_____|\n";
	textcolor(7);
	cout << endl << endl;
	return;
}

void highScoreBoard() {
	bool direction = 1;
	system("cls");
	draw(50, 11, 70, 26, 7);
	draw(50, 4, 70, 7, 7);
	textcolor(12);
	gotoxy(57, 5);
	cout << " _____            _   _     _\n";
	gotoxy(57, 6);
	cout << "|_   _|___ ___   | |_|_|___| |_    ___ ___ ___ ___ ___\n";
	gotoxy(57, 7);
	cout << "  | | | . | . |  |   | | . |   |  |_ -|  _| . |  _| -_|\n";
	gotoxy(57, 8);
	cout << "  |_| |___|  _|  |_|_|_|_  |_|_|  |___|___|___|_| |___|\n";
	gotoxy(57, 9);
	cout << "          |_|          |___|\n";
	textcolor(7);
	gotoxy(65, 39);
	cout << "Press ESC to return Menu!!";

	fstream in("highscore.txt", ios::in);
	int cnt = 0, n = 0;
	while (true)
	{
		if (cnt == 10 || in.eof())
			break;
		string s[10];
		getline(in, s[cnt], '\n');
		gotoxy(78, 13 + n + 2);
		cout << s[cnt];
		n += 2;
		cnt++;
		Sleep(80);
	}
	in.close();
	while (direction) {
		if (_kbhit()) {
			char c = _getch();
			if (c == 27) {
				direction = 0;
				system("cls");
				return;
			}
		}
	}
}

// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
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
	ShowCur(0);
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

//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}