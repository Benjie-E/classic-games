/*
Author: Ben Tangora
Class : CSI - 281 - 01

Description:
	Tic Tac Toe coded in C++ and using the console as a display/input device
*/

#include "ttt_functions.h"
#include <curses.h>

using namespace std;

int main()
{
	TTTManager ttt;
	int vicCon;
	bool gameWon = false, moveMade = false, goAgain = false;
	char pMove;

	//Initializing various variables for PDCurses
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);

	do
	{
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
					move(9, 5);
					printw("Invald Move! Please enter a valid move.");
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
		//congrats to win and checks if they want to exit the program
		ttt.printVictory();

		goAgain = ttt.goAgain();
		if (goAgain == true)
			ttt.boardReset();

	} while (goAgain == true);

	endwin();
	return 0;
}