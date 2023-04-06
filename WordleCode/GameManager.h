#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include "../common/Location.h"
#include <curses.h>

using namespace std;

class ScreenManager;

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

	string checkLetters(string input, string currentWord);
	string checkOrder(string input, string currentWord);

	void runGameLoop(bool &shouldQuit);
	void resetGame();

private:
	string mCurrentWord;
	string mWords[270];
	void importWords(string words[]);
	int mNumTries;
	string mInput;
	int mRandNum;
	ScreenManager* mScreenManager;
	
};

