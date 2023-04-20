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

private:
	const string GAME_OVER = "Game Over";
	const string HELPER_MESSAGE = "Press r to restart or anything else to quit";
};
