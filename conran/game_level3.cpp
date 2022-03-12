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
		gameover = check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet,snake, do_dai);
	
		//if (gameover) break;
		delete_position(snake, do_dai);
		
		move_snake();
		
		check_eating = false;
		set_snake(snake, do_dai, x_snake, y_snake, x_food, y_food, duoi, order_food, food, check_eating,3);

		gameover = check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet, snake, do_dai);
		bool check_2 = snake_touch_obstacle(do_dai, snake);
		gameover = max(check_2, gameover);
		bool check_1 = touch_gate();
		gameover = max(gameover, check_1);

		gameover = max(gameover, check_gameover(snake, do_dai, x, y, w, h));
		Sleep(speed);
		if (gameover)
		{
			check_die = true;
			Sleep(1);
			check_die = false;

			//check_second = false;
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