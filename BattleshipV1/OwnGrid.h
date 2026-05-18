/*
 * OwnGrid.h
 *
 *  Created on: 07-Dec-2021
 *      Author: Ananya
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include "Ship.h"
#include "Shot.h"



/**
 * The board that keeps track of player's moves.
 */
class OwnGrid{
	int rows;
	int columns;

	/**
	 * Contains ships coordinates.
	 */
	vector<Ship> ships;

	/**
	 * Map to store the count of the ships that can
	 * be placed by any player on his grid.
	 */
	map<int,int> shipType;

	/**
	 * Stores the Grid Positions of all the opponent player hits.
	 */
	set<GridPosition> shotAt;

public:

	/**
	 * Initializes the new instance of ownGrid.
	 * @param rows - Rows
	 * @param columns - columns of the grid
	 */
	OwnGrid(int rows, int columns);

	/**
	 * Getter method for number of rows.
	 * @return int
	 */
	int getRows();

	/**
	 * Getter method for number of columns.
	 * @return int
	 */
	int getColumns();

	/**
	 * Places the ships in the own grid.
	 * @param ship - const Ship& (reference to a ship object)
	 * @return bool value
	 */
	bool placeShip(const Ship& ship);

	/**
	 * Getter for all the ships placed present on the grid.
	 * @return const vector< Ship >
	 */
	const std::vector <Ship> getShips()const;

	/**
	 * To get the move made by the opponent.
	 * @param shot - const Shot& (reference to a Shot object)
	 * @return Shot::Impact - Impact due to the shot made
	 */
	Shot::Impact takeBlow(const Shot& shot);

	/**
	 * Returns all the opponent moves.
	 * @return const set< GridPosition > - Set of Grid positions where shots were made.
	 */
	const set<GridPosition> getShotAt();
};



#endif /* OWNGRID_H_ */
