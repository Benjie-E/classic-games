#include "GameManager.h"
#include <direct.h>

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

std::string GameManager::getWord()
{
	int wordIndex = (rand()%numberOfWords);
	return wordList[wordIndex];
}

void GameManager::importWords(std::string words[])
{
	std::ifstream fin;
	fin.open(".\\"+this->WORD_FILENAME);
	
	if (!fin.is_open())
	{
		std::cout << "failed to import words file" << std::endl;
		return;
	}

	int counter = 0;

	while (!fin.eof())
	{
		fin >> words[counter];
		counter++;
	}
	wordList = words;

}