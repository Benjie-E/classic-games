#include "GameManager.h"
#include <string>
#include <vector>
#include <ctime>

using namespace std;

Square::Square()
{
	surroundingMines = 0;
	hasMine = false;
	isRevealed = false;
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
	return mDifficulty;
}


int GameManager::getGameState()
{
	return mGameState;
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


int setDifficulty()
{
	int diffNum = 0;
	char diffChoice;
	refresh();
	do
	{
		printw("Enter a difficulty: 1 = Easy, 2 = Medium, 3 = Hard");
		refresh();
		diffChoice = getchar();
		erase();
		switch (diffChoice)
		{
		case '1':
			diffNum = EASY;
			break;
		case '2':
			diffNum = MEDIUM;
			break;
		case '3':
			diffNum = HARD;
			break;
		default:
			printw("Invalid response please try again\n");
			break;
		}
	} while (diffNum != HARD && diffNum != MEDIUM && diffNum != EASY);
	erase();
	return diffNum;
};


void GameManager::setGameState(int state)
{
	mGameState = state;
}

int GameManager::checkGameState()
{
	int i, j, minesFlagged = 0;
	// Checks to see if a mine has been revealed (the player loses)
	for (i = 0; i < mDifficulty; i++)
	{
		for (j = 0; j < mDifficulty; j++)
		{
			if (gameBoard[i][j].isRevealed == true && gameBoard[i][j].hasMine == true)
			{
				return PLAYERLOSE;
			}
			if (gameBoard[i][j].isFlagged == true && gameBoard[i][j].hasMine == true)
			{
				minesFlagged++;
			}
		}
	}

	// Player has won, all mines have been flagged
	if (minesFlagged == mTotalMines)
		return PLAYERWIN;
	else
		return STILLPLAYING; // Game is still going
}