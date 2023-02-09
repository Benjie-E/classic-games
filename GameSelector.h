#pragma once
#include "HangmanCode/Hangman/Hangman.h"
#include <curses.h>
#include <string>
#include <Windows.h>
class GameSelector
{
public:
	POINT menuPos;
	std::string gameList[4] = {"Hangman","TicTacToe","Wordle","Connect4"};
	enum gameList {Hangman,TicTacToe,Wordle,Connect4};
	GameSelector();
	bool updateSelector(int game);
	int select();
	int start(int game);
};

