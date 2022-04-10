#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <thread>
#include "Global_variable.h"
#include "graphic_console.h"
#include "Lib_game.h"

using namespace std;
void draw_obstacle()
{
	cnt_obstacle = 0;
	textcolor(14);
	for (int ix = 30; ix <= 100; ix += 30)
	{
		for (int iy = 2; iy <= 9; iy++)
		{
			gotoxy(ix, iy);
			cout << char(219);
			gotoxy(ix + 1, iy);
			cout << char(219);
			gotoxy(ix + 2, iy);
			cout << char(219);

			obstacle[cnt_obstacle].x = ix;
			obstacle[cnt_obstacle].y = iy;
			cnt_obstacle++;
			obstacle[cnt_obstacle].x = ix + 1;
			obstacle[cnt_obstacle].y = iy;
			cnt_obstacle++;
			obstacle[cnt_obstacle].x = ix + 2;
			obstacle[cnt_obstacle].y = iy;
			cnt_obstacle++;
		}
	}

	for (int ix = 45; ix <= 90; ix += 30)
	{
		for (int iy = 27; iy >= 20; iy--)
		{
			gotoxy(ix, iy);
			cout << char(219);
			gotoxy(ix + 1, iy);
			cout << char(219);
			gotoxy(ix + 2, iy);
			cout << char(219);

			obstacle[cnt_obstacle].x = ix;
			obstacle[cnt_obstacle].y = iy;
			cnt_obstacle++;
			obstacle[cnt_obstacle].x = ix + 1;
			obstacle[cnt_obstacle].y = iy;
			cnt_obstacle++;
			obstacle[cnt_obstacle].x = ix + 2;
			obstacle[cnt_obstacle].y = iy;
			cnt_obstacle++;
		}
	}
	textcolor(15);
}

void game_level_2()
{
	if (pass == 0)
	{
		savedata(filesave);
	}
	init();
	nameLevel2(x, y, h - 1, w, 12);
	draw_obstacle();
	check1to2 = false;
	check2to3 = false;
	bool dieu_huong = false;
	gameover_round_2 = false;
	while (gameover_round_2 == false && loop_thread_snake == true)
	{
		if (check2to3 == true || pass > 0)
		{
			if (pass == 0)
			{
				speed++;
				score += 50;
			}
			else
				pass--;
			check2to3 = true;
			gameover_round_2 = true;
			level = 3;
			game_level_3();
			break;
		}
	}
	return;
}
