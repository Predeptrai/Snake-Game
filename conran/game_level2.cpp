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
}

void game_level_2()
{
	init();
	nameLevel2(x, y, h - 1, w, 12);
	draw_obstacle();
	check1to2 = false;
	check2to3 = false;
	bool dieu_huong = false;
	gameover_round_2 = false;
	while (gameover_round_2 == false && loop_thread_snake == true)
	{
		if (check2to3 == true)
		{
			gameover_round_2 = true;
			speed++;
			game_level_3();
			cout << "134" << endl;
			break;
		}
	}
	/*cout << "Press Y to continue or Enter to return to Mainmenu" << endl;
	char key = _getch();
	if (key != 'y')
	{
		system("cls");
		return;
	}
	if (key == 'y')
	{
		system("cls");
		game_level_2();
	}*/
	return;
}
