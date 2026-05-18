/*
 * Shot.cpp
 *
 *  Created on: 09-Dec-2021
 *      Author: Ananya
 */


#include "Shot.h"

Shot::Shot(GridPosition targetPos)
{
	this->targetPosition = targetPos;
}

Shot::Shot()
{

}

GridPosition Shot::getTargetPosition()const
{
	return this->targetPosition;
}


