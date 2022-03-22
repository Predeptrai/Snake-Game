#include <iostream>
#include <conio.h>
#include "Global_variable.h"
#include "Lib_game.h"
#include "graphic_console.h"

using namespace std;



// tao thread cho nguoi tuyet va gan 2 bien check1 va check2 cho 2 luong snake va nguoi tuyet va check ben nguoi tuyet ( do snake cho 1 vong thi nguoi tuyet da chay duoc nhieu vong 
// tao 
void game_level_1()
{
	//10 1 100 27
	init();
	check1to2 = false;
	bool dieu_huong = false;

	gameover_round_1 = false;
	while (gameover_round_1 == false || loop_thread_snake == true)
	{
		if (check1to2 == true)
		{
			loop_thread_snake = false;
			game_level_2();
		}
	}

	check_eating = false;
	//snake_round_1.join();

	return;
}
