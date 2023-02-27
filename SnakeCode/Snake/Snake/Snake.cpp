#include <curses.h>
#include "Snake.h"
#include <iostream>

Snake::Snake() {

}
int Snake::getSnakeInput() {
    int input = getch();
    if (input == -1) {
        return -1;
    }
    switch (input) {
        case KEY_RIGHT:
            return 0;
            break;
        case KEY_DOWN:
            return 1;
            break;
        case KEY_LEFT:
            return 2;
            break;
        case KEY_UP:
            return 3;
            break;
        default:
            return -1;
    }
}

int main()
{
    initscr();
    noecho();
    keypad(stdscr,true);
    Snake snek;
    while (!false) {
        snek.getSnakeInput();

    }
}