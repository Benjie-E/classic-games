
#include "ScreenManager.h"
#include <iostream>
#include <curses.h>
const char* HANGMANPICS[7] = {R"(
  +---+
  |   |
      |
      |
      |
      |
========= )",R"(
  +---+
  |   |
  O   |
      |
      |
      |
========= )",R"(
  +---+
  |   |
  O   |
  |   |
      |
      |
========= )",R"(
  +---+
  |   |
  O   |
 /|   |
      |
      |
========= )",R"(
  +---+
  |   |
  O   |
 /|\  |
      |
      |
========= )",R"(
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
========= )",R"(
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
========= )"};
ScreenManager::ScreenManager()
{
    initscr();
    currentPhase = -1;
    hangmanPos.y = 0;
    hangmanPos.x = 0;
    letterPos.y = 20;
    letterPos.x = 0;

}

ScreenManager::~ScreenManager()
{
    endwin();
}

void ScreenManager::updateHangedMan()
{
    refresh();
    move(hangmanPos.y,hangmanPos.x);
    currentPhase++;
    printw(HANGMANPICS[currentPhase]);
}

void ScreenManager::reset()
{
    currentPhase = -1;

}

void ScreenManager::updateLetter(char letter)
{
    move(letterPos.y, letterPos.x);
    
}
