/*
 * Board.h
 *
 *  Created on: 07-Dec-2021
 *      Author: Ananya
 */
#include "OwnGrid.h"
#include "OpponentGrid.h"

#ifndef BOARD_H_
#define BOARD_H_

/**
 * Contains the game board.
 * Contains both own grid and opponent grid.
 */
class Board{
	OwnGrid ownGrid;
	OpponentGrid opponentGrid;

public:
	/**
	 * Initializes the board instance.
	 * Takes row and column as inputs.
	 * @param rows - int
	 * @param columns - int
	 */
	Board(int rows, int columns);

	/**
	 * Getter function for number of rows.
	 * @return integer value
	 */
	int getRows();

	/**
	 * Getter function for number of columns.
	 * @return integer value
	 */
	int getColumns();

	/**
	 * Getter function for an object of type Own grid
	 * @return - OwnGrid reference
	 */
	OwnGrid& getOwnGrid();

	/**
	 * Getter function for an object of type Opponent grid
	 * @return - OpponentGrid reference
	 */
	OpponentGrid& getOpponentGrid();
};



#endif /* BOARD_H_ */
