/*
 * GridPosition.h
 *
 *  Created on: 07-Dec-2021
 *      Author: Ananya
 */
#include <iostream>
using namespace std;

#include <string>

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_
#define BOARDSIZE 10


/**
 * An immutable class. *
 * Represents game board in the form of a grid for player and opponent player.
 * Represented in terms of rows and columns.
 */
class GridPosition
{
	char row;
	int column;

public:
	/**
	 * Default constructor
	 */
	GridPosition();

	/**
	 * Destructor method.
	 */
	virtual ~GridPosition();

	/**
	 * Parameterized constructor to initialize new instances of grid
	 * in terms of rows and columns.
	 * @param row - char
	 * @param column - int
	 */
	GridPosition(char row, int column);

	/**
	 * Parameterized constructor to initialize new instances of grid
	 * in terms of string.
	 * @param position - string
	 */
	GridPosition( std::string position);

	/**
	 * Validation method for GridPosition.
	 * @return bool value
	 */
	bool isValid();

	/**
	 * Returns the row number of the GridPosition.
	 * @return char
	 */
	char getRow()const;

	/**
	 * Returns the column number of the GridPosition.
	 * @return int
	 */
	int getColumn()const;

	/**
	 * Method to concatenate row and column.
	 * String typecast overloading.
	 * Returns a string
	 */
	operator std::string() const;

	/**
	 * Copy constructor for assignment operator
	 * @param pos - const GridPosition& (const reference of GridPosition)
	 */
	GridPosition(const GridPosition& pos);

	/**
	 * Assignment (=)  operator overloading function.	 *
	 * const method - assures the compiler that the constant parameter will
	 * not be modified in this method.
	 * @param GridPosition
	 * @return GridPosition
	 */
	bool operator == (GridPosition)const;

	/**
	 * Less (<) than operator overloaded method.
	 * Used to maintain the set in a sorted manner.
	 * @param const GridPosition
	 * @return bool value
	 */
	bool operator < (const GridPosition)const;

};

#endif /* GRIDPOSITION_H_ */
