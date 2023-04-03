#include "GameManager.h"
#include <string>

using namespace std;

Square::Square()
{
	surroundingMines = 0;
	hasMine = false;
	isRevealed = false;
	isFlagged = false;
}


int GameManager::getTotalMines()
{
	return mTotalMines;
}


int GameManager::getFlagged()
{
	return mFlaggedMines;
}


void GameManager::SetMinesAmount(int dif)
{
	if (dif == EASY)
		mTotalMines = EASYMINES;
	else if (dif == HARD)
		mTotalMines = HARDMINES;
	else
		mTotalMines = MEDMINES;
}


void Square::printSquare()
{
	if (isRevealed)
	{
		if (hasMine)
		{
			attron(COLOR_PAIR(3));
			printw("XX");
			attroff(COLOR_PAIR(3));
		}
		else // if (!hasMine)
		{
			attron(COLOR_PAIR(surroundingMines));
			printw("%d ", surroundingMines);
			attroff(COLOR_PAIR(surroundingMines));
		}
	}
	else // if (!isRevealed)
	{
		if (isFlagged)
		{
			attron(COLOR_PAIR(10));
			printw("!!");
			attroff(COLOR_PAIR(10));
		}
		else
		{
			attron(COLOR_PAIR(9));
			printw("  ");
			attroff(COLOR_PAIR(9));
		}
	}
}


GameManager::GameManager(int difficulty)
{
	mDifficulty = difficulty;
	SetMinesAmount(difficulty);
	mFlaggedMines = 0;

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