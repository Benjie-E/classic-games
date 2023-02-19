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
	init_pair(NONE, COLOR_WHITE, COLOR_BLACK);
	init_pair(RED, COLOR_RED, COLOR_RED);
	init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW);
	refresh();

	GameManager game;
	DisplayManager screen;
	screen.updateScreen(game);

	while (game.getWinner() == NONE && game.turnNumber <= (COLUMNS * ROWS))
	{
		screen.manageCursor(game);
		game.placePiece(screen.getGameboardCol());
		screen.updateScreen(game);
		game.checkWin();
	}

	screen.winMessage(game.getWinner());

	getch();

	return 0;
}