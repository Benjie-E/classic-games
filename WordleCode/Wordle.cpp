#include <iostream>
#include "../common/Location.h"
#include <time.h>
#include "GameManager.h"
#include "ScreenManager.h"
#include "Wordle.h"

WordleGame::WordleGame()
{
    //settup stuff
    srand(time(NULL));
    int randNum = rand() % 270 + 1;
    GameManager gameManager(randNum);
    ScreenManager screenManager;
    gameManager.introMessage();
    curs_set(0);


    //game loop
    bool shouldQuit = false;
    while (!shouldQuit)
    {
        gameManager.runGameLoop(shouldQuit);
    }
    return;
}

