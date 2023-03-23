#pragma once
#include <curses.h>
#include "SnakeGameManager.h"
class SnakeScreenManager
{
public:
	SnakeScreenManager();
	~SnakeScreenManager();
	void updateVisuals();
	void printHead();
	void printBody();
	void printApple();
	void printBox();
};

