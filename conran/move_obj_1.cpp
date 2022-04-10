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

toa_do snake[MAX], pre_snake[MAX];
bool done_pre_snake = false, done_now_snake = false;
char duoi[MAX];
int x_snake = 50, y_snake = 13;
int xfinish = 20, yfinish = 4;
bool finish = 0;
int x = 10, y = 1, w = 100, h = 27;
int pointX[MAX], pointY[MAX];
int order_food = 5;
int speed = 50;
int score = 0;
int level = 1;
int pass = 0;
int basescore = 0;
char* filesave = (char*)"temp.txt";

// Nguoi tuyet
int size_nguoi_tuyet = 7, size_ao_nguoi_tuyet = 19;
toa_do nguoi_tuyet[MAX], pre_nguoi_tuyet[MAX];
bool done_pre_nguoi_tuyet = false, done_now_nguoi_tuyet = false;
toa_do food;
char ve_nguoi_tuyet[MAX];
bool check_nguoi_tuyet = true;
bool check_nguoi_tuyet_thread_1 = true;
bool check_nguoi_tuyet_thread_2 = false;
bool loop_main_thread = true;
int x_food, y_food;
int playagain = 1;
bool check_esc = false;
bool save_name = false;

bool gameover = false;
bool block = true;
bool gameover_round_1 = true;
bool gameover_round_2 = true;
bool gameover_round_3 = true;
bool check_snake = true;
bool loop_thread_snake = false;
bool flag_save = false;

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
		menuSaveSlot(4);
		system("cls");
		graphicConsole();
		int k = menu(5);
		if (k == 4)
			break;
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