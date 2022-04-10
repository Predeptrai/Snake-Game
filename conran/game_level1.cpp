#include <iostream>
#include <conio.h>
#include <thread>
#include "Global_variable.h"
#include "Lib_game.h"
#include "graphic_console.h"
#include <string>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef pair <int, string> thong_tin;
void sort_score(string s)
{
	ifstream fin;
	fin.open("highscore.txt", ios::beg);
	thong_tin a[100];
	int n = 0;
	while (true)
	{
		fin >> a[n].first;
		if (a[n].first == -1) break;
		fin.ignore();
		fin >> a[n].second;
		a[n].first *= (-1);
		n++;
	}
	a[n].first = -score;
	a[n].second = s;
	n++;
	sort(a, a + n);

	fin.close();


	ofstream fout;
	fout.open("highscore.txt", ios::out);
	for (int i = 0; i < n; i++)
	{
		fout << -a[i].first << " " << a[i].second << endl;
	}
	fout << "-1" << endl;
	fout.close();
	return;
}

// tao thread cho nguoi tuyet va gan 2 bien check1 va check2 cho 2 luong snake va nguoi tuyet va check ben nguoi tuyet ( do snake cho 1 vong thi nguoi tuyet da chay duoc nhieu vong 
void game_level_1()
{
	//10 1 100 27
	if (pass == 0)
	{
		savedata(filesave);
	}
	flag_save = false;
	init();
	nameLevel1(x, y, h, w, 12);


	first_time = false;
	check2to3 = false;
	check3to1 = false;
	check1to2 = false;
	bool dieu_huong = false;
	gameover_round_1 = false;
	loop_thread_snake = true;
	Sleep(0.1);
	while (gameover_round_1 == false && loop_thread_snake == true)
	{
		if (check1to2 == true || pass > 0)
		{
			if (pass == 0)
			{
				speed += 3;
				score += 50;
			}
			else
				pass--;
			check1to2 = true;
			gameover_round_1 = true;
			level = 2;
			game_level_2();
			break;
		}
	}
	loop_main_thread = false;
	Sleep(0.1);
	if (!flag_save) {
		gotoxy(30, 15);
		cout << "Press Y to load from last checkpoint or press ESC to return the menu!";
		char c;
		do
		{
			c = _getch();
			if (c == 'y') {
				loop_main_thread = true;
				system("cls");
				thread snake_round(snake_thread);
				pass = level - 1;
				score = basescore;
				game_level_1();
				loop_main_thread = false;
				snake_round.join();
				system("cls");
			}
			if (c == 27)
			{
				check_esc = true;
			}
			if (check_esc)
			{
				c = 27;
			}
			
		} while (c != 27);
		flag_save = true;
	}
	system("cls");
	if (save_name == false)
	{
		ofstream fout("highscore.txt", ios::app);
		string s;
		gotoxy(68, 18);
		cout << "Enter your name (max 5 charaters): ";
		cin >> s;
		//cout << s << endl;
		fout.close();
		sort_score(s);
		save_name = true;
	}
	loop_thread_snake = false;
	loop_main_thread = false;
	return;
}
