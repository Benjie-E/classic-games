#pragma once
#include <iostream>
#include <curses.h>
#include <random>
#include <time.h>
#include "../common/Location.h"


class Apple
{
public:
	Apple();
	~Apple();

	int getY() { return location->getY(); }
	int getX() { return location->getX(); }

private:
	Location* location;

	const int MAX_X = getmaxx(stdscr)-2;
	const int MAX_Y = getmaxy(stdscr)-2;
};

