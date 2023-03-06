#pragma once
#include <curses.h>
#include "SnakeGameManager.h"
class SnakeScreenManager
{
	SnakeScreenManager();
	~SnakeScreenManager();
	void updateVisuals();
	void printHead();
	void printBody();
	void printApple();

};

