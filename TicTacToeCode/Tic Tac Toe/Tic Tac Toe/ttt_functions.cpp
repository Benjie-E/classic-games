/*
Author: Ben Tangora
Class : CSI - 281 - 01

Description:
	Tic Tac Toe coded in C++ and using the console as a display/input device
*/

#include "ttt_functions.h"
#include <curses.h>

using namespace std;

/*      Pre:  Players knows position they want to place their piece
 *     Post:  Piece has been placed or user has been informed of error
 *  Purpose:  To place a players piece on the board
 *********************************************************************/
bool TTTManager::setChar(char tile)
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
int TTTManager::getWinStatus()
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

/*      Pre:  Update board to current game state
 *     Post:  Board has updated and is ready to print
 *  Purpose:  Show players the current game status
 *********************************************************************/
void TTTManager::updateBoard()
{
	move(0, 5);
	printw("Tic-Tac-Toe in C++");
	WINDOW* gameWindow = newwin(7, 13, 1, 7);
	refresh();

	box(gameWindow, 0, 0);

	wmove(gameWindow, 1, 1);
	wprintw(gameWindow, " ");

	if (tiles[1] == 'X')
		wattron(gameWindow, COLOR_PAIR(1));
	else if (tiles[1] == 'O')
		wattron(gameWindow, COLOR_PAIR(2));
	waddch(gameWindow, tiles[1]);
	if (tiles[1] == 'X')
		wattroff(gameWindow, COLOR_PAIR(1));
	else if (tiles[1] == 'O')
		wattroff(gameWindow, COLOR_PAIR(2));

	wprintw(gameWindow, " | ");

	if (tiles[2] == 'X')
		wattron(gameWindow, COLOR_PAIR(1));
	else if (tiles[2] == 'O')
		wattron(gameWindow, COLOR_PAIR(2));
	waddch(gameWindow, tiles[2]);
	if (tiles[2] == 'X')
		wattroff(gameWindow, COLOR_PAIR(1));
	else if (tiles[2] == 'O')
		wattroff(gameWindow, COLOR_PAIR(2));

	wprintw(gameWindow, " | ");

	if (tiles[3] == 'X')
		wattron(gameWindow, COLOR_PAIR(1));
	else if (tiles[3] == 'O')
		wattron(gameWindow, COLOR_PAIR(2));
	waddch(gameWindow, tiles[3]);
	if (tiles[3] == 'X')
		wattroff(gameWindow, COLOR_PAIR(1));
	else if (tiles[3] == 'O')
		wattroff(gameWindow, COLOR_PAIR(2));

	wmove(gameWindow, 2, 1);
	wprintw(gameWindow,"-----------");
	wmove(gameWindow, 3, 1);
	wprintw(gameWindow, " ");

	if (tiles[4] == 'X')
		wattron(gameWindow, COLOR_PAIR(1));
	else if (tiles[4] == 'O')
		wattron(gameWindow, COLOR_PAIR(2));
	waddch(gameWindow, tiles[4]);
	if (tiles[4] == 'X')
		wattroff(gameWindow, COLOR_PAIR(1));
	else if (tiles[4] == 'O')
		wattroff(gameWindow, COLOR_PAIR(2));

	wprintw(gameWindow, " | ");

	if (tiles[5] == 'X')
		wattron(gameWindow, COLOR_PAIR(1));
	else if (tiles[5] == 'O')
		wattron(gameWindow, COLOR_PAIR(2));
	waddch(gameWindow, tiles[5]);
	if (tiles[5] == 'X')
		wattroff(gameWindow, COLOR_PAIR(1));
	else if (tiles[5] == 'O')
		wattroff(gameWindow, COLOR_PAIR(2));

	wprintw(gameWindow, " | ");

	if (tiles[6] == 'X')
		wattron(gameWindow, COLOR_PAIR(1));
	else if (tiles[6] == 'O')
		wattron(gameWindow, COLOR_PAIR(2));
	waddch(gameWindow, tiles[6]);
	if (tiles[6] == 'X')
		wattroff(gameWindow, COLOR_PAIR(1));
	else if (tiles[6] == 'O')
		wattroff(gameWindow, COLOR_PAIR(2));

	wmove(gameWindow, 4, 1);
	wprintw(gameWindow, "-----------");
	wmove(gameWindow, 5, 1);
	wprintw(gameWindow, " ");

	if (tiles[7] == 'X')
		wattron(gameWindow, COLOR_PAIR(1));
	else if (tiles[7] == 'O')
		wattron(gameWindow, COLOR_PAIR(2));
	waddch(gameWindow, tiles[7]);
	if (tiles[7] == 'X')
		wattroff(gameWindow, COLOR_PAIR(1));
	else if (tiles[7] == 'O')
		wattroff(gameWindow, COLOR_PAIR(2));

	wprintw(gameWindow, " | ");

	if (tiles[8] == 'X')
		wattron(gameWindow, COLOR_PAIR(1));
	else if (tiles[8] == 'O')
		wattron(gameWindow, COLOR_PAIR(2));
	waddch(gameWindow, tiles[8]);
	if (tiles[8] == 'X')
		wattroff(gameWindow, COLOR_PAIR(1));
	else if (tiles[8] == 'O')
		wattroff(gameWindow, COLOR_PAIR(2));

	wprintw(gameWindow, " | ");

	if (tiles[9] == 'X')
		wattron(gameWindow, COLOR_PAIR(1));
	else if (tiles[9] == 'O')
		wattron(gameWindow, COLOR_PAIR(2));
	waddch(gameWindow, tiles[9]);
	if (tiles[9] == 'X')
		wattroff(gameWindow, COLOR_PAIR(1));
	else if (tiles[9] == 'O')
		wattroff(gameWindow, COLOR_PAIR(2));

	wrefresh(gameWindow);
}

/*      Pre:  Player needs to enter where to try and place their piece
 *     Post:  Player has entered a possible location to place their piece
 *  Purpose:  get the location that the player wants to put their piece
 *********************************************************************/
char TTTManager::getMove()
{
	char playerChoice;
	
	move(9, 5);
	printw("Place your ");
	addch(PLAYER[player]);
	printw(" in square: ");

	refresh();
	cin >> playerChoice;
	return playerChoice;
}

/*      Pre:  Has the game been completed
 *     Post:  game has either been completed or not
 *  Purpose:  To see if the game is over or not
 *********************************************************************/
bool TTTManager::finishedCheck()
{
	int winStatus = getWinStatus();

	if (winStatus == 1)
	{
		return true;
	}

	else if (winStatus == 2)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

/*      Pre:  Has the game been completed
 *     Post:  game has either been completed or not
 *  Purpose:  To see if the game is over or not
 *********************************************************************/
void TTTManager::printVictory()
{
	clear();
	updateBoard();
	move(9, 5);
	int vicCon = getWinStatus();

	if (vicCon == 1)
	{
		printw("Congratulations Player ");
		if (player == 1)
			printw("1 (X's)");
		else if (player == 0)
			printw("2 (O's)");
		printw("! You have won!");
	}
	else
	{
		printw("Game has resulted in a tie.");
		move(10, 5);
		printw("Neither player wins!");
	}

	refresh;
	getch();
}

/*      Pre:  Game has been completed
 *     Post:  Program knows if the user wants to play again or not
 *  Purpose:  To either prep the program for exiting or restarting to game
 *********************************************************************/
bool TTTManager::goAgain()
{
	char anotherGame = 'P';
	while (anotherGame != 'Y' && anotherGame != 'N')
	{
		clear();
		move(2, 5);
		printw("Would you like to go again? (Y or N)");
		anotherGame = getch();
		anotherGame = toupper(anotherGame);
	}

	if (anotherGame == 'Y')
		return true;
	else
		return false;
}

/*      Pre:  Player wants to play again but old values are stored
 *     Post:  Old values had been reset to default
 *  Purpose:  To reset the board and get the program ready for the next game
 *********************************************************************/
void TTTManager::boardReset()
{
	for (int i = 1; i <= 9; i++)
	{
		tiles[i] = char(i + 48);
		charPlaced[i] = false;
	}

	player = 0;
}