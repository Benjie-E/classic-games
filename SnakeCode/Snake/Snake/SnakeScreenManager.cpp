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

void SnakeScreenManager::updateVisuals() {
    clear();
    printBox();
    printApple();
    refresh();
    getch();
}

void SnakeScreenManager::printHead()
{
    Location headLoc = SnakeGameManager::getInstance()->getHeadLocation();
    move(headLoc.getY(), headLoc.getX());
    addch('@');
}

void SnakeScreenManager::printBody()
{
}

void SnakeScreenManager::printApple()
{
    if (SnakeGameManager::getInstance() == NULL)
    {

    }
    else
    {
        Location* apple = SnakeGameManager::getInstance()->getAppleLocation();
        move(apple->getY(), apple->getX());
        addch('A');
        refresh();
    }
}
void SnakeScreenManager::printBox() {
    int maxX = SnakeGameManager::getInstance()->getMaxX();
    int maxY = SnakeGameManager::getInstance()->getMaxY();

    box(stdscr, '|', '-');
}
