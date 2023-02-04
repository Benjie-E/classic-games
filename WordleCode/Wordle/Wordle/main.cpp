#include <iostream>
#include <Windows.h>
#include <time.h>
#include "GameManager.h"

int main()
{
    //settup stuff
    srand(time(NULL));
    int randNum = rand() % 270 + 1;
    GameManager gameManager(randNum);
    gameManager.introMessage();

    cout << gameManager.getCurrentWord() << endl;

    //game loop
    gameManager.runGameLoop();
    

    return 0;
}

