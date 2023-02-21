#include <iostream>
#include <Windows.h>
#include <time.h>
#include "GameManager.h"
#include "ScreenManager.h"
#include "Wordle.h"

Wordle::Wordle()
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

