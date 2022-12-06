#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <conio.h>
#include "Global_variable.h"
#include "Lib_game.h"
#include <thread>
#include "graphic_console.h"

using namespace std;

void sound_phat()
{
	while (check_first)
	{
		if (check_eating > 0)
		{
			PlaySound(TEXT("sound_eating.wav"), NULL, SND_SYNC);
			check_eating--;
		}

	}
	return;
}

void sound_die()
{
	while (check_second)
	{
		if (check_die > 0)
		{
			PlaySound(TEXT("deadth.wav"), NULL, SND_SYNC);
			check_die--;
		}
	}
}

void snake_thread()
{
	loop_main_thread = true;
	while (loop_main_thread)
	{
		while (gameover_round_1 == false || gameover_round_2 == false || gameover_round_3 == false)
		{


			loop_thread_snake = true;
			bool* tam = new bool;
			if (gameover_round_1 == false)
			{
				tam = &gameover_round_1;
				level = 1;
			}
			if (gameover_round_2 == false)
			{
				tam = &gameover_round_2;
				level = 2;
			}
			if (gameover_round_3 == false)
			{
				tam = &gameover_round_3;
				level = 3;
				nguoi_tuyet_thread();
			}

			delete_position(snake, do_dai);

			if (move_snake() == 4)
			{
				flag_save = true;
				loop_thread_snake = false;
				*tam = true;
				return;
			}
			done_now_snake = false;
			set_snake(snake, do_dai, x_snake, y_snake, x_food, y_food, duoi, order_food, food, level);
			done_now_snake = true;
			done_pre_snake = false;
			save(pre_snake, snake, do_dai);
			done_pre_snake = true;
			check_case_snake_dead(tam, level);
			Sleep(100 - (5 * speed));
			if (check1to2 == true || check2to3 == true || check3to1 == true)
			{
				break;
			}
			if (*tam)
			{
				check_die++;
				return;
			}
		}
		Sleep(1);
	}
	loop_thread_snake = false;
}

void nguoi_tuyet_thread()
{
	done_now_nguoi_tuyet = false;
	set_nguoi_tuyet(nguoi_tuyet, ve_nguoi_tuyet, size_ao_nguoi_tuyet, x, w, check_nguoi_tuyet, food, order_food, duoi);
	done_now_nguoi_tuyet = true;

	done_pre_nguoi_tuyet = false;
	save(pre_nguoi_tuyet, nguoi_tuyet, size_nguoi_tuyet);
	done_pre_nguoi_tuyet = true;
	return;
}