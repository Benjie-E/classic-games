#include <curses.h>
#include "Snake.h"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <cstdlib>

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
            return dir;
    }
}
void Snake::changeDirection(direction dir)
{
    if (this->dir == dir)
    {
        return;
    }
    else
    {
        this->dir = dir;
    }
}

Snake::Snake(int x, int y)
{
    Location newLocation(y, x);
    head = newLocation;
    dir = UP;
}

void Snake::gameLoop() 
{
    clock.start();
    if (dir == UP)
    {
        head = Location(head.getY() - 1, head.getX());
    }
    else if (dir == DOWN)
    {
        head = Location(head.getY() + 1, head.getX());
    }
    else if (dir == LEFT)
    {
        head = Location(head.getY(), head.getX() - 2);
    }
    else if (dir == RIGHT)
    {
        head = Location(head.getY(), head.getX() + 2);
    }
    while (this->clock.getElapsedTime() < 100);
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

