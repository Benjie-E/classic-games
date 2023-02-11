#include "DisplayManager.h"
#include <cmath>

using namespace std;

DisplayManager::DisplayManager()
{
	mCursorRow = 11; // first row under gameboard
	mCursorCol = 0;  // leftmost column of screen
	mGameboardCol = 0; // column 1 of gameboard
}


void DisplayManager::updateScreen(const GameManager &game)
{
	clear();
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			attron(COLOR_PAIR(game.gameBoard[i][j]));
			printw("[]");
			attroff(COLOR_PAIR(game.gameBoard[i][j]));
			printw("   ");
		}
		//cout << endl;
		printw("\n\n");
	}
	mvprintw(mCursorRow, mCursorCol, "^^");
	refresh();
}


void DisplayManager::manageCursor(const GameManager &game)
{
	// TODO: get rid of magic numbers
	int keypress;

	move(mCursorRow, mCursorCol);

	while (true)
	{
		keypress = getch();
		switch (keypress)
		{
		case KEY_RIGHT:
			mCursorCol = (mCursorCol + 5) % 35;
			mGameboardCol = (mGameboardCol + 1) % 7;
			updateScreen(game);
			break;
		case KEY_LEFT:
			mCursorCol = (mCursorCol + 30) % 35;
			mGameboardCol = (mGameboardCol - 1) % 7;
			updateScreen(game);
			break;
		case KEY_ENTER: // a few possible ENTER keys, need to capture all
		case 10: // newline \n
		case 13: // carriage return \r
			// previous 3 cases will end up here (fall-through)
			return;
			break;
		default:
			break;
		}
	}
}


int DisplayManager::getCursorRow()
{
	return mCursorRow;
}


int DisplayManager::getCursorCol()
{
	return mCursorCol;
}


int DisplayManager::getGameboardCol()
{
	return mGameboardCol;
}


void DisplayManager::setCursorRow(int row)
{
	mCursorRow = row;
}


void DisplayManager::setCursorCol(int col)
{
	mCursorCol = col;
}


void DisplayManager::setGameboardCol(int col)
{
	mGameboardCol = col;
}