
#include "ScreenManager.h"
#include <iostream>
#include <curses.h>
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
std::string wordMessage = "The word was: ";
ScreenManager::ScreenManager()
{
    WINDOW *window = initscr();
    curs_set(0);
    noecho();
    hangmanPos.setYX(0, 0);
    letterPos.setYX(20, 0);
    wordPos.setYX(22, 10);
}

ScreenManager::~ScreenManager()
{
    clear();
    refresh();
}

void ScreenManager::updateHangedMan(int phase)
{
    refresh();
    move(hangmanPos.getY(), hangmanPos.getX());
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
    mvaddch(letterPos.getY(), letterPos.getX() + index, letter);
}
void ScreenManager::start(int length) {
    move(wordPos.getY(), wordPos.getX());
    for (int i = 0;i < length;i++) {
        addstr("_ ");
    }

    refresh();

}
void ScreenManager::updateWord(int index, char letter)
{
    mvaddch(wordPos.getY(), wordPos.getX() + index * 2, letter);
    refresh();
}

void ScreenManager::win(std::string word)
{
    clear();
    move(hangmanPos.getY(), hangmanPos.getX());
    addstr(WINTEXT);
    move(wordPos.getY(), hangmanPos.getX());
    std::string winMessage = wordMessage;
    winMessage.append(word);
    addstr(winMessage.c_str());
    refresh();
}

void ScreenManager::lose(std::string word)
{
    clear();
    move(hangmanPos.getY(), hangmanPos.getX());
    addstr(LOSETEXT);
    move(wordPos.getY(), hangmanPos.getX());
    std::string loseMessage = wordMessage;
    loseMessage.append(word);
    addstr(loseMessage.c_str());
    refresh();
}
