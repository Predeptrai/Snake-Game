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

toa_do snake[MAX];
char duoi[MAX];
int x_snake = 50, y_snake = 13;
int xfinish = 20, yfinish = 4;
bool finish = 0;
int x = 10, y = 1, w = 100, h = 27;
int pointX[MAX], pointY[MAX];
int order_food = 5;
int speed = 50;

// Nguoi tuyet
int size_nguoi_tuyet = 7;
toa_do nguoi_tuyet[MAX];
toa_do food;
char ve_nguoi_tuyet[MAX];
bool check_nguoi_tuyet = true;
int x_food, y_food;
bool gameover = false;
int check = 2;
int do_dai = 6;
toa_do gate[MAX];
int cnt_gate = 0;

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
		cout << " New game" << endl;
		gotoxy(75, 26);
		textcolor(11);
		cout << " Continue game" << endl;
		gotoxy(75, 28);
		textcolor(14);
		cout << " Highscore" << endl;
		gotoxy(75, 30);
		textcolor(14);
		cout << " Instruction" << endl;
		gotoxy(75, 32);
		textcolor(4);
		cout << " Option" << endl;
		gotoxy(75, 34);
		textcolor(9);
		cout << " Quit" << endl;
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
				else if (c == 'o')
					option = 4;
				else if (c == 'q')
					option = 5;
			}
			if (option != 0)
			{
				if (option == 1)
				{
					gameover = false;
					system("cls");
					game_level_1();
					break;
				}
				else
				{
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
	check_first = false;
	check_second = false;
	first.join();
	second.join();

	/*_getch();*/
	return;
}