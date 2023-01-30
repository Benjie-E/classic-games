#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>

using namespace std;

class GameManager
{
public:
	GameManager();
	~GameManager();

	const string WORD_FILENAME = "words.txt";

	string getWord(string words[]);
	string getCurrentWord() { return mCurrentWord; }
	void importWords(string words[]);
	void changeCurrentWord();

private:
	string mCurrentWord;
	string mWords[270];
	
};

