#include <iostream>
#include <conio.h>
#include <fstream>
#include "Lib_game.h"
#include "graphic_console.h"
#include <stdio.h>

using namespace std;


void check_case_snake_dead(bool* ok, int round)
{
	bool check_1 = touch_gate();
	*ok = max(*ok, check_gameover(snake, do_dai, x, y, w, h));
	*ok = max(check_1, *ok);
	if (round == 2|| round == 3)
	{
		*ok = max(*ok, snake_touch_obstacle(do_dai, snake));
	}
	if (round == 3)
	{

		*ok = max(*ok,check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet, snake, do_dai));
	}
	return;
}
void move_snake()
{
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
	return;
}
void init()
{
	cnt_gate = 0;
	check = 2;
	finish = 0;
	do_dai = 6;
	init_duoi(duoi);
	order_food = 5;
	x_snake = 50, y_snake = 13;
	draw(x, y, w, h, 11);
	drawBattery(x, y, w, h, 11);
	drawLevelBar(x, y, w, h, 11);
	drawDirectionBox(x, y, w, h, 11);
	snake_position(snake, do_dai);
	drawSymbolSnake();
	drawContentBox(x, y, w, h, 11);
	draw_snake(snake, do_dai, duoi);
	srand(time(NULL));
	create_food(x_food, y_food, snake, do_dai, order_food, duoi, food);
}
void save(toa_do a[MAX], toa_do b[MAX], int dodai)
{
	for (int i = 0; i < dodai; i++)
	{
		a[i] = b[i];
	}
	return;
}

void set_nguoi_tuyet(toa_do nguoi_tuyet[], char ve_nguoi_tuyet[], int size,int x,int w,bool &check, toa_do& food, int order_food, char duoi[])
{
	gotoxy(23, 20);
	cout << order_food << endl;
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
			if (nguoi_tuyet[i].x == x + w - 2)
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
			if (nguoi_tuyet[i].x == x + 2)
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


void add_Val_to_1D(toa_do a[], int x, int& n,bool check)
{
	if (check == 0)
	{
		for (int i = n; i > 0; i--)
		{
			a[i].x = a[i - 1].x;
		}
		a[0].x = x;
		n++;
	}
	else
	{
		for (int i = n; i > 0; i--)
		{
			a[i].y = a[i - 1].y;
		}
		a[0].y = x;
		n++;
	}
}

void remove_Val_from_1D(toa_do a[], int x, int& n, bool check)
{
	if (check == 0)
	{
		for (int i = x; i < n; i++)
		{
			a[i].x = a[i + 1].x;
		}
		n--;
	}
	else
	{
		for (int i = x; i < n; i++)
		{
			a[i].y = a[i + 1].y;
		}
		n--;
	}
}


void set_snake(toa_do snake[], int& size, int x, int y, int &x_food, int &y_food,char duoi[],int &order_food, toa_do& food,bool &check_eating, int level)
{
	int tam = size;
	add_Val_to_1D(snake, x, tam,0);
	add_Val_to_1D(snake, y, size,1);

	if (snake_eat_food(snake[0].x, snake[0].y, food.x, food.y) == false)
	{
		tam = size;
		remove_Val_from_1D(snake, tam - 1, tam, 0);
		remove_Val_from_1D(snake, size - 1, size, 1);
		if (snake[0].x == xfinish && snake[0].y == yfinish && finish)
		{
			if (level == 1)
			{
				gameover_round_1 = true;
				system("cls");
				check1to2 = true;
				return;
			}
			else if (level == 2)
			{
				gameover_round_2 = true;
				system("cls");
				check2to3 = true;
				return;
			}
			else
			{
				gameover = true;
				return;
			}
		}
	}

	else if (order_food <= 5 + level * 4)
	{
		check_eating = true;
		create_food(x_food, y_food, snake, size, order_food, duoi, food);

	}
	else
	{
		check_eating = true;

		draw_finish_gate(level);
	}

	draw_snake(snake, size, duoi);
}

bool snake_wall(int a, int b, int x, int y, int w, int h)
{
	if (a > x && a < x + w && b>y && b < y + h)
		return false;
	return true;
}

bool snake_bite_itsTail(toa_do snake[], int size)
{
	for (int i = 1; i < size; i++)
	{
		if ((snake[0].x == snake[i].x) && (snake[0].y == snake[i].y))
		{
			return true;
		}
	}
	return false;
}

bool check_gameover(toa_do snake[], int size, int x, int y, int w, int h)
{

	//gotoxy(1, 2);
	//cout<< snake_bite_itsTail(pointX, pointY, size) << endl;
	if (snake_wall(snake[0].x, snake[0].y, x, y, w, h) || snake_bite_itsTail(snake, size))
		return true;

	return false;
}
bool final_food(int x, int y)
{
	if (order_food < 8)
	{
		return false;
	}
	if (order_food == 8)
	{
		if (x >= 10 && x <= 30 && y >= 1 && y <= 9)
		{
			return true;
		}
	}
	return false;
}

void create_food(int& x, int& y, toa_do snake[], int size,int &order_food,char duoi[], toa_do& food)
{
	order_food++;
	int tam_x, tam_y;
	do {
		tam_x = rand() % (99 - 11 + 1) + 11;
		tam_y = rand() % (26 - 2 + 1) + 2;
	} while (snake_coincide(snake, size, x, y) || food_touch_obs(x,y)||final_food(x,y));
	food.x = tam_x;
	food.y = tam_y;
	tam_x = x;
	tam_y = y;

	int i = rand() % (15 - 1 + 1) + 1;
	SetColor(i);
	gotoxy(food.x, food.y);

	cout << duoi[order_food];
	SetColor(7);
}

bool snake_coincide(toa_do snake[], int size, int x, int y)
{
	for (int i = 0; i < size; i++)
	{
		if ((x == snake[i].x) && (y == snake[i].y))
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
bool check_nguoi_tuyet_va_ran(toa_do nguoi_tuyet[], int size_nguoi_tuyet, toa_do snake[MAX], int size)
{
	for (int i = 0; i < size_nguoi_tuyet; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (snake[j].x == nguoi_tuyet[i].x && snake[j].y == nguoi_tuyet[i].y)
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

bool snake_touch_obstacle(int size, toa_do snake[])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < cnt_obstacle; j++)
		{
			if (snake[i].x == obstacle[j].x && snake[i].y == obstacle[j].y)
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