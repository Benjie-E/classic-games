#include "GameManager.h"
#include "DisplayManager.h"

using namespace std;

int main()
{
	GameManager game;
	DisplayManager screen;

	initscr();
	start_color();
	init_pair(EMPTY, COLOR_WHITE, COLOR_BLACK);
	init_pair(RED_PIECE, COLOR_RED, COLOR_RED);
	init_pair(YELLOW_PIECE, COLOR_YELLOW, COLOR_YELLOW);
	refresh();

	while (true)
	{
		screen.showBoard(game);
		game.placePiece(screen.getDecision());
		clear();
		refresh();
	}

	return 0;
}