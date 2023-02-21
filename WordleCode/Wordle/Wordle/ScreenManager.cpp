#include "ScreenManager.h"

ScreenManager::ScreenManager()
{
	initscr();
	start_color();
	noecho();

	init_pair(RIGHT_LETTER, COLOR_BLACK, COLOR_YELLOW);
	init_pair(ORDER, COLOR_BLACK, COLOR_GREEN);

	mCurrentDepth = 5;
}

ScreenManager::~ScreenManager()
{
}

void ScreenManager::makeWordleBox()
{
	for (int i = 1; i < 11; i++)
	{
		move(mCurrentDepth - 1, i);
		addch('-');
	}

	for (int i = 0; i < 12; i += 2)
	{
		move(mCurrentDepth, i);
		addch('|');
	}

	for (int i = 1; i < 11; i++)
	{
		move(mCurrentDepth + 1, i);
		addch('-');
	}
	
	refresh();
}

string ScreenManager::getInput(int numTries)
{
	char builder = ' ';
	string input;
	for (int i = 1; i < 11; i+=2)
	{
		builder = getch();
		move(mCurrentDepth, i);
		addch(builder);
		input += builder;
	}
	return input;
}

void ScreenManager::proccesGuess(string guess, string currentWord, int numTries)
{
	int j = 0;
	int answer;
	makeWordleBox();
	for (int i = 1; i < 11; i+=2)
	{
		answer = checkLetter(guess[j], currentWord, j);

		if (answer == 3)
		{
			attron(COLOR_PAIR(ORDER));
			move(mCurrentDepth, i);
			addch(guess[j]);
			attroff(COLOR_PAIR(ORDER));
			refresh();
		}
		else if (answer == 1)
		{
			attron(COLOR_PAIR(RIGHT_LETTER));
			move(mCurrentDepth, i);
			addch(guess[j]);
			attroff(COLOR_PAIR(RIGHT_LETTER));
			refresh();
		}
		else
		{
			move(mCurrentDepth, i);
			addch(guess[j]);
			refresh();
		}
		j++;
	}
	mCurrentDepth += 4;
}

int ScreenManager::checkLetter(char charToCheck, string currentWord, int i)
{
	//if it is right letter in right place retrun right order
	if (currentWord[i] == charToCheck)
	{
		return ORDER;
	}
	
	//if it is right letter in wrong place return right letter
	for (int j = 0; j < 5; j++)
	{
		if (currentWord[j] == charToCheck)
		{
			return RIGHT_LETTER;
		}
	}

	//if it is the wrong letter in the wrong place return wrong letter
	return WRONG_LETTER;
}

void ScreenManager::reset()
{
	mCurrentDepth = 5;
}

