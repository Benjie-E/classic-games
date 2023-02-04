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

    string test = gameManager.getCurrentWord();

    //variables for later use
    string input;
    int numTries = 5;
    int i;
    string currentWord = gameManager.getCurrentWord();

    //game loop
    while (true)
    {
        cout << "enter guess or exit to quit game" << endl;
        cin >> input;

        if (input == gameManager.getCurrentWord())
        {
            
        }

        for (i = 0; i <= 5; i++)
        {
            
        }
        


    }

    return 0;
}

