#pragma once
#include <iostream>
#include <curses.h>
#include <string>

using namespace std;

const enum Difficulties
{
	EASY=9,
	MEDIUM=16,
	HARD=22
};

const enum MineAmount
{
	EASYMINES=10,
	MEDMINES=40,
	HARDMINES=99
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
	GameManager(int difficulty, int mineDif);
	~GameManager();

	Square operator()(int row, int col);

	Square** gameBoard;

	//Accessors
	int getDifficulty();
	int getTotalMines();
	int getFlagged();
	
private:
	int mDifficulty, mTotalMines, mFlaggedMines;
};