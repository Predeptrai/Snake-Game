#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>


using namespace std;

struct toa_do
{
	int x, y;
};


bool check_nguoi_tuyet_va_ran(toa_do nguoi_tuyet[],int size_nguoi_tuyet,int pointX[],int pointY[],int size);


void set_nguoi_tuyet(toa_do nguoi_tuyet[], char ve_nguoi_tuyet[], int size, int x, int w,bool &check, toa_do& food, int order_food,char duoi[]);


void chuong_ngai_vat_nguoi_tuyet(int x, int y, int w, int h, toa_do nguoi_tuyet[], char ve_nguoi_tuyet[], int size_nguoi_tuyet);
void chuong_ngai_vat_nguoi(int x, int y, int w, int h);
void init_duoi(char duoi[]);
void draw(int x, int y, int w, int h, int color);
void draw_snake(int pointX[], int pointY[], int& size, char duoi[]);
void snake_position(int pointX[], int pointY[], int& size);
void set_snake(int pointX[], int pointY[], int& size, int x, int y, int& x_food, int& y_food, char duoi[], int& order_food, toa_do& food, bool& check_eating);
void delete_position(int pointX[], int pointY[], int size);
bool snake_wall(int x, int y);
bool snake_bite_itsTail(int pointX[], int pointY[], int size);
bool check_gameover(int pointX[], int pointY[], int size,int x,int y,int w,int h);
void create_food(int& x, int& y, int pointX[], int pointY[], int size,int &order_food, char duoi[], toa_do& food);
bool snake_coincide(int pointX[], int pointY[], int size, int x, int y);
bool snake_eat_food(int x, int y, int x_food, int y_food);

