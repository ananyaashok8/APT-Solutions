/*
 * GridPosition.cpp
 *
 *  Created on: 07-Dec-2021
 *      Author: Ananya
*/
#include <iostream>
#include <stdlib.h>

using namespace std;

#include <set>
#include "Board.h"
#include "ConsoleView.h"
/*
* Outputs the failedMessage on the console if condition is false.
*
* @param condition the condition
* @param failedMessage the message
*/

void assertTrue(bool condition, string failedMessage);

void part2tests(){
	Board myBoard(10, 10);

	//Test for placing ships
	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"B2"},GridPosition{"B5"}}),
			"Cannot place ship B2-B5");//Length = 4
	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"D4"},GridPosition{"G4"}}),
			"Cannot place ship D4-G4");//Length = 5
	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"F6"},GridPosition{"F7"}}),
			"Cannot place ship F6-F7");//Length = 2

	//Test for illegal positions of the ships
	assertTrue(!myBoard.getOwnGrid().placeShip(Ship{GridPosition{"B7"},GridPosition{"D9"}}),
			"Can place ship diagonally B7-D9");//Length = 3

	//Test for illegal lengths of the ships
	assertTrue(!myBoard.getOwnGrid().placeShip(Ship{GridPosition{"G1"},GridPosition{"G1"}}),
			"Can place ship of length 1");//Length = 1
	assertTrue(!myBoard.getOwnGrid().placeShip(Ship{GridPosition{"A1"},GridPosition{"A6"}}),
			"Can place ship of length 6");//Length = 6

	//Tests for proper placement of ships
	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"E6"},GridPosition{"G6"}}),
			"Cannot place ship E6-G6");//Length = 3
	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"F8"},GridPosition{"G8"}}),
			"Cannot place ship F8-G8");//Length = 2

	//Tests for blocked area
	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"H6"},GridPosition{"H7"}}),
				"Can place ship H6-H7");//Length = 2 //BA
	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"H10"},GridPosition{"I10"}}),
				"Can place ship H10-I10");//Length = 2


	ConsoleView viewBoard(&myBoard);
	viewBoard.print();
}


