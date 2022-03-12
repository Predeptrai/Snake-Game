#include <iostream>
#include <conio.h>
#include "Global_variable.h"
#include "Lib_game.h"
#include "graphic_console.h"

using namespace std;

void game_level_1()
{
	//10 1 100 27
	init();
	check1to2 = false;
	bool dieu_huong = false;
	while (gameover == false)
	{
		delete_position(snake, do_dai);

		move_snake();

		check_eating = false;
		set_snake(snake, do_dai, x_snake, y_snake, x_food, y_food, duoi, order_food, food, check_eating,1);

		gameover = check_gameover(snake, do_dai, x, y, w, h);
		bool check_1 = touch_gate();
		gotoxy(1, 1);
		cout << gameover << endl;
		gameover = max(check_1, gameover);;
		Sleep(speed);

		if (check1to2 == true)
		{
			break;
		}

		if (gameover)
		{
			check_die = true;
			Sleep(1);
			check_die = false;
			gotoxy((x + w) / 2-9, (y + h) / 2);

			cout << "Press Enter to return Menu" << endl;
			cin.get();
			system("cls");
			break;
		}
	}
	check_eating = false;
	return;
}
