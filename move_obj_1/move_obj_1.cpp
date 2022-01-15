#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "graphic_console.h"
#include "Lib_game.h"

#define MAX 100

using namespace std;

void main()
{
	
	int x_snake = 50, y_snake = 13;
	int x = 10, y = 1, w = 100, h = 27;
	int pointX[MAX], pointY[MAX];
	int size = 4;
	draw(x, y, w, h, 11);
	snake_position(pointX, pointY, size);
	draw_snake(pointX, pointY, size);
	srand(time(NULL));
	int x_food, y_food;
	create_food(x_food, y_food, pointX, pointY, size);
	bool gameover = false;
	int check = 2;

	while (gameover == false)
	{
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
		set_snake(pointX, pointY, size, x_snake, y_snake, x_food, y_food);
		gameover = check_gameover(pointX, pointY, size);
		Sleep(150);
	}

	_getch();
	return;
}