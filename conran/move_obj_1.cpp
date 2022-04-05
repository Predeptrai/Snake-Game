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
int check_eating = 0;
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

int check = 2;
int do_dai = 6;
toa_do gate[MAX];
int cnt_gate = 0;

bool check1to2 = false;
bool check2to3 = false;
bool check3to1 = false;
int check_die = 0;
bool first_time = true;

void main()
{
	setConsole();
	thread first(sound_phat);
	thread second(sound_die);
	while (true)
	{
		graphicConsole();
		/*gotoxy(75, 10);
		textcolor(13);
		cout << "Menu game" << endl;*/ // fix after
		gotoxy(75, 24);
		textcolor(7);
		cout << "   New game" << endl;
		gotoxy(75, 26);
		textcolor(11);
		cout << " Continue game" << endl;
		gotoxy(75, 28);
		textcolor(14);
		cout << "   Highscore" << endl;
		gotoxy(75, 30);
		textcolor(14);
		cout << "  Instruction" << endl;
		gotoxy(75, 32);
		textcolor(4);
		cout << "    Option" << endl;
		gotoxy(75, 34);
		textcolor(9);
		cout << "     Quit" << endl;
		SetColor(7);

		/*gotoxy(0, 28);
		cout << "Press 'N' to start new game 'C' to continue playing 'H' to see the highest score 'O' to set game 'Q' to escape the game.\n";*/

		
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
				else if (c == 'i')
					option = 4;
				else if (c == 'o')
					option = 5;
				else if (c == 'q')
					option = 6;
			}
			if (option != 0)
			{
				if (option == 1)
				{
					system("cls");
					speed = 1;
					thread snake_round(snake_thread);
					game_level_2();
					snake_round.join();
					break;
				}
				else if (option == 3)
				{
					highScoreBoard();
					break;
				}
				else if (option == 4) {
					system("cls");
					drawIntro(x, y, w, h, 11);
					gotoxy(x + w / 2 + 10, y + h + 3);
					system("cls");
					break;
				}
				else if (option == 6)
					break;
			}

		} while (option != 5);
		if (option == 6)
			break;

	/*	int k = menu(5);
		if (k == 4)
			break;*/
	}

	
	textcolor(7);
	gotoxy(0, 37);
	loop_main_thread = false;
	check_nguoi_tuyet_thread_1 = false;
	check_second = false;
	check_first = false;
	first.join();
	second.join();
	
	return;
}