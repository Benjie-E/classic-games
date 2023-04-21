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
	isHighlighted = false;
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
			if (isHighlighted)
			{
				attron(COLOR_PAIR(12));
				printw("!!");
				attroff(COLOR_PAIR(12));
			}
			else
			{
				attron(COLOR_PAIR(10));
				printw("!!");
				attroff(COLOR_PAIR(10));
			}
		}
		else
		{
			if (isHighlighted)
			{
				attron(COLOR_PAIR(11));
				printw("  ");
				attroff(COLOR_PAIR(11));
			}
			else
			{
				attron(COLOR_PAIR(9));
				printw("  ");
				attroff(COLOR_PAIR(9));
			}
		}
	}
}


GameManager::GameManager(int difficulty)
{
	mDifficulty = difficulty;
	setMinesAmount(difficulty);
	mFlagsPlaced = 0;
	mGameState = 0;
	mMinesFlagged = 0;
	mNotMined = (difficulty * difficulty) - mTotalMines;
	mFirstMoveMade = false;

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
	return mFlagsPlaced;
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
	// Basic menu for the player to input if they want to replay
	int choice = 0, numChoices = 3, selected = 0, diffNum = 0, i;
	string options[] = { "Easy (9x9)", "Medium (16x16)", "Hard (22x22)", "> Easy(9x9)", "> Medium (16x16)", "> Hard (22x22)"};
	keypad(stdscr, true);

	while (true)
	{
		// clears screen and prints menu
		clear();
		mvprintw(0, 0, "[ENTER] or [X] to select.");
		for (i = 0; i < numChoices; i++)
		{
			if (i == selected)
			{
				mvprintw(i + 1, 1, options[i + numChoices].c_str());
			}
			else
			{
				mvprintw(i + 1, 1, options[i].c_str());
			}
		}

		choice = getch();

		switch (choice) {
		case KEY_UP: //Up arrow: Moves selection up
			selected = (selected - 1 + numChoices) % numChoices;
			break;
		case 119: //W: Moves selection up
			selected = (selected - 1 + numChoices) % numChoices;
			break;
		case KEY_DOWN: // Down arrow. Moves selection down
			selected = (selected + 1) % numChoices;
			break;
		case 115: // S: Moves selection down
			selected = (selected + 1) % numChoices;
			break;
		case 10: //Enter: Returns selected
		case 32:
		case 88: // X also returns selected
		case 120:
			clear();
			if (selected == 0)
				return EASY;
			else if (selected == 1)
				return MEDIUM;
			else
				return HARD;
			break;
		default:
			break;
		}
	}
}


void GameManager::setGameState(int state)
{
	mGameState = state;
}


void GameManager::checkGameState(int row, int col)
{
	int minesFlagged = 0, gameState = 0;
	// Checks to see if a mine has been revealed (the player loses)

	if (gameBoard[row][col].isRevealed == true && gameBoard[row][col].hasMine == true)
	{
		gameState = PLAYERLOSE;
	}
	// Player has won, all non mine spaces have been revealed
	else if (mNumCleared == mNotMined)
		gameState = PLAYERWIN;
	else
		gameState = STILLPLAYING; // Game is still going

	setGameState(gameState);
}

void GameManager::updateFlag(int row, int column)
{
	if (!gameBoard[row][column].isRevealed) // do nothing to revealed squares
	{
		gameBoard[row][column].isFlagged = !gameBoard[row][column].isFlagged;

		if (gameBoard[row][column].isFlagged && !gameBoard[row][column].hasMine)
			mMinesFlagged++;

		if (gameBoard[row][column].isFlagged)
			mFlagsPlaced++;
		else if (gameBoard[row][column].isFlagged) // flag got removed
			mFlagsPlaced--;
	}
	else if (gameBoard[row][column].isFlagged) // remove flag from revealed square
	{
		gameBoard[row][column].isFlagged = false;
		mFlagsPlaced--;
	}
}


void GameManager::updateRevealed(int row, int col)
{
	if (!gameBoard[row][col].isRevealed && !gameBoard[row][col].hasMine) //square isn't revealed (yet) and doesn't have a mine
		mNumCleared++;
}


void GameManager::cording(int row, int col)
{
	int topRow = row - 1;
	int botRow = row + 1;
	int leftCol = col - 1;
	int rightCol = col + 1;

	if (!gameBoard[row][col].isRevealed && gameBoard[row][col].surroundingMines == 0)
	{
		gameBoard[row][col].isRevealed = true;
		mNumCleared++;

		//Top
		if (row != 0) //Doesn't go outside of the game board
		{
			cording(topRow, col);
		}

		//Bottom
		if (row != mDifficulty - 1)
		{
			cording(botRow, col);
		}
		//Left
		if (col != 0)
		{
			cording(row, leftCol);
		}
		//Right
		if (col != mDifficulty - 1)
		{
			cording(row, rightCol);
		}
	}
}


void GameManager::firstMove()
{
	bool picking = true;
	int row, col;

	if (!mFirstMoveMade) //First move has not been made
	{
		while (picking)
		{
			// Picks random square and checks if it has a mine
			row = rand() % (mDifficulty);
			col = rand() % (mDifficulty);
			if (!gameBoard[row][col].hasMine)
			{
				//If it doesn't have a mine, reveals it and makes sure this doesn't repeat.
				gameBoard[row][col].isRevealed = true;
				picking = false;
				mFirstMoveMade = true;
				refresh();
			}
		}
	}
}