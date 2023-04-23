#include "Location.h"
Location::Location()
{
    this->x = 0;
    this->y = 0;
}

void Location::setX(int x)
{
    this->x = x;
}

void Location::setY(int y)
{
    this->y = y;
}

void Location::setYX(int y, int x)
{
    setX(x);
    setY(y);
}
