/*
 * Shot.h
 *
 *  Created on: 09-Dec-2021
 *      Author: Ananya
 */

#include "GridPosition.h"

#ifndef SHOT_H_
#define SHOT_H_


/**
 * Represents the moves made by any player.
 * Holds the Grid Position of the move made and the
 * types of Impact caused.
 */
class Shot
{
private:
	GridPosition targetPosition;

public:
	/**
	 * Enumeration of type of Impact.
	 * NONE or HIT or SUNKEN -> result of the player move.
	 */
	typedef enum shot{NONE, HIT, SUNKEN}Impact;

	/**
	 * Initializes the new instance of the Shot.
	 * @param targetPos - GridPosition
	 */
	Shot(GridPosition targetPos);

	/**
	 * Default constuctor
	 */
	Shot();

	/**
	 * Getter method for getting the target position for the move made.
	 * @return GridPosition
	 */
	GridPosition getTargetPosition()const;
};



#endif /* SHOT_H_ */
