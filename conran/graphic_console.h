#pragma once
#include <string.h>
#include <iostream>
#include "Lib_game.h"
#include <Windows.h>
#define MAUNEN 175
#define MAUCHU 7 
enum trangthai { UP, DOWN, LEFT, RIGHT, enter, BACK };
using namespace std;
void SetWindowSize(SHORT width, SHORT height);
void FixConsoleWindow();
void resizeConsole(int width, int height);
void textcolor(int x);
void gotoxy(int x, int y);
void XoaManHinh();
void ToMau(int x, int y, string& a, int color);
void SetColor(WORD color);
int whereX();
int whereY();
void ShowCur(bool CursorVisibility);
int inputKey();
void drawSnakeShape();
void setConsole();
void graphicConsole();
void menuBoard();
void draw_SnakeTxt();
void highScoreBoard();
int menu(int n);
trangthai key(int z);