#include "GameManager.h"

GameManager::GameManager()
{
	importWords(mWords);

	mCurrentWord = getWord(mWords);
}

GameManager::~GameManager()
{
}

string GameManager::getWord(string words[])
{
	srand(time(NULL));
	int ranNum = rand() % 270 + 1;

	string word = words[ranNum];
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

void GameManager::changeCurrentWord()
{
	mCurrentWord = getWord(mWords);
}