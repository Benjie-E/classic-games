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

void GameManager::runGameLoop(bool &shouldQuit)
{
	while (true)
	{
		cout << endl;
		cout << "Please enter guess or exit to quit game" << endl;
		cin >> mInput;

		if (mInput == "exit" || mInput == "Exit")
		{
			cout << endl;
			cout << "quiting game" << endl;
			shouldQuit = true;
			break;
		}
			

		if (mInput.length() != 5)
		{ 
			cout << endl;
			cout << "This word is not five letters long please try again" << endl;
			continue;
		}
			

		if (mInput == mCurrentWord)
		{
			cout << endl;
			string input;
			cout << "Correct!!!" << endl;
			cout << "would you like to play again (y for yes n for no)" << endl;
			cin >> input;

			if (input == "y")
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
			cout << endl;
			cout << "incorrect guess" << endl;
			cout << "These letters were right: " << checkLetters(mInput, mCurrentWord) << endl;
			cout << "These letter were in the right order: " << checkOrder(mInput, mCurrentWord) << endl;
			cout << endl;
			mNumTries--;
		}

		if (mNumTries <= 0)
		{
			cout << endl;
			string input;
			cout << "out of tries" << endl;
			cout << "the correct word was " << getCurrentWord() << endl;
			cout << endl;
			cout << "would you like to play again (y for yes n for no)" << endl;
			cin >> input;

			if (input == "y")
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
	string returnLetters = "";

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
	string returnLetters = "";

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
}