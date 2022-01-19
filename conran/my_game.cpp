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
	gotoxy(x + 2, y + 1);
	cout << "A";
	ve_nguoi_tuyet[0] = 'A';
	nguoi_tuyet[0].x = x + 2;
	nguoi_tuyet[0].y = y + 1;
	gotoxy(x + 1, y + 2);
	cout << "/";

	ve_nguoi_tuyet[1] = '/';
	nguoi_tuyet[1].x = x + 1;
	nguoi_tuyet[1].y = y + 2;

	gotoxy(x + 2, y + 2);
	cout << "@";

	ve_nguoi_tuyet[2] = '@';
	nguoi_tuyet[2].x = x + 2;
	nguoi_tuyet[2].y = y + 2;

	gotoxy(x + 3, y + 2);
	cout << "\\";

	ve_nguoi_tuyet[3] = '\\';
	nguoi_tuyet[3].x = x + 3;
	nguoi_tuyet[3].y = y + 2;

	gotoxy(x + 1, y + 3);
	cout << "@";

	ve_nguoi_tuyet[4] = '@';
	nguoi_tuyet[4].x = x + 1;
	nguoi_tuyet[4].y = y + 3;

	gotoxy(x + 2, y + 3);
	cout << "@";

	ve_nguoi_tuyet[5] = '@';
	nguoi_tuyet[5].x = x + 2;
	nguoi_tuyet[5].y = y + 3;

	gotoxy(x + 3, y + 3);
	cout << "@";

	ve_nguoi_tuyet[6] = '@';
	nguoi_tuyet[6].x = x + 3;
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
//	cout << w << " ";
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
	}

	for (int iy = y; iy <= y + h; iy++)
	{
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + w, iy);
		cout << char(179);
	}

	gotoxy(x, y);
	cout << char(218);
	gotoxy(x + w, y);
	cout << char(191);
	gotoxy(x, y + h);
	cout << char(192);
	gotoxy(x + w, y + h);
	cout << char(217);
}

void draw_snake(int pointX[], int pointY[], int& size, char duoi[])
{
	//size = 4;
	//cout << size << endl;
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			gotoxy(pointX[i], pointY[i]);
			cout << duoi[i];
		}
		else
		{
			gotoxy(pointX[i], pointY[i]);
			cout << duoi[i];
		}
	}
}

void snake_position(int pointX[], int pointY[], int& size)
{
	int x = 50, y = 13;
	for (int i = 0; i < size; i++)
	{
		pointX[i] = x;
		pointY[i] = y;
		x--;
	}
}

void delete_position(int pointX[], int pointY[], int size)
{
	for (int i = 0; i < size; i++)
	{
		gotoxy(pointX[i], pointY[i]);
		cout << " ";
	}
}
