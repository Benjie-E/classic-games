#pragma once
#include <iostream>
#include <curses.h>
#include <random>
#include <time.h>
#include "SnakeLocation.h"


class Apple
{
public:
	Apple();
	~Apple();

	int getY() { return mLocation->getY(); }
	int getX() { return mLocation->getX(); }

private:
	Location* mLocation;

	const int MAX_X = getmaxx(stdscr) - 2;
	const int MAX_Y = getmaxy(stdscr) - 2;
};