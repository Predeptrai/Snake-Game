#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <thread>
#include "Global_variable.h"
#include "graphic_console.h"
#include "Lib_game.h"

using namespace std;
void game_level_3()
{
	//thread conran(snake_thread);
	const char* filename = "slot1.txt";
	savedata(filename);
	init();
	nameLevel3(x, y, h, w, 12);
	draw_obstacle();
	chuong_ngai_vat_nguoi_tuyet(x, y, w, h, nguoi_tuyet, ve_nguoi_tuyet, size_nguoi_tuyet);
	gameover_round_3 = false;
	check_nguoi_tuyet_thread_1 = true;
	check_nguoi_tuyet_thread_2 = true;
	check3to1 = false;
	speed = 2;
	while (gameover_round_3 == false && loop_thread_snake == true)
	{
		check2to3 = false;
		if (check3to1)
		{
			gameover_round_3 = true;
			speed++;
			level = 1;
			game_level_1();
		}
		//set_nguoi_tuyet(nguoi_tuyet, ve_nguoi_tuyet, size_nguoi_tuyet, x, w, check_nguoi_tuyet, food, order_food, duoi);	
		//if (gameover) break;
		//speed++;
		//game_level_1();
		//break;
	}
	/*cout << "Press Y to continue or Enter to return to Mainmenu" << endl;
	char key = _getch();
	if (key != 'y')
	{
		system("cls");
		return;
	}
	if (key == 'y')
	{
		system("cls");
		game_level_1();
	}*/

	check_nguoi_tuyet_thread_2 = false;
	check_nguoi_tuyet_thread_1 = false;
	//conran.join();
	return;
}