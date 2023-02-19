#include "GameManager.h"

using namespace std;

GameManager::GameManager()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			gameBoard[i][j] = NONE;
		}
	}
	
	isRedTurn = true;
	mWinner = NONE;
	turnNumber = 1;
}


void GameManager::placePiece(int column)
{	
	int i = 1;

	while (i < ROWS && gameBoard[i][column] == NONE)
	{
		i++;
	}

	// only do something if column is not full
	if (gameBoard[i - 1][column] == NONE)
	{
		if (isRedTurn)
			gameBoard[i - 1][column] = RED;
		else
			gameBoard[i - 1][column] = YELLOW;

		isRedTurn = !isRedTurn;
		turnNumber++;
	}
}


void GameManager::checkWin()
{
	int check;
	bool isWin = false;

	if (!isRedTurn)
		check = RED;
	else
		check = YELLOW;

	// check horizontal wins
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS - 3; j++)
		{
			/* COLUMNS - 3 because the loop checks for 4 in a row starting
			*  from the left. farthest horizontal win would be columns 4, 5, 6,
			*  and 7 */
			if (gameBoard[i][j] == check)
			{
				if (gameBoard[i][j + 1] == check)
				{
					if (gameBoard[i][j + 2] == check)
					{
						if (gameBoard[i][j + 3] == check)
						{
							mWinner = check;
							return;
						}
					}
				}
			}
		}
	}

	//check vertical wins
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS - 3; j++)
		{
			// same reasoning for ROWS - 3 as COLUMNS - 3 above
			if (gameBoard[j][i] == check)
			{
				if (gameBoard[j + 1][i] == check)
				{
					if (gameBoard[j + 2][i] == check)
					{
						if (gameBoard[j + 3][i] == check)
						{
							mWinner = check;
							return;
						}
					}
				}
			}
		}
	}

	// check diagonal wins, high left to low right
	/* starts checks across rows from index 0 to 2 between columns 0 and 3
	*  (both inclusive) because those are the locations where these matching
	*  patterns could exist */
	for (int i = 0; i < ROWS - 3; i++)
	{
		for (int j = 0; j < COLUMNS - 3; j++)
		{
			if (gameBoard[i][j] == check)
			{
				if (gameBoard[i + 1][j + 1] == check)
				{
					if (gameBoard[i + 2][j + 2] == check)
					{
						if (gameBoard[i + 3][j + 3] == check)
						{
							mWinner = check;
							return;
						}
					}
				}
			}
		}
	}

	// check diagonal wins, high right to low left
	// starts checks across rows from index 0 to 2 between columns 3 and 6
	for (int i = 0; i < ROWS - 3; i++)
	{
		for (int j = 3; j < COLUMNS; j++)
		{
			if (gameBoard[i][j] == check)
			{
				if (gameBoard[i + 1][j - 1] == check)
				{
					if (gameBoard[i + 2][j - 2] == check)
					{
						if (gameBoard[i + 3][j - 3] == check)
						{
							mWinner = check;
							return;
						}
					}
				}
			}
		}
	}
}


int GameManager::getWinner()
{
	return mWinner;
}


void GameManager::setWinner(int winner)
{
	mWinner = winner;
}