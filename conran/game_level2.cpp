#include <iostream>
#include <stdio.h>
#include <conio.h>
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
}

void game_level_2()
{
	draw_obstacle();
	init();
	nameLevel2(x, y, w, h, 11);
	check2to3 = false;
	gameover_round_2 = false;
	while (gameover_round_2 == false|| loop_thread_snake == true)
	{
		check1to2 = false;
		if (check2to3)
		{
			gameover_round_2 = true;
			game_level_3();
			break;
		}
	}
	return;
}
