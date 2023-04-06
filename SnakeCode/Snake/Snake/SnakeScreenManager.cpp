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
    printHead();
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
        Location* apple = SnakeGameManager::getInstance()->getAppleLocation();
        move(apple->getY(), apple->getX());
        addch('A');
}
void SnakeScreenManager::printBox() {
    int maxX = SnakeGameManager::getInstance()->getMaxX();
    int maxY = SnakeGameManager::getInstance()->getMaxY();

    box(stdscr, '|', '-');
}
