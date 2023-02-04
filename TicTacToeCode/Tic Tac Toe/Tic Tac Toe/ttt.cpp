/*
Author: Ben Tangora
Class : CSI - 281 - 01

Description:
	Tic Tac Toe coded in C++ and using the console as a display/input device
*/

#include "ttt_functions.h"

using namespace std;

int main()
{
	Board ttt;
	int player = 0;
	bool gameWon = false, moveMade = false;
	char pMove;

	ttt.printBoard();

	do
	{
		//players move
		while(moveMade == false)
		{
			pMove = ttt.getMove(player);
			moveMade = ttt.setChar(pMove, player);
			ttt.printBoard();
			if (moveMade == false)
			{
				cout << "\tInvald Move! Please enter a valid move." << endl;
			}
			system("cls");
			ttt.printBoard();
		}

		//checking results of player move
		moveMade = false;
		gameWon = ttt.finishedCheck();
		player++;
		player = player % 2;
	} while (gameWon == false);

	//congrats to win and exits program
	cout << "\tCongratulations Player " << player << "! You have won!" << endl;
	return 0;
}