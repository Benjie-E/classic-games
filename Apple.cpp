#include "Apple.h"
#include "common/Location.h"
Apple::Apple()
{
	int randY = rand() % MAX_Y + 1;
	int randX = rand() % MAX_X + 1;

	mLocation = new Location(randY, randX);
}

Apple::~Apple()
{
	delete mLocation;
}