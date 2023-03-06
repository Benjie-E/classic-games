#pragma once
#include "Snake.h"
#include "Apple.h"

class SnakeGameManager
{
public:

	static SnakeGameManager* snakeInstance;

	//singlton stuff
	static SnakeGameManager* getInstance() { return snakeInstance; }
	static void createInstance();
	static void destroyInstance();

	SnakeGameManager();
	~SnakeGameManager();

	Location getHeadLocation();
	Location getBodyLocations();
	std::vector<Location> getAppleLocation();
	void reset();

private:
	Apple* currentApple;
	Snake* snake;

	const int MAX_X = 30;
	const int MAX_Y = 30;
};

