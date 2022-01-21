#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Global_variable.h"
#include "graphic_console.h"
#include "Lib_game.h"

using namespace std;
void game_level_3()
{
	draw_obstacle();
	chuong_ngai_vat_nguoi_tuyet(x, y, w, h, nguoi_tuyet, ve_nguoi_tuyet, size_nguoi_tuyet);
	init();

	while (gameover == false )
	{
		set_nguoi_tuyet(nguoi_tuyet, ve_nguoi_tuyet, size_nguoi_tuyet, x, w, check_nguoi_tuyet, food, order_food, duoi);
		gameover = check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet, pointX, pointY, do_dai);
	
		//if (gameover) break;
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
		set_snake(pointX, pointY, do_dai, x_snake, y_snake, x_food, y_food, duoi, order_food, food, check_eating,3);

		gameover = check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet, pointX, pointY, do_dai);
		bool check_2 = snake_touch_obstacle(do_dai, pointX, pointY);
		gameover = max(check_2, gameover);
		bool check_1 = touch_gate();
		gameover = max(gameover, check_1);

		gameover = max(gameover, check_gameover(pointX, pointY, do_dai, x, y, w, h));
		Sleep(speed);
		if (gameover)
		{
			check_second = false;
			system("cls");
			gotoxy((x + w) / 2 - 9, (y + h) / 2);
			cout << "Press Enter to return Menu" << endl;
			cin.get();
			system("cls");
			break;
		}
	}
	check_eating = false;
	return;
}