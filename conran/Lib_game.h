#pragma once
#include <iostream>
#include <stdio.h>
#include "Global_variable.h"
#include <conio.h>
#define MAX 100

using namespace std;

bool touch_gate();
void init();
bool check_nguoi_tuyet_va_ran(toa_do nguoi_tuyet[],int size_nguoi_tuyet,toa_do snake[MAX],int size);
void set_nguoi_tuyet(toa_do nguoi_tuyet[], char ve_nguoi_tuyet[], int size, int x, int w,bool &check, toa_do& food, int order_food,char duoi[]);
void chuong_ngai_vat_nguoi_tuyet(int x, int y, int w, int h, toa_do nguoi_tuyet[], char ve_nguoi_tuyet[], int& size_nguoi_tuyet);
void chuong_ngai_vat_nguoi(int x, int y, int w, int h);
void init_duoi(char duoi[]);
void draw(int x, int y, int w, int h, int color);
void drawBattery(int x, int y, int w, int h, int color);
void drawLevelBar(int x, int y, int w, int h, int color);
void drawSymbolSnake();
void drawDirectionBox(int x, int y, int w, int h, int color);
void drawContentBox(int x, int y, int w, int h, int color);

void draw_snake(toa_do snake[MAX], int& size, char duoi[]);
void snake_position(toa_do snake[MAX], int& size);
void set_snake(toa_do snake[MAX], int& size, int x, int y, int& x_food, int& y_food, char duoi[], int& order_food, toa_do& food, bool& check_eating, int level);
void delete_position(toa_do snake[MAX], int size);
bool snake_wall(int x, int y);
bool snake_bite_itsTail(toa_do snake[MAX], int size);
bool check_gameover(toa_do snake[MAX], int size,int x,int y,int w,int h);
void create_food(int& x, int& y, toa_do snake[MAX], int size,int &order_food, char duoi[], toa_do& food);
bool snake_coincide(toa_do snake[MAX], int size, int x, int y);
bool snake_eat_food(int x, int y, int x_food, int y_food);
void game_level_1();
void game_level_2();
void game_level_3();
bool snake_touch_obstacle(int size, toa_do snake[MAX]);
void draw_obstacle();
bool food_touch_obs(int x,int  y);
void draw_finish_gate(int level);
void move_snake();
void snake_thread();
void check_case_snake_dead(bool* ok,int round);
void save(toa_do a[MAX],toa_do b[MAX],int dodai);
void nguoi_tuyet_thread();
void highscore(player* user, int soluong);

