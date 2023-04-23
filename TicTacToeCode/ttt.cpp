/*
Author: Ben Tangora
Class : CSI - 281 - 01

Description:
	Tic Tac Toe coded in C++ and using the console as a display/input device
*/

#include "ttt_functions.h"
#include <curses.h>
#include "ttt.h"
using namespace std;

TTT::TTT()
{
	TTTManager ttt;
	int vicCon;
	bool gameWon = false, moveMade = false, goAgain = false;
	char pMove;

	//Initializing various variables for PDCurses
	initscr();
	start_color();
	curs_set(0);
	//Red text, black background
	init_pair(1, COLOR_RED, COLOR_BLACK);
	//Blue text, black background
	init_pair(2, COLOR_BLUE, COLOR_BLACK);

	do
	{
		//Clears the board and prints out the current state of the board
		clear();
		ttt.updateBoard();
		refresh();

		do
		{
			//players move
			while (moveMade == false)
			{
				ttt.updateBoard();
				pMove = ttt.getMove();
				moveMade = ttt.setChar(pMove);
				if (moveMade == false)
				{
					move(9, 3);
					printw("Invalid Move! Please enter a valid move.");
					refresh();
					getch();
					clear();
				}
			}

			//checking results of player move
			moveMade = false;
			gameWon = ttt.finishedCheck();
			ttt.player++;
			ttt.player = ttt.player % 2;
		} while (gameWon == false);


		//checks if how game ended and then displays the results
		//congrats to win and checks if they want to play again, otherwise exists the program
		ttt.printVictory();

		goAgain = ttt.goAgain();
		if (goAgain == true)
			ttt.boardReset();

	} while (goAgain == true);

	endwin();
	return;
}