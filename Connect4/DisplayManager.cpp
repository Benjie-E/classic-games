#include "DisplayManager.h"
#include <cmath>

using namespace std;
using namespace Connect4NS;
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
		printw("\n\n");
	}
	mvprintw(mCursorRow, mCursorCol, "^^");
	move(mCursorRow + 1, 0);
	if (game.isRedTurn)
	{
		printw("RED's turn.");
	}
	else
	{
		printw("YELLOW's turn.");
	}
	refresh();
}


void DisplayManager::manageCursor(const GameManager &game)
{
	int keypress;

	move(mCursorRow, mCursorCol);

	while (true)
	{
		keypress = getch();
		switch (keypress)
		{
		case KEY_RIGHT:
			// use modulus for screen wrapping
			mCursorCol = (mCursorCol + COL_SPACING) % BOARD_WIDTH;
			mGameboardCol = (mGameboardCol + 1) % COLUMNS;
			updateScreen(game);
			break;
		case KEY_LEFT:
			mCursorCol = (mCursorCol + COL_SPACING_WRAPAROUND) % BOARD_WIDTH;
			mGameboardCol = (mGameboardCol - 1) % COLUMNS;
			updateScreen(game);
			break;
		case KEY_ENTER: // a few possible ENTER keys, need to capture all
		case 10: // newline \n
		case 13: // carriage return \r
		case 32: // spacebar
		case KEY_DOWN:
			// previous 4 cases will end up here (fall-through)
			return;
			break;
		default:
			break;
		}
	}
}


void DisplayManager::winMessage(int winner)
{
	move(mCursorRow, 0);
	if (winner == RED)
		printw("\nRed wins!\n");
	else if (winner == YELLOW)
		printw("\nYellow wins!\n");
	else // if draw
		printw("\nDraw...\n");
}


bool DisplayManager::replay()
{
	int keypress;
	bool cursorOnQuit = false;

	mCursorRow += 3;
	mvprintw(mCursorRow, 0, ">  Play Again");
	mvprintw(mCursorRow + 1, 3, "Quit");

	while (true)
	{
		keypress = getch();
		switch (keypress)
		{
		case KEY_UP:
		case KEY_DOWN:
			if (cursorOnQuit)
			{
				mvaddch(mCursorRow + 1, 0, ' ');
				mvaddch(mCursorRow, 0, '>');
			}
			else
			{
				mvaddch(mCursorRow, 0, ' ');
				mvaddch(mCursorRow + 1, 0, '>');
			}
			cursorOnQuit = !cursorOnQuit;
			break;
		case KEY_ENTER: // a few possible ENTER keys, need to capture all
		case 10: // newline \n
		case 13: // carriage return \r
		case 32: // spacebar
			// previous 4 cases will end up here (fall-through)
			return !cursorOnQuit;
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