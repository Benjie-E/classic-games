#include "DisplayManager.h"
#include "GameManager.h"

int main()
{
	//Starts terminal with curses
	initscr();
	noecho();
	curs_set(0);
	start_color();
	refresh();
	GameManager game(MEDIUM);
	DisplayManager display;
	display.updateScreen(game);
	getchar();
	return 0;
}