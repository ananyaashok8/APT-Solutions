/*
 * Ship.cpp
 *
 *  Created on: 07-Dec-2021
 *      Author: Ananya
 */

#include "Ship.h"

Ship::Ship()
{
	// TODO Auto-generated constructor stub

}

Ship::~Ship()
{
	// TODO Auto-generated destructor stub
}

Ship::Ship(const GridPosition &bow, const GridPosition &stern)
{
	this->bow = bow;
	this->stern = stern;
}

bool Ship::isValid()
{
	//Vertical direction validation
	if((bow.getRow() < stern.getRow()) || (stern.getRow() < bow.getRow())){
		if((bow.getColumn() == stern.getColumn())){
			if((this->length() <= 5) && (this->length() > 1)){
				return true;
			}
			return false;
		}
	}

	//Horizontal direction validation
	else if(((bow.getColumn() < stern.getColumn())) || (stern.getColumn() < bow.getColumn())){
		if(bow.getRow() == stern.getRow()){
			if((this->length() <= 5) && (this->length() > 1)){
				return true;
			}
			return false;
		}
	}

	return false;
}

GridPosition Ship::getBow() const
{
	return bow;
}

GridPosition Ship::getStern()const
{
	return stern;
}

int Ship::length()const
{
	if(bow.getColumn() == stern.getColumn()){
		if(stern.getRow() < bow.getRow()){
			return(bow.getRow() - stern.getRow() + 1);
		}
		else{
			return (stern.getRow() - bow.getRow() + 1);
		}
	}

	else if(bow.getRow() == stern.getRow()){
		if(bow.getColumn() > stern.getColumn()){
			return (bow.getColumn() - stern.getColumn() + 1);
		}
		else{
			return (stern.getColumn() - bow.getColumn() + 1);
		}
	}

	return 0;
}

const set<GridPosition> Ship::occupiedArea() const
{
	set<GridPosition> areaOccupied;

	char row = 'A';
	int col = 0;
	unsigned short shipLen = this->length();
	if (bow.getRow() == stern.getRow())
	{
		col = bow.getColumn();
		if(bow.getColumn() < stern.getColumn()){
			for (unsigned short rowIndex = 0; rowIndex < shipLen; rowIndex++){
				GridPosition currentPosition(bow.getRow(), col);
				areaOccupied.insert((string) currentPosition);
				col++;
			}
		}
		else{
			for (unsigned short rowIndex = 0; rowIndex < shipLen; rowIndex++){
				GridPosition currentPosition(bow.getRow(), col);
				areaOccupied.insert((string) currentPosition);
				col--;
			}
		}
	}
	else if (bow.getColumn() == stern.getColumn())
	{
		row = bow.getRow();
		if(bow.getRow() < stern.getRow()){
			for (unsigned short colIndex = 0; colIndex < shipLen; colIndex++){
				GridPosition currentPosition(row, bow.getColumn());
				areaOccupied.insert((string) currentPosition);
				row++;
			}
		}
		else{
			for (unsigned short colIndex = 0; colIndex < shipLen; colIndex++){
				GridPosition currentPosition(row, bow.getColumn());
				areaOccupied.insert((string) currentPosition);
				row--;
			}
		}
	}
	return areaOccupied;
}

const std::set<GridPosition> Ship::blockedArea() const
{
	set<GridPosition> blkArea;
	set<GridPosition>::iterator index;

	//Check for surrounding area to avoid the overlap of ships.
	for(auto index:occupiedArea()){
		for(short row=-1; row<=1; ++row){
			for(short col=-1; col<=1; ++col){
				GridPosition pos(index.getRow()+row, index.getColumn()+col);
				if(pos.isValid()){
					blkArea.insert(pos);
				}
			}
		}
	}

	return blkArea;
}
