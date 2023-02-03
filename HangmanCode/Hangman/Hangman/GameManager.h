#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ScreenManager.h"
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

private:
	int numberOfWords = 854;
	std::string* wordList = nullptr;
};