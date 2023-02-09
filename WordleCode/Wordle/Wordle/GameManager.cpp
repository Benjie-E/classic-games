#include "GameManager.h"

GameManager::GameManager(int randNum)
{
	importWords(mWords);
	mNumTries = 5;
	mCurrentWord = getWord(mWords, randNum);
	mRandNum = randNum;
}

GameManager::~GameManager()
{
}

string GameManager::getWord(string words[], int randNum)
{
	string word = words[randNum];
	return word;
}

void GameManager::importWords(string words[])
{
	ifstream fin;
	fin.open(this->WORD_FILENAME);

	if (!fin.is_open())
	{
		printw("failed to import words file\n");
		refresh();
		return;
	}

	int counter = 0;

	while (!fin.eof())
	{
		fin >> words[counter];
		counter++;
	}	
}

void GameManager::changeCurrentWord(int randNum)
{
	mCurrentWord = getWord(mWords, randNum);
}

void GameManager::introMessage()
{
	printw("Welcome to Wordle!\n");
	printw("A random 5 letter word will be selected and it's your job to guess what it is\n");
	printw("You will have 5 tries and will be told what letters and right and if they are in the right position or not\n");
	printw("Good luck!\n");
	refresh();
}

void GameManager::runGameLoop(bool &shouldQuit)
{
	while (true)
	{
		printw(" \n");
		printw("Please enter guess or exit to quit game\n");
		refresh();
		getstr(mInput);

		if (mInput == "exit" || mInput == "Exit")
		{
			printw(" ");
			printw("quiting game\n");
			refresh();
			shouldQuit = true;
			break;
		}
		

		if (sizeof(mInput) != 5)
		{ 
			printw(" \n");
			printw("This word is not five letters long please try again\n");
			refresh();
			continue;
		}
			

		if (mInput == mCurrentWord)
		{
			printw(" \n");
			printw("Correct!!!\n");
			printw("would you like to play again (y for yes n for no)\n");
			refresh();
			getstr(mInput);
			mString = mInput;

			if (mString == "y")
			{
				resetGame();
			}
			else
			{
				shouldQuit = true;
				break;
			}
		}
		else
		{
			printw("\n");
			printw("incorrect guess\n");
			printw(checkLetters(mInput, mCurrentWord).c_str());
			printw(checkOrder(mInput, mCurrentWord).c_str());
			printw(" ");
			refresh();
			mNumTries--;
		}

		if (mNumTries <= 0)
		{
			printw(" ");
			printw("out of tries\n");
			printw(getCurrentWord().c_str());
			printw(" ");
			printw("would you like to play again(y for yes n for no\n");
			refresh();
			getstr(mInput);
			mString = mInput;

			if (mString == "y")
			{
				resetGame();
			}
			else
			{
				shouldQuit = true;
				break;
			}
		}
	}
}

string GameManager::checkLetters(string input, string currentWord)
{
	string returnLetters = "Correct letters are: ";

	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 5; j++)
		{
			if (currentWord[i] == input[j])
			{
				returnLetters += input[j];
			}
		}
	}
	returnLetters += " \n";
	return returnLetters;
}

string GameManager::checkOrder(string input, string currentWord)
{
	string returnLetters = "Letter in right order: ";

	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 5; j++)
		{
			if (currentWord[i] == input[j] && i == j)
			{
				returnLetters += input[j];
			}
		}
	}
	returnLetters += " \n";
	return returnLetters;
}

void GameManager::resetGame()
{
	mRandNum++;
	mNumTries = 5;
	changeCurrentWord(mRandNum);
}