#pragma once

#include "GameManager.h"
#include <curses.h>

const int COL_SPACING = 5;
const int COL_SPACING_WRAPAROUND = 30;
const int BOARD_WIDTH = 35;


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
	void winMessage(int winner);

private:
	int mCursorRow;
	int mCursorCol;
	int mGameboardCol;
};