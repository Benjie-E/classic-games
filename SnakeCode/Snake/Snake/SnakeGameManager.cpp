#include "SnakeGameManager.h"

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
Location SnakeGameManager::getBodyLocations() {
	return snake.body;
}
void SnakeGameManager::createInstance()
{
	snakeInstance = new SnakeGameManager();
}

void SnakeGameManager::destroyInstance()
{
	delete snakeInstance;
}