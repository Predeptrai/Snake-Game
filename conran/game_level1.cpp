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
		set_snake(pointX, pointY, do_dai, x_snake, y_snake, x_food, y_food, duoi, order_food, food, check_eating,1);

		gameover = check_gameover(pointX, pointY, do_dai, x, y, w, h);
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
			check_second = false;
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