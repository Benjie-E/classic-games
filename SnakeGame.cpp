#include "SnakeGame.h"
#include "SnakeGameManager.h"
#include "SnakeScreenManager.h"

SnakeGame::SnakeGame()
{
}

SnakeGame::~SnakeGame()
{
}

void SnakeGame::GameLoop()
{
    srand(time(NULL));
    initscr();
    noecho();
    SnakeGameManager::createInstance();
    SnakeScreenManager* screenManager = new SnakeScreenManager;

    while (SnakeGameManager::getInstance()->getShouldLoop())
    {
        SnakeGameManager::getInstance()->gameLoop();
        screenManager->updateVisuals();
    }
}