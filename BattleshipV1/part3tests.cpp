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

void part3tests(){
	Board myBoard(10, 10);

	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"B2"},GridPosition{"B5"}}),
			"Cannot place ship B2-B5");//Length = 4
	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"E4"},GridPosition{"I4"}}),
			"Cannot place ship E4-I4");//Length = 5
	assertTrue(!myBoard.getOwnGrid().placeShip(Ship{GridPosition{"B7"},GridPosition{"D9"}}),
			"Can place ship diagonally B7-D9");//Length = 3
	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"A10"},GridPosition{"D10"}}),
			"Can place another ship of length 5");//Length = 4
	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"E6"},GridPosition{"G6"}}),
			"Cannot place ship E6-G6");//Length = 3
	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"F8"},GridPosition{"G8"}}),
			"Cannot place ship F8-G8");//Length = 3

	ConsoleView viewBoard(&myBoard);
	viewBoard.print();

	//Tests to take blows on the own grid and keep track of it.
	assertTrue(myBoard.getOwnGrid().takeBlow(GridPosition{"A1"}) == Shot::NONE, "This blow is not a MISS");
	assertTrue(myBoard.getOwnGrid().takeBlow(GridPosition{"D4"}) == Shot::NONE, "This blow is not a MISS");
	assertTrue(myBoard.getOwnGrid().takeBlow(GridPosition{"F8"}) == Shot::HIT, "This blow is not a HIT");
	assertTrue(myBoard.getOwnGrid().takeBlow(GridPosition{"G8"}) == Shot::SUNKEN, "This blow is not a SUNKEN");
	assertTrue(myBoard.getOwnGrid().takeBlow(GridPosition{"C10"}) == Shot::HIT, "This blow is not a HIT");
	assertTrue(myBoard.getOwnGrid().takeBlow(GridPosition{"I4"}) == Shot::HIT, "This blow is not a HIT");

	//Blows made on the Opponent and tracked in the opponent grid.
	myBoard.getOpponentGrid().shotResult(GridPosition{"A1"},Shot::HIT);
	myBoard.getOpponentGrid().shotResult(GridPosition{"B5"},Shot::HIT);
	myBoard.getOpponentGrid().shotResult(GridPosition{"C5"},Shot::HIT);
	myBoard.getOpponentGrid().shotResult(GridPosition{"A5"},Shot::SUNKEN);
	myBoard.getOpponentGrid().shotResult(GridPosition{"D5"},Shot::NONE);


	viewBoard.print();
}


