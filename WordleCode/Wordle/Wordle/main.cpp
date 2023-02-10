#include <iostream>
#include <Windows.h>
#include <time.h>
#include "GameManager.h"
#include "ScreenManager.h"

int main()
{
    //settup stuff
    srand(time(NULL));
    int randNum = rand() % 270 + 1;
    GameManager gameManager(randNum);
    ScreenManager screenManager;
    gameManager.introMessage();
    screenManager.makeWordleBox();
    

    //game loop
    bool shouldQuit = false;
    while (!shouldQuit)
    {
        gameManager.runGameLoop(shouldQuit);
    }

    return 0;
}

