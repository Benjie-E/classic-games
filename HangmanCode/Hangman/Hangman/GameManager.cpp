#include "GameManager.h"
#include <direct.h>
#include <curses.h>
#include <time.h>
GameManager::GameManager()
{
	srand(time(NULL));
	words = new std::string[numberOfWords];
	importWords(words);
}

GameManager::~GameManager()
{
	
}
void GameManager::start()
{
	word = getWord();
	gameLoop();
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

char GameManager::getLetter()
{
	char letter = 0;
	while (!isalpha(letter)) {
		letter = getch();
	}
	return letter;
}

void GameManager::gameLoop()
{
	while (true) {
		getch();
		screen.updateHangedMan();
	}
	
	
}
