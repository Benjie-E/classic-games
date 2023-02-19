#pragma once

const int COLUMNS = 7;
const int ROWS = 6;
const int GRID_SIZE = COLUMNS * ROWS;

const enum SlotFills
{
	NONE=0,
	RED,	
	YELLOW
};

class GameManager
{
public:
	GameManager();
	~GameManager() {};
	
	void placePiece(int column);
	void checkWin();

	int gameBoard[ROWS][COLUMNS];
	bool isRedTurn;
	int turnNumber;

	// accessors and mutators
	int getWinner();
	void setWinner(int winner);

private:
	int mWinner;
};