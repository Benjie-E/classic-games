#include "GameManager.h"
#include "ScreenManager.h"

GameManager::GameManager(int randNum)
{
	importWords(mWords);
	mNumTries = 5;
	mCurrentWord = getWord(mWords, randNum);
	mRandNum = randNum;

	mScreenManager = new ScreenManager;
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
		printw("Failed to import words file.\n");
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
	printw("A random 5 letter word will be selected and it's your job to guess what it is.\n");
	printw("You will have 5 tries and will be told what letters are right and if they are in the right position or not.\n");
	printw("Good luck!\n");
	refresh();
}

void GameManager::runGameLoop(bool &shouldQuit)
{
	while (true)
	{
		mScreenManager->makeWordleBox();
		refresh();
		mInput = mScreenManager->getInput(mNumTries);

		if (mInput == "exit!" || mInput == "Exit!")
		{
			printw("\n");
			printw("Quiting game\n");
			refresh();
			shouldQuit = true;
			break;
		}
		

		if (mInput.size() != 5)
		{ 
			printw("\n");
			printw("This word is not five letters long, please try again\n");
			refresh();
			continue;
		}
			

		if (mInput == mCurrentWord)
		{
			printw("\n");
			printw("Correct!!!\n");
			printw("Would you like to play again? (y for yes or anything else for no)\n");
			refresh();
			char input = getch();

			if (input == 'y')
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
			mScreenManager->proccesGuess(mInput, mCurrentWord, mNumTries);
			mNumTries--;
		}

		if (mNumTries <= 0)
		{
			printw("\n");
			printw("----------\n");
			printw("Out of tries\n");
			printw("The correct word was: ");
			printw(getCurrentWord().c_str());
			printw("\n");
			printw("Would you like to play again? (y for yes or anything else for no)\n");
			refresh();
			char input = getch();

			if (input == 'y')
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
	string returnLetters;
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
	return returnLetters;
}

string GameManager::checkOrder(string input, string currentWord)
{
	string returnLetters;

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
	return returnLetters;
}

void GameManager::resetGame()
{
	mRandNum++;
	mNumTries = 5;
	changeCurrentWord(mRandNum);
	mScreenManager->reset();
	clear();
}