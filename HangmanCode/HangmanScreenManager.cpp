
#include "ScreenManager.h"
#include <iostream>
#include "dependencies/PDCurses-3.9/curses.h"
using namespace HangmanNS;
const char* LOSETEXT = { R"(

 __     ______  _    _   _      ____   _____ ______ 
 \ \   / / __ \| |  | | | |    / __ \ / ____|  ____|
  \ \_/ / |  | | |  | | | |   | |  | | (___ | |__   
   \   /| |  | | |  | | | |   | |  | |\___ \|  __|  
    | | | |__| | |__| | | |___| |__| |____) | |____ 
    |_|  \____/ \____/  |______\____/|_____/|______|
                                                    
                                                    
)" };
const char* WINTEXT = { R"(

 __     ______  _    _  __          _______ _   _ 
 \ \   / / __ \| |  | | \ \        / /_   _| \ | |
  \ \_/ / |  | | |  | |  \ \  /\  / /  | | |  \| |
   \   /| |  | | |  | |   \ \/  \/ /   | | | . ` |
    | | | |__| | |__| |    \  /\  /   _| |_| |\  |
    |_|  \____/ \____/      \/  \/   |_____|_| \_|
                                                  
                                                  
)" };
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
    WINDOW *window = initscr();
    curs_set(0);
    noecho();
    hangmanPos.y = 0;
    hangmanPos.x = 0;
    letterPos.y = 20;
    letterPos.x = 0;
    wordPos.y = 22;
    wordPos.x = 10;
}

ScreenManager::~ScreenManager()
{
    clear();
    refresh();
}

void ScreenManager::updateHangedMan(int phase)
{
    refresh();
    move(hangmanPos.y,hangmanPos.x);
    printw(HANGMANPICS[phase]);
}

void ScreenManager::reset()
{

}
int ScreenManager::letterToIndex(char letter)
{
    return int(letter) - 0x41;
}

void ScreenManager::updateLetter(char letter)
{
    int index = letterToIndex(letter);
    refresh();
    mvaddch(letterPos.y, letterPos.x+index,letter);
}
void ScreenManager::start(int length) {
    move(wordPos.y, wordPos.x);
    for (int i = 0;i < length;i++) {
        addstr("_ ");
    }

    refresh();

}
void ScreenManager::updateWord(int index, char letter)
{
    mvaddch(wordPos.y,wordPos.x+index*2,letter);
    refresh();
}

void ScreenManager::win()
{
    clear();
    move(hangmanPos.y, hangmanPos.x);
    addstr(WINTEXT);
    refresh();
}

void ScreenManager::lose()
{
    clear();
    move(hangmanPos.y, hangmanPos.x);
    addstr(LOSETEXT);
    refresh();
}
