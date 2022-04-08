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
using namespace std;



// tao thread cho nguoi tuyet va gan 2 bien check1 va check2 cho 2 luong snake va nguoi tuyet va check ben nguoi tuyet ( do snake cho 1 vong thi nguoi tuyet da chay duoc nhieu vong 
// tao 
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
	check1to2 = false;
	bool dieu_huong = false;
	loop_thread_snake = true;
	gameover_round_1 = false;

	while (gameover_round_1 == false && loop_thread_snake == true)
	{
		if (check1to2 == true || pass > 0)
		{
			if (pass == 0)
			{
				speed++;
				score += 50;
			}
			else
				pass--;
			check1to2 == true;
			gameover_round_1 = true;
			level = 2;
			game_level_2();
			break;
		}
	}

	if (!flag_save) {
		gotoxy(50, 15);
		cout << "Press Y to load from last checkpoint.";
		char c;
		do
		{
			c = _getch();
			if (c == 'y') {
				system("cls");
				thread snake_round(snake_thread);
				pass = level - 1;
				score = basescore;
				game_level_1();
				snake_round.join();
				system("cls");
			}
		} while (c != 27);
		flag_save = true;
	}
	system("cls");
	ofstream fout("highscore.txt", ios::app);
	char* s = new char[6];
	gotoxy(68, 18);
	cout << "Enter your name (max 5 charaters): ";
	cin.getline(s, 6);
	fout << s << " " << score << endl;
	fout.close();
	delete[]s;
	loop_thread_snake = false;
	loop_main_thread = false;
	return;
}
