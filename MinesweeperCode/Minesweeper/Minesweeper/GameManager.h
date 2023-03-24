#pragma once
#include <iostream>
#include <curses.h>

using namespace std;

const enum Difficulties
{
	EASY=9,
	MEDIUM=16,
	HARD=22
};


struct Square
{
	Square();
	~Square() {};

	int surroundingMines;
	bool hasMine, isRevealed, isFlagged;

	//friend ostream& operator<<(ostream& out, const Square& square);
	void printSquare();
};


class GameManager
{
public:
	GameManager(int difficulty);
	~GameManager();

	Square operator()(int row, int col);

	Square** gameBoard;
	//Accessors
	int getDifficulty();
	
private:
	int mDifficulty;
};