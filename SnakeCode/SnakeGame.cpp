#include "SnakeGameManager.h"
#include "SnakeScreenManager.h"
#include "SnakeGame.h"
SnakeGame::SnakeGame()
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
