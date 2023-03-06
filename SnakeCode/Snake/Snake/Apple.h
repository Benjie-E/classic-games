#pragma once
#include <iostream>
#include <curses.h>
#include <random>
#include <time.h>
#include "Location.h"


class Apple
{
public:
	Apple();
	~Apple();

	int getY() { return location->getY(); }
	int getX() { return location->getX(); }

private:
	Location* location;

	const int MAX_X = 30;
	const int MAX_Y = 30;
};

