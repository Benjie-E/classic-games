#pragma once

#include "GameManager.h"
#include <curses.h>

class DisplayManager
{
public:
	DisplayManager();
	~DisplayManager() {};

	void manageCursor();

	// accessors and mutators
	int getCursorRow();
	int getCursorCol();
	void setCursorRow(int row);
	void setCursorCol(int col);

private:
	int mCursorRow;
	int mCursorCol;
};