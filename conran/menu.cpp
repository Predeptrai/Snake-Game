#include <iostream>
#include "graphic_console.h"
using namespace std;



trangthai key(int z) {
	char c;
	c = _getch();
	if (z == 224) {
		
		if (c == 72) return UP;
		if (c == 80) return DOWN;
		if (c == 75) return LEFT;
		if (c == 77) return RIGHT;
		if (c == 13) return enter;

	}
	if (z == 13) return enter;
}
int menu(int n) {
	string func[] = { "NEW GAME", "CONTINUE GAME", "HIGHSCORE","INSTRUCTION", "SPEED", "QUIT"};
	int tt = 0;
	int* tro = &tt;
	int* mau = new int[n];
	for (int i = 0; i > n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	while (1) {
		for (int i = 0; i < n; i++) {
			if (i == 0) gotoxy(77, 24);
			if (i == 1) gotoxy(75, 26);
			if (i == 2) gotoxy(77, 28);
			if (i == 3) gotoxy(76, 30);
			if (i == 4) gotoxy(79, 32);
			if (i == 5) gotoxy(79, 34);
			textcolor(mau[i]);
			cout << func[i] << endl;
		}

		int z = _getch();
		trangthai state = key(z);
		switch (state) {
			case UP: {
				if (tt == 0){
					tt = n - 1;
				}
				else {
					tt--;
				}
				break;
			}
				   
			case DOWN: {
				if (tt == n - 1) {
					tt = 0;
				}
				else {
					tt++;
				}
				break;
			}

			case enter: {
				if (tt == 0)
				{
					gotoxy(0, 0);
					cout << "vao game";
					return 0;
				}
				if (tt == 1)
				{
					gotoxy(0, 0);
					cout << "continue game";
					return 0;
				}
				if (tt == 2)
				{
					gotoxy(0, 0);
					cout << "vao game";
					return 0;
				}
				if (tt == 3)
				{
					gotoxy(0, 0);
					cout << "intro game";
					return 0;
				}
				if (tt == 4)
				{
					gotoxy(0, 0);
					cout << "speed game";
					return 0;
				}
				if (tt == 5)
				{
					gotoxy(0, 0);
					cout << "quit game";
					return 0;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
	}
	if (*tro == 0) {
		gotoxy(0, 0);
		cout << "newgame";
	}
//f (*tro==n-1)
}