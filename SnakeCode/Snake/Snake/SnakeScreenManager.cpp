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
    refresh();
    getch();
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
void SnakeScreenManager::printBox() {
    int maxX = SnakeGameManager::getInstance()->getMaxX();
    int maxY = SnakeGameManager::getInstance()->getMaxY();
    for (int i = 0;i < maxY;i++) {
        move(0, i);
        addch('-');
    }
}
