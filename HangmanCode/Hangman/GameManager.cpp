#include "GameManager.h"
#include <cstring>

GameManager::GameManager()
{
	srand(time(NULL));
	words = new std::string[numberOfWords];
	importWords(words);
	currentPhase = 0;
	solvedLetters = 0;
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
void GameManager::lose()
{
	screen.lose();
	getch();
}
void GameManager::won()
{
	screen.win();
	getch();
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
	for (char c: words[wordIndex]) {
		word+=toupper(c);
	}
	return word;
}

void GameManager::importWords(std::string words[])
{
	std::ifstream fin;
	fin.open(".\\HangmanCode\\Hangman\\"+this->WORD_FILENAME);
	
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
	words;
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
	while (true) {
		screen.updateHangedMan(currentPhase);
		while (currentPhase < 6) {
			char letter = getLetter();
			if (usedChars.find(letter) != -1) {
				continue;
			}
			usedChars += letter;
			if (validateLetter(letter).empty()) {
				currentPhase++;
				screen.updateHangedMan(currentPhase);
			}
			else {
				for (int i : validateLetter(letter))
					screen.updateWord(i, letter);
					solvedLetters++;
			}
			isDone();
			screen.updateLetter(letter);
			if (solvedLetters >= word.length()) {
				won();
				return;
			}
		}
		lose();
		return;
	}
	
}

