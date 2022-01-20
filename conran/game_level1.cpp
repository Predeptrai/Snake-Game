#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Global_variable.h"
#include "Lib_game.h"
#include "graphic_console.h"

using namespace std;

void game_level_1()
{
	//10 1 100 27
	int size = 6;
	init_duoi(duoi);
	order_food = 5;
	x_snake = 50, y_snake = 13;
	draw(x, y, w, h, 11);
	snake_position(pointX, pointY, size);
	draw_snake(pointX, pointY, size, duoi);
	srand(time(NULL));

	create_food(x_food, y_food, pointX, pointY, size, order_food, duoi, food);
	check_first = true;

	while (gameover == false)
	{
		
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

		//gameover = check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet, pointX, pointY, size);

		gameover = check_gameover(pointX, pointY, size, x, y, w, h);
		Sleep(speed);
		if (gameover)
		{
			char tam;
			gotoxy((x + w) / 2-9, (y + h) / 2);
			cout << "Press Enter to return Menu" << endl;
			cin.get();
			system("cls");
		}
	}

	check_first = false;
	return;
}