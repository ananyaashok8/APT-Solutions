/*
 * OwnGrid.cpp
 *
 *  Created on: 07-Dec-2021
 *      Author: Ananya
 */
#include <iostream>
#include <algorithm>
using namespace std;
#include "OwnGrid.h"
#include "Ship.h"
#include "GridPosition.h"
#include "Shot.h"

OwnGrid::OwnGrid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	this->shipType[5] = 1;
	this->shipType[4] = 2;
	this->shipType[3] = 3;
	this->shipType[2] = 4;
}

int OwnGrid::getRows()
{
	return this->rows;
}

int OwnGrid::getColumns()
{
	return this->columns;
}

bool OwnGrid::placeShip(const Ship &ship)
{
	Ship tempShip;
	tempShip = ship;
	bool placeShipSuccess = false;
	set<GridPosition> outcome;
	set<GridPosition> ocpArea;
	set<GridPosition> blockArea;

	if(shipType[ship.length()]){

		if(tempShip.isValid()){
			ocpArea = ship.occupiedArea();

			for(auto shipIndex:ships){
				set<GridPosition> oldShips = shipIndex.blockedArea();
				//built-in library function to check if any ships are intersecting.
				std::set_intersection(ocpArea.begin(), ocpArea.end(),
						oldShips.begin(), oldShips.end(), std::inserter(outcome, outcome.begin()));
				if(!outcome.empty()){
					placeShipSuccess = false;
				}
			}
			//This ship has passed all validation and can be pushed to the vector.
			ships.push_back(ship);

			//Decrementing count in the map after placing
			shipType[ship.length()]--;

			placeShipSuccess = true;
		}
	}
	else{
		placeShipSuccess = false;
	}

	return placeShipSuccess;
}

const std::vector<Ship> OwnGrid::getShips()const
{
	return this->ships;
}

Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
	Shot currentMove;
	currentMove = shot;
	GridPosition placeMove = shot.getTargetPosition();
	set<GridPosition> tempGrid;

	//Iterate through vector of ships
	for(auto shipIndex:getShips()){
		//Calculate occupied area for each ship
		for(auto posIndex:shipIndex.occupiedArea()){
			//Check if ship's coordinate is same as the placeMove position
			if(currentMove.getTargetPosition() == posIndex){
				set_intersection(shotAt.begin(), shotAt.end(), shipIndex.occupiedArea().begin(),
						shipIndex.occupiedArea().end(), std::inserter(tempGrid, tempGrid.begin()));
				if((int)tempGrid.size() == (shipIndex.length()-1)){
					shotAt.insert(placeMove);
					return shot.SUNKEN;
				}
				else{
					shotAt.insert(placeMove);
					return shot.HIT;
				}
			}
		}
	}
	shotAt.insert(placeMove);
	return shot.NONE;
}

const set<GridPosition> OwnGrid::getShotAt()
{
	return shotAt;
}
