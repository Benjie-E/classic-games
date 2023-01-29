#include <iostream>
#include "GameManager.h"

int main()
{
    GameManager gameManager;
    const int NUM_WORDS = 270;
    string words[NUM_WORDS];

    gameManager.importWords(words);


    return 0;
}

