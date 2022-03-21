#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <thread>
#include "graphic_console.h"
#include "Lib_game.h"
#include "Global_variable.h"

#define MAX 100

using namespace std;

toa_do obstacle[MAX * MAX];
int cnt_obstacle = 0;
bool check_eating = false;
bool check_first = true;
bool check_second = true;

toa_do snake[MAX],pre_snake[MAX];
bool done_pre_snake = false, done_now_snake = false;
char duoi[MAX];
int x_snake = 50, y_snake = 13;
int xfinish = 20, yfinish = 4;
bool finish = 0;
int x = 10, y = 1, w = 100, h = 27;
int pointX[MAX], pointY[MAX];
int order_food = 5;
int speed = 50;

// Nguoi tuyet
int size_nguoi_tuyet = 7,size_ao_nguoi_tuyet=19;
toa_do nguoi_tuyet[MAX],pre_nguoi_tuyet[MAX];
bool done_pre_nguoi_tuyet = false, done_now_nguoi_tuyet = false;
toa_do food;
char ve_nguoi_tuyet[MAX];
bool check_nguoi_tuyet = true;
bool check_nguoi_tuyet_thread_1 = true;
bool check_nguoi_tuyet_thread_2 = false;
bool loop_main_thread = true;
int x_food, y_food;

bool gameover = false;
bool block = true;
bool gameover_round_1 = true;
bool gameover_round_2 = true;
bool gameover_round_3 = true;
bool check_snake = true;
bool loop_thread_snake = false;

//check valid
int check = 2;
int do_dai = 6;
toa_do gate[MAX];
int cnt_gate = 0;

// direction
bool check1to2 = false;
bool check2to3 = false;
bool check_die = false;

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

void sound_die()
{
	while (check_second)
	{
		if (check_die)
		{
			PlaySound(TEXT("deadth.wav"), NULL, SND_SYNC);
		}
			//gameover = false;
	}
}

void main()
{
	ShowCur(0);
	thread first(sound_phat);
	thread second(sound_die);
	thread snake_round(snake_thread);
	thread snow_man(nguoi_tuyet_thread);
	while (true)
	{
		graphicConsole();

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
			if (option != 0)
			{
				if (option == 1)
				{
					system("cls");
					game_level_1();
					break;
				}
				else if(option == 3)
				{
					highScoreBoard();
					break;
				}
			}

		} while (option != 5);

		if (option == 5)
			break;
	}

	

	/*gotoxy(60, 30);
	textcolor(13);
	cout << "Thanks for playing this game <3.\n";
	*/
	textcolor(7);
	gotoxy(0, 37);
	loop_main_thread = false;
	check_nguoi_tuyet_thread_1 = false;
	check_second = false;
	check_first = false;
	first.join();
	second.join();
	snake_round.join();
	snow_man.join();
	/*_getch();*/
	return;
}