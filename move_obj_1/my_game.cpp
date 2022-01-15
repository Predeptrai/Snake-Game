#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "graphic_console.h"
#include "Lib_game.h"

using namespace std;

void draw(int x, int y, int w, int h, int color)
{
	textcolor(color);
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

void draw_snake(int pointX[], int pointY[], int& size)
{
	//size = 4;

	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			gotoxy(pointX[i], pointY[i]);
			cout << char(2);
		}
		else 
		{
			gotoxy(pointX[i], pointY[i]);
			cout << "o";
		}	
	}
}

void snake_position(int pointX[], int pointY[], int& size)
{
	size = 4;
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