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
	if (round == 2 || round == 3)
	{
		*ok = max(*ok, snake_touch_obstacle(do_dai, snake));
	}
	if (round == 3)
	{

		*ok = max(*ok,check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet, snake, do_dai));
	}
	return;
}
int move_snake()
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
			else if (c == 'l')
				check = 4;
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
		return check;
}
void init()
{
	system("cls");
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
	//powerBattery();
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


void set_snake(toa_do snake[], int& size, int x, int y, int &x_food, int &y_food,char duoi[],int &order_food, toa_do& food, int level)
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
				check1to2 = true;
				return;
			}
			else if (level == 2)
			{
				check2to3 = true;
				return;
			}
			else
			{
				if (level == 3)
				{
					check3to1 = true;
					return;
				}

			}
		}
	}

	else if (order_food < 5 + level * 4)
	{
		check_eating++;
		score += 10;
		Sleep(2);
		create_food(x_food, y_food, snake, size, order_food, duoi, food);
		if (!gameover_round_1) 
		{
			powerBattery_Level_1();
		}
		else
		{
			if (!gameover_round_2)
			{
				powerBattery_Level_2();
			}
			else 
			{
				if (!gameover_round_3)
				{
					powerBattery_Level_3();
				}
			}
		}
	}
	else
	{
		check_eating++;
		Sleep(2);
		score += 50;
		order_food++;
		draw_finish_gate(level);
		if (!gameover_round_1)
		{
			powerBattery_Level_1();
		}
		else
		{
			if (!gameover_round_2)
			{
				powerBattery_Level_2();
			}
			else
			{
				if (!gameover_round_3)
				{
					powerBattery_Level_3();
				}
			}
		}
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
	if (order_food != 10 || order_food != 14 || order_food != 18)
	{
		return false;
	}
	if (order_food == 10 || order_food == 14 || order_food == 18)
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
	} while (snake_coincide(snake, size, tam_x, tam_y) || food_touch_obs(tam_x, tam_y)||final_food(tam_x, tam_y));
	food.x = tam_x;
	food.y = tam_y;
	x = tam_x;
	y = tam_y;

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

bool isValidName(player* user, int soluong, int pos) {
	if (pos < 1)
		return false;
	int len = strlen(user[pos].name);
	bool flag = 0;
	for (int i = 0; i < pos; i++) {
		flag = 1;
		for (int j = 0; j < len; j++) {
			if (user[i].name[j] != user[pos].name[j]) {
				flag = 0;
				break;
			}
		}
		if (flag)
			break;
	}
	return flag;
}

void savedata(const char slot[10])
{
	ofstream out(slot, ios::trunc);
	out << level << endl;
	out << score << endl;
	out << speed;
	out.close();
}
void tieptuc(const char slot[10])
{
	ifstream in(slot, ios::in);
	in >> level;
	in >> score;
	in >> speed;
	if (level == 1)
	{
		system("cls");
		thread snake_round(snake_thread);
		game_level_1();
		snake_round.join();
	}
	else if (level == 2)
	{
		system("cls");
		pass = 1;
		thread snake_round(snake_thread);
		game_level_1();
		snake_round.join();
	}
	else
	{
		system("cls");
		pass = 2;
		thread snake_round(snake_thread);
		game_level_1();
		snake_round.join();
	}
	in.close();
}

void powerBattery_Level_1() {
	if (order_food == 7) {
		for (int i = 11; i <= 34; i++) {
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 8) {
		for (int i = 36; i <= 60; i++) {
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 9) {
		for (int i = 62; i <= 86; i++) {
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 10) {
		for (int i = 88; i <= 109; i++) {
			gotoxy(i, 31);
			cout << char(219);
		}
	}

	return;
}

void powerBattery_Level_2() {
	if (order_food == 7) {
		for (int i = 11; i <= 23; i++) { //34
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 8) {
		for (int i = 24; i <= 34; i++) { //34
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 9) {
		for (int i = 36; i <= 48; i++) { //60
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 10) {
		for (int i = 49; i <= 60; i++) { //60
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 11) {
		for (int i = 62; i <= 74; i++) { // 86
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 12) {
		for (int i = 75; i <= 86; i++) { // 86
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 13) {
		for (int i = 88; i <= 100; i++) {
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 14) {
		for (int i = 101; i <= 109; i++) {
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	return;
}

void powerBattery_Level_3() {
	if (order_food == 7) {
		for (int i = 11; i <= 19; i++) { //34
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 8) {
		for (int i = 20; i <= 27; i++) { //34
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 9) {
		for (int i = 28; i <= 34; i++) {
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 10) {
		for (int i = 36; i <= 44; i++) { //60
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 11) {
		for (int i = 45; i <= 53; i++) { // 86
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 12) {
		for (int i = 54; i <= 60; i++) { // 86
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 13) {
		for (int i = 62; i <= 70; i++) {
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 14) {
		for (int i = 71; i <= 79; i++) {
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 15) {
		for (int i = 80; i <= 86; i++) {
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 16) {
		for (int i = 88; i <= 96; i++) {
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 17) {
		for (int i = 97; i <= 104; i++) {
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	if (order_food == 18) {
		for (int i = 105; i <= 109; i++) {
			gotoxy(i, 31);
			cout << char(219);
		}
	}
	return;
}