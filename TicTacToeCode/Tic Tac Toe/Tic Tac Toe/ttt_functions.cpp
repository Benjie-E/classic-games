/*
Author: Ben Tangora
Class : CSI - 281 - 01

Description:
	Tic Tac Toe coded in C++ and using the console as a display/input device
*/

#include "ttt_functions.h"

using namespace std;

/*      Pre:  Players knows position they want to place their piece
 *     Post:  Piece has been placed or user has been informed of error
 *  Purpose:  To place a players piece on the board
 *********************************************************************/
bool Board::setChar(char tile, int player)
{
	int tileNum = int(tile) - 48;

	if (tiles[tileNum] == tile)
	{
		tiles[tileNum] = PLAYER[player];
		charPlaced[tileNum] = true;
		return true;
	}
	else
	{
		return false;
	}
}

/*      Pre:  Players has placed their pieces and victory condition is unknown
 *     Post:  victory status is known (victory, tie, or ongoing)
 *  Purpose:  return the game status to the program
 *********************************************************************/
int Board::getWinStatus()
{
	int winStatus;

		//Checks if one of the players wins
	if (tiles[1] == tiles[2] && tiles[2] == tiles[3] || tiles[4] == tiles[5] && tiles[5] == tiles[6] ||
		tiles[7] == tiles[8] && tiles[8] == tiles[9] || tiles[1] == tiles[4] && tiles[4] == tiles[7] ||
		tiles[2] == tiles[5] && tiles[5] == tiles[8] || tiles[3] == tiles[6] && tiles[6] == tiles[9] ||
		tiles[1] == tiles[5] && tiles[5] == tiles[9] || tiles[3] == tiles[5] && tiles[5] == tiles[7])
	{
		winStatus = 1;
	}
	// checks if no one can win (board is fully placed) 
	else if (charPlaced[0] == true && charPlaced[1] == true && charPlaced[2] == true && charPlaced[3] == true &&
		charPlaced[4] == true && charPlaced[5] == true && charPlaced[6] == true && charPlaced[7] == true &&
		charPlaced[8] == true && charPlaced[9] == true)
	{
		winStatus = 2;
	}
	else //game is still going or the conditions above are not met
	{
		winStatus = 3;
	}

	return winStatus;
}

/*      Pre:  Board has been updated and needs to be printed
 *     Post:  Board has been printed to the screen
 *  Purpose:  Show players the current game status
 *********************************************************************/
void Board::printBoard()
{
	cout << "\t " << tiles[1] << " | " << tiles[2] << " | " << tiles[3] << endl;
	cout << "\t----------" << endl;
	cout << "\t " << tiles[4] << " | " << tiles[5] << " | " << tiles[6] << endl;
	cout << "\t----------" << endl;
	cout << "\t " << tiles[7] << " | " << tiles[8] << " | " << tiles[9] << endl;
	cout << endl;
}

/*      Pre:  Player needs to enter where to try and place their piece
 *     Post:  Player has entered a possible location to place their piece
 *  Purpose:  get the location that the player wants to put their piece
 *********************************************************************/
char Board::getMove(int playerNum)
{
	char playerChoice;

	cout << "\n\tWhere would you like to place your " << PLAYER[playerNum] << "? : ";

	cin >> playerChoice;

	return playerChoice;
}

/*      Pre:  Has the game been completed
 *     Post:  game has either been completed or not
 *  Purpose:  To see if the game is over or not
 *********************************************************************/
bool Board::finishedCheck()
{
	int winStatus = getWinStatus();

	if (winStatus == 1)
	{
		return true;
	}

	if (winStatus == 2)
	{
		return true;
	}
	
	if (winStatus == 3)
	{
		return false;
	}
}