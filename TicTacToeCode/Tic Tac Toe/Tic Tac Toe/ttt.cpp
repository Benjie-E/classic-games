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
	int player = 1;
	bool gameWon = false, moveMade = false;
	char pMove;

	do
	{
		do
		{
			ttt.printBoard();
			pMove = ttt.getMove();
			moveMade = ttt.setChar(pMove, player);
			if (moveMade == false)
			{
				cout << "Invald Move! Please enter a valid move." << endl;
			}
		} while (moveMade = false);

		moveMade = false;
		gameWon = ttt.winCheck();
	} while (gameWon == false);

	cout << "Congratulations Player " << player << "! You have won!" << endl;
	return 0;
}