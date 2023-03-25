#pragma once

#include "GameManager.h"

class DisplayManager
{
public:
	DisplayManager();
	~DisplayManager() {};

	void manageCursor();

	// accessors and mutators
	void updateScreen(GameManager &game);
	int getCursorRow();
	int getCursorCol();
	void setCursorRow(int row);
	void setCursorCol(int col);
	void displayStats(WINDOW* statDis, GameManager& game);

private:
	int mCursorRow;
	int mCursorCol;
};