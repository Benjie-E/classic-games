#include "SnakeGameManager.h"
#include "SnakeScreenManager.h"

SnakeGameManager* SnakeGameManager::snakeInstance = NULL;

Location SnakeGameManager::getAppleLocation()
{
	Location appleLocation(currentApple->getY(), currentApple->getX());
	return appleLocation;
}
Location SnakeGameManager::getHeadLocation()
{
	return snake->head;
}
std::vector<Location> SnakeGameManager::getBodyLocations() {
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
}

SnakeGameManager::~SnakeGameManager()
{
}

void SnakeGameManager::createNewApple()
{
	currentApple = new Apple;
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
	if (snake->head.getX() == MAX_X || snake->head.getX() == MAX_Y || snake->head.getX() == -MAX_X || snake->head.getX() == -MAX_Y)
	{
		//game over!
		//show some game over text and then ask player if they want to play agian or quit
	}
}

void SnakeGameManager::newGame()
{
	createNewApple();
	createSnake();
}

