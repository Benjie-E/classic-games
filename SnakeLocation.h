#pragma once

class SnakeLocation {
public:
	SnakeLocation();
	SnakeLocation(int y, int x) { this->y = y; this->x = x; };

	int getX() { return this->x; }
	int getY() { return this->y; }

private:
	int y;
	int x;
};
