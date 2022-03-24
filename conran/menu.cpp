//#include
//
//#define MAUNEN 175
//#define MAUCHU 7
//
//typedef char str[30];
//str func[5] = { "NEW GAME", "CONTINUE GAME", "HIGHSCORE", "OPTION", "QUIT" };
//
//enum trangthai { UP, DOWN, LEFT, RIGHT, ENTER, BACK };
//trangthai key(int z)
//{
//	if (z == 224)
//	{
//		char c;
//		c = _getch();
//		if (c == 72) return UP;
//		if (c == 80) return DOWN;
//		if (c == 75) return LEFT;
//		if (c == 77) return RIGHT;
//
//	}
//	else if (z == 13) return ENTER;
//}
//int menu(str func[5], int n)
//{
//	int tt = 0;
//	int* mau = new int[n];
//	for (int i = 0; i > n; i++)
//	{
//		mau[i] = MAUCHU;
//	}
//	mau[0] = MAUNEN;
//
//	while (1)
//	{
//		clrscr();
//		for (int i = 65; i < 105; i++)
//		{
//			gotoxy(i, 1);
//			cout << "*";
//			gotoxy(i, 9);
//			cout << "*";
//		}
//
//		for (int i = 1; i < 10; i++)
//		{
//			gotoxy(65, i);
//			cout << "*";
//			gotoxy(105, i);
//			cout << "*";
//		}
//		gotoxy(80, 2);
//		textcolor(9);
//		cout << "INSTRUCTION";
//		gotoxy(82, 12);
//		textcolor(11);
//		cout << "MENU GAME" << endl;
//		for (int i = 0; i < n; i++)
//		{
//			if (i == 0) gotoxy(82, 15);
//			if (i == 1) gotoxy(80, 18);
//			if (i == 2) gotoxy(82, 21);
//			if (i == 3) gotoxy(83, 24);
//			if (i == 4) gotoxy(84, 27);
//			TextColor(mau[i]);
//			cout << func[i] << endl;
//		}
//
//		int z = _getch();
//		trangthai state = key(z);
//		switch (state)
//		{
//		case UP:
//		{
//			if (tt == 0)
//			{
//				tt = n - 1;
//			}
//			else tt--;
//			break;
//		}
//		case DOWN:
//		{
//			if (tt == n - 1)
//			{
//				tt = 0;
//			}
//			else tt++;
//			break;
//		}
//		case ENTER:
//		{
//			return tt;
//		}
//		}
//
//		for (int i = 0; i < n; i++)
//		{
//			mau[i] = MAUCHU;
//		}
//		mau[tt] = MAUNEN;
//	}
//}