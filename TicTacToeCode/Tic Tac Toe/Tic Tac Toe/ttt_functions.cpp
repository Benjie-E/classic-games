#include "ttt_functions.h"

using namespace std;

bool Board::setChar(char tile, int player)
{
	int tileNum = int(tile);
	cout << tileNum << endl;

	if (tiles[tileNum] == tile)
	{
		tiles[tileNum] = PLAYER[player];
		return true;
	}
	else
	{
		return false;
	}
}

int Board::winCheck()
{
	int winStatus;

	return winStatus;
}

void Board::printBoard()
{

}

char getMove()
{
	char playerChoice;

	return playerChoice;
}