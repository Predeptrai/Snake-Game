#include <iostream>
#include <conio.h>
#include <fstream>
#include "Lib_game.h"
#include "graphic_console.h"
#include <stdio.h>

using namespace std;

void set_nguoi_tuyet(toa_do nguoi_tuyet[], char ve_nguoi_tuyet[], int size,int x,int w,bool &check, toa_do& food, int order_food, char duoi[])
{
	if (check == true)// Qua phai
	{
		//Xoa nhan vat
		bool ok = false;
		for (int i = 0; i < size; i++)
		{
			gotoxy(nguoi_tuyet[i].x, nguoi_tuyet[i].y);
			
			if (nguoi_tuyet[i].x == food.x && nguoi_tuyet[i].y == food.y)
			{
				int K = rand() % (15 - 1 + 1) + 1;
				SetColor(K);
				cout << duoi[order_food];
				SetColor(7);

			}
			else
			{
				cout << " ";
			}
			nguoi_tuyet[i].x++;
			if (nguoi_tuyet[i].x == x + w - 1)
			{
				check = false;
			}
		}
		// Tao lai nhan vat
		for (int i = 0; i < size; i++)
		{
			gotoxy(nguoi_tuyet[i].x, nguoi_tuyet[i].y);
			cout << ve_nguoi_tuyet[i];
		}
	}
	else//Qua trai
	{
		//Xoa nhan vat
		for (int i = 0; i < size; i++)
		{
			gotoxy(nguoi_tuyet[i].x, nguoi_tuyet[i].y);
			if (nguoi_tuyet[i].x == food.x && nguoi_tuyet[i].y == food.y)
			{
				int K = rand() % (15 - 1 + 1) + 1;
				SetColor(K);
				cout << duoi[order_food];
				SetColor(7);

			}
			else
			{
				cout << " ";
			}
			nguoi_tuyet[i].x--;
			if (nguoi_tuyet[i].x == x + 1)
			{
				check = true;
			}
		}
		// Tao lai nhan vat
		for (int i = 0; i < size; i++)
		{
			gotoxy(nguoi_tuyet[i].x, nguoi_tuyet[i].y);
			cout << ve_nguoi_tuyet[i];
		}
	}
	return;
}


void add_Val_to_1D(int a[], int x, int& n)
{
	for (int i = n; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	n++;
}

void remove_Val_from_1D(int a[], int x, int& n)
{
	for (int i = x; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

void set_snake(int pointX[], int pointY[], int& size, int x, int y, int &x_food, int &y_food,char duoi[],int &order_food, toa_do& food,bool &check_eating)
{
	int tam = size;
	add_Val_to_1D(pointX, x, tam);
	add_Val_to_1D(pointY, y, size);

	if (snake_eat_food(pointX[0], pointY[0], food.x, food.y) == false)
	{
		tam = size;
		remove_Val_from_1D(pointX, tam - 1, tam);
		remove_Val_from_1D(pointY, size - 1, size);
	}
	else
	{
		check_eating = true;
	
		create_food(x_food, y_food, pointX, pointY, size,order_food, duoi, food);
	
	}

	draw_snake(pointX, pointY, size,duoi);
}

bool snake_wall(int a, int b, int x, int y, int w, int h)
{

	if (a > x && a < x + w && b>y && b < y + h)
		return false;
	return true;
}

bool snake_bite_itsTail(int pointX[], int pointY[], int size)
{
	for (int i = 1; i < size; i++)
	{
		if ((pointX[0] == pointX[i]) && (pointY[0] == pointY[i]))
			return true;
	}
	return false;
}

bool check_gameover(int pointX[], int pointY[], int size, int x, int y, int w, int h)
{
	if (snake_wall(pointX[0], pointY[0], x, y, w, h) || snake_bite_itsTail(pointX, pointY, size))
		return true;

	return false;
}

void create_food(int& x, int& y, int pointX[], int pointY[], int size,int &order_food,char duoi[], toa_do& food)
{
	order_food++;
	do {
		x = rand() % (99 - 11 + 1) + 11;
		y = rand() % (26 - 2 + 1) + 2;
	} while (snake_coincide(pointX, pointY, size, x, y) || food_touch_obs(x,y));
	food.x = x;
	food.y = y;

	int i = rand() % (15 - 1 + 1) + 1;
	SetColor(i);
	gotoxy(food.x, food.y);

	cout << duoi[order_food];
	SetColor(7);
}

bool snake_coincide(int pointX[], int pointY[], int size, int x, int y)
{
	for (int i = 0; i < size; i++)
	{
		if ((x == pointX[i]) && (y == pointY[i]))
			return true;
	}
	return false;
}

bool snake_eat_food(int x, int y, int x_food, int y_food)
{
	if (x == x_food && y == y_food)
	{
		return true;
	}
	return false;
}
bool check_nguoi_tuyet_va_ran(toa_do nguoi_tuyet[], int size_nguoi_tuyet, int pointX[], int pointY[], int size)
{
	for (int i = 0; i < size_nguoi_tuyet; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (pointX[j] == nguoi_tuyet[i].x && pointY[j] == nguoi_tuyet[i].y)
			{
				
				return true;
			}
		}
	}
	return false;
}
void init_duoi(char duoi[])
{
	ifstream in("data.txt");
	int i = 0;
	do
	{
		in >> duoi[i];
		i++;
	} while (duoi[i] != ' ');
	in.close();
	return;
}

bool snake_touch_obstacle(int size, int pointX[], int pointY[])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < cnt_obstacle; j++)
		{
			if (pointX[i] == obstacle[j].x && pointY[i] == obstacle[j].y)
				return true;
		}
	}	
	return false;
}

bool food_touch_obs(int x,int y)
{
	for (int i = 0; i < cnt_obstacle; i++)
	{
		if (x == obstacle[i].x && y == obstacle[i].y)
			return true;
	}
	return false;
}