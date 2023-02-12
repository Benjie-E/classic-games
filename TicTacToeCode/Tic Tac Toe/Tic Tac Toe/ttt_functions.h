/*
Author: Ben Tangora
Class : CSI - 281 - 01

Description:
	Tic Tac Toe coded in C++ and using the console as a display/input device
*/

#pragma once

#include <string>
#include <iostream>
#include <curses.h>

using namespace std;

const char PLAYER[2]{ 'X','O' };

class TTTManager {
public:
	int player = 0;

	bool setChar(char tile);
	bool finishedCheck();
	int getWinStatus();
	void updateBoard();
	char getMove();
	void printVictory();
	bool goAgain();
	void boardReset();

private:
	char tiles[10]{'1','1','2','3','4','5','6','7','8','9' };
	bool charPlaced[10]{ true,false,false,false,false,false,false,false,false,false };
};