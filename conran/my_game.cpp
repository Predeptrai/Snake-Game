#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Lib_game.h"

#include "graphic_console.h"

#define MAX 100

using namespace std;


void chuong_ngai_vat_nguoi_tuyet(int x, int y, int w, int h, toa_do nguoi_tuyet[], char ve_nguoi_tuyet[], int& size_nguoi_tuyet)
{
	y += h / 2 - 1;
	int n = 3;
	gotoxy(x + 3 + n, y);
	cout << "*";
	ve_nguoi_tuyet[7] = '*';
	nguoi_tuyet[7].x = x + 3 + n;
	nguoi_tuyet[7].y = y;

	gotoxy(x + 2 + n, y + 1);
	cout << "*";
	ve_nguoi_tuyet[8] = '*';
	nguoi_tuyet[8].x = x + 2 + n;
	nguoi_tuyet[8].y = y + 1;

	gotoxy(x + 4 + n, y + 1);
	cout << "*";
	ve_nguoi_tuyet[9] = '*';
	nguoi_tuyet[9].x = x + 4 + n;
	nguoi_tuyet[9].y = y + 1;


	gotoxy(x + 3 + n, y + 1);
	cout << "A";
	ve_nguoi_tuyet[0] = 'A';
	nguoi_tuyet[0].x = x + 3 + n;
	nguoi_tuyet[0].y = y + 1;


	gotoxy(x + 1 + n, y + 2);
	cout << "*";

	ve_nguoi_tuyet[10] = '*';
	nguoi_tuyet[10].x = x + 1 + n;
	nguoi_tuyet[10].y = y + 2;

	gotoxy(x + 5 + n, y + 2);
	cout << "*";

	ve_nguoi_tuyet[11] = '*';
	nguoi_tuyet[11].x = x + 5 + n;
	nguoi_tuyet[11].y = y + 2;


	gotoxy(x + 2 + n, y + 2);
	cout << "/";

	ve_nguoi_tuyet[1] = '/';
	nguoi_tuyet[1].x = x + 2 + n;
	nguoi_tuyet[1].y = y + 2;

	gotoxy(x + 3 + n, y + 2);
	cout << "@";

	ve_nguoi_tuyet[2] = '@';
	nguoi_tuyet[2].x = x + 3 + n;
	nguoi_tuyet[2].y = y + 2;

	gotoxy(x + 4 + n, y + 2);
	cout << "\\";

	ve_nguoi_tuyet[3] = '\\';
	nguoi_tuyet[3].x = x + 4 + n;
	nguoi_tuyet[3].y = y + 2;



	gotoxy(x + 1 + n, y + 3);
	cout << "*";

	ve_nguoi_tuyet[12] = '*';
	nguoi_tuyet[12].x = x + 1 + n;
	nguoi_tuyet[12].y = y + 3;

	gotoxy(x + 5 + n, y + 3);
	cout << "*";

	ve_nguoi_tuyet[13] = '*';
	nguoi_tuyet[13].x = x + 5 + n;
	nguoi_tuyet[13].y = y + 3;

	gotoxy(x + 2 + n, y + 3);
	cout << "@";

	ve_nguoi_tuyet[4] = '@';
	nguoi_tuyet[4].x = x + 2 + n;
	nguoi_tuyet[4].y = y + 3;

	gotoxy(x + 3 + n, y + 3);
	cout << "@";

	ve_nguoi_tuyet[5] = '@';
	nguoi_tuyet[5].x = x + 3 + n;
	nguoi_tuyet[5].y = y + 3;

	gotoxy(x + 4 + n, y + 3);
	cout << "@";

	ve_nguoi_tuyet[6] = '@';
	nguoi_tuyet[6].x = x + 4 + n;
	nguoi_tuyet[6].y = y + 3;

	gotoxy(x + 1 + n, y + 4);
	cout << "*";

	ve_nguoi_tuyet[14] = '*';
	nguoi_tuyet[14].x = x + 1 + n;
	nguoi_tuyet[14].y = y + 4;

	gotoxy(x + 2 + n, y + 4);
	cout << "*";

	ve_nguoi_tuyet[15] = '*';
	nguoi_tuyet[15].x = x + 2 + n;
	nguoi_tuyet[15].y = y + 4;

	size_nguoi_tuyet = 15;

	gotoxy(x + 3 + n, y + 4);
	cout << "*";

	ve_nguoi_tuyet[++size_nguoi_tuyet] = '*';
	nguoi_tuyet[size_nguoi_tuyet].x = x + 3 + n;
	nguoi_tuyet[size_nguoi_tuyet].y = y + 4;

	gotoxy(x + 4 + n, y + 4);
	cout << "*";

	ve_nguoi_tuyet[++size_nguoi_tuyet] = '*';
	nguoi_tuyet[size_nguoi_tuyet].x = x + 4 + n;
	nguoi_tuyet[size_nguoi_tuyet].y = y + 4;

	gotoxy(x + 5 + n, y + 4);
	cout << "*";

	ve_nguoi_tuyet[++size_nguoi_tuyet] = '*';
	nguoi_tuyet[size_nguoi_tuyet].x = x + 5 + n;
	nguoi_tuyet[size_nguoi_tuyet].y = y + 4;


	size_nguoi_tuyet = 7;
	return;
}
void chuong_ngai_vat_nguoi(int x, int y, int w, int h)
{
	gotoxy(x + 2, y + 1);
	cout << "@";
	gotoxy(x + 1, y + 2);
	cout << "/";
	gotoxy(x + 2, y + 2);
	cout << "|";
	gotoxy(x + 3, y + 2);
	cout << "\\";
	gotoxy(x + 2, y + 3);
	cout << "|";
	gotoxy(x + 1, y + 4);
	cout << "/";
	gotoxy(x + 3, y + 4);
	cout << "\\";
	return;
}

void draw(int x, int y, int w, int h, int color)
{
	textcolor(12);

	for (int ix = x; ix <= x + w; ix++)
	{
		gotoxy(ix, y);
		cout << char(219);
		gotoxy(ix, y + h);
		cout << char(219);
	}

	for (int iy = y; iy <= y + h; iy++)
	{
		gotoxy(x, iy);
		cout << char(219);
		gotoxy(x + w, iy);
		cout << char(219);
	}
	return;
}

void drawDirectionBox(int x, int y, int w, int h, int color)
{
	textcolor(12);

	for (int ix = x + w + 3; ix <= x + w + 48; ix++)
	{
		gotoxy(ix, y);
		cout << char(219);
		gotoxy(ix, y + h);
		cout << char(219);
	}

	for (int iy = y; iy <= y + h; iy++)
	{
		gotoxy(x + w + 3, iy);
		cout << char(219);
		gotoxy(x + w + 48, iy);
		cout << char(219);
	}
	SetColor(9);

	gotoxy(x + w + 11, y + 3);
	cout << " _____ _____ _____ _____ _____";
	gotoxy(x + w + 11, y + 4);
	cout << "|   __| __  |     |  |  |  _  |";
	gotoxy(x + w + 11, y + 5);
	cout << "|  |  |    -|  |  |  |  |   __|";
	gotoxy(x + w + 11, y + 6);
	cout << "|_____|__|__|_____|_____|__|";
	gotoxy(x + w + 21, y + 8);
	cout << " ___ ___";
	gotoxy(x + w + 21, y + 9);
	cout << "|   |_  |";
	gotoxy(x + w + 21, y + 10);
	cout << "| | |_  |";
	gotoxy(x + w + 21, y + 11);
	cout << "|___|___|";
	SetColor(15);

	gotoxy(x + w + 10, y + 15);
	cout << "PLAYER DATA";
	gotoxy(x + w + 10, y + 17);
	cout << "SCORE : " << score;

	SetColor(10);
	gotoxy(x + w + 8, y + 20);
	cout << "	   ___     ____________";
	gotoxy(x + w + 8, y + 21);
	cout << "<<<((__O\\   (__<>___<>__ \\     ____";
	gotoxy(x + w + 8, y + 22);
	cout << "	       \\ \\_(__<>___<>__)\\O\\_/O___>-<";
	gotoxy(x + w + 8, y + 23);
	cout << "          \\O__<>___<>___<>)\\___/";
	SetColor(15);
	return;
}

void drawContentBox(int x, int y, int w, int h, int color)
{
	textcolor(12);

	for (int ix = x + w + 3; ix <= x + w + 48; ix++)
	{
		gotoxy(ix, y + h + 2);
		cout << char(219);
		gotoxy(ix, y + h + 12);
		cout << char(219);
	}

	for (int iy = y + h + 3; iy <= y + h + 12; iy++)
	{
		gotoxy(x + w + 3, iy);
		cout << char(219);
		gotoxy(x + w + 48, iy);
		cout << char(219);
	}
	SetColor(11);
	gotoxy(x + w + 8, y + h + 5);
	cout << "'UP' OR 'W'	:   MOVING UP";
	gotoxy(x + w + 8, y + h + 6);
	cout << "'DOWN' OR S	:   MOVING DOWN";
	gotoxy(x + w + 8, y + h + 7);
	cout << "'RIGHT' OR A	:   TURN RIGHT";
	gotoxy(x + w + 8, y + h + 8);
	cout << "'LEFT' OR 'D'	:   TURN LEFT";
	gotoxy(x + w + 8, y + h + 9);
	cout << "'L'               :   SAVE THE GAME";
	SetColor(15);
	return;
}

void drawBattery(int x, int y, int w, int h, int color)
{
	textcolor(56);
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoxy(ix, y + h + 2);
		cout << char(219);
		gotoxy(ix, y + h + 4);
		cout << char(219);
	}

	for (int iy = y + h + 2; iy <= y + h + 3; iy++)
	{
		gotoxy(x, iy);
		cout << char(219);
		gotoxy(x + w, iy);
		cout << char(219);
	}
	// chia khoang 
	for (int iy = y + h + 2; iy <= y + h + 3; iy++)
	{
		gotoxy(x + w / 2, iy);
		cout << char(219);
		gotoxy(x + w / 2 + 1, iy);
		cout << char(219);
	}
	// ve doan dau 
	for (int iy = y + h + 2; iy <= y + h + 3; iy++)
	{
		gotoxy(x + w / 4 - 1, iy);
		cout << char(219);
		gotoxy(x + w / 4, iy);
		cout << char(219);
	}
	// ve doan cuoi
	for (int iy = y + h + 2; iy <= y + h + 3; iy++)
	{
		gotoxy(x + 3 * w / 4 + 1, iy);
		cout << char(219);
		gotoxy(x + 3 * w / 4 + 2, iy);
		cout << char(219);
	}
	return;
}

void drawLevelBar(int x, int y, int w, int h, int color)
{
	textcolor(12);

	for (int ix = x; ix <= x + w; ix++)
	{
		gotoxy(ix, y + h + 6);
		cout << char(219);
		gotoxy(ix, y + h + 12);
		cout << char(219);
	}

	for (int iy = y + h + 6; iy <= y + h + 11; iy++)
	{
		gotoxy(x, iy);
		cout << char(219);
		gotoxy(x + w, iy);
		cout << char(219);
	}
	return;
}

void drawSymbolSnake()
{
	SetColor(10);
	gotoxy(1, 2);
	cout << " _____";
	gotoxy(1, 3);
	cout << "/  ___|";
	gotoxy(1, 4);
	cout << "\\  `--.";
	gotoxy(1, 5);
	cout << " `- - .\\";
	gotoxy(1, 6);
	cout << " /\\__/ /";
	gotoxy(1, 7);
	cout << " \\____/";


	gotoxy(1, 9);
	cout << " _   _";
	gotoxy(1, 10);
	cout << "| \\ | |";
	gotoxy(1, 11);
	cout << "|  \\| |";
	gotoxy(1, 12);
	cout << "| . ` |";
	gotoxy(1, 13);
	cout << "| |\\  |";
	gotoxy(1, 14);
	cout << "\\_| \\_/";


	gotoxy(1, 16);
	cout << "  ___";
	gotoxy(1, 17);
	cout << " / _ \\";
	gotoxy(1, 18);
	cout << "/ /_\\ \\";
	gotoxy(1, 19);
	cout << "|  _  |";
	gotoxy(1, 20);
	cout << "| | | |";
	gotoxy(1, 21);
	cout << "\\_| |_/";

	gotoxy(1, 23);
	cout << " _   __";
	gotoxy(1, 24);
	cout << "| | / /";
	gotoxy(1, 25);
	cout << "| |/ /";
	gotoxy(1, 26);
	cout << "|    \\";
	gotoxy(1, 27);
	cout << "| |\\  \\";
	gotoxy(1, 28);
	cout << "\\_| \\_/";


	gotoxy(1, 30);
	cout << " _____";
	gotoxy(1, 31);
	cout << "|  ___|";
	gotoxy(1, 32);
	cout << "| |__";
	gotoxy(1, 33);
	cout << "|  __|";
	gotoxy(1, 34);
	cout << "| |___";
	gotoxy(1, 35);
	cout << "\\____/";
	SetColor(15);

}

void draw_snake(toa_do snake[], int& size, char duoi[])
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			gotoxy(snake[i].x, snake[i].y);
			cout << duoi[i];
		}
		else
		{
			gotoxy(snake[i].x, snake[i].y);
			cout << duoi[i];
		}
	}
}

void snake_position(toa_do snake[], int& size)
{
	int x = 50, y = 13;
	for (int i = 0; i < size; i++)
	{
		snake[i].x = x;
		snake[i].y = y;
		x--;
	}
}

void delete_position(toa_do snake[], int size)
{
	for (int i = 0; i < size; i++)
	{
		gotoxy(snake[i].x, snake[i].y);
		cout << " ";
	}
}

void draw_finish_gate(int level)
{
	finish = 1;
	cnt_gate = 0;
	for (int i = 0; i <= 2; i++)
	{
		gotoxy(xfinish - 1 + i, yfinish - 1);
		cout << char(219);
		gate[cnt_gate].x = xfinish - 1 + i;
		gate[cnt_gate].y = yfinish - 1;
		cnt_gate++;
	}
	gotoxy(xfinish - 1, yfinish);
	cout << char(219);
	gate[cnt_gate].x = xfinish - 1;
	gate[cnt_gate].y = yfinish;
	cnt_gate++;
	gotoxy(xfinish + 1, yfinish);
	cout << char(219);
	gate[cnt_gate].x = xfinish + 1;
	gate[cnt_gate].y = yfinish;
	cnt_gate++;
	return;
}

bool touch_gate()
{
	for (int i = 0; i < do_dai; i++)
	{
		for (int j = 0; j < cnt_gate; j++)
		{
			if (snake[i].x == gate[j].x && snake[i].y == gate[j].y)
			{
				return true;
			}
		}
	}
	return false;
}
