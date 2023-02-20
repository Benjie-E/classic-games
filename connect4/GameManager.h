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
	//bool keepPlaying;

	// accessors and mutators
	int getWinner();
	int getTurnNumber();
	void setWinner(int winner);
	void setTurnNumber(int turnNumber);

private:
	int mTurnNumber;
	int mWinner;
};