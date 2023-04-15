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
	void setConsoleSize(int dif);
	void setCursorRow(int row);
	void setCursorCol(int col);
	void displayStats(int difficulty, GameManager& game);
	bool replay(GameManager game);

private:
	int mCursorRow;
	int mCursorCol;
};