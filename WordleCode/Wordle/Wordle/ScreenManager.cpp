#include "ScreenManager.h"

ScreenManager::ScreenManager()
{
	initscr();
	start_color();
	noecho();
}

ScreenManager::~ScreenManager()
{
}

void ScreenManager::makeWordleBox()
{
	printw("--------------------------\n");
	printw("|    |    |    |    |    |\n");
	printw("|    |    |    |    |    |\n");
	printw("|    |    |    |    |    |\n");
	printw("--------------------------\n");
	refresh();
}

string ScreenManager::getInput(int numTries)
{
	char builder = ' ';
	string input;
	for (int i = 1; i < 6; i++)
	{
		builder = getch();
		move(15 - numTries * 2, i * 4);
		addch(builder);
		input += builder;
	}
	return input;
}

void ScreenManager::proccesGuess(string guess, string currentWord, int numTries)
{
	int answer;
	for (int i = 0; i < 5; i++)
	{
		answer = checkLetter(guess[i], currentWord, i);
		move(15 - numTries * 2, i + 1 * 4);


	}
}

int ScreenManager::checkLetter(char charToCheck, string currentWord, int i)
{
	//if it is right letter in right place retrun right order
	if (currentWord[i] == charToCheck)
	{
		return RIGHT_ORDER;
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

