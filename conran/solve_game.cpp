#include <iostream>
#include <conio.h>
#include "graphic_console.h"
#include "Lib_game.h"
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
		//cout << size << endl;
		create_food(x_food, y_food, pointX, pointY, size,order_food, duoi, food);
		//size--;
	}

	draw_snake(pointX, pointY, size,duoi);
}

bool snake_wall(int a, int b, int x, int y, int w, int h)
{
	if (a > x && a < x + w && b>y && b < y + h)
		return false;
	return true;
	//if ((x >= 10 && x <= 100+10) && y == 1)
	//	return true;
	//else if ((x >= 10 && x <= 100) && y == 27)
	//	return true;
	//else if ((y >= 1 && y <= 27) && x == 10)
	//	return true;
	//else if ((y >= 1 && y <= 27) && x == 100)
	//	return true;

	//return false;
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
	//cout << "d";
	order_food++;
	do {
		x = rand() % (99 - 11 + 1) + 11;
		y = rand() % (26 - 2 + 1) + 2;
	} while (snake_coincide(pointX, pointY, size, x, y));
	food.x = x;
	food.y = y;
	int i = rand() % (15 - 1 + 1) + 1;
	SetColor(i);
	gotoxy(x, y);
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
		//Beep(400, 50);
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

	duoi[0] = '2';
	duoi[1] = '1';
	duoi[2] = 'C';
	duoi[3] = 'L';
	duoi[4] = 'C';
	duoi[5] = '0';
	duoi[6] = '7';
	duoi[7] = '_';
	duoi[8] = '2';
	duoi[9] = '1';
	duoi[10] = '1';
	duoi[11] = '2';
	duoi[12] = '7';
	duoi[13] = '1';
	duoi[14] = '6';
	duoi[15] = '2';
	duoi[16] = '-';
	duoi[17] = '2';
	duoi[18] = '1';
	duoi[19] = '1';
	duoi[20] = '2';
	duoi[21] = '7';

	duoi[22] = '4';
	duoi[23] = '3';
	duoi[24] = '0';
	duoi[25] = '2';
	duoi[26] = '1';
	duoi[27] = '1';
	duoi[28] = '2';
	duoi[29] = '7';
	duoi[30] = '6';
	duoi[31] = '7';

	duoi[32] = '6';
	duoi[33] = '2';
	duoi[34] = '1';
	duoi[35] = '1';
	duoi[36] = '2';
	duoi[37] = '7';
	duoi[38] = '0';
	duoi[39] = '1';
	duoi[40] = '4';
	return;
}
