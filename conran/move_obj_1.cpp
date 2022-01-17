


#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include "graphic_console.h"
#include "Lib_game.h"
#include <thread>
#define MAX 100

using namespace std;
bool check_eating = false;

void sound_phat()
{
	while(true)
	{
		if (check_eating)
		{
			PlaySound(TEXT("sound_eating"), NULL, SND_SYNC);
		}
	}
	return;
}

void main()
{

	FixConsoleWindow();
	char duoi[MAX];
	char cnv[5];
	init_duoi(duoi);
	int x_snake = 50, y_snake = 13;
	int x = 10, y = 1, w = 100, h = 27;
	int pointX[MAX], pointY[MAX];
	int size = 6;
	int order_food = 5;
	// Nguoi tuyet
	int size_nguoi_tuyet = 7;
	toa_do nguoi_tuyet[MAX];
	toa_do food;
	char ve_nguoi_tuyet[MAX];
	bool check_nguoi_tuyet = true;
	//SetWindowSize(w, h);
	//cout << w << " " << h << endl;

	chuong_ngai_vat_nguoi_tuyet(x, y, w, h, nguoi_tuyet, ve_nguoi_tuyet, size_nguoi_tuyet);
	draw(x, y, w, h, 11);
	snake_position(pointX, pointY, size);
	draw_snake(pointX, pointY, size, duoi);
	srand(time(NULL));
	int x_food, y_food;
	create_food(x_food, y_food, pointX, pointY, size, order_food, duoi,food);
	bool gameover = false;
	int check = 2;
	//Beep(400, 50);
	thread first(sound_phat);

	while (gameover == false)
	{
		set_nguoi_tuyet(nguoi_tuyet, ve_nguoi_tuyet, size_nguoi_tuyet, x, w, check_nguoi_tuyet,food, order_food,duoi);
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
		set_snake(pointX, pointY, size, x_snake, y_snake, x_food, y_food, duoi, order_food, food,check_eating);
		//sound_phat(check_eating);
		gameover = check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet, pointX, pointY, size);

		gameover = max(gameover, check_gameover(pointX, pointY, size, x, y, w, h));
		Sleep(50);
	}
	first.join();
	_getch();
	return;
}