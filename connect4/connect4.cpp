#include "DisplayManager.h"
#include "connect4.h"
using namespace std;
using namespace Connect4NS;
Connect4::Connect4()
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

	while (true)
	{
		GameManager game;
		DisplayManager screen;
		screen.updateScreen(game);

		while (game.getWinner() == NONE && game.getTurnNumber() <= (COLUMNS * ROWS))
		{
			screen.manageCursor(game);
			game.placePiece(screen.getGameboardCol());
			screen.updateScreen(game);
			game.checkWin();
		}

		screen.winMessage(game.getWinner());

		if (!screen.replay())
			break;
	}
	return;
}