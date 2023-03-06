#include "SnakeScreenManager.h"
SnakeScreenManager::SnakeScreenManager()
{
    WINDOW* window = initscr();
    curs_set(0);
    noecho();
    
}

SnakeScreenManager::~SnakeScreenManager()
{
}

void SnakeScreenManager::updateVisuals() {
    clear();

}

void SnakeScreenManager::printHead()
{
    
}

void SnakeScreenManager::printBody()
{
}

void SnakeScreenManager::printApple()
{
    Location apple = SnakeGameManager::getInstance()->getAppleLocation();
    move(apple.getY(), apple.getX());
    addch('A');
    refresh();
}

