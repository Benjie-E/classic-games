#pragma once

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
};


class GameManager
{
public:
	GameManager(int difficulty);
	~GameManager();

	Square operator()(int row, int col);

	Square** gameBoard;
	
private:
	int mDifficulty;
};