#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#define MAX 100

using namespace std;

struct toa_do
{
	int x, y;
};

extern toa_do obstacle[MAX * MAX];
extern int cnt_obstacle;

extern bool check_eating;
extern bool check_first;
extern char duoi[MAX];
extern int x_snake, y_snake;
extern int x, y, w, h;
extern int pointX[MAX], pointY[MAX];
extern int order_food;
extern int speed;

// Nguoi tuyet
extern int size_nguoi_tuyet;
extern toa_do nguoi_tuyet[MAX];
extern toa_do food;
extern char ve_nguoi_tuyet[MAX];
extern bool check_nguoi_tuyet;
extern int x_food, y_food;
extern bool gameover;
extern int check;
