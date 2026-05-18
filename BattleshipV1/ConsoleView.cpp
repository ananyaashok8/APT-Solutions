/*
 * ConsoleView.cpp
 *
 *  Created on: 07-Dec-2021
 *      Author: Ananya
 */

#include "ConsoleView.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>


ConsoleView::~ConsoleView(){
	delete []ownGrid;
	delete []oppGrid;
}

ConsoleView::ConsoleView(Board *board)
{
	this->board = board;
	this->rows = board->getRows();
	this->cols = board->getColumns();

	//Allocating memory for OwnGrid
	ownGrid = new char*[rows];
	for(unsigned short r=0; r<rows; ++r){
		ownGrid[r] = new char[cols];
	}

	//Allocating memory for OpponentGrid
	oppGrid = new char*[rows];
	for(unsigned short r=0; r<rows; ++r){
		oppGrid[r] = new char[cols];
	}

	//Initializing OwnGrid
	initializeGrid(ownGrid);

	//Initializing OpponentGrid
	initializeGrid(oppGrid);
}

void ConsoleView::print()
{
	//Updating the board with ships and player moves.
	setShips(ownGrid);
	setShots(ownGrid);

	//Print method implementation
	cout << endl << "            OWN GRID           " << endl;
	cout << "                               1" << endl;
	cout << "    1  2  3  4  5  6  7  8  9  0" << endl;
	for(unsigned short rowIndex=0; rowIndex<rows; ++rowIndex){
		cout << " " << (char)(rowIndex+ASCIIVALUE);
		for(unsigned short colIndex=0; colIndex<cols; ++colIndex){
			cout << "  " << ownGrid[rowIndex][colIndex];
		}
		cout << endl;
	}

	cout << endl << "            OPP GRID            " << endl;
	cout << "                               1" << endl;
	cout << "    1  2  3  4  5  6  7  8  9  0" << endl;
	for(unsigned short rowIndex=0; rowIndex<rows; ++rowIndex){
		cout << " " << (char)(rowIndex+ASCIIVALUE);
		for(unsigned short colIndex=0; colIndex<cols; ++colIndex){
			cout << "  " << oppGrid[rowIndex][colIndex];
		}
		cout << endl;
	}

}


void ConsoleView::initializeGrid(char **grid)
{
	for(unsigned short rowIndex=0; rowIndex<rows; ++rowIndex){
		for(unsigned short colIndex=0; colIndex<cols; ++colIndex){
			grid[rowIndex][colIndex] = '~';
		}
	}
}


void ConsoleView::setShips(char **grid) const
{
	vector<Ship> v1 = board->getOwnGrid().getShips();
	auto iter = v1.begin();

	//Iterate through the ships vector and update the ships' positions individually
	while(iter!=v1.end()){
		const set<GridPosition> shipSet = (*iter).occupiedArea();

		for(auto itr = shipSet.begin(); itr!=shipSet.end(); ++itr){
			unsigned short rowBow = itr->getRow() - ASCIIVALUE;
			unsigned short colBow = itr->getColumn() - 1;

			ownGrid[rowBow][colBow] = '#';
		}
		++iter;
		cout << endl;
	}
}


void ConsoleView::setShots(char **grid) const
{
	vector<Ship> ships = board->getOwnGrid().getShips();
	set<GridPosition> shotAt = board->getOwnGrid().getShotAt();
	set<GridPosition> temp;

	//For updating the HITS made
	for(auto iter:shotAt){
		if(ownGrid[iter.getRow()-ASCIIVALUE][iter.getColumn()-1] == '#'){
			ownGrid[iter.getRow()-ASCIIVALUE][iter.getColumn()-1] = 'O';
		}
		else if(ownGrid[iter.getRow()-ASCIIVALUE][iter.getColumn()-1] == '~'){
			ownGrid[iter.getRow()-ASCIIVALUE][iter.getColumn()-1] = '^';
		}
	}

	//For updating Opponent Grid
	map<GridPosition, Shot::Impact> myMap = board->getOpponentGrid().getShotsAt();
	for(auto it=myMap.begin(); it!=myMap.end(); ++it){
		GridPosition pos = it->first;
		Shot::Impact value = it->second;
		string str = (string)pos;
		unsigned short row = pos.getRow()-ASCIIVALUE;
		unsigned short col = pos.getColumn()-1;

		switch(value){
		case Shot::NONE:	oppGrid[row][col] = '^';
		break;
		case Shot::HIT: 	oppGrid[row][col] = 'O';
		break;
		case Shot::SUNKEN:	oppGrid[row][col] = '#';
		break;
		}

	}
}
