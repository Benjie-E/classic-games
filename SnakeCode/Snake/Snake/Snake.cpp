#include <curses.h>
#include "Snake.h"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

Snake::direction Snake::getSnakeInput() {
    int input = getch();
    switch (input) {
        case KEY_RIGHT:
            return RIGHT;
            break;
        case KEY_DOWN:
            return DOWN;
            break;
        case KEY_LEFT:
            return LEFT;
            break;
        case KEY_UP:
            return UP;
            break;
        default:
            return OTHER;
    }
}
void Snake::changeDirection(direction dir)
{
    if (dir == OTHER) { //invalid direction
        return;
    }
    if (dir == currentDirection) { //same as current direction
        return;
    }
    if ((dir + 2)%4 == currentDirection) {//opposite of current direction
        return;
    }
    currentDirection = dir;
}
Snake::Snake()
{
}
void Snake::gameLoop() {
    move(0, 0);
    
    while (true) {
        Sleep(1000);
        addch('0');
        refresh();
    }
}

