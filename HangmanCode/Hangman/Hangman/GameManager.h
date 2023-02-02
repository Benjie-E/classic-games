#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>

class GameManager
{
public:
	GameManager();
	~GameManager();

	const std::string WORD_FILENAME = "words.txt";

	std::string getWord();
	int getNumWords() { return numberOfWords; }
	void importWords(std::string words[]);

	char getLetter;


private:
	int numberOfWords = 854;
	std::string* wordList = nullptr;
};