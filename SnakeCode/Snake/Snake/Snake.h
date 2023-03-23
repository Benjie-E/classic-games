#pragma once
#include "Location.h"
#include <vector>

using namespace std;

class Snake {
public:
	enum direction {OTHER = -1, RIGHT, DOWN, LEFT, UP };
	Snake();
	void gameLoop();
	direction getSnakeInput(); //RDLU
	void changeDirection(direction dir);
	direction currentDirection = OTHER;
	Location head;
	std::vector<Location> body;

	vector<Location> locations;
};
