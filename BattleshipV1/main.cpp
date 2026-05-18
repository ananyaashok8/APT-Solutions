// Standard (system) header files
#include <iostream>
#include <stdlib.h>

using namespace std;

#include <set>
#include "Board.h"
#include "ConsoleView.h"

void part1tests();
void part2tests();
void part3tests();

void assertTrue(bool condition, string failedMessage) {
	if (!condition) {
		cout << failedMessage << endl;
	}
}


// Main program
int main (void)
{
	cout << "Battleship Game Started!!";

	/*
	 * TEST1: Run the test cases respective to the exercise:1.
	 * To perform input validations.
	 */
	part1tests();

	/*
	 * TEST2: Run the test cases respective to the exercise:2.
	 * Perform test on Display and arrangement rules.
	 */
	part2tests();

	/*
	 * TEST3: Run the test cases respective to the exercise:3.
	 * Perform test on Shots made by the players.
	 */
	part3tests();

	return 0;
}
