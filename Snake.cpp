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
    SnakeLocation newSnakeLocation(y, x);
    head = newSnakeLocation;
    dir = UP;
}

void Snake::gameLoop()
{
    clock.start();
    if (dir == UP)
    {
        head = SnakeLocation(head.getY() - 1, head.getX());
    }
    else if (dir == DOWN)
    {
        head = SnakeLocation(head.getY() + 1, head.getX());
    }
    else if (dir == LEFT)
    {
        head = SnakeLocation(head.getY(), head.getX() - 1);
    }
    else if (dir == RIGHT)
    {
        head = SnakeLocation(head.getY(), head.getX() + 1);
    }
    while (this->clock.getElapsedTime() < 100);
}

void Snake::increaseSize()
{
    int vecSize = body.size();

    if (vecSize == 0)
    {
        if (dir == UP)
        {
            SnakeLocation newBody(head.getY() - 1, head.getX());
            body.push_back(newBody);
        }
        else if (dir == DOWN)
        {
            SnakeLocation newBody(head.getY() + 1, head.getX());
            body.push_back(newBody);
        }
        else if (dir == RIGHT)
        {
            SnakeLocation newBody(head.getY(), head.getX() - 1);
            body.push_back(newBody);
        }
        else if (dir == LEFT)
        {
            SnakeLocation newBody(head.getY(), head.getX() + 1);
            body.push_back(newBody);
        }

    }
    else
    {
        for (int i = 0; i < vecSize; i++)
        {
            SnakeLocation newBody(head.getY() - i, head.getX() - i);
            body.push_back(newBody);
        }
    }
}