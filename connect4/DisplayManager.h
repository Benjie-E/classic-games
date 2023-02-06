#pragma once

#include "GameManager.h"
#include <iostream>


class DisplayManager
{
public:
	DisplayManager() {};
	~DisplayManager() {};

	void showBoard(const GameManager& game);
	int getDecision();
};