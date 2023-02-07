#include "GameManager.h"
#include <cstring>

GameManager::GameManager()
{
	srand(time(NULL));
	words = new std::string[numberOfWords];
	importWords(words);
	currentPhase = 0;
	
}

GameManager::~GameManager()
{
	
}
void GameManager::start()
{
	word = getWord();
	screen.start(word.size());
	gameLoop();
	
}
void GameManager::lost()
{
}
void GameManager::won()
{
}
void GameManager::updateWord(int index)
{

}
std::vector<int> GameManager::validateLetter(char letter)
{
	std::vector<int> correctIndexes;
	for (int i = 0;i < word.size();i++) {
		if (word[i] == letter) {
			correctIndexes.push_back(i);
		}
	}
	return correctIndexes;
}

bool GameManager::isDone()
{
	return false;
}

std::string GameManager::getWord()
{
	int wordIndex = (rand()%numberOfWords);
	std::string word = "";
	for (char c: wordList[wordIndex]) {
		word+=toupper(c);
	}
	return word;
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
	numberOfWords = counter;
}

char GameManager::getLetter()
{
	char letter = 0;
	while (!isalpha(letter)) {
		letter = getch();
	}
	return toupper(letter);
}

void GameManager::gameLoop()
{
	while (currentPhase<=6) {
		char letter= getLetter();
		if (usedChars.find(letter)!=-1) {
			continue;
		}
		usedChars+=letter;
		if (validateLetter(letter).empty()) {
			screen.updateHangedMan(currentPhase);
			currentPhase++;
		}
		else {
			for (int i : validateLetter(letter))
				screen.updateWord(i,letter);
		}
		isDone();
		screen.updateLetter(letter);
	}
	lost();
}

