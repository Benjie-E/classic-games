#include "DisplayManager.h"
#include <cmath>

using namespace std;

DisplayManager::DisplayManager()
{
	mCursorRow = 11; // first row under gameboard
	mCursorCol = 0;  // leftmost column of screen
	mGameboardCol = 0; // column 1 of gameboard
}


void DisplayManager::showBoard(const GameManager& game)
{
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
	refresh();
}


//int DisplayManager::getDecision()
//{
//	int column = 0;
//	printw("\nWhich column would you like to place your piece in? (1-7) ");
//	refresh();
//	scanw("%d", &column);
//	refresh();
//
//	return column - 1; // adjust for zero-indexed array
//}


int DisplayManager::manageCursor()
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
			move(mCursorRow, mCursorCol);
			mGameboardCol = (mGameboardCol + 1) % 7;
			break;
		case KEY_LEFT:
			mCursorCol = (mCursorCol + 30) % 35;
			move(mCursorRow, mCursorCol);
			mGameboardCol = (mGameboardCol - 1) % 7;
			break;
		case KEY_ENTER: // a few possible ENTER keys, need to capture all
		case 10: // newline \n
		case 13: // carriage return \r
			// previous 3 cases will end up here (fall-through)
			return mGameboardCol;
			break;
		default:
			break;
		}
	}
}