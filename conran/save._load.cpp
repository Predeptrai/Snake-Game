#include<iostream>
#include<fstream>
#include<string>
#include"save_load.h"
#include"Global_variable.h"

using namespace std;
#define size 100

void SaveResult(player a[], int& NumberOfPlayer, int level, int do_dai) // con chua luu level
{
	NumberOfPlayer++;
	a[NumberOfPlayer - 1].do_dai = do_dai;
	cout << "Input your name : ";
	cin.ignore();
	getline(cin, a[NumberOfPlayer - 1].name);
	for (int i = 0; i < a[NumberOfPlayer - 1].do_dai; i++)
	{
		a[NumberOfPlayer - 1].pointX[i] = pointX[i];
		a[NumberOfPlayer - 1].pointY[i] = pointY[i];
		a[NumberOfPlayer - 1].level = level;
	}
}

void LoadResult(player a[], int& NumberOfPlayer, player b)
{
	cout << "Input your name :";
	getline(cin, b.name);
	for (int i = 0; i < NumberOfPlayer; i++)
	{
		if (b.name == a[i].name)
		{
			b.level = a[i].level;
			b.do_dai = a[i].do_dai;
			for (int j = 0; j < b.do_dai; j++)
			{
				b.pointX[i] = a[i].pointX[i];
				b.pointY[i] = a[i].pointY[i];
			}
		}
	}
}


//void showHighScore() {
//	ifstream fin;
//	player a[5];
//	fin.open("highscore.txt", ios::in);
//	if (fin.is_open()) {
//		for (int i = 0; i < 5; i++) {
//			fin >> a[i].
//		}
//	}
//	fin.close();
//}