/*
 * OpponentGrid.cpp
 *
 *  Created on: 07-Dec-2021
 *      Author: Ananya
 */
#include <sstream>
#include <vector>
#include "OpponentGrid.h"
#include "Ship.h"
#include "GridPosition.h"

OpponentGrid::OpponentGrid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
}

int OpponentGrid::getRows()
{
	return rows;
}

int OpponentGrid::getColumns()
{
	return columns;
}

void OpponentGrid::shotResult(const Shot &shot, Shot::Impact Impact)
{
	pair<map<GridPosition, Shot::Impact>::iterator, bool> pairValue;
	pairValue = shots.insert(pair<GridPosition, Shot::Impact>(shot.getTargetPosition(), Impact));

	//If the Blow is SUNKEN then update the rest HITS to SUNKEN
	if(Impact == Shot::SUNKEN){
		map<GridPosition, Shot::Impact>::iterator iter1 = pairValue.first;
		GridPosition bow = iter1->first;
		GridPosition stern = iter1->first;

		// west or north directional check
		for(auto itr=shots.rbegin(); itr!=shots.rend(); ++itr){
			GridPosition temp = itr->first;
			//Check for ships arranged Vertically
			if(bow.getRow() == temp.getRow()){
				if((bow.getColumn() - temp.getColumn()) == 1){
					bow = temp;
					itr->second = Shot::SUNKEN;
				}
			}

			//Check for ships arranged vertically
			else if(bow.getColumn() == temp.getColumn()){
				if((bow.getRow() - temp.getRow()) == 1){
					bow = temp;
					itr->second = Shot::SUNKEN;
				}
			}
		}

		map<GridPosition, Shot::Impact>::iterator iter2 = pairValue.first;


		// east or south directional check
		for(auto itr=iter2; itr!=shots.end(); ++itr){
			GridPosition test = itr->first;
			//Check for ships arranged horizontally
			if(stern.getRow() == test.getRow()){
				if((test.getColumn() - stern.getColumn()) == 1){
					stern = test;
					itr->second = Shot::SUNKEN;
				}
			}

			//Validation for horizontally placed ships
			else if(stern.getColumn() == test.getColumn()){
				if((test.getRow() - stern.getRow()) == 1){
					stern = test;
					itr->second = Shot::SUNKEN;
				}
			}

			else{
				break;
			}
		}

		//Push the sunken ships finally to the vector
		sunkenShips.push_back(Ship{bow, stern});
	}
}

const map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt()
{
	return shots;
}
