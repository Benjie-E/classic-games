#pragma once

#include "GameManager.h"
#include <curses.h>

class DisplayManager
{
public:
	DisplayManager();
	~DisplayManager() {};

	void updateScreen(const GameManager &game);
	void manageCursor(const GameManager &game);

	// accessors/mutators
	int getCursorRow();
	int getCursorCol();
	int getGameboardCol();
	void setCursorRow(int row);
	void setCursorCol(int col);
	void setGameboardCol(int col);

private:
	int mCursorRow;
	int mCursorCol;
	int mGameboardCol;
};