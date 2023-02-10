#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>
#include <curses.h>

using namespace std;

class ScreenManager
{
public:
	ScreenManager();
	~ScreenManager();

	void makeWordleBox();
	string getInput(int numTries);
	int checkLetter(char charToCheck, string currentGuess, int i);
	void proccesGuess(string guess, string currentWord, int numTries);

private:
	const int RIGHT_LETTER = 0;
	const int RIGHT_ORDER = 1;
	const int WRONG_LETTER = 2;
	int mCurrentDepth;
};

