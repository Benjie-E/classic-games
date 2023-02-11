#include "GameManager.h"
#include "DisplayManager.h"

using namespace std;

int main()
{
	// start the terminal with Curses
	initscr();
	keypad(stdscr, true); // get arrow keys
	noecho(); // don't output anything from user
	raw(); // handle keyboard inputs directly
	curs_set(0); // hide terminal cursor
	start_color();
	init_pair(EMPTY, COLOR_WHITE, COLOR_BLACK);
	init_pair(RED_PIECE, COLOR_RED, COLOR_RED);
	init_pair(YELLOW_PIECE, COLOR_YELLOW, COLOR_YELLOW);
	refresh();

	GameManager game;
	DisplayManager screen;
	int column;
	screen.updateScreen(game);

	while (!game.isWin)
	{
		screen.updateScreen(game);
		screen.manageCursor(game);
		game.placePiece(screen.getGameboardCol());
	}

	return 0;
}