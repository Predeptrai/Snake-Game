#pragma once
#include <string.h>
#include <iostream>
#include "Lib_game.h"
#include <Windows.h>

using namespace std;
#define MAUNEN 175
#define MAUCHU 7 
enum trangthai { UP, DOWN, LEFT, RIGHT, enter, BACK };
void FixConsoleWindow();
void resizeConsole(int width, int height);
void textcolor(int x);
void gotoxy(int x, int y);
void SetColor(WORD color);
void ShowCur(bool CursorVisibility);
void drawSnakeShape();
void setConsole();
void graphicConsole();
void menuBoard();
void draw_SnakeTxt();
void highScoreBoard();
int menu(int n);
trangthai key(int z);
void nameLevel1(int x, int y, int h, int w, int color);
void nameLevel2(int x, int y, int h, int w, int color);
void nameLevel3(int x, int y, int h, int w, int color);