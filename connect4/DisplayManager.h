#pragma once

#include "GameManager.h"
#include <curses.h>

class DisplayManager
{
public:
	DisplayManager() {};
	~DisplayManager() {};

	void showBoard(const GameManager& game);
	int getDecision();
};