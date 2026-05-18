/*
 * ModuloNCounter.cpp
 *
 *  Created on: 10-Nov-2021
 *      Author: 91819
 */
#include "ModuloNCounter.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * Initialization of variables using a default constructor
 */
ModuloNCounter::ModuloNCounter()
{
	//Initialize the attributes
	 mdc_digits = 0;
	 m_base = 0;
	 pSDC = NULL;
}

/**
 * Initialization of variables using a parameterized constructor
 */

ModuloNCounter::ModuloNCounter( int digit, int base)
{

	 mdc_digits = digit;
	 m_base = base;
	 if (0 == digit)
	 	{
	 		digit = 1;
	 	}

	// new operator for memory allocation
	 pSDC = new ModuloNDigit[mdc_digits];

	//Initialize the single digit counters
	for (int i = 0; i < mdc_digits; i++)
	{
		pSDC[i]= ModuloNDigit(m_base); // use pointer to call the SDC constructor
	}

}


/**
 * Initialization of variables to 0 before cleaning the memory allocated using the destructor
 */

ModuloNCounter::~ModuloNCounter()
{
	mdc_digits = 0;
	m_base = 0;
}


/**
 * to print the counter value
 */

void ModuloNCounter::mdc_print()
{

	if(m_base == 2 )
	{
		for (short i = mdc_digits - 1; i >= 0; i--)
			{
			  pSDC[i].sdc_print();
			}
	}
	else
	{
		for(short i = mdc_digits - 1; i >= 0; i--)
		{

			pSDC[i].sdc_print();
			if(i % mdc_digits==0)
				cout<<" ";

		}

	}

}


/**
 * to count the counter data for given digits and base values
 */

int ModuloNCounter::mdc_count()
{
	int carry =0;
	for (int i = 0; i < mdc_digits; i++)
		{
			carry =  pSDC[i].sdc_count();
			if (0 == carry)
			{
				//no need to tick further
				break;
			}
		}

		return 0;
}


/**
 * post-increment overloading implementation for Modulo N Counter
 */

ModuloNCounter& ModuloNCounter::operator ++()
{
	mdc_count();
	return *this;
}

/**
 * pre-increment overloading implementation for Modulo N Counter
 */

ModuloNCounter ModuloNCounter::operator ++(int)
{
	ModuloNCounter temp = *this;
	this->mdc_count();
	return temp;
}

/**
 * copy constructor for pre-increment operator overloading implementation of Modulo N Counter
 */

ModuloNCounter::ModuloNCounter(const ModuloNCounter &obj)
{
	mdc_digits = obj.mdc_digits;
	m_base = obj.m_base;
	pSDC = new ModuloNDigit[mdc_digits];
	for(int i=0; i < mdc_digits; i++)
	{
		pSDC[i] = obj.pSDC[i]; // deep copy
	}

}

/**
 * assignment operator overloading for pre-increment operator overloading implementation of Modulo N Counter
 */

ModuloNCounter& ModuloNCounter::operator =(const ModuloNCounter &obj)
{
	delete[] pSDC;
	mdc_digits = obj.mdc_digits;
	m_base = obj.m_base;
	pSDC = new ModuloNDigit[mdc_digits];
	for(int i=0; i < mdc_digits; i++)
	{
		pSDC[i] = obj.pSDC[i];
	}
	return *this;

}


