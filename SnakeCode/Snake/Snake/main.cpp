#include "SnakeGameManager.h"
#include "SnakeScreenManager.h"
int main()
{
    srand(time(NULL));
    initscr();
    noecho();
    SnakeGameManager::createInstance();
    SnakeScreenManager* screenManager = new SnakeScreenManager;
}
