#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Global_variable.h"
#include "graphic_console.h"
#include "Lib_game.h"

using namespace std;
void game_level_3()
{
	draw_obstacle();
	chuong_ngai_vat_nguoi_tuyet(x, y, w, h, nguoi_tuyet, ve_nguoi_tuyet, size_nguoi_tuyet);
	init();
	gameover_round_3 = false;
	check_nguoi_tuyet_thread_1 = true;
	check_nguoi_tuyet_thread_2 = true;
	while (gameover_round_3 == false || loop_thread_snake == true)
	{
		check2to3 = false;;
		//set_nguoi_tuyet(nguoi_tuyet, ve_nguoi_tuyet, size_nguoi_tuyet, x, w, check_nguoi_tuyet, food, order_food, duoi);	
		//if (gameover) break;

	}
	check_eating = false;
	return;
}