#pragma once

#include <string>
#include <iostream>

using namespace std;

const char PLAYER[2]{ 'X','O' };

class Board {
public:
	bool setChar(char tile, int player);
	int winCheck();
	void printBoard();
	char getMove();

private:
	char tiles[9]{ '1','2','3','4','5','6','7','8','9' };
};