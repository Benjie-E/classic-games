#pragma once
#include "SnakeLocation.h"
#include <vector>
#include "Timer.h"

using namespace std;

class Snake {
public:
	enum direction { OTHER = -1, RIGHT, DOWN, LEFT, UP };
	Snake(int x, int y);
	void gameLoop();
	direction getSnakeInput(); //RDLU
	void changeDirection(direction dir);
	SnakeLocation head;
	std::vector<SnakeLocation> body;

	vector<SnakeLocation> SnakeLocations;

	void increaseSize();

	direction dir;

private:
	Timer clock;
};

