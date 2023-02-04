/*
Author: Ben Tangora
Class : CSI - 281 - 01

Description:
	Tic Tac Toe coded in C++ and using the console as a display/input device
*/

#pragma once

#include <string>
#include <iostream>

using namespace std;

const char PLAYER[2]{ 'X','O' };

class Board {
public:
	bool setChar(char tile, int player);
	bool finishedCheck();
	int getWinStatus();
	void printBoard();
	char getMove(int playerNum);

private:
	char tiles[10]{'1','1','2','3','4','5','6','7','8','9' };
	bool charPlaced[10]{ true,false,false,false,false,false,false,false,false,false };
};