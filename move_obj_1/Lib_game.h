#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

void draw(int x, int y, int w, int h, int color);
void draw_snake(int pointX[], int pointY[], int& size);
void snake_position(int pointX[], int pointY[], int& size);
void set_snake(int pointX[], int pointY[], int size, int x, int y, int x_food, int y_food);
void delete_position(int pointX[], int pointY[], int size);
bool snake_wall(int x, int y);
bool snake_bite_itsTail(int pointX[], int pointY[], int size);
bool check_gameover(int pointX[], int pointY[], int size);
void create_food(int& x, int& y, int pointX[], int pointY[], int size);
bool snake_coincide(int pointX[], int pointY[], int size, int x, int y);
bool snake_eat_food(int x, int y, int x_food, int y_food);

