#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ScreenManager.h"
#include <vector>
#include <direct.h>
#include <curses.h>
#include <time.h>

class GameManager
{
public:
	GameManager();
	~GameManager();

	const std::string WORD_FILENAME = "words.txt";

	std::string getWord();
	int getNumWords() { return numberOfWords; }
	void importWords(std::string words[]);
	char getLetter();
	void gameLoop();
	std::string* words;
	std::string word;
	void start();
	ScreenManager screen;
	void lost();
	void won();
	int currentPhase;
	void updateWord(int index);
	std::vector<int> validateLetter(char letter);
	std::string usedChars;
	bool isDone();
private:
	int numberOfWords = 854;
};