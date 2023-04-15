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

const enum GameStates
{
	STILLPLAYING=0,
	PLAYERWIN=1,
	PLAYERLOSE=2
};


struct Square
{
	Square();
	~Square() {};

	int surroundingMines;
	bool hasMine, isRevealed, isFlagged;

	void printSquare();
};


class GameManager
{
public:
	GameManager(int difficulty);
	~GameManager();

	Square operator()(int row, int col);

	Square** gameBoard;

	void calcSurroundingMines();
	void placeMines();

	//Accessors
	int getDifficulty();
	int getGameState();
	int getTotalMines();
	int getFlagged();
	void setMinesAmount(int dif);
	void setGameState(int);
	int checkGameState();
	
private:
	int mDifficulty, mTotalMines, mFlaggedMines;
	//GameStates: 0 = normal play, 1 = player win, 2 = player lose
	int mGameState = 0;
};

int setDifficulty();