#include "DisplayManager.h"

using namespace std;

DisplayManager::DisplayManager()
{
	mCursorRow = 0;
	mCursorCol = 0;
}


void DisplayManager::setConsoleSize(int dif)
{
	//These are just guess values, and will need to be tweaked later.
	if (dif == EASY)
	{
		resize_term(22, 38);
	}
	else if (dif == HARD)
	{
		resize_term(48, 90);
	}
	//Medium is the default state
	else
	{
		resize_term(36, 66);
	}

}


void DisplayManager::displayStats(int difficulty, GameManager& game)
{
	//Function to set everything up to be displayed in the window
	//I am 100% sure there is a better way to do this but it is nearly 1 am and my brain isn't working anymore.
	int titleY, difY;
	string total, flagged, dif;

	int difInt = game.getDifficulty();
	total = to_string(game.getTotalMines());
	flagged = to_string(game.getFlagged());

	if (difInt == EASY)
		dif = "Easy";
	else if (difInt == MEDIUM)
		dif = "Medium";
	else
		dif = "Hard";

	//Sets title and game stats starting location
	if (difficulty == EASY)
	{
		titleY = 12;
		difY = 1;
	}
	else if (difficulty == HARD)
	{
		titleY = 39;
		difY = 27;
	}
	else
	{
		titleY = 27;
		difY = 15;
	}

	//Displays game state of game
	if (game.getGameState() == 1)
	{
		move(0, titleY - 5);
		printw("YOU WON IN MINESWEEPER!");
	}
	else if (game.getGameState() == 2)
	{
		move(0, titleY - 6);
		printw("YOU LOST IN MINESWEEPER!");
	}
	else
	{
		move(0, titleY - 4);
		printw("PLAYING MINESWEEPER");
	}

	//Create window for game stats to be displayed in
	WINDOW* statDis = newwin(3, 36, 1, difY);
	box(statDis, 0, 0);
	wmove(statDis, 1, 1);

	string flags = "Flags: " + flagged + " / " + total;
	wprintw(statDis, flags.c_str());

	//Displays Difficulty
	string diffic = "Difficulty: " + dif;
	wmove(statDis, 1, 16);
	wprintw(statDis, diffic.c_str());

	wrefresh(statDis);
	refresh();
}


void DisplayManager::manageCursor()
{
	return;
}


int DisplayManager::getCursorRow()
{
	return mCursorRow;
}


int DisplayManager::getCursorCol()
{
	return mCursorCol;
}


void DisplayManager::setCursorRow(int row)
{
	mCursorRow = row;
}


void DisplayManager::setCursorCol(int col)
{
	mCursorCol = col;
}


void DisplayManager::updateScreen(GameManager &game)
{
	int difficulty = game.getDifficulty();
	displayStats(difficulty, game);
	move(4, 2);
	//Prints out the board.
	for (int i = 0; i < difficulty; i++)
	{
		for (int j = 0; j < difficulty; j++)
		{
			// If the game has been won or lost reveal all 
			if (game.getGameState() != 0)
			{
				if (game.gameBoard[i][j].hasMine == false && game.gameBoard[i][j].isFlagged == true)
					game.gameBoard[i][j].isFlagged == false;
				game.gameBoard[i][j].isRevealed = true;
			}
			game.gameBoard[i][j].printSquare();
			printw("  ");
		}
		printw("\n\n");
		move((i * 2) + 6, 2);
	}
	refresh();
}

bool DisplayManager::replay(GameManager game)
{
	// Basic menu for the player to input if they want to replay
	int choice = 0;
	int selected = 0;
	bool replay = false;
	int i = 0;
	string options[] = { "Replay", "Quit", "> Replay", "> Quit"};
	keypad(stdscr, true);

	while (true)
	{
		// clears screen and prints menu
		clear();
		for (i = 0; i <= 1; i++)
		{
			if (i == selected)
			{
				mvprintw(i + 1, 1, options[i + 2].c_str());
			}
			else
			{
				mvprintw(i + 1, 1, options[i].c_str());
			}
		}

		choice = getch();

		switch (choice) {
			case KEY_UP:
				selected = (selected + 1) % 2;
				break;
			case 119:
				selected = (selected + 1) % 2;
				break;
			case KEY_DOWN:
				selected = (selected + 1) % 2;
				break;
			case 115:
				selected = (selected + 1) % 2;
				break;
			case 10:
				if (selected == 0)
					replay = true;
				else
					replay = false;
				break;
			case 32:
				if (selected == 0)
					replay = true;
				else
					replay = false;
				break;
			default:
				break;
		}
		
		if (choice == 10 || choice == 32)
			break;
	}

	return replay;
}