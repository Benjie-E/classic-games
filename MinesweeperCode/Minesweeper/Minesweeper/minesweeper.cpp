#include "DisplayManager.h"
#include "GameManager.h"

int main()
{
	// seed the RNG (it's a surprise tool that will help us later)
	srand(time(NULL));
	//Starts terminal with curses
	initscr();
	noecho();
	curs_set(0);
	start_color();
	// colors correspond to different numbers of mines
	init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_BLACK);
	// unrevealed colors
	init_pair(9, COLOR_WHITE, COLOR_WHITE);
	init_pair(10, COLOR_RED, COLOR_WHITE); // flagged
	refresh();

	bool playing = true;

	while (playing == true)
	{
		int gameDiff = setDifficulty();
		GameManager game(gameDiff);
		DisplayManager display;
		bool playing = true;

		display.setConsoleSize(game.getDifficulty());

		// Main game loops
		while (game.getGameState() == 0)
		{
			//For Testing, delete before release
			game.setGameState(1);

			// Keep code below but delete this comment before release
			display.updateScreen(game);
			// Movement and selecting board piece will go here
			game.setGameState(game.checkGameState());
		}

		// checks if the player wants to play again
		getch(); // This is so that the player can see the fully revealed board
		playing = display.replay(game);
		
		//Unallocates existing managers
		display.~DisplayManager();
		game.~GameManager();
	}
	getch();
	return 0;
}