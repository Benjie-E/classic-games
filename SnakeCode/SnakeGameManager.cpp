#include "SnakeGameManager.h"
#include "SnakeScreenManager.h"

SnakeGameManager* SnakeGameManager::snakeInstance = NULL;

Location* SnakeGameManager::getAppleLocation()
{
	Location* appleLocation = new Location(currentApple->getY(), currentApple->getX());
	return appleLocation;
}
Location SnakeGameManager::getHeadLocation()
{
	return snake->head;
}
std::vector<Location> SnakeGameManager::getBodyLocations() 
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
	else if (snake->head.getX() == MAX_X + 1 || snake->head.getY() == MAX_Y + 1 || snake->head.getX() < 1|| snake->head.getY() < 1)
	{
		//game over!
		isGameOver = true;
		nodelay(stdscr, false);
	}
	for (Location b : getBodyLocations()) {
		if (getHeadLocation().getX() == b.getX() && getHeadLocation().getY() == b.getY()) {
			isGameOver = true;
			nodelay(stdscr, false);
		}
	}
}

void SnakeGameManager::newGame()
{
	nodelay(stdscr,true);
	isGameOver = false;
	createNewApple();
	createSnake();
}

void SnakeGameManager::gameLoop()
{
	//update locations of the snake, apple, and body, and check for collisions
	//update locations
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
