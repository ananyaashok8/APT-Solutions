/*
 * SimpleUI.h
 *
 *  Created on: 15-Jan-2022
 *      Author: Ananya Ashok
 */

#ifndef SIMPLEUI_H_
#define SIMPLEUI_H_

#include "StudentDb.h"


/**
 * Represents User Interface to get student data from the user .
 */
class SimpleUI
{
	StudentDb *dbPtr;

public:

	/**
	 * Parameterized constructor to SimpleUI class.
	 */
	SimpleUI(StudentDb& db);


	/**
	 * Represents the operations that can be performed on the student database.
	 */
	void run();
};

#endif /* SIMPLEUI_H_ */
