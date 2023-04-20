#include "SnakeGameManager.h"
#include "SnakeGameManager.h"
#include "SnakeScreenManager.h"

SnakeGameManager* SnakeGameManager::snakeInstance = NULL;

SnakeLocation* SnakeGameManager::getAppleSnakeLocation()
{
	SnakeLocation* appleSnakeLocation = new SnakeLocation(currentApple->getY(), currentApple->getX());
	return appleSnakeLocation;
}
SnakeLocation SnakeGameManager::getHeadSnakeLocation()
{
	return snake->head;
}
std::vector<SnakeLocation> SnakeGameManager::getBodySnakeLocations()
{
	return snake->body;
}
void SnakeGameManager::createInstance()
{
	snakeInstance = new SnakeGameManager();
}

void SnakeGameManager::destroyInstance()
{
	delete snakeInstance;
}

SnakeGameManager::SnakeGameManager()
{
	keypad(stdscr, true);
	shouldLoop = true;
	newGame();
}

SnakeGameManager::~SnakeGameManager()
{
}

void SnakeGameManager::createNewApple()
{
	currentApple = new Apple();
}

void SnakeGameManager::createSnake()
{
	int newRandX = rand() % MAX_X + 1;
	int newRandY = rand() % MAX_Y + 1;

	snake = new Snake(newRandX, newRandY);
}

void SnakeGameManager::checkForCollisions()
{
	if (snake->head.getX() == currentApple->getX() && snake->head.getY() == currentApple->getY())
	{
		//the player has gotten a new apple
		snake->increaseSize();
		createNewApple();
	}
	else if (snake->head.getX() == MAX_X + 1 || snake->head.getY() == MAX_Y + 1 || snake->head.getX() < 1 || snake->head.getY() < 1)
	{
		//game over!
		isGameOver = true;
		nodelay(stdscr, false);
	}
}

void SnakeGameManager::newGame()
{
	nodelay(stdscr, true);
	isGameOver = false;
	createNewApple();
	createSnake();
}

void SnakeGameManager::gameLoop()
{
	//update SnakeLocations of the snake, apple, and body, and check for collisions
	//update SnakeLocations
	if (isGameOver)
	{
		char input = getch();
		if (input == 'r')
		{
			//new game!
			newGame();
		}
		else
		{
			shouldLoop = false;
		}
	}
	else
	{
		snake->changeDirection(snake->getSnakeInput());
		snake->gameLoop();
		checkForCollisions();
	}
}
