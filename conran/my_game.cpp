#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Lib_game.h"

#include "graphic_console.h"

#define MAX 100

using namespace std;


void chuong_ngai_vat_nguoi_tuyet(int x, int y, int w, int h, toa_do nguoi_tuyet[], char ve_nguoi_tuyet[], int size_nguoi_tuyet)
{
	y += h / 2-1;
	gotoxy(x + 3, y + 1);
	cout << "A";
	ve_nguoi_tuyet[0] = 'A';
	nguoi_tuyet[0].x = x + 3;
	nguoi_tuyet[0].y = y + 1;
	gotoxy(x + 2, y + 2);
	cout << "/";

	ve_nguoi_tuyet[1] = '/';
	nguoi_tuyet[1].x = x + 2;
	nguoi_tuyet[1].y = y + 2;

	gotoxy(x + 3, y + 2);
	cout << "@";

	ve_nguoi_tuyet[2] = '@';
	nguoi_tuyet[2].x = x + 3;
	nguoi_tuyet[2].y = y + 2;

	gotoxy(x + 4, y + 2);
	cout << "\\";

	ve_nguoi_tuyet[3] = '\\';
	nguoi_tuyet[3].x = x + 4;
	nguoi_tuyet[3].y = y + 2;

	gotoxy(x + 2, y + 3);
	cout << "@";

	ve_nguoi_tuyet[4] = '@';
	nguoi_tuyet[4].x = x + 2;
	nguoi_tuyet[4].y = y + 3;

	gotoxy(x + 3, y + 3);
	cout << "@";

	ve_nguoi_tuyet[5] = '@';
	nguoi_tuyet[5].x = x + 3;
	nguoi_tuyet[5].y = y + 3;

	gotoxy(x + 4, y + 3);
	cout << "@";

	ve_nguoi_tuyet[6] = '@';
	nguoi_tuyet[6].x = x + 4;
	nguoi_tuyet[6].y = y + 3;
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
	textcolor(color);

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
