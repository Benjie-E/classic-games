#include "GameManager.h"
#include "DisplayManager.h"

using namespace std;

int main()
{
	GameManager game;
	DisplayManager screen;

	while (true)
	{
		screen.showBoard(game);
		game.placePiece(screen.getDecision());
	}

	return 0;
}