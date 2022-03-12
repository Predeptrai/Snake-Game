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
	check2to3 = false;
	while (gameover == false)
	{
	
		delete_position(snake, do_dai);

		move_snake();

		check_eating = false;
		set_snake(snake, do_dai, x_snake, y_snake, x_food, y_food, duoi, order_food, food, check_eating,2);

		gameover = snake_touch_obstacle(do_dai,snake);
		bool check_1 = touch_gate();
		gameover = max(gameover, check_1);
		gameover = max(gameover, check_gameover(snake, do_dai, x, y, w, h));
		Sleep(speed);

		if (check2to3)
		{
			break;
		}

		if (gameover)
		{
			check_die = true;
			Sleep(1);
			check_die = false;

			//check_second = false;
			gotoxy((x + w) / 2 - 9, (y + h) / 2);
			cout << "Press Enter to return Menu" << endl;
			cin.get();
			system("cls");
			break;
		}
	}
	return;
}
