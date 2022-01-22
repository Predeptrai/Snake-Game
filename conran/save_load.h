#pragma once
#include<string>
using namespace std;

#define size 100

struct player {
	string name;
	int pointX[size], pointY[size];
	int do_dai;
	int level;
};

void SaveResult(player a[], int& NumberOfPlayer);