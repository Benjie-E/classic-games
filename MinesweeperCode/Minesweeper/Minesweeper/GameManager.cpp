#include "GameManager.h"
#include <string>
#include <vector>
#include <ctime>

using namespace std;

Square::Square()
{
	surroundingMines = 0;
	hasMine = false;
	isRevealed = true;
	isFlagged = false;
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
	setMinesAmount(difficulty);
	mFlaggedMines = 0;

	// dynamic allocation of 2d arrays is gross
	gameBoard = new Square * [mDifficulty];
	for (int i = 0; i < mDifficulty; i++)
	{
		gameBoard[i] = new Square[mDifficulty];
	}

	// generate mines HERE (before calcSurroundingMines)
	placeMines();
	calcSurroundingMines();
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


void GameManager::calcSurroundingMines()
{
	/*
	* There's a lot of unique cases here due to corners, etc.
	* So this is kind of a mess but...it works. (hopefully)
	* The nested ifs are to avoid going out of the array's ranges
	*/
	int i, j;
	int boardSize = getDifficulty();
	Square* tmp;

	for (i = 0; i < boardSize; i++)
	{
		for (j = 0; j < boardSize; j++)
		{
			tmp = &gameBoard[i][j];
			if (i > 0) // has square above it
			{
				if (gameBoard[i - 1][j].hasMine)
					tmp->surroundingMines++;
				if (j > 0) // ...and to the up-left
					if (gameBoard[i - 1][j - 1].hasMine)
						tmp->surroundingMines++;
				if (j < boardSize - 1) // ...and to the up-right
					if (gameBoard[i - 1][j + 1].hasMine)
						tmp->surroundingMines++;
			}
			if (i < boardSize - 1) // has square below it
			{
				if (gameBoard[i + 1][j].hasMine)
					tmp->surroundingMines++;
				if (j > 0) // ...and down-left
					if (gameBoard[i + 1][j - 1].hasMine)
						tmp->surroundingMines++;
				if (j < boardSize - 1) // ...and down-right
					if (gameBoard[i + 1][j + 1].hasMine)
						tmp->surroundingMines++;
			}
			if (j > 0) // has square to the left
				if (gameBoard[i][j - 1].hasMine)
					tmp->surroundingMines++;
			if (j < boardSize - 1) // has square to the right
				if (gameBoard[i][j + 1].hasMine)
					tmp->surroundingMines++;
		}
	}
	tmp = NULL;
	delete tmp;
}


void GameManager::placeMines()
{
	int totalSquares = mDifficulty * mDifficulty;
	
	vector<int> allSquareIndexes;
	// fill the vector with the indexes of the squares on the board
	for (int i = 0; i < totalSquares; i++)
	{
		allSquareIndexes.push_back(i);
	}

	int vecIndex, tmp, row, col;
	for (int i = 0; i < mTotalMines; i++)
	{
		// lottery picks a random square and removes it from the vector
		vecIndex = rand() % (allSquareIndexes.size() - 1);
		tmp = allSquareIndexes[vecIndex];
		allSquareIndexes.erase(allSquareIndexes.begin() + vecIndex);
		// math time
		row = tmp / (mDifficulty); // row is the quotient
		col = tmp % (mDifficulty); // col is the remainder
		gameBoard[row][col].hasMine = true;
	}
}


int GameManager::getDifficulty()
{
	const int difficulty = mDifficulty;
	return difficulty;
}


int GameManager::getTotalMines()
{
	return mTotalMines;
}


int GameManager::getFlagged()
{
	return mFlaggedMines;
}


void GameManager::setMinesAmount(int dif)
{
	if (dif == EASY)
		mTotalMines = EASYMINES;
	else if (dif == HARD)
		mTotalMines = HARDMINES;
	else
		mTotalMines = MEDMINES;
}

