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

		//if (z == 72) return UP;
		//if (z == 80) return DOWN;
		//if (z == 75) return LEFT;
		//if (z == 77) return RIGHT;
		//if (z == 13) return enter;

	}
	if (z == 13) return enter;
}
int menu(int n) {
	string func[] = { "NEW GAME", "CONTINUE GAME", "HIGHSCORE","INSTRUCTION", "QUIT" };
	int tt = 0;
	int* mau = new int[n];
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	int direction = 1;
	mau[0] = MAUNEN;
	while (direction) {
		for (int i = 0; i < n; i++) {
			if (i == 0) gotoxy(77, 24);
			if (i == 1) gotoxy(75, 26);
			if (i == 2) gotoxy(77, 28);
			if (i == 3) gotoxy(76, 30);
			if (i == 4) gotoxy(79, 32);
			if (i == 5) gotoxy(79, 34);
			textcolor(mau[i]);
			cout << func[i] << endl;
			gotoxy(0, 0);
		}

		int z = _getch();
		trangthai state = key(z);
		switch (state) {
		case UP: {
			if (tt == 0) {
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
				// vao game level 1
				system("cls");
				score = 0;
				speed = 2;
				thread snake_round(snake_thread);
				game_level_1();
				snake_round.join();
				return 0;
			}
			if (tt == 1)
			{
				const char* filename = "slot1.txt";
				tieptuc(filename);
				return 0;
			}
			if (tt == 2)
			{
				highScoreBoard();
				return 0;
			}
			if (tt == 3)
			{
				// intro game
				system("cls");
				drawIntro(x, y, w, h, 11);
				gotoxy(x + w / 2 + 10, y + h + 3);
				system("cls");
				return 0;
			}
			if (tt == 4)
			{
				return 4;
			}
		}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
	}
}

void drawIntro(int x, int y, int w, int h, int color) {
	system("cls");
	bool direction = 1;
	while (direction) {
		textcolor(12);
		for (int ix = x + 5; ix <= x + 53 + w; ix++)
		{
			gotoxy(ix, y);
			cout << char(219);
			gotoxy(ix, y + h + 10);
			cout << char(219);
		}

		for (int iy = y; iy <= y + h + 10; iy++)
		{
			gotoxy(x + 5, iy);
			cout << char(219);
			gotoxy(x + 53 + w, iy);
			cout << char(219);
		}
		textcolor(11);
		gotoxy(x + w / 2 - 5, y + 2);
		cout << "    _____   ____________  ____  ____  __  ______________________  _   __";
		gotoxy(x + w / 2 - 5, y + 3);
		cout << "   /  _/ | / /_  __/ __ \\/ __ \\/ __ \\/ / / / ____/_  __/  _/ __ \\/ | / /";
		gotoxy(x + w / 2 - 5, y + 4);
		cout << "   / //  |/ / / / / /_/ / / / / / / / / / / /     / /  / // / / /  |/ /";
		gotoxy(x + w / 2 - 5, y + 5);
		cout << " _/ // /|  / / / / _, _/ /_/ / /_/ / /_/ / /___  / / _/ // /_/ / /|  /";
		gotoxy(x + w / 2 - 5, y + 6);
		cout << "/___/_/ |_/ /_/ /_/ |_|\\____/_____/\\____/\\____/ /_/ /___/\\____/_/ |_/";
		drawIDStudent(x, y, w, h, 12);

		gotoxy(0, 0);
		cout << "ESC to escaspe";
		if (_kbhit()) {
			char c = _getch();
			if (c == 27) {
				direction = 0;
			}
		}
	}
	return;
	//system("pause");
}

void drawIDStudent(int x, int y, int w, int h, int color) {
	textcolor(12);
	ShowCur(0);
	for (int ix = x + 15; ix <= x + 78; ix++) {
		gotoxy(ix, y + 10);
		cout << char(219);
		gotoxy(ix, y + 33);
		cout << char(219);
	}

	for (int iy = y + 10; iy <= y + 33; iy++) {
		gotoxy(x + 15, iy);
		cout << char(219);
		gotoxy(x + 78, iy);
		cout << char(219);
	}
	//textcolor(39);
	textcolor(15);
	gotoxy(x + 28, y + 13);
	cout << " ____  ____    __    __  __    ___";
	gotoxy(x + 28, y + 14);
	cout << "(_  _)( ___)  /__\\  (  \\/  )  (__ )";
	gotoxy(x + 28, y + 15);
	cout << "  )(   )__)  /(__)\\  )    (    (_ \\";
	gotoxy(x + 28, y + 16);
	cout << " (__) (____)(__)(__)(_/\\/\\_)  (___/";

	//textcolor(224);
	gotoxy(x + 25, y + 19);
	cout << "PHAM HONG GIA BAO";
	gotoxy(x + 25, y + 22);
	cout << "NGUYEN HUY THANH";
	gotoxy(x + 25, y + 25);
	cout << "PHAN HUU PHUOC";
	gotoxy(x + 25, y + 28);
	cout << "LE NGUYEN THAI";

	gotoxy(x + 55, y + 19);
	cout << "21127014";
	gotoxy(x + 55, y + 22);
	cout << "21127430";
	gotoxy(x + 55, y + 25);
	cout << "21127636";
	gotoxy(x + 55, y + 28);
	cout << "21127162";
	drawRule(x, y, w, h, 12);

}

void drawRule(int x, int y, int w, int h, int color) {
	textcolor(12);
	ShowCur(0);
	for (int ix = x + 83; ix <= x + 145; ix++) {
		gotoxy(ix, y + 8);
		cout << char(219);
		gotoxy(ix, y + 33);
		cout << char(219);
	}

	for (int iy = y + 8; iy <= y + 33; iy++) {
		gotoxy(x + 83, iy);
		cout << char(219);
		gotoxy(x + 145, iy);
		cout << char(219);
	}
	textcolor(15);
	gotoxy(x + 105, y + 10);
	cout << "  ___ _   _ _    ___";
	gotoxy(x + 105, y + 11);
	cout << " | _ \\ | | | |  | __|";
	gotoxy(x + 105, y + 12);
	cout << " |   / |_| | |__| _|";
	gotoxy(x + 105, y + 13);
	cout << " |_|_\\\\___/|____|___|";

	gotoxy(x + 90, y + 17);
	cout << "Use the LEFT arrow, UP arrow, DOWN arrow and RIGHT ";
	gotoxy(x + 90, y + 19);
	cout << "Or use A, W, S and D";
	gotoxy(x + 90, y + 21);
	cout << "arrow to control the snake.";
	gotoxy(x + 90, y + 23);
	cout << "Try to avoid hitting the obstacles and snake's body.";
	gotoxy(x + 90, y + 25);
	cout << "Eat enough food to level up.";
	gotoxy(x + 90, y + 27);
	cout << "Press \"L\" button to SAVE THE GAME.";
	gotoxy(x + 110, y + 30);
	cout << "ENJOY THE GAME!";
}