#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Global_variable.h"
#include "graphic_console.h"
#include "Lib_game.h"

void game_level_3()
{
	int size = 6;
	init_duoi(duoi);

	draw(x, y, w, h, 11);
	draw_obstacle();
	chuong_ngai_vat_nguoi_tuyet(x, y, w, h, nguoi_tuyet, ve_nguoi_tuyet, size_nguoi_tuyet);
	snake_position(pointX, pointY, size);
	draw_snake(pointX, pointY, size, duoi);
	srand(time(NULL));

	create_food(x_food, y_food, pointX, pointY, size, order_food, duoi, food);

	while (gameover == false && check_first)
	{
		set_nguoi_tuyet(nguoi_tuyet, ve_nguoi_tuyet, size_nguoi_tuyet, x, w, check_nguoi_tuyet, food, order_food, duoi);
		gameover = check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet, pointX, pointY, size);
	
		if (gameover) break;
		delete_position(pointX, pointY, size);

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
		set_snake(pointX, pointY, size, x_snake, y_snake, x_food, y_food, duoi, order_food, food, check_eating);

		gameover = check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet, pointX, pointY, size);
		bool check = snake_touch_obstacle(size, pointX, pointY);
		gameover = max(check, gameover);
		gameover = max(gameover, check_gameover(pointX, pointY, size, x, y, w, h));
		Sleep(speed);
	}

	check_first = false;
}