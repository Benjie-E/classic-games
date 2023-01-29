#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class GameManager
{
public:
	GameManager();
	~GameManager();

	const string WORD_FILENAME = "words.txt";

	string getWord();
	int getNumWords() { return numberOfWords; }
	void importWords(string words[]);

private:
	int numberOfWords = 270;
	
};

