#pragma once
#include "Snake.h"
#include "Apple.h"

class SnakeScreenManager;

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
	bool getGameOver() { return isGameOver; }
	bool getShouldLoop() { return shouldLoop; }
	std::vector<Location> getBodyLocations();
	Location* getAppleLocation();
	int getMaxX() { return MAX_X; };
	int getMaxY() { return MAX_Y; };

	void createNewApple();
	void createSnake();

	void newGame();
	void checkForCollisions();

	void gameLoop();

private:
	Apple* currentApple;
	Snake* snake;

	const int MAX_X = getmaxx(stdscr) - 2;
	const int MAX_Y = getmaxy(stdscr) - 2;

	bool isGameOver;
	bool shouldLoop;
};
