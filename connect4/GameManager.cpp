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
	
	isPlayer1Turn = true;
	isWin = false;
}

void GameManager::placePiece(int column)
{
	bool placed = false;
	
	int i = 0;
	//int* tmp;

	while (gameBoard[i + 1][column] == EMPTY && i < ROWS)
	{
		i++;
	}

	if (isPlayer1Turn)
		gameBoard[i][column] = PIECE1;
	else
		gameBoard[i][column] = PIECE2;

	isPlayer1Turn = !isPlayer1Turn;

	return;
}