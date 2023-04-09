#pragma once
class Location {
public:
	Location();
	Location(int y, int x) { this->y = y;this->x = x; };

	int getX() { return this->x; }
	int getY() { return this->y; }
	void setX(int x);
	void setY(int y);
	void setYX(int y, int x);
private:
	int y;
	int x;
};