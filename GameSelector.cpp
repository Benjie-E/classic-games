#include "GameSelector.h"

GameSelector::GameSelector()
{
    menuPos.x = 0;
    menuPos.y = 0;
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr,true);
}

bool GameSelector::updateSelector(int game)
{
    echochar(' ');
    move(menuPos.y+game*2,menuPos.x+1);
    echochar('X');
    move(menuPos.y + game * 2, menuPos.x + 1);
    return true;
}

int GameSelector::select()
{
    for (int i = 0;i < int(sizeof(gameList) / sizeof(std::string));i++) {
        std::string formattedString = "[ ] "+gameList[i];
        mvaddstr(menuPos.y+i*2,menuPos.x,formattedString.c_str());
    }
    refresh();
    int value = 0;
    int input = -1;
    int test = -1;
    updateSelector(0);
    while (input == -1) {
        test = getch();
        switch (test) {
        case KEY_UP:
            value = (value - 1) % int(size(gameList));
            if (value < 0) {
                value += int(size(gameList));
            }
            updateSelector(value);
            break;
        case KEY_DOWN:
            value = (value + 1) % int(size(gameList));
            updateSelector(value);
            break;
        case 10: //Enter
            input = value;
            break;
        default:
            break;
        }
    }
    return value;
}

int GameSelector::start(int game)
{
    switch (game) {
    case Hangman:
        Hangman::Hangman();
        break;
    default:
        mvaddstr(menuPos.y+size(gameList)*2,menuPos.x,"Game Not Found");
        getch();
        clear();
        refresh();
    }
    return 0;
}
