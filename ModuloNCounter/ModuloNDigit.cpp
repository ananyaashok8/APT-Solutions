/*
 * ModuloNDigit.cpp
 *
 *  Created on: 10-Nov-2021
 *      Author: 91819
 */
#include "ModuloNDigit.h"

#include <iostream>
#include <stdlib.h>


/**
 * Initialization of variables using a default constructor
 */
ModuloNDigit::ModuloNDigit()
{
	//Initialize the attributes
		 sdc_currentCount = 0;
		 m_base = 0;
}

/**
 * Initialization of variables using a parameterized constructor
 */
ModuloNDigit::ModuloNDigit(int base)
{
	//Initialize the attributes
	 sdc_currentCount = 0;
	 m_base = base;

}


/**
 * de-Initialization of variables using destructor
 */
ModuloNDigit::~ModuloNDigit()
{
	//Initialize the attributes
		 sdc_currentCount = 0;
		 m_base = 0;
}


/**
 * Initialization of input variables
 */

void ModuloNDigit::sdc_init(int count, int base)
{
	if (base <= 16)
	{
		m_base = base;
	}
	else
	{
		//Default value initialization
		cout << "User INput error, take 10 as base" << "\n";
		m_base = 10;
	}

}



void ModuloNDigit::sdc_print()
{
	//print function for ModuloNDigit
	cout << hex << sdc_currentCount ;
}


int ModuloNDigit::sdc_count()
{
	// to count values from 0-N
		if (sdc_currentCount < m_base-1)
						{
					        sdc_currentCount++;
							return 0;
						}
						else
						{
							sdc_currentCount = 0;
							return 1;
						}
		return 0;
}


