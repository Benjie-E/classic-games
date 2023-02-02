#include <iostream>
#include "GameManager.h"
#include "ScreenManager.h"
#include <time.h>
#include <curses.h>
//Word list from https://github.com/Xethron/Hangman

int main() {

    ScreenManager screenManager;
    srand(time(NULL));
    GameManager gameManager;
    const int NUM_WORDS = 854;
    std::string words[NUM_WORDS];

    gameManager.importWords(words);
    std::string word = gameManager.getWord();
    while (true) {
        getch();
        screenManager.updateHangedMan();
    }
    
    return 0;
}