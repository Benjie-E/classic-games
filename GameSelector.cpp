#include "GameSelector.h"

GameSelector::GameSelector()
{
    menuPos.setYX(0, 0);
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr,true);
}

bool GameSelector::updateSelector(int game)
{
    echochar(' ');
    move(menuPos.getY() + game * 2, menuPos.getX() + 1);
    echochar('X');
    move(menuPos.getY() + game * 2, menuPos.getX() + 1);
    return true;
}

int GameSelector::select()
{
    for (int i = 0;i < int(sizeof(gameList) / sizeof(std::string));i++) {
        std::string formattedString = "[ ] "+gameList[i];
        mvaddstr(menuPos.getY() + i * 2, menuPos.getX(), formattedString.c_str());
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
        clear();
        HangmanNS::Hangman::Hangman();
        break;
    case Wordle:
        clear();
        WordleGame::WordleGame();
        break;
    case TicTacToe:
        clear();
        TTT::TTT();
        break;
    case Connect4:
        clear();
        Connect4NS::Connect4::Connect4();
        break;
    case Exit:
        clear();
        exit(0);
    default:
        mvaddstr(menuPos.getY() + size(gameList) * 2, menuPos.getX(), "Game Not Found");
        getch();
        
    }
    noraw();
    clear();
    refresh();
    return 0;
}
