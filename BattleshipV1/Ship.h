/*
 * Ship.h
 *
 *  Created on: 07-Dec-2021
 *      Author: Ananya
 */
#include "GridPosition.h"
using namespace std;
#include <set>
#include <stdlib.h>

#ifndef SHIP_H_
#define SHIP_H_


/**
 * Represents the properties of Ship like Bow and Stern. *
 * BOW - starting position of the ship.
 * STERN - end position of the ship.
 */
class Ship
{
	GridPosition bow;
	GridPosition stern;

public:
	/**
	 * Initializes the new instance of the ship.
	 * @param bow - const GridPosition& [object reference(bow)]
	 * @param stern - const GridPosition& [object reference(stern)]
	 */
	Ship(const GridPosition& bow, const GridPosition& stern);

	/**
	 * Default constructor
	 */
	Ship();

	/**
	 * Destructor method
	 */
	~Ship();

	/**
	 * Checks if the entered ship position is valid.
	 * @return bool value
	 */
	bool isValid();

	/**
	 * Getter method for returning bow of the ship.
	 * @return GridPosition of the bow
	 */
	GridPosition getBow()const;

	/**
	 * Getter method for returning stern of the ship.
	 * @return GridPosition of the stern
	 */
	GridPosition getStern()const;

	/**
	 * Returns the length of the ship.
	 * @return int
	 */
	int length()const;

	/**
	 * Returns the area occupied by the ship object.
	 * @return const set<GridPosition>
	 */
	const std::set<GridPosition> occupiedArea()const;

	/**
	 * Returns the blocked area around the ship.
	 * @return const set<GridPosition>
	 */
	const std::set<GridPosition> blockedArea()const;
};

#endif /* SHIP_H_ */
