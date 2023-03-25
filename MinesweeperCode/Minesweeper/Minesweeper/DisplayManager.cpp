#include "DisplayManager.h"

using namespace std;

DisplayManager::DisplayManager()
{
	mCursorRow = 0;
	mCursorCol = 0;
}


void DisplayManager::displayStats(WINDOW* statDis, GameManager& game)
{
	//Function to set everything up to be displayed in the window
	//I am 100% sure there is a better way to do this but it is nearly 1 am and my brain isn't working anymore.

	//Displays flag stats
	string total, flagged, dif;
	total = to_string(game.getTotalMines());
	flagged = to_string(game.getFlagged());
	string flags = "Flags: " + flagged + " / " + total;
	wmove(statDis, 1, 1);
	wprintw(statDis, flags.c_str());

	//Displays Difficulty
	int difInt = game.getDifficulty();
	if (difInt == 9)
		dif = "Easy";
	else if (difInt == 16)
		dif = "Medium";
	else
		dif = "Hard";
	string diffic = "Difficulty: " + dif;
	wmove(statDis, 1, 20);
	wprintw(statDis, diffic.c_str());

}


void DisplayManager::manageCursor()
{
	return;
}


int DisplayManager::getCursorRow()
{
	return mCursorRow;
}


int DisplayManager::getCursorCol()
{
	return mCursorCol;
}


void DisplayManager::setCursorRow(int row)
{
	mCursorRow = row;
}


void DisplayManager::setCursorCol(int col)
{
	mCursorCol = col;
}


void DisplayManager::updateScreen(GameManager &game)
{
	int difficulty = game.getDifficulty();

	//Displays title of game
	move(0, 18);
	printw("Minesweeper");

	//Displays game stats
	WINDOW* stats = newwin(4, 40, 2, 5);
	box(stats, 0, 0);
	displayStats(stats, game);
	
	//Prints out the board.
	move(6, 2);
	for (int i = 0; i < difficulty; i++)
	{
		for (int j = 0; j < difficulty; j++)
		{
			game.gameBoard[i][j].printSquare();
			printw(" ");
		}
		printw("\n\n");
		move((i * 2) + 6, 2);
	}
	wrefresh(stats);
	refresh();
}