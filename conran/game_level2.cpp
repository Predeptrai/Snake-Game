#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Global_variable.h"
#include "graphic_console.h"
#include "Lib_game.h"

using namespace std;
void draw_obstacle()
{
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
	while (gameover == false && check_first)
	{
	
		if (gameover) break;
		delete_position(pointX, pointY, do_dai);

		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 72 && check != 0)
					check = 1;

				else if (c == 80 && check != 1)
					check = 0;

				else if (c == 75 && check != 2)
					check = 3;

				else if (c == 77 && check != 3)
					check = 2;
			}
			else
			{
				if (c == 'w' && check != 0)
					check = 1;

				else if (c == 's' && check != 1)
					check = 0;

				else if (c == 'a' && check != 2)
					check = 3;

				else if (c == 'd' && check != 3)
					check = 2;
			}
		}

		switch (check)
		{
		case 0:
			y_snake++;
			break;

		case 1:
			y_snake--;
			break;

		case 2:
			x_snake++;
			break;

		case 3:
			x_snake--;
			break;
		}
		check_eating = false;
		set_snake(pointX, pointY, do_dai, x_snake, y_snake, x_food, y_food, duoi, order_food, food, check_eating,2);

		gameover = snake_touch_obstacle(do_dai, pointX, pointY);
		gameover = max(gameover, check_gameover(pointX, pointY, do_dai, x, y, w, h));
		Sleep(speed);
		if (gameover)
		{
			gotoxy((x + w) / 2 - 9, (y + h) / 2);
			cout << "Press Enter to return Menu" << endl;
			cin.get();
			system("cls");
			break;;
		}
	}

	check_first = false;
}
