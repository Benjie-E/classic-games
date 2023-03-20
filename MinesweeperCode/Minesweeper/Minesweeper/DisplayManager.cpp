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
	int rows = game.getDifficulty();
	int columns = rows;
	//The window doesn't show up right now idk why
	WINDOW* gameWindow = newwin(rows, columns, 3, 3);
	move(2, 2);
	printw("This is a test line");
	refresh();
}