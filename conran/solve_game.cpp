#include <iostream>
#include <conio.h>
#include <fstream>
#include "graphic_console.h"
#include "Lib_game.h"
#include <stdio.h>

using namespace std;

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

void set_snake(int pointX[], int pointY[], int& size, int x, int y, int &x_food, int &y_food,char duoi[])
{
	int tam = size;
	add_Val_to_1D(pointX, x, tam);
	add_Val_to_1D(pointY, y, size);

	if (snake_eat_food(pointX[0], pointY[0], x_food, y_food) == false)
	{
		tam = size;
		remove_Val_from_1D(pointX, tam - 1, tam);
		remove_Val_from_1D(pointY, size - 1, size);
	}

	else
	{
		//cout << size << endl;
		create_food(x_food, y_food, pointX, pointY, size,duoi);
		//size--;
	}

	draw_snake(pointX, pointY, size,duoi);
}

bool snake_wall(int x, int y)
{
	if ((x >= 10 && x <= 100) && y == 1)
		return true;
	else if ((x >= 10 && x <= 100) && y == 27)
		return true;
	else if ((y >= 1 && y <= 27) && x == 10)
		return true;
	else if ((y >= 1 && y <= 27) && x == 100)
		return true;

	return false;
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

bool check_gameover(int pointX[], int pointY[], int size)
{
	if (snake_wall(pointX[0], pointY[0]) || snake_bite_itsTail(pointX, pointY, size))
		return true;

	return false;
}

void create_food(int& x, int& y, int pointX[], int pointY[], int size, char* duoi)
{
	//cout << "d";
	do {
		x = rand() % (99 - 11 + 1) + 11;
		y = rand() % (26 - 2 + 1) + 2;
	} while (snake_coincide(pointX, pointY, size, x, y) == true);

	int i = rand() % (15 - 1 + 1) + 1;
	SetColor(i);
	gotoxy(x, y);
	cout << duoi[size];
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
		return true;

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
	return;
}
