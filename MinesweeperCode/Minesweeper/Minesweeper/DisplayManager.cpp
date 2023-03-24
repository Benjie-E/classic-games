#include "DisplayManager.h"

using namespace std;

DisplayManager::DisplayManager()
{
	mCursorRow = 0;
	mCursorCol = 0;
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
	int columns = (difficulty * 3) + 1;
	int rows = difficulty;
	WINDOW* mineBoard = newwin(rows, columns, 2, 2);
	box(mineBoard, 0, 0);
	
	//Prints out the board. Right now still working on how exactly we want to do that.
	//Either going to print by itself or be contained inside a window.
	wmove(mineBoard, 1, 1);
	//move(2, 2);
	for (int i = 0; i < difficulty; i++)
	{
		for (int j = 0; j < difficulty; j++)
		{
			game.gameBoard[i][j].printSquare();
			printw(" ");
		}
		printw("\n\n");
		//move(i + 2, 1);
	}
	wrefresh(mineBoard);
	refresh();
}