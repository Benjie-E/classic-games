#include "SnakeScreenManager.h"

SnakeScreenManager::SnakeScreenManager()
{
    WINDOW* window = initscr();
    curs_set(0);
    noecho();
    updateVisuals();

}

SnakeScreenManager::~SnakeScreenManager()
{
}

void SnakeScreenManager::updateVisuals()
{
    if (SnakeGameManager::getInstance()->getGameOver())
    {
        clear();
        move(10, 47);
        addnstr(GAME_OVER.c_str(), 10);
        move(12, 32);
        addnstr(HELPER_MESSAGE.c_str(), 44);
        refresh();
    }
    else
    {
        clear();
        printBox();
        printApple();
        printHead();
        printBody();
        refresh();
    }
}

void SnakeScreenManager::printHead()
{
    Location headLoc = SnakeGameManager::getInstance()->getHeadLocation();
    move(headLoc.getY(), headLoc.getX());
    addch('@');
}

void SnakeScreenManager::printBody()
{
    for (int i = 0; i < SnakeGameManager::getInstance()->getBodyLocations().size(); i++)
    {
        move(SnakeGameManager::getInstance()->getBodyLocations()[i].getX(), SnakeGameManager::getInstance()->getBodyLocations()[i].getY());
        addch('|');
    }
}

void SnakeScreenManager::printApple()
{
    Location* apple = SnakeGameManager::getInstance()->getAppleLocation();
    move(apple->getY(), apple->getX());
    addch('A');
}
void SnakeScreenManager::printBox() {
    int maxX = SnakeGameManager::getInstance()->getMaxX();
    int maxY = SnakeGameManager::getInstance()->getMaxY();

    box(stdscr, '|', '-');
}
