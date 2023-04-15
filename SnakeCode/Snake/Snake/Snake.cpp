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
    if (this->dir == dir) { //same as current direction
        return;
    }
    if ((dir + 2)%4 == this->dir) {//opposite of current direction
        return;
    }
    this->dir = dir;
}

Snake::Snake(int x, int y)
{
    Location newLocation(y, x);
    head = newLocation;
}

void Snake::gameLoop() 
{
    if (dir == UP)
    {
        head = Location(head.getX(), head.getY() + 1);
    }
    else if (dir == DOWN)
    {
        head = Location(head.getX(), head.getY() - 1);
    }
    else if (dir == LEFT)
    {
        head = Location(head.getX() - 1, head.getY());
    }
    else if (dir == RIGHT)
    {
        head = Location(head.getX() + 1, head.getY());
    }
}

void Snake::increaseSize()
{
    int vecSize = body.size();

    if (vecSize == 0)
    {
        Location newBody(head.getY() - 1, head.getX() - 1);
        body.push_back(newBody);
    }
    else
    {
        for (int i = 0; i < vecSize; i++)
        {
            Location newBody(head.getY() - i, head.getX() - i);
            body.push_back(newBody);
        }
    }
}

