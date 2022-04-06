#include <iostream>
#include <conio.h>
#include <thread>
#include "Global_variable.h"
#include "Lib_game.h"
#include "graphic_console.h"

using namespace std;



// tao thread cho nguoi tuyet va gan 2 bien check1 va check2 cho 2 luong snake va nguoi tuyet va check ben nguoi tuyet ( do snake cho 1 vong thi nguoi tuyet da chay duoc nhieu vong 
// tao 
void game_level_1()
{
	//10 1 100 27
	flag_save = false;
	init();
	nameLevel1(x, y, h, w, 12);
	/*savedata(score, lever);*/
	
		first_time = false;
		check1to2 = false;
		bool dieu_huong = false;
		loop_thread_snake = true;
		gameover_round_1 = false;
		
		while (gameover_round_1 == false && loop_thread_snake == true)
		{
			if (check1to2 == true)
			{
				gameover_round_1 = true;
				speed++;
				game_level_2();
				break;
			}
		}

		if (!flag_save) {
			gotoxy(50, 15);
			cout << "Press Y to continue.";
			char c = _getch();
			if (c == 'y') {
				system("cls");
				speed = 2;
				thread snake_round(snake_thread);
				game_level_1();
				snake_round.join();
			}
		}

		system("cls");
		loop_thread_snake = false;
	return;
}
