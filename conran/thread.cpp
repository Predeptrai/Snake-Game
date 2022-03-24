#include <iostream>
#include <conio.h>
#include "Global_variable.h"
#include "Lib_game.h"
#include "graphic_console.h"

using namespace std;


void snake_thread()
{
	int dem = 0;
	while (loop_main_thread)
	{
		/*gotoxy(10, 10);
		cout << gameover_round_1 << " " << gameover_round_2 << " " << gameover_round_3 << endl;*/
		while (gameover_round_1 == false || gameover_round_2 == false || gameover_round_3 == false)
		{	
			loop_thread_snake = true;
			int round = 0;
			bool* tam=new bool;
			if (gameover_round_1 == false)
			{
				tam = &gameover_round_1;
				round = 1;
			}
			if (gameover_round_2 == false)
			{
				tam = &gameover_round_2;
				round = 2;
			}
			if (gameover_round_3 == false)
			{
				tam = &gameover_round_3;
				round = 3;
			}

			delete_position(snake, do_dai);

			move_snake();

			done_now_snake = false;
			set_snake(snake, do_dai, x_snake, y_snake, x_food, y_food, duoi, order_food, food, check_eating, round);
			done_now_snake = true;

			done_pre_snake = false;
			save(pre_snake, snake, do_dai);
			done_pre_snake = true;

			check_eating = false;
			
			check_case_snake_dead(tam, round);

			if (check1to2 == true || check2to3 == true)
			{
				break;
			}

			Sleep(100 / speed);
			if (*tam)
			{
				check_die = true;
				Sleep(0.1);
				check_die = false;
				gotoxy((x + w) / 2 - 9, (y + h) / 2);
			}
		}
	
		loop_thread_snake = false;
		Sleep(1);

	}
	cout << "Exited";
}
void check_nguoi_tuyet_va_ran_thread()
{
	while (check_nguoi_tuyet_thread_1)
	{
		while (check_nguoi_tuyet_thread_2)
		{
			if (done_now_nguoi_tuyet == true && done_now_snake == true)
			{
				gameover_round_3 = max(gameover_round_3,check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet, snake, do_dai));
			}


			if (done_now_nguoi_tuyet == true && done_pre_snake == true)
			{
				gameover_round_3 = max(gameover_round_3, check_nguoi_tuyet_va_ran(nguoi_tuyet, size_nguoi_tuyet, pre_snake, do_dai));
			}


			if (done_pre_nguoi_tuyet == true && done_now_snake == true)
			{
				gameover_round_3 = max(gameover_round_3, check_nguoi_tuyet_va_ran(pre_nguoi_tuyet, size_nguoi_tuyet, snake, do_dai));
			}


			if (done_pre_nguoi_tuyet == true && done_pre_snake == true)
			{
				gameover_round_3 = max(gameover_round_3, check_nguoi_tuyet_va_ran(pre_nguoi_tuyet, size_nguoi_tuyet, pre_snake, do_dai));
			}
		}
		Sleep(1);
	}
}

void nguoi_tuyet_thread()
{
	while (check_nguoi_tuyet_thread_1)
	{
		while (check_nguoi_tuyet_thread_2 || gameover_round_3 == false)
		{
			done_now_nguoi_tuyet = false;
			set_nguoi_tuyet(nguoi_tuyet, ve_nguoi_tuyet, size_ao_nguoi_tuyet, x, w, check_nguoi_tuyet, food, order_food, duoi);
			done_now_nguoi_tuyet = true;

			done_pre_nguoi_tuyet = false;
			save(pre_nguoi_tuyet, nguoi_tuyet, size_nguoi_tuyet);
			done_pre_nguoi_tuyet = true;

			Sleep(20);
		}
		Sleep(1);
	}
}