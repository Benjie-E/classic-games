#pragma once
#include "HangmanCode/Hangman.h"
#include "Connect4/connect4.h"
#include "WordleCode/Wordle.h"
#include "TicTacToeCode/ttt.h"
#include <curses.h>
#include <string>
#include "common/Location.h"
class GameSelector
{
public:
	Location menuPos;
	std::string gameList[5] = {"Hangman","TicTacToe","Wordle","Connect4","Exit"};
	enum gameList {Hangman,TicTacToe,Wordle,Connect4,Exit};
	GameSelector();
	bool updateSelector(int game);
	int select();
	int start(int game);
};

