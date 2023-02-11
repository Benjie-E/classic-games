#include "GameManager.h"

using namespace std;

GameManager::GameManager()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			gameBoard[i][j] = EMPTY;
		}
	}
	
	isRedTurn = true;
	isWin = false;
}


void GameManager::placePiece(int column)
{
	bool placed = false;
	
	int i = 0;

	while (gameBoard[i + 1][column] == EMPTY && i < ROWS)
	{
		i++;
	}

	if (isRedTurn)
		gameBoard[i][column] = RED_PIECE;
	else
		gameBoard[i][column] = YELLOW_PIECE;

	isRedTurn = !isRedTurn;

	return;
}


void GameManager::checkWin()
{
	for (int i = 0; i < ROWS; i++)
	{

	}
}