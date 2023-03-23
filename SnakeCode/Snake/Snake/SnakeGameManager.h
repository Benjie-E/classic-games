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
	std::vector<Location> getBodyLocations();
	Location getAppleLocation();
	void reset();
	static int getMaxX() { return MAX_X; };
	static int getMaxY() { return MAX_Y; };

	void createNewApple();
	void createSnake();

	void newGame();
	void checkForCollisions();

private:
	Apple* currentApple;
	Snake* snake;

	const static int MAX_X = 30;
	const static int MAX_Y = 30;

	bool isGameOver;
};

