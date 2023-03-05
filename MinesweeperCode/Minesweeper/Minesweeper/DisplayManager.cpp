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