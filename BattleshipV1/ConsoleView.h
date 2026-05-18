/*
 * ConsoleView.h
 *
 *  Created on: 07-Dec-2021
 *      Author: Ananya
 */

#include "Board.h"

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#define ASCIIVALUE 65

/**
 * Prints the player's board(Own grid and Opponent grid)
 * on the console.
 */
class ConsoleView{
	/**
	 * Pointer variable to store the board's address
	 */
	Board* board;
	unsigned short rows;
	unsigned short cols;

	/**
	 * Pointer to store the 2D-character array(Own grid)
	 */
	char **ownGrid;

	/**
	 * Pointer to store the 2D-character array(Opponent grid)
	 */
	char **oppGrid;

public:
	/**
	 * Initializes the new instance of a console view.
	 * @param board - Takes a board's address
	 */
	ConsoleView(Board* board);

	/**
	 * Copy constructor
	 * @param obj - reference to ConsoleView
	 */
	ConsoleView(ConsoleView& obj);

	/**
	 * Assignment operator overloaded method
	 * @param obj - reference to ConsoleView
	 */
	ConsoleView operator =(ConsoleView& obj);

	/**
	 * Destructor - deallocates the 2D-char array.
	 */
	~ConsoleView();

	/**
	 * Initializes the char arrays with '~'.
	 * @param grid - 2D-char array
	 */
	void initializeGrid(char** grid);

	/**
	 * Adds the ships to the grids.
	 * @param grid - 2D-char array
	 */
	void setShips(char** grid)const;

	/**
	 * Adds blows/shots made by the opponent.
	 * @param grid - 2D-char array
	 */
	void setShots(char** grid)const;

	/**
	 * Prints the board on the console.
	 */
	void print();
};



#endif /* CONSOLEVIEW_H_ */
