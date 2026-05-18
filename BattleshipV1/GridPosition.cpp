/*
 * GridPosition.cpp
 *
 *  Created on: 07-Dec-2021
 *      Author: Ananya
 */
#include <iostream>
#include <stdlib.h>

#include "GridPosition.h"

using namespace std;


GridPosition::GridPosition()
{
	row ='A';
	column = 0;
}

GridPosition::~GridPosition()
{

}

GridPosition::GridPosition(char rowVal, int columnVal)
{
	row = rowVal;
	column = columnVal;
}

GridPosition::GridPosition(std::string position)
{
	//implementation to split the string input into row and column.
	string rowVal, columnVal;
	rowVal = position.at(0);
	columnVal = position.substr(1,2);
	row = rowVal[0];
	column = stoi(columnVal);
}

bool GridPosition::isValid()
{
	if((isalpha(row)) && (column > 0)){
		return true;
	}
	else{
		return false;
	}
}

char GridPosition::getRow()const
{
	return row;
}

int GridPosition::getColumn()const
{
	return column;
}

GridPosition::operator std::string() const
{
	string concatenatedValue = row + to_string(this->column);
	return concatenatedValue;
}


bool GridPosition::operator ==(GridPosition gridPosition)const
{
	if(this->row == gridPosition.row)
	{
		if(this->column == gridPosition.column)
		{
			return true;
		}
		return false;
	}

	return false;
}


bool GridPosition::operator <(GridPosition gridPosition)const
{
	if((this->row < gridPosition.row) || (this->column < gridPosition.column)){
		return true;
	}
	return false;
}

GridPosition::GridPosition(const GridPosition &pos)
{
	this->row = pos.row;
	this->column = pos.column;
}
