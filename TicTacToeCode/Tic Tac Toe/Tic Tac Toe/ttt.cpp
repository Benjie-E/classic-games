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
	Board ttt;
	int player = 0;
	bool gameWon = false, moveMade = false;
	char pMove;
	initscr();

	ttt.printBoard();
	refresh();

	do
	{
		//players move
		while(moveMade == false)
		{
			ttt.printBoard();
			pMove = ttt.getMove(player);
			moveMade = ttt.setChar(pMove, player);
			if (moveMade == false)
			{
				move(8, 5);
				printw("Invald Move! Please enter a valid move.");
				refresh();
				getch();
				clear();
			}
		}

		//checking results of player move
		moveMade = false;
		gameWon = ttt.finishedCheck();
		player++;
		player = player % 2;
	} while (gameWon == false);

	//congrats to win and exits program
	clear();
	ttt.printBoard();
	move(8, 5);
	printw("Congratulations Player ");
	if (player == 1)
		printw("1");
	else
		printw("2");
	printw("! You have won!");

	refresh;
	getch();
	endwin();

	return 0;
}