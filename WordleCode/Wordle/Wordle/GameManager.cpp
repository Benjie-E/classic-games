#include "GameManager.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

string GameManager::getWord()
{
	return string();
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