/*
 * OpponentGrid.h
 *
 *  Created on: 07-Dec-2021
 *      Author: Ananya
 */
#include <map>
#include <vector>
#include "Ship.h"
#include "Shot.h"

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

/**
 * The board that keeps track of opponent's moves.
 */
class OpponentGrid{
	int rows;
	int columns;

	/**
	 * Stores the shots made by the opponent and the
	 * Impact of those shots.
	 * key - GridPosition
	 * value - Shot::Impact (NONE or HIT or SUNKEN)
	 */
	map<GridPosition, Shot::Impact> shots;

	/**
	 * Sunken ships Vector for opponent player.
	 */
	vector<Ship> sunkenShips;

public:
	/**
	 * Parameterized Constructor
	 * Initializes the new instance of an Opponent Grid
	 * @param rows - int
	 * @param columns - int
	 */
	OpponentGrid(int rows, int columns);

	/**
	 * Getter method for returning the rows of the grid.
	 * @return int
	 */
	int getRows();

	/**
	 * Getter method for returning the columns of the grid.
	 * @return int
	 */
	int getColumns();

	/**
	 * Represents the impact on opponent player's board after a shot.
	 * @param shot - const Shot& (reference of shot made)
	 * @param Impact - Shot::Impact (Impact got as a result of the shot)
	 */
	void shotResult(const Shot& shot, Shot::Impact Impact);

	/**
	 * Represents all the moves made by the player,
	 * collectively of HIT, MISS and SUNKEN.
	 * @return Returns the map containing the shots, positions and the Impact
	 */
	const map<GridPosition, Shot::Impact>& getShotsAt();
};



#endif /* OPPONENTGRID_H_ */
