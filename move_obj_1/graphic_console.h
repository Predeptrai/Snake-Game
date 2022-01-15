#pragma once
#include <string.h>
#include <iostream>
#include <Windows.h>

using namespace std;

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