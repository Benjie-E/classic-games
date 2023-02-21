#include "GameManager.h"
#include "Hangman.h"
//Word list from https://github.com/Xethron/Hangman

using namespace HangmanNS;
Hangman::Hangman()
{
    GameManager gameManager;
    gameManager.start();
    return;
}
