#include "DisplayManager.h"

using namespace std;

DisplayManager::DisplayManager()
{
	mCursorRow = 0;
	mCursorCol = 0;
}


void DisplayManager::setConsoleSize(int dif)
{
	//These are just guess values, and will need to be tweaked later.
	if (dif == EASY)
	{
		resize_term(22, 38);
	}
	else if (dif == HARD)
	{
		resize_term(48, 90);
	}
	//Medium is the default state
	else
	{
		resize_term(36, 66);
	}

}


void DisplayManager::displayStats(int difficulty, GameManager& game)
{
	//Function to set everything up to be displayed in the window
	//I am 100% sure there is a better way to do this but it is nearly 1 am and my brain isn't working anymore.
	int titleY, difY;

	//Sets
	if (difficulty == EASY)
	{
		titleY = 12;
		difY = 1;
	}
	else if (difficulty == HARD)
	{
		titleY = 39;
		difY = 27;
	}
	else
	{
		titleY = 27;
		difY = 15;
	}

	//Displays title of game
	move(0, titleY);
	printw("Minesweeper");

	//Displays game stats
	WINDOW* statDis = newwin(3, 36, 1, difY);
	box(statDis, 0, 0);

	//Displays flag stats
	string total, flagged, dif;
	total = to_string(game.getTotalMines());
	flagged = to_string(game.getFlagged());
	string flags = "Flags: " + flagged + " / " + total;
	wmove(statDis, 1, 1);
	wprintw(statDis, flags.c_str());

	//Displays Difficulty
	int difInt = game.getDifficulty();
	if (difInt == EASY)
		dif = "Easy";
	else if (difInt == MEDIUM)
		dif = "Medium";
	else
		dif = "Hard";
	string diffic = "Difficulty: " + dif;
	wmove(statDis, 1, 16);
	wprintw(statDis, diffic.c_str());
	wrefresh(statDis);
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

	displayStats(difficulty, game);
	move(4, 2);
	//Prints out the board.
	for (int i = 0; i < difficulty; i++)
	{
		for (int j = 0; j < difficulty; j++)
		{
			game.gameBoard[i][j].printSquare();
			printw("  ");
		}
		printw("\n\n");
		move((i * 2) + 6, 2);
	}
	refresh();
}