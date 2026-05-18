/*
 * Board.cpp
 *
 *  Created on: 07-Dec-2021
 *      Author: Ananya
 */

#include "Board.h"

Board::Board(int rows, int columns):ownGrid(rows, columns), opponentGrid(rows, columns)
{

}

int Board::getRows()
{
	return this->ownGrid.getRows();
}

int Board::getColumns()
{
	return this->ownGrid.getColumns();
}

OwnGrid& Board::getOwnGrid()
{
	return this->ownGrid;
}

OpponentGrid& Board::getOpponentGrid()
{
	return this->opponentGrid;
}

