#include "GameManager.h"

GameManager::GameManager(int randNum)
{
	importWords(mWords);
	mNumTries = 5;
	mCurrentWord = getWord(mWords, randNum);
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
		cout << "failed to import words file" << endl;
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
	cout << "Welcome to Wordle!" << endl;
	cout << "A random 5 letter word will be selected and it's your job to guess what it is" << endl;
	cout << "You will have 5 tries and will be told what letters and right and if they are in the right position or not" << endl;
	cout << "Good luck!" << endl;
}

void GameManager::runGameLoop()
{
	while (true)
	{
		cout << "Please enter guess or exit to quit game" << endl;
		cin >> mInput;

		if (mInput == "exit" || mInput == "Exit")
			break;

		if (mInput.length() != 5)
			break;

		if (mInput == mCurrentWord)
		{
			cout << "Correct!!!" << endl;
		}
		else
		{

		}

	}
}