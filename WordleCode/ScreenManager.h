#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include "../common/Location.h"
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
	void reset();

private:
	const int RIGHT_LETTER = 1;
	const int WRONG_LETTER = 2;
	const int ORDER = 3;
	int mCurrentDepth;
};

