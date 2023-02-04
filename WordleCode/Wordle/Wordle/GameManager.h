#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>

using namespace std;

class GameManager
{
public:
	GameManager(int randNum);
	~GameManager();

	const string WORD_FILENAME = "words.txt";

	string getWord(string words[], int RandNum);
	string getCurrentWord() { return mCurrentWord; }
	void changeCurrentWord(int randNum);
	void introMessage();

private:
	string mCurrentWord;
	string mWords[270];
	void importWords(string words[]);
	
};

