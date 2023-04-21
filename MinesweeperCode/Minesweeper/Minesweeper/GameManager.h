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
	bool hasMine, isRevealed, isFlagged, isHighlighted;

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
	void cording(int row, int col); 
	void placeMines();
	void checkGameState(int row, int col);
	void firstMove();

	//Accessors
	int getDifficulty();
	int getGameState();
	int getTotalMines();
	int getFlagged();

	//Mutators
	void setMinesAmount(int dif);
	void setGameState(int);
	void updateFlag(int row, int col);
	void updateRevealed(int row, int col);
	
private:
	int mDifficulty, mTotalMines, mFlagsPlaced;
	//GameStates: 0 = normal play, 1 = player win, 2 = player lose
	int mGameState;
	int mNumCleared, mNotMined;
	bool mFirstMoveMade;
};

int setDifficulty();