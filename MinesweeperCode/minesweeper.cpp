#include "MinesweeperDisplayManager.h"
#include "MinesweeperGameManager.h"
#include "minesweeper.h"
using namespace MinesweeperNS;
Minesweeper::Minesweeper()
{
	// seed the RNG (it's a surprise tool that will help us later)
	srand(time(NULL));
	//Starts terminal with curses
	initscr();
	noecho();
	curs_set(0);
	start_color();
	keypad(stdscr, true);
	// colors correspond to different numbers of mines
	init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_BLACK);
	// unrevealed colors
	init_pair(9, COLOR_WHITE, COLOR_WHITE);
	init_pair(10, COLOR_RED, COLOR_WHITE); // flagged
	// highlighted colors
	init_pair(11, COLOR_WHITE, COLOR_YELLOW); // highlighted
	init_pair(12, COLOR_RED, COLOR_YELLOW); // flagged and highlighted
	refresh();

	bool playing = true;

	while (playing == true)
	{
		int gameDiff = setDifficulty();
		GameManager game(gameDiff);
		DisplayManager display;

		display.setConsoleSize(game.getDifficulty());

		game.gameBoard[0][0].isHighlighted = true;
		game.firstMove();

		// Main game loops
		while (game.getGameState() == 0)
		{
			display.updateScreen(game);
			display.manageInput(game);
		}

		int input = 0;
		while (true) // X or x
		{
			input = getch();
			if (input == 88 || input == 120)
			{
				break;
			}
		}

		// checks if the player wants to play again
		playing = display.replay(game);
	}
	return;
}