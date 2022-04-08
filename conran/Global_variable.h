#pragma once
#include <iostream>
#include <stdio.h>
#include <thread>
#include <conio.h>
#define MAX 100
#define WIDTH 1320
#define HEIGHT 700
#define X_CENTER WIDTH / 20
#define Y_CENTER HEIGHT / 32
// Board game
#define SPACE 32
#define ENTER 13
#define ESC 27
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77

using namespace std;

struct toa_do
{
	int x, y;
};

struct player {
	int lvl, score = 0;
	char* name;
};

extern toa_do obstacle[MAX * MAX];
extern int cnt_obstacle;

extern int xfinish, yfinish;
extern bool finish;;
extern bool check_first;
extern bool check_second;
extern int pass;
extern char duoi[MAX];
extern int x_snake, y_snake;
extern int x, y, w, h;
extern int score;
extern int level;
extern int pointX[MAX], pointY[MAX];
extern int order_food;
extern int speed;
extern char* filesave;
extern int basescore;

// Nguoi tuyet
extern int size_nguoi_tuyet;
extern toa_do nguoi_tuyet[MAX];
extern toa_do food;
extern char ve_nguoi_tuyet[MAX];
extern bool check_nguoi_tuyet;
extern int x_food, y_food;
extern bool gameover;
extern int check;
extern int do_dai;
extern toa_do gate[MAX];
extern int cnt_gate;
extern bool check1to2;
extern bool check2to3;
extern toa_do snake[MAX];
extern bool gameover_round_1;
extern bool gameover_round_2;
extern bool gameover_round_3;
extern bool block;
extern bool check_snake;
extern bool check_nguoi_tuyet_thread_1;
extern bool check_nguoi_tuyet_thread_2;
extern bool loop_thread_snake;
extern bool done_pre_snake;
extern bool done_now_snake;
extern toa_do pre_snake[MAX];

extern toa_do pre_nguoi_tuyet[MAX];
extern bool done_pre_nguoi_tuyet;
extern bool done_now_nguoi_tuyet;

extern int size_ao_nguoi_tuyet;
extern bool loop_main_thread;
extern bool check3to1;
extern thread snake_round();
extern int check_eating;
extern int check_die;
extern bool first_time;
extern bool flag_save;