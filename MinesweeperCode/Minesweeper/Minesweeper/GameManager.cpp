#include "GameManager.h"

Square::Square()
{
	surroundingMines = 0;
	hasMine = false;
	isRevealed = false;
	isFlagged = false;
}


GameManager::GameManager(int difficulty)
{
	mDifficulty = difficulty;

	// dynamic allocation of 2d arrays is gross
	gameBoard = new Square * [mDifficulty];
	for (int i = 0; i < mDifficulty; i++)
	{
		gameBoard[i] = new Square[mDifficulty];
	}
}


GameManager::~GameManager()
{
	// gotta get rid of all those pointers
	for (int i = 0; i < mDifficulty; i++)
	{
		delete[] gameBoard[i];
	}
	delete[] gameBoard;
}


Square GameManager::operator()(int row, int col)
{
	return gameBoard[row][col];
}

int GameManager::getDifficulty()
{
	const int difficulty = mDifficulty;
	return difficulty;
}