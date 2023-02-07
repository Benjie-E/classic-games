#pragma once

const int COLUMNS = 7;
const int ROWS = 6;
const int BOARD_SIZE = COLUMNS * ROWS;

enum SlotFills
{
	EMPTY=0,
	RED_PIECE,	
	YELLOW_PIECE
};

class GameManager
{
public:
	GameManager();
	~GameManager() {};
	
	void placePiece(int column);

	int gameBoard[ROWS][COLUMNS];
	bool isRedTurn;
	bool isWin;
};