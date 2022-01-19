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
bool check_first = true;
char duoi[MAX];
int x_snake = 50, y_snake = 13;
int x = 10, y = 1, w = 100, h = 27;
int pointX[MAX], pointY[MAX];
int order_food = 5;
int speed = 80;
// Nguoi tuyet
int size_nguoi_tuyet = 7;
toa_do nguoi_tuyet[MAX];
toa_do food;
char ve_nguoi_tuyet[MAX];
bool check_nguoi_tuyet = true;
int x_food, y_food;
bool gameover = false;
int check = 2;

void sound_phat()
{
	while(check_first)
	{
		if (check_eating)
		{
			PlaySound(TEXT("sound_eating"), NULL, SND_SYNC);
		}
	}
	return;
}

void game()
{

	int size = 6;
	init_duoi(duoi);
	
	chuong_ngai_vat_nguoi_tuyet(x, y, w, h, nguoi_tuyet, ve_nguoi_tuyet, size_nguoi_tuyet);
	draw(x, y, w, h, 11);
	snake_position(pointX, pointY, size);
	draw_snake(pointX, pointY, size, duoi);
	srand(time(NULL));
	
	create_food(x_food, y_food, pointX, pointY, size, order_food, duoi, food);
	
	while (gameover == false)
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

		gameover = max(gameover, check_gameover(pointX, pointY, size, x, y, w, h));
		Sleep(speed);
	}

	check_first = false;
}

void main()
{
	resizeConsole(1200, 700);
	FixConsoleWindow();
	
	thread first(sound_phat);

	gotoxy(75, 10);
	textcolor(13);
	cout << "Menu game" << endl;
	gotoxy(65, 12);
	textcolor(7);
	cout << " New game" << endl;
	gotoxy(65, 15);
	textcolor(11);
	cout << " Continue game" << endl;
	gotoxy(65, 18);
	textcolor(14);
	cout << " Highscore" << endl;
	gotoxy(65, 21);
	textcolor(4);
	cout << " Option" << endl;
	gotoxy(65, 24);
	textcolor(9);
	cout << " Quit" << endl;
	SetColor(7);

	gotoxy(0, 28);
	cout << "Press 'N' to start new game 'C' to continue playing 'H' to see the highest score 'O' to set game 'Q' to escape the game.\n";

	int option = 0;
	do
	{
		if (_kbhit())
		{
			char c = _getch();
			if (c == 'n')
				option = 1;
			else if (c == 'c')
				option = 2;
			else if (c == 'h')
				option = 3;
			else if (c == 'o')
				option = 4;
			else if (c == 'q')
				option = 5;
		}

		switch (option)
		{
		case 1:
			system("cls");
			game();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		}

	} while (option != 5);

	textcolor(13);
	cout << "Thanks for playing this game <3.\n";
	textcolor(7);
	
	
	check_first = false;
	first.join();
	_getch();
	return;
}