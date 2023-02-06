#include "DisplayManager.h"

using namespace std;

void DisplayManager::showBoard(const GameManager& game)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << game.gameBoard[i][j] << "  ";
		}
		cout << endl;
	}
}

int DisplayManager::getDecision()
{
	int column = 0;
	cout << "\nWhich column would you like to place your piece in? (1-7) ";
	cin >> column;

	return column - 1; // adjust for zero-indexed array
}