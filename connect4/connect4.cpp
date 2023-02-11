#include "GameManager.h"
#include "DisplayManager.h"

using namespace std;

int main()
{
	// start the terminal with Curses
	initscr();
	keypad(stdscr, true); // get arrow keys
	noecho(); // don't output anything from user
	raw();
	start_color();
	init_pair(EMPTY, COLOR_WHITE, COLOR_BLACK);
	init_pair(RED_PIECE, COLOR_RED, COLOR_RED);
	init_pair(YELLOW_PIECE, COLOR_YELLOW, COLOR_YELLOW);
	refresh();

	GameManager game;
	DisplayManager screen;
	int column;

	while (true)
	{
		screen.showBoard(game);
		column = screen.manageCursor();
		game.placePiece(column);
		clear();
	}

	return 0;
}