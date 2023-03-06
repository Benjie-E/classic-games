#pragma once
class Location {
public:
	Location();
	Location(int y, int x) { this->y = y;this->x = x; };
private:
	int y;
	int x;
};