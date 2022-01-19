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
void game()
{

	int size = 6;
	init_duoi(duoi);

	chuong_ngai_vat_nguoi_tuyet(x, y, w, h, nguoi_tuyet, ve_nguoi_tuyet, size_nguoi_tuyet);
	draw(x, y, w, h, 11);
	snake_position(pointX, pointY, size);
	draw_snake(pointX, pointY, size, duoi);
	srand(time(NULL));

	create_food(x_food, y_food, pointX, pointY, size, order_food, duoi, food);

	while (gameover == false && check_first)
	{
		set_nguoi_tuyet(nguoi_tuyet, ve_nguoi_tuyet, size_nguoi_tuyet, x, w, check_nguoi_tuyet, food, order_food, duoi);
		gameover = check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet, pointX, pointY, size);
		if (gameover) break;
		delete_position(pointX, pointY, size);

		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 72 && check != 0)
					check = 1;

				else if (c == 80 && check != 1)
					check = 0;

				else if (c == 75 && check != 2)
					check = 3;

				else if (c == 77 && check != 3)
					check = 2;
			}
			else
			{
				if (c == 'w' && check != 0)
					check = 1;

				else if (c == 's' && check != 1)
					check = 0;

				else if (c == 'a' && check != 2)
					check = 3;

				else if (c == 'd' && check != 3)
					check = 2;
			}
		}

		switch (check)
		{
		case 0:
			y_snake++;
			break;

		case 1:
			y_snake--;
			break;

		case 2:
			x_snake++;
			break;

		case 3:
			x_snake--;
			break;
		}
		check_eating = false;
		set_snake(pointX, pointY, size, x_snake, y_snake, x_food, y_food, duoi, order_food, food, check_eating);

		gameover = check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet, pointX, pointY, size);

		gameover = max(gameover, check_gameover(pointX, pointY, size, x, y, w, h));
		Sleep(speed);
	}

	check_first = false;
}