#include "Apple.h"

Apple::Apple()
{
	int randY = rand() % MAX_Y + 1;
	int randX = rand() % MAX_X + 1;

	location = new Location(randY, randX);
}

Apple::~Apple()
{
	delete location;
}