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
		//increase the size of snake
		//spawn new apple
	}
}

void SnakeGameManager::newGame()
{
	createNewApple();
	createSnake();
	SnakeScreenManager *screenManager = new SnakeScreenManager;
}

