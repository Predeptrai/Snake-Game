#include "graphic_console.h"
#include "Lib_game.h"

void nameLevel1(int x, int y, int h, int w, int color)
{
	//textcolor();
	gotoxy(x + 28, y + h + 7);
	cout << " __                              _      ___";
	gotoxy(x + 28, y + h + 8);
	cout << "|  |      ___      _ _    ___   | |    |_  |";
	gotoxy(x + 28, y + h + 9);
	cout << "|  |__   | -_|    | | |  | -_|  | |     _| |_";
	gotoxy(x + 28, y + h + 10);
	cout << "|_____|  |___|     \\_/   |___|  |_|    |_____|";
}

void nameLevel2(int x, int y, int h, int w, int color)
{
	//textcolor();


	gotoxy(x + 28, y + h + 7);
	 cout<<" _                              _   ___";
	 gotoxy(x + 28, y + h + 8);
	 cout<<"| |                            | | |__ \\";
	 gotoxy(x + 28, y + h + 9);
	 cout<<"| |        ___  __   __   ___  | |    ) |";
	 gotoxy(x + 28, y + h + 10);
	 cout<<"| |       / _ \\ \\ \\ / /  / _ \\ | |   / /";
	 gotoxy(x + 28, y + h + 11);
	 cout<<"| |____  |  __/  \\ V /  |  __/ | |  / /_";
	 gotoxy(x + 28, y + h + 12);
	 cout<<"|______|  \\___|   \\_/    \\___| |_| |____|";
}

void nameLevel3(int x, int y, int h, int w, int color)
{
	//textcolor();

	gotoxy(x + 28, y + h + 7);
	cout<<" _                              _   ____";
	gotoxy(x + 28, y + h + 8);
	cout<<"| |                            | | |___ \\";
	gotoxy(x + 28, y + h + 9);
	cout<<"| |        ___  __   __   ___  | |   __) |";
	gotoxy(x + 28, y + h + 10);
	cout<<"| |       / _ \\ \\ \\ / /  / _ \\ | |  |__ <";
	gotoxy(x + 28, y + h + 11);
	cout<<"| |____  |  __/  \\ V /  |  __/ | |  ___) |";
	gotoxy(x + 28, y + h + 12);
	cout<<"|______|  \\___|   \\_/    \\___| |_| |____/"; 

}

/*
	   *  * 	********
    *  R  *	    ********
	   *  *	    ********
*/