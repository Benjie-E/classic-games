#pragma once
#include "../common/Location.h"
#include <vector>
#include "Timer.h"

using namespace std;

class Snake {
public:
	enum direction {OTHER = -1, RIGHT, DOWN, LEFT, UP };
	Snake(int x, int y);
	void gameLoop();
	direction getSnakeInput(); //RDLU
	void changeDirection(direction dir);
	Location head;
	std::vector<Location> body;

	vector<Location> locations;

	void increaseSize();

	direction dir;
	
private:
	Timer clock;
};
